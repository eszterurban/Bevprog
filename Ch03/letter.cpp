#include "std_lib_facilities.h"

int main()
{

//1
cout << "Enter the name of the person you want to write to." << endl;
string first_name; 
cin >> first_name;
cout << "Dear " << first_name << endl;

//2
cout << "How are you? I am fine. I miss you!" << endl;
cout << "I am hope you are fine as well." << endl;
cout << "Please write the name of your friend you would like to talk about." << endl;

//3
string friend_name; 
cin >> friend_name;
cout << "Have you seen " << friend_name << " lately?" << endl;

//4
char friend_sex=0;
cout << "Please write the gender of your friend (f/m)." << endl;
cin >> friend_sex;
if (friend_sex=='m')
{
	cout << "If you see " << friend_name << " please ask him to call me." << endl;
}
else if (friend_sex=='f')
{
	cout << "If you see " << friend_name << " please ask her to call me." << endl;
}

//5
int age;
cout << "Please enter the age of the recipient." << endl;
cin >> age;
if (age<=0 || age>=110)
	simple_error("you're kidding!");

cout << "I hear you just hade a birthday and you are " << age << " year old." << endl;

//6
if (age<=12)
	cout << "Next year you will be " << age+1 << "." << endl;
else if (age==17)
	cout << "Next year you will be able to vote." << endl;
else if (age>=70)
	cout << "I hope you are enjoying retirement." << endl;

//7
cout << endl << "Your sincerely," << endl << endl << "Eszter" << endl;

return 0;
}
