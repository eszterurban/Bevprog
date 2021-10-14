#include "std_lib_facilities.h"

int main(){

try{
	//string s = "ape"; if (s=="fool") cout << "Success!\n"; eredeti
	string s = "ape"; if (s!="fool") cout << "Success!\n"; // helyes megoldás: A == helyett != jelet kell használni, mert ez jelenti a nem egyenlőséget.
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
