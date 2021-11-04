
/*
	calculator08buggy.cpp
	Helpful comments removed.
	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

struct Token {
	char kind;		//Megadja hogy az input művelet, szám vagy feladat
	double value;
	string name;		//Változók tárolása
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string str) :kind(ch), value(0), name(str) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }	//A tokent visszarakja a token streambe

	void ignore(char);
};

const char let = '#';		//A számológép által értelmezett kifejezések
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char set = 'S';
const char rt = 'R';
const char power = 'P';


Token Token_stream::get()
{
//Buffer vizsgálata
	if (full) { full = false; return buffer; }
	//Következő token vizsgálata
	char ch;
	cin >> ch;
	switch (ch) {	
	case '#':	//Az input vizsgálása karakterenként
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);		//Az érték amit visszaad az egy művelet
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);		//Az érték amit visszaad az egy szám
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			if (s == "let") return Token(let);		//Több karaktert igénylő műveletek
			if (s == "sqrt") return Token(rt);
			if (s == "set") return Token(set);
			if (s == "pow") return Token(power);
			if (s == "exit") return Token(quit);
			return Token(name, s);
		}
		error("Bad token");		//Rosszul beírt karakter esetén error
	}
	return Token('e');
}

void Token_stream::ignore(char c)		//A tokken stream figyelmen kívül hagyása
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

//A names vector szimbólumainak értékét kéri le
double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
	return 0;
}

//A name vector érékeit adja meg
void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

//A name vectorban lévő szimbólumok létezését vizsgálja
bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

//A zárójelek, pozitív, negatív számok és a szimbólumok kezelése
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	return d;
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
	return 0;
}

//A szorzás, osztás kezelése
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

//Összeadás, kivonás kezelése
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

//Új szimbólum készítése
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

//Gyökvonás értelmezése
double fsqrt()
{
	double d = expression();
	if (d < 0) error("Can not be negative number!");
	else return sqrt(d);
	return 0;
}

//Hatványozás

//Kulcsszavak irányítása
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	case rt:
	{
		return fsqrt();
	}
	default:
		ts.unget(t);
		return expression();
	}
}

//Mindent figyelmen kívül hagy a token stream amíg ; nem írunk
void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
{
	try {
		names.push_back(Variable("k",1000));		//k értékadása
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}
