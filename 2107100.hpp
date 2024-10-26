#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;
#define TOLERANCE 0.00001

void printSolutionFromUpperTriangular(const vector<vector<double>>& matrix, int n) {
    vector<double> solution(n, 0);
    bool hasUniqueSolution = true;

    // Back-substitution to find solutions
    for (int i = n - 1; i >= 0; --i) {
        double sum = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            sum -= matrix[i][j] * solution[j];
        }

        if (matrix[i][i] == 0) {
            if (abs(sum) > 1e-9) {
                cout << "No solution (inconsistent system).\n";
                return;
            } else {
                hasUniqueSolution = false;
            }
        } else {
            solution[i] = sum / matrix[i][i];
        }
    }

    if (!hasUniqueSolution) {
        cout << "Many solutions (system is underdetermined).\n";
    } else {
        cout << "Unique Solution:\n";
        for (int i = 0; i < n; ++i) {
            cout << "x" << i + 1 << " = " << solution[i] << endl;
        }
    }
}

void gaussElimination() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));
    cout << "Enter the augmented matrix (including RHS for each equation):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int pivotRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[pivotRow][i])) {
                pivotRow = j;
            }
        }

        if (pivotRow != i) {
            swap(matrix[i], matrix[pivotRow]);
        }

        double pivot = matrix[i][i];
        if (pivot == 0) {
            continue;
        }

        for (int j = i; j <= n; ++j) {
            matrix[i][j] /= pivot;
        }

        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i];
            for (int k = i; k <= n; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    printSolutionFromUpperTriangular(matrix, n);
}

void printSolutionFromRREF(const vector<vector<double>>& matrix, int n) {
    vector<double> solution(n, 0);
    bool hasUniqueSolution = true;

    for (int i = 0; i < n; ++i) {
        bool allZeroRow = true;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                allZeroRow = false;
                break;
            }
        }

        if (allZeroRow && matrix[i][n] != 0) {
            cout << "No solution (inconsistent system).\n";
            return;
        } else if (allZeroRow && matrix[i][n] == 0) {
            hasUniqueSolution = false;
        } else {
            solution[i] = matrix[i][n];
        }
    }

    if (!hasUniqueSolution) {
        cout << "Many solutions (system is underdetermined).\n";
    } else {
        cout << "Unique Solution:\n";
        for (int i = 0; i < n; ++i) {
            cout << "x" << i + 1 << " = " << solution[i] << endl;
        }
    }
}

void gaussJordanElimination() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));
    cout << "Enter the augmented matrix (including RHS for each equation):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        double pivot = matrix[i][i];
        if (pivot == 0) {
            bool nonZeroBelow = false;
            for (int j = i + 1; j < n; ++j) {
                if (matrix[j][i] != 0) {
                    swap(matrix[i], matrix[j]);
                    nonZeroBelow = true;
                    pivot = matrix[i][i];
                    break;
                }
            }
            if (!nonZeroBelow) {
                continue;
            }
        }

        for (int j = 0; j <= n; ++j) {
            matrix[i][j] /= pivot;
        }

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = matrix[j][i];
                for (int k = 0; k <= n; ++k) {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }
    }

    printSolutionFromRREF(matrix, n);
}




void LUdecomposition(vector<vector<double>>&a, vector<vector<double>>&l, vector<vector<double>>&u, int n) {
   int i = 0, j = 0, k = 0;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (j < i)
         l[j][i] = 0;
         else {
            l[j][i] = a[j][i];
            for (k = 0; k < i; k++) {
               l[j][i] = l[j][i] - l[j][k] * u[k][i];
            }
         }
      }
      for (j = 0; j < n; j++) {
         if (j < i)
         u[i][j] = 0;
         else if (j == i)
         u[i][j] = 1;
         else {
            u[i][j] = a[i][j] / l[i][i];
            for (k = 0; k < i; k++) {
               u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
            }
         }
      }
   }
}

vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b) {
    int n = b.size();
    vector<double> y(n, 0);

    for (int i = 0; i < n; ++i) {
        y[i] = b[i];
        for (int j = 0; j < i; ++j) {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }
    return y;
}

// Backward substitution to solve Ux = y
vector<double> backwardSubstitution(const vector<vector<double>>& U, const vector<double>& y) {
    int n = y.size();
    vector<double> x(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    return x;
}

// Function to solve a system of equations given L, U, and b
void solveLinearSystem(int n, vector<vector<double>> &L,vector<vector<double>> &U, vector<double> &b) {
    
        // Solve for y in Ly = b
    vector<double> y = forwardSubstitution(L, b);
    
    // Solve for x in Ux = y
    vector<double> x = backwardSubstitution(U, y);
    cout << "L Decomposition is as follows..."<<endl;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout<<L[i][j]<<" ";
      }
      cout << endl;
   }
   cout << "U Decomposition is as follows..."<<endl;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout<<L[i][j]<<" ";
      }
      cout << endl;
   }

    // Output the result
    cout << "Solution:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

void LUMethod() {

    int n;
    cout << "Select the number of variables (2-5): ";
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n, 0));
    vector<vector<double>> l(n, vector<double>(n, 0));
    vector<vector<double>> u(n, vector<double>(n,0));
    vector<double> b(n);

    cout<<"Enter matrix values: "<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter the result vector b:\n";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    LUdecomposition(a, l, u, n);
    solveLinearSystem(n, l, u, b);
}
