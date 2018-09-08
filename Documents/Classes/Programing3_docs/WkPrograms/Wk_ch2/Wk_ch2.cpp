#include "Wk_ch2.hpp"
/*
 * Question one: clockType
 * 
 * */

extClockType::extClockType(){
	hr =0;
	min=0;
	sec=0;
};
extClockType::extClockType(int hour, int minute, int second){
if(hour >= 0 && hour < 24)
	hr = hour;
else{
	hr = 0;
	std::cout <<hour<< " is an invalid hour input.\n";
	}
if(minute >= 0 && minute < 60)
	min = minute;
else{
	min = 0;
	std::cout <<minute<< " is an invalid minute input.\n";
	}
if(second >= 0 && second < 60)
	sec = second;
else{
	sec = 0;
	std::cout <<second<< " is an invalid second input.\n";
	}
};
void extClockType::setTime(int hours, int minutes, int seconds){
if(hours >= 0 && hours < 24)
	hr = hours;
else{
	hr = 0;
	std::cout <<hours<< " is an invalid hour input.\n";
	}
if(minutes >= 0 && minutes < 60)
	min = minutes;
else{
	min = 0;
	std::cout <<minutes<< " is an invalid minute input.\n";
	}	
if(seconds >= 0 && seconds < 60)
	sec = seconds;
else{
	sec = 0;
	std::cout <<seconds<< " is an invalid second input.\n";
	}
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
int dateType::daysInMonth(int i){
	if (!isLeapYear())
		return monthDay[i];
	else if(i == 1)
		return 29;
	else	
		return monthDay[dMonth - 1];
}
int dateType::daysPassed(){
	int sum = 0;
	for(int i = 0; i < dMonth-1; i++)
		sum = sum + daysInMonth(i);
	sum = sum + dDay;	
	return sum;
}

int dateType::daysRemaining(){
	if(isLeapYear())
		return 365 - daysPassed();
	else
		return 364 - daysPassed();
}
void dateType::operator +(int days){
	int sum = dDay + days;
	while(sum > daysInMonth()){
		sum = sum - daysInMonth();
		if(dMonth!=12)
			dMonth++;
		else{
			dMonth = 1;
			dYear++;
		}
		
	}
	dDay = sum;
}

void dateType::printDate() const {
	std::cout << months[dMonth-1] <<" " << dDay <<", " <<dYear <<std::endl;
}
