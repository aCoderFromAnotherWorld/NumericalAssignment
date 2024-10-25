#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;


#define A (9+2*y-z)
#define B (-6+2*x+z)
#define C (12-x+y)

void jacobi()
{
    double Ex[10], Ey[10], Ez[10], E[10];
    double x = 0, y = 0, z = 0, tx, ty, tz;
    for(int it = 1; it <= 10; it++)
    {
        tx = A / 10 ;
        ty = B / 8 ;
        tz = C / 5 ;

        Ex[it-1] = abs(tx - x);
        Ey[it-1] = abs(ty - y);
        Ez[it-1] = abs(tz - z);
        E[it-1] = (Ex[it-1] + Ey[it-1] + Ez[it-1]) / 3;
        cout<<setprecision(5)<<it<<"\t"<<x<<"\t"<<y<<"\t"<<z<<"\t"<<tx<<"\t"<<ty<<"\t"<<tz<<"\t"<<Ex[it-1]<<"\t"<<Ey[it-1]<<"\t"<<Ez[it-1]<<"\t"<<E[it-1]<<"\n";
        x = tx, y = ty, z = tz ;
    }
    cout<<"End Jacobi\n";
    cout<<setprecision(3)<<"x="<<x<<"y="<<y<<"z="<<z<<endl;
}