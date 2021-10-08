#include "std_lib_facilities.h"

int main()
{
	double szam1;
	double szam2;
	
	cout << "To exit to the programe type '|'. To continue give two numbers." << endl;
	
	while(cin >> szam1 >> szam2)
	{
		
		if (szam1 < szam2)
			{
				cout << "the smaller value is: " << szam1 << endl;
				cout << "the larger value is: " << szam2 << endl;
				if (szam2 - szam1 < 1.0/100)
				{
					cout << "the numbers are almost equal." << endl;
				}
			}
		else if (szam2 < szam1)
			{
				cout << "the smaller value is: " << szam2 << endl;
				cout << "the larger value is: " << szam1 << endl;
				if (szam1 - szam2 < 1.0/100)
				{
					cout << "the numbers are almost equal." << endl;
				}
			}
		 else
			{
				cout << "the numbers are equal." << endl;
			}
	}

	return 0;
}
