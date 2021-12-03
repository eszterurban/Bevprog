#include "std_lib_facilities.h"

template<typename t>
struct s
{
	private:
		t val;
	public:
		s(t x)
		{
			val = x;
		}
		
		t get()const;
		
		t& get();
		
		void kiir()
		{
			cout << val << endl;
		}
		
		void operator=(const t& stemp)
		{
			val=stemp;
		}
};

template<typename t>
t s<t>::get()const
{
	return val;
}

template<typename t>
t& s<t>::get()
{
	return val;
}

template<typename t>
ostream& operator << (ostream& os, s<t>& stemp) 
{
	return os << stemp.get();
}

template<typename t>
istream& operator >> (istream& is, s<t>& stemp) 
{
	return is >> stemp.get();
}

void kiirvector(ostream& os, vector<int>vektor)
{
	cout << "Vector elemei: " << endl;
	for(int i = 0; i < vektor.size(); i++)
	{
		cout << vektor[i] << " ";
	}
	cout << endl;
}

int main()
{
	s<int> sint(42);
	sint.kiir();
	s<char> schar('C');
	schar.kiir();
	s<double> sdouble(4.2);
	sdouble.kiir();
	s<vector<int>>svector({32,21,5,12});
	kiirvector(cout, svector.get());

	cout << endl;
	cout << sint.get() << endl;
	cout << schar.get() << endl;
	cout << sdouble.get() << endl;
	kiirvector(cout ,svector.get());
	cout << endl;

	cout << "Irjon be inputot!" << endl;
	cin >> sint;
	cout << sint<< endl;
	cin >> schar;
	cout << schar << endl;
	cin >> sdouble;
	cout << sdouble << endl;
    
	return 0;
}
