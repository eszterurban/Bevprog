#include "std_lib_facilities.h"

int main(){

try{
	//string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i]; eredeti
	string s = "Success!\n"; for (int i=0; i<=s.size(); ++i) cout << s[i]; // helyes megoldás: A <char> rész nek kell mert az a vectornak ad típust és itt csak egy string típusra van szükség. A for ciklusmagon belül a második feltétel az s teljes hosszáig tartson és ne legyen vele egyenlő csak kisebb.
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

