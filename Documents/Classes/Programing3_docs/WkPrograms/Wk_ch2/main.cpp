#include <iostream>
#include "Wk_ch2.cpp"

int main(){	//	Test program for class extClockType
	
	extClockType clock1;
	clock1.setTime(8, 30, 44);
	clock1.printTime();
	extClockType clock2(25, 60, 12);
	clock2.printTime();
	for (int i =0; i < 48; i++)
		clock2.incrementSeconds();
	clock2.printTime();
	if(clock1.equalTime(clock2))
		std::cout << "The times are equal.\n";
	else
		std::cout << "The times are not equal.\n";
	clock2.printTime();
	int hr, min, sec;
	clock1.getTime(hr,min,sec);
	clock2.setTime(hr,min,sec);
		if(clock1.equalTime(clock2))
		std::cout << "The times are equal.\n";
	else
		std::cout << "The times are not equal.\n";
	clock2.printTime();
	
	
	return 0;
}
