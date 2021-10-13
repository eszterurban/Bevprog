#include "std_lib_facilities.h"

int main(){

try{
	//cout <<"Success!\n; eredeti
	cout << "Success!\n"; // helyes megoldás: A ; előtt kell egy bezáró ".
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

