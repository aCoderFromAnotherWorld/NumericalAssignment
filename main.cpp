#include "2107100.hpp"
#include "2107086.hpp"
#include "2107102.hpp"

// Main function
int main()
{
    int choice;
    do
    {
        cout << "\n---- Numerical Methods Console Application ----\n";
        cout << "1. Solution For Linear Equation\n";
        cout << "2. Solution of Non-linear Equations\n";
        cout << "3. Solution of Differential Equations\n";
        cout << "4. Matrix Inversion\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\ta. Jacobi Iteratiive Method\n";
            cout << "\tb. Gauss-Seidel Iterative Method\n";
            cout << "\tc. Gauss Elimination\n";
            cout << "\td. Gausss-Jordan Elimination\n";
            cout << "\te.LU Eactorization\n";
            cout << "Choose an option: ";
            char sub_choice;
            cin >> sub_choice;

            switch (sub_choice)
            {
            case 'a':
                call(1);
                break;
            case 'b':
                call(2);
                break;
            case 'c':
                gaussElimination();
                break;
            case 'd':
                gaussJordanElimination();
                break;
            case 'e':
                LUMethod();
                break;

            default:
                cout << "Invalid choice\n";
            }
            break;
        }
        case 2:
        {
            cout << "\ta. Bi-section method\n"
                 << "\tb. False position method\n"
                 << "\tc. Secant method\n"
                 << "\td. Newton-Raphson method\n"
                 <<"\tChoose an option: ";

            char sub_choice;
            cin >> sub_choice;
            switch (sub_choice)
            {
            case 'a':
                BiSection();
                break;
            case 'b':
                FaslePosition();
                break;
            case 'c':
                SecantMethod();
                break;
            case 'd':
                NewtonRaphson();
                break;
            default:
                cout << "Invalid choice\n";
            }
            break;
        }
        case 3:
            cout << "\ta. Runge-Kutta Method\n";
            char a;
            cout<<"Choose an option: ";
            cin>>a;
            if(a == 'a')
            {
                rungeKuttaMethod();
            }
            else{
                cout<<"Invalid choice\n";
            }
            break;
        case 4:
            matrixInversion();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
