#include "std_lib_facilities.h"

int main()
{
	double szam1;
	double max;
	double min;
	bool sikeres = true;
	string egyseg;
	const double m_to_cm = 100;
	const double in_to_cm = 2.54;
	const double ft_to_in = 12;
	double vege;
	double ertekossz;
	vector<double> ertekek;
	
	
	cout << "To exit to the programe type '|'. To continue give a number and a unit. Unit can be : cm, m, in, ft." << endl;
	
	while(cin >> szam1 >> egyseg)
	{
		cout << szam1 << " " << egyseg << endl;
		
		if(egyseg == "cm")
			{
				vege = szam1 / m_to_cm;
				ertekek.push_back(vege);
			}
		else if(egyseg == "in")
			{
				vege = szam1 * in_to_cm / m_to_cm;
				ertekek.push_back(vege);
			}
		else if(egyseg == "ft")
			{
				vege = szam1 * ft_to_in * in_to_cm / m_to_cm;
				ertekek.push_back(vege);
			}
		else if(egyseg == "m")
			{
				vege = szam1;
				ertekek.push_back(vege);
			}
		else
			{
				sikeres = false;
			}
			
		if (sikeres)
			{
			if (max < vege)
				{
					cout << vege << " is the the largest so far." << endl;
					max = vege;
				}
			if (min > vege)
				{
					cout << vege << " is the the smallest so far." << endl;
					min = vege;
				}
			}
		else 
			{
				cout << "Unsupported unit!" << endl;
			}
		sikeres = true;
	}
	
	cout << "The numbers in the vector" << endl;
	int ossz=0;
	sort(ertekek);
	for (double ertek : ertekek)
		{
			cout << ertek << endl;
			ertekossz+=ertek;
			++ossz;
		}
	 
	 cout << "Smallest number: " << ertekek[0] << endl;
	 cout << "Largest number: " << max << endl;
	 cout << "Number of values: " << ossz << endl;
	 cout << "Sum of values: " << ertekossz << endl;

	return 0;
}
