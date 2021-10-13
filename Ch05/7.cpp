#include "std_lib_facilities.h"

int main(){

try{
	//if (cond) cout << "Success!\n"; else cout << "Fail!\n; eredeti
	vector<int>v(10); v[5]=7; if (v[5]<8) cout << "Success!\n"; else cout << "Fail!\n"; // helyes megoldás: Egy olyan  feltételt kell megadni ami teljesül és akkor az if hajtódik végre.
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
