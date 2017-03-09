#include <iostream>
#include <random>
#include <math.h>
using namespace std;
#define MAX 1000
double vect[MAX];
double cumsumVect[MAX];
double vect_1[MAX];
double vect_2[MAX];
double cumsumvect_1[MAX];
double cumsumvect_2[MAX];
double convoVect[2*MAX - 1];




void mean_reversion(double a[MAX],int day ,double *trade)
{
	do{
		if(day <= 4)
		{
			day = 0;
			cout << "Impossible to do mean reversion the number of days must be over 4 days" << endl;
			cout << " day : ";
			cin >> day;
		}
		else
		{
			(*trade) = -(a[day-1]/day);
		}
	}while(day < 5);
}


void convolution(double v1[MAX],double v2[MAX],double vConvo[2*MAX-1])
{
	for (size_t n = 0; n < 2*MAX - 1; n++)
        for (size_t k = 0; k < MAX; k++)
            vConvo[n] += (k < MAX ? v1[k] : 0) * (n - k < MAX ? v2[n - k] : 0);
}

void cumsum(double v[MAX],double a[MAX])
{
	a[0] = v[0];
	for( int i = 1 ; i < MAX ; i++ ){
		a[i] = a[i-1] + v[i];
	}
}

void fill_vector(double v[MAX])
{
	for (int i=0; i<MAX; i++) {
		std::default_random_engine generator;
		double d = pow(2,(double)i);
		std::normal_distribution<double> distribution(0.0,(1/d));
		double number = distribution(generator);
		v[i] = number;
	}
}

void show( double v[MAX])
{
	for(int i = 0 ; i < MAX ; i++){
		cout << "V[" << i << "] = " << v[i] << endl;
	}
}

int main()
{
	double trade = 0 ;
	int day, stop = 0, choice = -1;


	do{
		system("cls");
		cout << "\n\n\t\tMENU : \n" << endl;
		cout << "\t\t1) first question." << endl;
		cout << "\t\t2) second question." << endl;
		cout << "\t\t3) third question." << endl;
		cout << "\t\t4) Mean reversion." << endl;
		cout << "\t\t5) Exit.\n\n" << endl;
		cout << "\tYour choice : ";
		cin >> choice;
		system("cls");

		switch(choice)
		{

		case 1:
			fill_vector(vect);
			show(vect);
			system("pause");
			choice = -1;
			break;

		case 2:
			fill_vector(vect);
			cumsum(vect,cumsumVect);
			show(cumsumVect);
			system("pause");
			choice = -1;
			break;

		case 3:
			fill_vector(vect_1);
			fill_vector(vect_2);
			convolution(vect_1,vect_2,convoVect);
			show(convoVect);
			system("pause");
			choice = -1;
			break;

		case 4:
			cout << " day : ";
			cin >> day;
			mean_reversion(vect,day,&trade);
			cout << trade << endl;
			system("pause");
			choice = -1;
			break;

		case 5:
			stop = 1;
			break;

		default:
			cout << "\nError !!\n" << endl;
			system("pause");
			choice = -1;
			break;
		}

	}while(!stop);

	
	system("cls");
	system("pause");
    return 0;
}
