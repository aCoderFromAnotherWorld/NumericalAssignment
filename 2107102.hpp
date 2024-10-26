double calculateFunction(double x, double coeffs[], int degree)
{
    double result = 0.0;
    for (int i = 0; i <= degree; i++)
    {
        result += coeffs[i] * pow(x, degree - i);
    }
    return result;
}

// Helper function to validate the user-provided initial guesses
bool validateInitialGuesses(double coeffs[], int degree, double a, double b)
{
    double f_a = calculateFunction(a, coeffs, degree);
    double f_b = calculateFunction(b, coeffs, degree);

    if (f_a * f_b < 0)
    {                // Check if there's a sign change
        return true; // Valid guesses
    }
    else
    {
        cout << "Invalid initial guesses! f(a) and f(b) must have opposite signs.\n";
        return false; // Invalid guesses
    }
}

int SecantMethod()
{
    cout.precision(4);
    cout.setf(ios::fixed); // Set the precision of the output

    int degree;
    cout << "Enter the degree of the polynomial (1 to 4): ";
    cin >> degree;

    // Validate degree input
    if (degree < 1 || degree > 4)
    {
        cout << "Invalid degree. Please enter a value between 1 and 4.\n";
        return 1; // Exit if the degree is invalid
    }

    double coeffs[5]; // Array to hold coefficients for polynomials up to degree 4

    // Input coefficients for the polynomial
    cout << "Enter the coefficients from highest degree to constant term:\n";
    for (int i = 0; i <= degree; i++)
    {
        cout << "Coefficient of x^" << (degree - i) << ": ";
        cin >> coeffs[i];
    }

    double a, b, e; // Variables for the initial guesses and the desired accuracy

    // Input initial guesses from the user
    cout << "Enter the initial guesses:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    // Validate initial guesses
    while (!validateInitialGuesses(coeffs, degree, a, b))
    {
        cout << "Please enter new guesses:\n";
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
    }

    cout << "Enter the degree of accuracy e: ";
    cin >> e; // Take the desired accuracy

    // Secant method implementation
    double c; // Variable for the new guess
    do
    {
        // Calculate the next point using the secant formula
        c = b - (b - a) / (calculateFunction(b, coeffs, degree) - calculateFunction(a, coeffs, degree)) * calculateFunction(b, coeffs, degree);

        if (calculateFunction(c, coeffs, degree) == 0)
        {
            cout << "\nThe root of the equation is " << c; // Print the root
            return 0;
        }

        a = b;
        b = c;

    } while (abs(c - b) >= e); // Check if the error is greater than the desired accuracy

    cout << "\nThe root of the equation is " << c; // Print the root
    return 0;                                      // End of the program
}

int BiSection()
{
    cout.precision(4);     // Set the precision for output
    cout.setf(ios::fixed); // Fix the decimal places in output

    double lowerBound, upperBound, midpoint, tolerance, fLower, fUpper, fMid; // Variables for bounds and function values
    int degree;
    double coeffs[5]; // Declare coeffs outside the loop to be accessible later

    // Input loop to get valid initial guesses from the user
    do
    {
        cout << "Enter the degree of the polynomial (1 to 4): ";
        cin >> degree; // User inputs the degree of the polynomial

        if (degree < 1 || degree > 4)
        {
            cout << "Invalid degree. Please enter a value between 1 and 4.\n";
            continue; // Repeat if the degree is invalid
        }

        // Input coefficients based on the degree of the polynomial
        cout << "Enter the coefficients from highest degree to constant term:\n";
        for (int i = 0; i <= degree; i++)
        {
            cout << "Coefficient of x^" << (degree - i) << ": ";
            cin >> coeffs[i];
        }

        cout << "Enter the initial guesses for the root:\n";
        cout << "Lower bound (a): ";
        cin >> lowerBound; // User inputs the lower bound
        cout << "Upper bound (b): ";
        cin >> upperBound; // User inputs the upper bound
        cout << "Enter the desired degree of accuracy: ";
        cin >> tolerance; // User inputs the desired accuracy

        // Check if a root exists between lowerBound and upperBound
        if (calculateFunction(lowerBound, coeffs, degree) * calculateFunction(upperBound, coeffs, degree) > 0)
        {
            cout << "No root exists between the given bounds. Please enter different initial guesses.\n";
        }
    } while (calculateFunction(lowerBound, coeffs, degree) * calculateFunction(upperBound, coeffs, degree) > 0); // Repeat until valid guesses are provided

    // Bisection method to find the root
    while (fabs(lowerBound - upperBound) >= tolerance)
    {
        midpoint = (lowerBound + upperBound) / 2.0; // Calculate the midpoint
        fLower = calculateFunction(lowerBound, coeffs, degree);
        fUpper = calculateFunction(upperBound, coeffs, degree);
        fMid = calculateFunction(midpoint, coeffs, degree);

        // Display the current bounds and the midpoint value
        // cout << "Lower Bound (a) = " << lowerBound
        //      << " | Upper Bound (b) = " << upperBound
        //      << " | Midpoint (c) = " << midpoint
        //      << " | f(c) = " << fMid << endl;

        // Check if we have found the exact root
        if (fMid == 0)
        {
            cout << "The root of the equation is " << midpoint << endl;
            return 0; // Exit if the exact root is found
        }

        // Adjust the bounds based on the function values
        if (fLower * fMid > 0)
        {
            lowerBound = midpoint; // Move the lower bound up
        }
        else
        {
            upperBound = midpoint; // Move the upper bound down
        }
    }

    // Output the approximate root after finishing the iterations
    cout << "The root of the equation is approximately " << midpoint << endl;

    return 0; // End of the program
}

int FaslePosition()
{
    // Set precision for output
    cout.precision(4);
    cout.setf(ios::fixed);

    double x0, x1;
    double f0, f1, f2, x2, e;
    int iterationCount = 0;
    int degree;

    // Input for polynomial degree
    cout << "Enter the degree of the polynomial (1 to 4): ";
    cin >> degree;

    // Validate degree
    if (degree < 1 || degree > 4)
    {
        cout << "Invalid degree. Please enter a value between 1 and 4.\n";
        return 1; // Exit if the degree is invalid
    }

    double coeffs[5]; // Array to hold coefficients for polynomials up to degree 4

    // Input coefficients for the polynomial
    cout << "Enter the coefficients from highest degree to constant term:\n";
    for (int i = 0; i <= degree; i++)
    {
        cout << "Coefficient of x^" << (degree - i) << ": ";
        cin >> coeffs[i];
    }

    // Input loop to get valid initial guesses
    do
    {
        cout << "Enter two initial guesses (x0 and x1) such that f(x0) < 0 and f(x1) > 0:\n";
        cout << "x0: ";
        cin >> x0;
        cout << "x1: ";
        cin >> x1;

        // Calculate function values at the bounds
        f0 = calculateFunction(x0, coeffs, degree);
        f1 = calculateFunction(x1, coeffs, degree);

        // Check if the function values at the bounds have opposite signs
        if (f0 * f1 >= 0)
        {
            cout << "Invalid input! The function must have opposite signs at the two bounds. Please try again.\n";
        }
    } while (f0 * f1 >= 0); // Repeat until valid guesses are provided

    // Input for accuracy tolerance
    cout << "Enter desired accuracy (e): ";
    cin >> e;

    // Iterative method to find the root using the False Position Method
    do
    {
        // Calculate the next point using the false position formula
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        f2 = calculateFunction(x2, coeffs, degree);

        // Display the current iteration's results
        iterationCount++;
        // cout << "Iteration " << iterationCount << ": x = " << x2 << ", f(x) = " << f2 << endl;

        // Update bounds based on the sign of f(x2)
        if (f2 < 0)
        {
            x0 = x2; // Move lower bound up
            f0 = f2; // Update function value at the new lower bound
        }
        else
        {
            x1 = x2; // Move upper bound down
            f1 = f2; // Update function value at the new upper bound
        }

    } while (abs(f2) > e); // Continue until the function value is within tolerance

    // Output the root
    cout << "\nThe approximate root is: " << x2 << endl;

    return 0; // End of the program
}

// Function to calculate the derivative of the polynomial given its coefficients
double calculateDerivative(double x, double coeffs[], int degree)
{
    double result = 0.0;
    for (int i = 0; i < degree; i++)
    { // Derivative degree is one less than the polynomial degree
        result += coeffs[i] * (degree - i) * pow(x, degree - i - 1);
    }
    return result;
}

void NewtonRaphson()
{
    cout.precision(4); // Set the precision for output
    cout.setf(ios::fixed);

    int degree;
    cout << "Enter the degree of the polynomial (1 to 4): ";
    cin >> degree;

    // Validate degree input
    if (degree < 1 || degree > 4)
    {
        cout << "Invalid degree. Please enter a value between 1 and 4.\n";
        return; // Exit if the degree is invalid
    }

    double coeffs[5]; // Array to hold coefficients for polynomials up to degree 4

    // Input coefficients for the polynomial
    cout << "Enter the coefficients from highest degree to constant term:\n";
    for (int i = 0; i <= degree; i++)
    {
        cout << "Coefficient of x^" << (degree - i) << ": ";
        cin >> coeffs[i];
    }

    double x, x1, e, fx, fx1;

    // Input loop for the initial guess
    do
    {
        cout << "Enter the initial guess: ";
        cin >> x1; // Take an initial guess

        // Check if the derivative at the initial guess is zero
        fx1 = calculateDerivative(x1, coeffs, degree);
        if (fx1 == 0)
        {
            cout << "The derivative is zero at x = " << x1 << ". Please choose a different initial guess." << endl;
        }
    } while (fx1 == 0); // Repeat until a valid initial guess is provided

    // Input for desired accuracy
    cout << "Enter desired accuracy: ";
    cin >> e;

    cout << "x{i}" << "    " << "x{i+1}" << "        " << "|x{i+1}-x{i}|" << endl;

    // Newton-Raphson iteration
    do
    {
        x = x1;                                       // Make x equal to the last calculated value of x1
        fx = calculateFunction(x, coeffs, degree);    // Calculate f(x)
        fx1 = calculateDerivative(x, coeffs, degree); // Calculate f'(x)
        x1 = x - (fx / fx1);                          // Calculate the next approximation
        cout << x << "     " << x1 << "           " << abs(x1 - x) << endl;
    } while (fabs(x1 - x) >= e); // Continue until the desired accuracy is met

    cout << "The root of the equation is " << x1 << endl;
}
