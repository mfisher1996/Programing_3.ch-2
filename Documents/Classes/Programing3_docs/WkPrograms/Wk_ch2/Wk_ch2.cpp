#include "Wk_ch2.hpp"
/*
 * Question one: clockType
 * 
 * */
 
void extClockType::setTime(int hours, int minutes, int seconds){
if(hours >= 0 && hours < 24)
	hr = hours;
else
	hr = 0;
if(minutes >= 0 && minutes < 60)
	min = minutes;
else
	min = 0;
if(seconds >= 0 && seconds < 60)
	sec = seconds;
else
	sec = 0;
}

void extClockType::incrementSeconds(){
    if((sec+1) == 60){
        sec = 0;
        incrementMinutes();
    }
    else 
        sec++;
}

void extClockType::incrementMinutes(){
    if((min+1) == 60){
        min = 0;
        incrementHours();
    }
    else 
        min++;
}

void extClockType::incrementHours(){

    if((hr+1) == 24)
        hr = 0;
    else 
        hr++;
}

bool extClockType::equalTime(const extClockType & otherClock) const {
	if(sec != otherClock.sec || min != otherClock.min || hr != otherClock.hr)
		return 0;
	else
		return 1;
}

/*
 * Question two: dateType
 * 
 * */
bool dateType::isLeapYear(){
    if(dYear%4==0)
        return 1;
    else
        return 0;   
}

void dateType::setDate(int month, int day, int year){
    if(month > 12 || month <= 0){
        std::cout << month << " is not a valid month.\n";
        month = 1;
        }
    else
        dMonth = month;
    if(year <= 0 || year > 2999)
		std::cout << year << " is not a valid year.\n";
	else
		dYear = year;
    if(day <= 0)
        std::cout << day << " is not a valid day.\n";
    else if (day > monthDay[month-1] && !isLeapYear())   
        std::cout << "There are not " << day << " days in month " << month << ".\n"; 
    else if (isLeapYear() && month == 2 && day > 29)
		std::cout << "There are only 29 days in month " << month << " this year.\n";
	else 
		dDay = day;
    
        
}

dateType::dateType(int month, int day, int year){
    if(month > 12 || month <= 0){
        std::cout << month << " is not a valid month.\n";
        month = 1;
        }
    else
        dMonth = month;
        
    if(year <= 0 || year > 2999)
		std::cout << year << " is not a valid year.\n";
	else 
		dYear = year;
		
    if(day <= 0)
        std::cout << day << " is not a valid day.\n";
    else if (day > monthDay[month-1] && !isLeapYear())   
        std::cout << "There are not " << day << " days in month " << month << ".\n"; 
    else if (isLeapYear() && month == 2 && day > 29)
		std::cout << "There are only 29 days in month " << month << " this year.\n";
	else 
		dDay = day;
    
        
}

int dateType::daysInMonth(){
	if (!isLeapYear())
		return monthDay[dMonth - 1];
	else if(dMonth == 2)
		return 29;
	else	
		return monthDay[dMonth - 1];
}
