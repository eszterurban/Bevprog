#include "std_lib_facilities.h"

int ga[10] = {1, 2, 4, 8, 16, 32,  64, 128, 256, 512};

void f(int la[], int szam)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << la[i] << endl;
	}
	cout << endl;
	
	int* p = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		p[i] = la[i];
		cout << p[i] << endl;
	}
	delete[] p;
}

int main()
{
	f(ga, 10);
	int aa[10] = {1,2,6,24,120,720,5040,40320,362880,3628800};
	cout << endl;
	f(aa, 10);
	
	return 0;
}
