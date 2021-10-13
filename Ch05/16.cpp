#include "std_lib_facilities.h"

int main(){

try{
	//if (true) then cout << "Success!\n"; else cout << "Fail!\n"; eredeti
	if (true) cout << "Success!\n"; else cout << "Fail!\n"; // helyes megoldás: A then összekötés nem kell.
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

