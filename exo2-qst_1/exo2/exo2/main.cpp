#include <iostream>
#include <random>
#include <math.h>
using namespace std;
#define MAX 1000



void nFirstElementVect(int n, double a, double b, double u0, double u1, double v[MAX])
{
	v[0] = u0;
	v[1] = u1;

	for (int i = 2 ; i < n ; i++)
	{
		v[i] = -(a*v[i-1] + b*v[i-2]);
	}

}


void show( double v[MAX], int n )
{
	for(int i = 0 ; i < n ; i++){
		cout << "U[" << (i+1) << "] = " << v[i] << endl;
	}
}


int main()
{
	int n = 0;
	double a = 0.0, b = 0.0, u0 = 0.0, u1 = 0.0;
	double Y[MAX];
	
    cout << "Give us value of N : " ;
	cin >> n;
	cout << "Give us value of a : " ;
	cin >> a;
	cout << "Give us value of b : " ;
	cin >> b;
	cout << "Give us value of u0 : " ;
	cin >> u0;
	cout << "Give us value of u1 : " ;
	cin >> u1;

	nFirstElementVect(n,a,b,u0,u1,Y);

	show(Y,n);


	system("pause");
    return 0;
}
