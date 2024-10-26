// #include <iostream>
// #include <iomanip>
// #include <vector>
// #include <cmath>
// #include <algorithm>

// using namespace std;

// // Constants
const int MAX_ITER = 100;
// const double TOLERANCE = 1e-4;

// Function prototypes
void checkInfiniteOrNoSolution(const vector<vector<double> >& A, const vector<double>& b, int mehedi);
void call(int mehedi){
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<double> > A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter the matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the vector b:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    checkInfiniteOrNoSolution(A, b, mehedi);
}
void jacobiMethod(const vector<vector<double> >& A, const vector<double>& b);
void gaussSeidelMethod(const vector<vector<double> >& A, const vector<double>& b);
void rungeKuttaMethod();
void matrixInversion();


double derivativeFunction(double x, double y);
void inputMatrix(vector<vector<double> >& matrix, int n);
void printMatrix(const vector<vector<double> >& matrix);
bool isDiagonallyDominant(const vector<vector<double> >& A);
// Jacobi Method for solving linear equations
void jacobiMethod(const vector<vector<double> >& A, const vector<double>& b) {
    int n = A.size();
    vector<double> x(n, 0.0), x_new(n);

    for (int iter = 0; iter < MAX_ITER; iter++) {
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        double max_error = 0.0;
        for (int i = 0; i < n; i++) {
            max_error = max(max_error, fabs(x_new[i] - x[i]));
            x[i] = x_new[i];
        }

        if (max_error < TOLERANCE) {
            cout << "- Solution:\n";
            for (double val : x) {
                cout << fixed << setprecision(6) << val << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Jacobi method did not converge within the maximum iterations.\n";
}

// Gauss-Seidel Method for solving linear equations
void gaussSeidelMethod(const vector<vector<double> >& A, const vector<double>& b) {
    int n = A.size();
    vector<double> x(n, 0.0);

    for (int iter = 0; iter < MAX_ITER; iter++) {
        vector<double> x_new = x; // Copy the current solution

        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    sum += A[i][j] * x_new[j]; // Use updated values
                } else if (j > i) {
                    sum += A[i][j] * x[j]; // Use old values
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        double max_error = 0.0;
        for (int i = 0; i < n; i++) {
            max_error = max(max_error, fabs(x_new[i] - x[i]));
            x[i] = x_new[i]; // Update for next iteration
        }

        if (max_error < TOLERANCE) {
            cout << "- Solution:\n";
            for (double val : x) {
                cout << fixed << setprecision(6) << val << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Gauss-Seidel method did not converge within the maximum iterations.\n";
}

// Runge-Kutta 4th Order Method for solving ODEs
double derivativeFunction(double x, double y) {
    return 2 * x + 1; // Example dy/dx = 2x + 1
}

void rungeKuttaMethod() {
    double x0, y0, h, x_end;
    cout << "Enter initial value of x (x0): ";
    cin >> x0;
    y0 = derivativeFunction(x0, 0);
    cout << "Enter the end value of x: ";
    cin >> x_end;
    cout << "Enter the step size (h): ";
    cin >> h;

    int n = static_cast<int>((x_end - x0) / h);
    cout << fixed << setprecision(6);
    cout << "Step\tX\t\tY\n";
    for (int i = 0; i <= n; ++i) {
        cout << i << "\t" << x0 << "\t\t" << y0 << "\n";
        double k1 = h * derivativeFunction(x0, y0);
        double k2 = h * derivativeFunction(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * derivativeFunction(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * derivativeFunction(x0 + h, y0 + k3);
        y0 += (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 += h;
    }
}

// Matrix Inversion using Gauss-Jordan elimination
void matrixInversion() {
    int n;
    cout << "Enter the number of equations (n): ";
    cin >> n;

    vector<vector<double> > A(n, vector<double>(n));
    inputMatrix(A, n);

    vector<vector<double> > augmented(n, vector<double>(2 * n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = A[i][j];
        }
        augmented[i][i + n] = 1;
    }

    for (int i = 0; i < n; ++i) {
        double diagElement = augmented[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= diagElement;
        }

        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double ratio = augmented[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmented[k][j] -= ratio * augmented[i][j];
                }
            }
        }
    }

    cout << "Inverse of the matrix:\n";
    vector<vector<double> > inverse(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmented[i][j + n];
        }
    }

    printMatrix(inverse);
}

// Check for special cases: infinitely many solutions or no solution
void checkInfiniteOrNoSolution(const vector<vector<double> >& A, const vector<double>& b, int mehedi) {
    int n = A.size();
    vector<vector<double> > augmented(n, vector<double>(n + 1));

    // Create augmented matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = A[i][j];
        }
        augmented[i][n] = b[i];
    }

    // Row reduction to echelon form
    for (int i = 0; i < n; i++) {
        double maxEl = fabs(augmented[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(augmented[k][i]) > maxEl) {
                maxEl = fabs(augmented[k][i]);
                maxRow = k;
            }
        }
        for (int k = i; k < n + 1; k++) {
            swap(augmented[maxRow][k], augmented[i][k]);
        }
        for (int k = i + 1; k < n; k++) {
            double c = -augmented[k][i] / augmented[i][i];
            for (int j = i; j < n + 1; j++) {
                if (i == j) {
                    augmented[k][j] = 0;
                } else {
                    augmented[k][j] += c * augmented[i][j];
                }
            }
        }
    }

    int rankA = 0, rankAugmented = 0;
    for (int i = 0; i < n; i++) {
        bool allZeroA = true, allZeroAugmented = true;
        for (int j = 0; j < n; j++) {
            if (augmented[i][j] != 0) {
                allZeroA = false;
                break;
            }
        }
        if (!allZeroA) rankA++;
        for (int j = 0; j <= n; j++) {
            if (augmented[i][j] != 0) {
                allZeroAugmented = false;
                break;
            }
        }
        if (!allZeroAugmented) rankAugmented++;
    }

    if (rankA < rankAugmented) {
        cout << "The system has no solution.\n";
    } else if (rankA < n) {
        cout << "The system has infinitely many solutions.\n";
    } else {
        // Check for diagonal dominance before calling Jacobi method
        if (isDiagonallyDominant(A)) {
            if(mehedi == 1)
                jacobiMethod(A, b);
            else
                gaussSeidelMethod(A, b);
        } else {
            cout << "The matrix is not diagonally dominant; the Jacobi method may not converge.\n";
        }
    }
}

// Helper function to input matrix
void inputMatrix(vector<vector<double> >& matrix, int n) {
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Helper function to print matrix
void printMatrix(const vector<vector<double> >& matrix) {
    cout << fixed << setprecision(6);
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

// Check if the matrix is diagonally dominant
bool isDiagonallyDominant(const vector<vector<double> >& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                sum += fabs(A[i][j]);
            }
        }
        if (fabs(A[i][i]) < sum) {
            return false;
        }
    }
    return true;
}
