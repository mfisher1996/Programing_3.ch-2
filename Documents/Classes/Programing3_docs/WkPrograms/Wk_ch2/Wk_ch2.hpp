#include <iostream>
#include <iomanip>
/*
 * Quesiton 1: clockType
 * 
 * */
class extClockType
{
public:
	extClockType(int hour, int minute, int second);
	extClockType();
	void setTime(int hours, int minutes, int seconds);
	void getTime(int& hours, int& minutes, int& seconds) const{hours = hr; minutes = min; seconds = sec;};
	void printTime() const{std::cout <<std::setfill('0') << std::setw(2) << hr; 
		std::cout << ":";
		std::cout <<std::setfill('0') <<std::setw(2) << min;
		std::cout << ":";
		std::cout << std::setfill('0') <<std::setw(2) << sec; 
		std::cout << "\n";};
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	bool equalTime(const extClockType& otherClock) const;
	void setTimeZone(std::string z) {timeZone = z;};
	std::string getTimeZone() {return timeZone;};
private:
	int hr; //stores the hours
	int min; //store the minutes
	int sec; //store the seconds
	std::string timeZone;
};

class dateType{
public:
    void setDate(int month, int day, int year);
    int getDay() const{return dDay;};
    int getMonth() const{return dMonth;};
    int getYear() const{return dYear;}
    void setDay(int day);
    void setYear(int year);
    void setMonth(int month);
    void printDate() const;
    dateType(int month, int day, int year);
    dateType();
    bool isLeapYear();
    int daysInMonth();
    int daysPassed();
    int daysRemaining();
    void operator+(int days);
private:
    int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string months[12] = {"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
    int dMonth;
    int dDay;
    int dYear;
};
