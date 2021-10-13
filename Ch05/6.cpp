#include "std_lib_facilities.h"

int main(){

try{
	//vector<int>v(10); v[5]=7; if(v(5)!=7); eredeti
	vector<int>v(10); v[5]=7; if(v[5]!=7); cout << "Success!\n"; // helyes megoldás: A v egy vector ezért nem ()-et kell használni hanem []-et.
	keep_window_open();
	return 0;
}
catch (exception& e){
	cerr << "error: "<<e.what()<<'\n';
	keep_window_open();
	return 1;
}
catch (...){
	cerr << "Oops: unknown exeption!\n";
	keep_window_open();
	return 2;
}
}

