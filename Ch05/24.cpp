#include "std_lib_facilities.h"

int main(){

try{
	//int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n"; eredeti
	int x = 4; double d = 5/(x+2); if (d!=2*x+0.5) cout << "Success!\n"; // helyes megoldás: A d értékénél a --t +-ra írtam át mert ha - akkor a kapott érték a zárójelben 0 és 0-val való osztás nem értelmezett. Az if feltételt pedig !=-re írtam át és akkor a feltétel igaz lesz.
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

