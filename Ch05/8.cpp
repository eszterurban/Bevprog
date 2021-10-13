#include "std_lib_facilities.h"

int main(){

try{
	//bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n"; eredeti
	bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n"; // helyes megoldás: A c értékét igazra állítjuk.
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

