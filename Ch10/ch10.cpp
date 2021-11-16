#include "std_lib_facilities.h"

class Points
{
	public:
		vector<double> x;
		vector<double> y;
};

int main()
{
	vector<double> x;
	vector<double> y;
	double n1;
	double n2;
	
	cout <<"Please add 7 x and y coordinates!" << endl;
	
	for (int i=0; i<7; ++i)
	{
		cout << i+1 <<". coordinate: ";
		cin >> n1 >> n2;
		
		x.push_back(n1);
		y.push_back(n2);
	}
	
	cout << "You add 7 pair coordiantes." << endl;
	
	cout << "Here are your entered points: "<< endl;
	
	for (int i = 0; i < 7; ++i)
	{
		cout << x[i] << ',' << y[i] << endl;
	}
	
	ofstream iras;
	iras.open("mydata.txt");
	
	for (int i = 0; i < 7; ++i)
	{
		iras << x[i] << ' ' << y[i] << endl;
	}
	
	iras.close();
	ifstream olvas;
	olvas.open("mydata.txt");
	vector<double> processed_points1;
	vector<double> processed_points2;

	cout << "There are the processed_points vectors coordinates:\n";

	for (int i = 0; i < 7; ++i)
	{
		olvas >> n1 >> n2;
		processed_points1.push_back(n1);
		processed_points2.push_back(n2);
	}

	olvas.close();

	for (int i = 0; i < 7; ++i)
	{
		cout << processed_points1[i] << ' ' << processed_points2[i] << '\n';
	}
	
	//Check if the vectors are the same
	bool same = true;

	for (int i = 0; i < 7; ++i)
	{
		if ( (x[i] != processed_points1[i]) || (y[i] != processed_points2[i]) )
		{
			same = false;
		}
	}

	if (same == false)
	{
		cout << "Something's wrong!";
	}

	return 0;
	
}
