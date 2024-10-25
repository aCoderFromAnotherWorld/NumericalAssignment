#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;
#define TOLERANCE 0.00001
#define A (9+2*y-z)
#define B (-6+2*x+z)
#define C (12-x+y)

void jacobi()
{
    double Ex, Ey, Ez, E = INFINITY;
    double x = 0, y = 0, z = 0, tx, ty, tz;

    cout<<"Number of unknown variable : ";
    int n;
    cin>>n;
    vector<double> var(n, 0);
    vector<vector<double>> coeff(n, vector<double>(n+1));

    // vector<vector<double>> error(n, vector<double>(n, 0));
    double a1, b1, c1, a2, b2, c2, a3, b3, c3;
    cout<<"Enter value for a1, b1, c1";
    
    while(E > TOLERANCE)
    {
        tx = A / 10 ;
        ty = B / 8 ;
        tz = C / 5 ;

        Ex = abs(tx - x);
        Ey = abs(ty - y);
        Ez = abs(tz - z);
        E = (Ex + Ey + Ez) / 3;
        // cout<<setprecision(5)<<it<<"\t"<<x<<"\t"<<y<<"\t"<<z<<"\t"<<tx<<"\t"<<ty<<"\t"<<tz<<"\t"<<Ex[it-1]<<"\t"<<Ey[it-1]<<"\t"<<Ez[it-1]<<"\t"<<E[it-1]<<"\n";
        x = tx, y = ty, z = tz ;
    }
    // cout<<"End Jacobi\n";
    cout<<setprecision(3)<<"x="<<x<<"y="<<y<<"z="<<z<<endl;
}