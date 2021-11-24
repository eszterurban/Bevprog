#include "std_lib_facilities.h"

void print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "print_array10()-nek a " << i+1 << ". eleme: " << a[i] << endl;
	}
	cout << endl;
}

void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "print_array()-nek a " << i+1 << ". eleme: " << a[i] << endl;
	}
	cout << endl;
}

void print_vector(ostream& os, vector<int> printvektor, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "print_vector()-nak a " << i+1 << ". eleme: " << printvektor[i] << endl;
	}
	cout << endl;
}

int main()
{
	int* tiz = new int[10];
	
	print_array10(cout, tiz);
	
	int n = 10;

	print_array(cout, tiz, n);
	
	int* tiz2 = new int[10];
	
	for (int i = 0; i < 10; ++i) 
	{
		tiz2[i] = 100 + i;
		cout << "tiz2-nek a " << i+1 << ". eleme: " << tiz2[i] << endl;
	}
	cout << endl;
	
	int* tizenegy = new int[11];

	for (int i = 0; i < 11; ++i) 
	{
		tizenegy[i] = 100 + i;
		cout << "tizenegy-nek a " << i+1 << ". eleme: " << tizenegy[i] << endl;
	}
	cout << endl;
	
	int* husz = new int[20];

	for (int i = 0; i < 20; ++i)
	{
		husz[i] = 100 + i;
		cout << "husz-nak a " << i+1 << ". eleme: " << husz[i] << endl;
	}
	cout << endl;
	
	delete[] tiz;
	delete[] tiz2;
	delete[] tizenegy;
	delete[] husz;
	
	vector<int> vektor10;

	for (int i = 0; i < 10; ++i)
	{
		vektor10.push_back(100+i);
		cout << "vektor10-nek a " << i+1 << ". eleme: " << vektor10[i] << endl;
	}
	cout << endl;

	vector<int> vektor11;

	for (int i = 0; i < 11; ++i)
	{
		vektor11.push_back(100+i);
		cout << "vektor11-nek a " << i+1 << ". eleme: " << vektor11[i] << endl;
	}
	cout << endl;

	vector<int> vektor20;

	for (int i = 0; i < 20; ++i) 
	{
		vektor20.push_back(100+i);
		cout << "vektor20-nak a " << i+1 << ". eleme: " << vektor20[i] << endl;
	}
	cout << endl;


	
	return 0;
}
