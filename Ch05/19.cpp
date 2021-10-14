#include "std_lib_facilities.h"

int main(){

try{
	//vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n"; eredeti
	vector<int> v(5); for (int i=0; i<=v.size(); ++i); cout << "Success!\n"; // helyes megoldás: A vectornak meg kell adni milyen típussal dolgozhat, ebben az esetben <int>.
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

