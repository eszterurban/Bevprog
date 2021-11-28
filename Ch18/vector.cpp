#include "std_lib_facilities.h"

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> lv)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << lv[i] << endl;
 	}
 	cout << endl;
 	
 	vector<int>* p = new vector<int>;
 	for (int i = 0; i < 10; ++i)
	{
		p->push_back(lv[i]);
		cout << (*p)[i] << endl;
 	}
 	delete p;
}

int main()
{
	f(gv);
	vector<int> vv = {1,2,6,24,120,720,5040,40320,362880,3628800};
	cout << endl;
	f(vv);
	
	return 0;
}
