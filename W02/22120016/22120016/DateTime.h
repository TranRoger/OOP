#pragma once

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class DateTime {
private:
	// Attributes
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int second;

	// Utilities
	string fill(string);
public:
	// Constructor
	DateTime() {
		time_t info = time(NULL);
		tm now;
		localtime_s(&now, &info);

		this->day = now.tm_mday;
		this->month = now.tm_mon + 1;
		this->year = now.tm_year + 1900;
		this->hour = now.tm_hour;
		this->minute = now.tm_min;
		this->second = now.tm_sec;
	}

	DateTime(int day, int month, int year, int hour, int minute, int second) {
		this->day = day;
		this->month = month;
		this->year = year;
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	// Getter
	int getDay();
	int getMonth();
	int getYear();
	int getHour();
	int getMinute();
	int getSecond();

	// Operation
	int compare(DateTime);
	string convertToString();
};