#include "std_lib_facilities.h"

int main(){

try{
	//string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n"; eredeti
	string s = "ape"; bool c = "fool">s; if (c) cout << "Success!\n"; // helyes megoldás: A c típusa bool. És a relációs jelet meg kell cserélni, mert akkor lesz igaz a feltétel.
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

