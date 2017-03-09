#include <iostream>
#include <random>
using namespace std;
double X[10000];
double Y[10000];
int T=100;

double SumArray(const double *X, int N)
{
	double Sum=0;
	const double *p=X;
	while (p <X+N)  
		Sum += *p++;
	return (Sum);
}

inline double Mean(const double *X, int N)
{
  return ( SumArray(X,N)/N );
}

double Covariance(double *X,double *Y, int N)
{
        double Temp[20000];
        int k;
		const double *p=X;
		const double *q=Y;
        for(k=0; k<N; k++)
			Temp[k]= (*p++) * (*q++);
		return Mean(Temp,N)-Mean(X,N)*Mean(Y,N);
}

double Variance(double *X, int N)
{
        return Covariance(X,X,N);
}

void init(){
    int i=0;
    for (i=0;i<T;i++){
        X[i]=i;
        Y[i]=5*X[i];
    }

	cout << "Vector X and Y created \n" << endl;
	system("pause");
}

void add_noise(){
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(6.0,1.0);
    int i =0;
     for (i=0;i<T;i++){
        double number = distribution(generator);
        Y[i]+=number;
     }
	 cout << "Noise added \n" << endl;
	 system("pause");
}
void display_table(){
    int i =0;
     for (i=0;i<T;i++){
        cout << Y[i] << endl;
     }
	 cout << "Vector Y displyed \n" << endl;
	 system("pause");
}
void regression(int *a , int *b){
	int i=0,sum =0;
	*a=Covariance(Y,X,T)/Variance(X,T);
	sum =*a;
	*b=Mean(Y,T)-sum*Mean(X,T);
	cout << "Regression calculated \n" << endl;
	 system("pause");
}
int main()
{
	int  stop = 0, choice = -1;
	int a=0,b=0;



	do{
		system("cls");
		cout << "\n\n\t\tMENU : \n" << endl;
		cout << "\t\t1) first question." << endl;
		cout << "\t\t2) second question." << endl;
		cout << "\t\t3) third question." << endl;
		cout << "\t\t4) Test." << endl;
		cout << "\t\t5) Exit.\n\n" << endl;
		cout << "\tYour choice : ";
		cin >> choice;
		system("cls");

		switch(choice)
		{

		case 1:
			init();
			system("pause");
			choice = -1;
			break;

		case 2:
			add_noise();
			system("pause");
			display_table();
			system("pause");
			choice = -1;
			break;

		case 3:
			regression(&a,&b);
			cout << " a = " <<  a  << endl;
			cout << " b = " <<  b  << endl;
			system("pause");
			choice = -1;
			break;

		case 4:
			cout << "\n\t\t For 100 : " << endl;
			init();
			add_noise();
			regression(&a,&b);
			cout << "\t a = " <<  a  << endl;
			cout << "\t b = " <<  b  << endl;
			system("pause");
			cout << "\n\t\t For 10.000 : " << endl;
			T = 10000;
			init();
			add_noise();
			regression(&a,&b);
			cout << "\t a = " <<  a  << endl;
			cout << "\t b = " <<  b  << endl;
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
