#include "std_lib_facilities.h"

int main(){

try{
	// vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n"; eredeti
	 vector<char> v(5); for (int i=0; i<v.size(); ++i) cout << "Success!\n"; // helyes megoldás: A for ciklusmagon belül a második feltétel ne 0-nál legyen nagyobb hanem i-nél. A kiíratás elől a ;-t ki kell törölni hogy többször írja ki a program.
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
