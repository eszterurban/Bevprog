#include "std_lib_facilities.h"

int main()
{
	int* number = new int;
	*number = 7;
	int* p1 = number;
	cout << "p1 értéke: " << *p1 << endl;
	cout << "p1 memóriahelye: " << p1 << endl;
	
	int* het = new int[7];
	for (int i = 0; i < 7; ++i)
	{
		het[i] = pow(2, i);
		cout << het[i] << endl;
	}
	int* p2 = het;
	cout << "p2 értéke: " << *p2 << endl;
	cout << "p2 memóriahelye: " << p2 << endl;
	
	int* p3 = p2;
	p1 = p2;
	p3 = p2;
	cout << "p1 értéke: " << *p1 << endl;
	cout << "p1 memóriahelye: " << p1 << endl;
	cout << "p2 értéke: " << *p2 << endl;
	cout << "p2 memóriahelye: " << p2 << endl;
	
	int* tiz = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		tiz[i] = pow(2, i);
		cout << tiz[i] << endl;
	}
	p1 = tiz;
	cout << "p1 értéke: " << *p1 << endl;
	cout << "p1 memóriahelye: " << p1 << endl;
	
	int* tiz2 = new int[10];
	p2 = tiz2;
	cout << "p2 értéke: " << *p2 << endl;
	cout << "p2 memóriahelye: " << p2 << endl;
	
	*p2 = *p1;
	
	vector<int> vektor10;
	for (int i = 0; i < 10; ++i)
	{
		vektor10.push_back(pow(2, i));
		cout << "vektor10-nek a " << i+1 << ". eleme: " << vektor10[i] << endl;
	}
	cout << endl;
	
	vector<int> vektor10_2;
	for (int i = 0; i < 10; ++i)
	{
		vektor10_2.push_back(pow(2, i));
		cout << "vektor10_2-nek a " << i+1 << ". eleme: " << vektor10_2[i] << endl;
	}
	cout << endl;

	delete[] number;
	delete[] het;
	delete[] tiz;
	delete[] tiz2;
	
	return 0;
}
