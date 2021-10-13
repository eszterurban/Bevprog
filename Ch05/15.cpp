#include "std_lib_facilities.h"

int main(){

try{
	//string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i]; eredeti
	string s = "Success!\n"; for (int i=0; i<1; ++i) cout << s; // helyes megoldás: A for ciklusmagon belül a második feltétele ne 6-nál legyen kisebb hanem csak 1-nél, mert így akkor csak egyszer írtja ki. A kiíratás után csak az s-et kell írni.
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

