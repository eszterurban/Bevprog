#include "std_lib_facilities.h"

int main(){

try{
	//cout << success << '\n'; eredeti
	cout << "Success!" << "\n"; // helyes megoldás: A kiirandó részt átírjuk a megfeleőre, ugyanezt a részt és a sortörés " " közé rakjuk.
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

