#include "std_lib_facilities.h"

const vector<string> months=
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

struct Date
{
	int year, month, day;
	
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int y, int m, int d)
{
	if (y>0)
		year = y;
	else
		error("Invalid year");
		
	if (m<=12 && m>0)
		month = m;
	else 
		error("Invalid month");

	if (d<=31 && d>0)
		day = d;
	else 
		error("Invalid day");
}

void Date::add_day(int n)
{
	day += n;
	
	if (day>31)
	{
		month++;
		day -=31;
		if (month >12)
		{
			year++;
			month -=12;
		}
	}
}

int main()
{
	try{
		Date today {1978, 6, 25};
		cout << "Date: " << today.year << '.' << months[today.month-1] << '.' << today.day << endl;
		
		today.add_day(1);
		cout << "Date: " << today.year << "." << months[today.month-1] << "." << today.day << endl;
		
		return 0;
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}
}
