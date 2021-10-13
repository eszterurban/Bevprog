#include "std_lib_facilities.h"

int main(){

try{
	//int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n"; eredeti
	int i = 0; int j = 9; while (i<10) ++i; if (j<i) cout << "Success!\n"; // helyes megoldás: A while-on belül az i értékét kell növelni minden körüljárás után nem pedig a j-ét.
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

