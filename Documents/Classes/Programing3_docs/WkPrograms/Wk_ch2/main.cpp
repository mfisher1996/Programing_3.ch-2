#include <iostream>
#include "Wk_ch2.cpp"

int main(){	//	Test program for class dateType
	
	dateType day1(5,5,2005), day2;
	day2.setDate(4,32,2019);
	day1.printDate();
	day2.printDate();
	day2.setDay(28);
	day2.setMonth(2);
	std::cout << day1.getMonth() << std::endl;
	if(day1.isLeapYear())
		std::cout<<"This is a leap year.\n";
	else
		std::cout<<"This is not a leap year.\n";
	std::cout << "There are " << day1.daysInMonth() << " days in month " <<day1.getMonth() <<".\n";
	std::cout << day1.daysPassed() << " days have passed in " << day1.getYear() << ".\n";
	std::cout << day1.daysRemaining() << " days are left in " << day1.getYear() << ".\n";
	std::cout << "The current date is ";
	day1.printDate();
	std::cout << "In 120 days the date will be ";
	day1 + 120;
	day1.printDate();
	
	return 0;
}
