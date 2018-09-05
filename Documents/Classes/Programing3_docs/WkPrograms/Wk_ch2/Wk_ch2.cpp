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
dateType::dateType(){
dYear= 2001;
dMonth = 1;
dDay = 1;
}
bool dateType::isLeapYear(){
    if(dYear%4==0)
        return 1;
    else
        return 0;   
}
void dateType::setYear(int year){
	 if(year <= 0 || year > 2999)
		std::cout << year << " is not a valid year.\n";
	else
		dYear = year;
}

void dateType::setMonth(int month){
	 if(month > 12 || month <= 0){
        std::cout << month << " is not a valid month.\n";
        month = 1;
        }
    else
        dMonth = month;
}

void dateType::setDay(int day){
	if(day <= 0)
        std::cout << day << " is not a valid day.\n";
    else if (day > monthDay[dMonth-1] && !isLeapYear())   
        std::cout << "There are not " << day << " days in month " << dMonth << ".\n"; 
    else if (isLeapYear() && dMonth == 2 && day > 29)
		std::cout << "There are only 29 days in month " << dMonth << " this year.\n";
	else 
		dDay = day;
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

int dateType::daysPassed(){
	int sum = 0;
	for(int i = 0; i < dMonth; i++)
		sum = sum + monthDay[i];
	sum = sum - dDay;	
	return sum;
}

int dateType::daysRemaining(){
	if(isLeapYear())
		return 366 - daysPassed();
	else
		return 365 - daysPassed();
}
void dateType::operator +(int days){
	int sum = dDay + days;
	while(sum > daysInMonth()){
		if(dMonth!=12)
			dMonth++;
		else{
			dMonth = 1;
			dYear++;
		}
		sum = sum - daysInMonth();
	}
	dDay = sum;
}

void dateType::printDate() const {
	std::cout << dMonth <<" " << dDay <<", " <<dYear <<std::endl;
}
