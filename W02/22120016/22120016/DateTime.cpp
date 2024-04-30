#include "DateTime.h"

// getter
int DateTime::getDay() {
	return day;
}

int DateTime::getMonth() {
	return month;
}

int DateTime::getYear() {
	return year;
}

int DateTime::getHour() {
	return hour;
}

int DateTime::getMinute() {
	return minute;
}

int DateTime::getSecond() {
	return second;
}

// Operation
int DateTime::compare(DateTime date) {
	if (year > date.getYear()) return 1;
	else if (year < date.getYear()) return -1;

	if (month > date.getMonth()) return 1;
	else if (month < date.getMonth()) return -1;

	if (day > date.getDay()) return 1;
	else if (day < date.getDay()) return -1;

	if (hour > date.getHour()) return 1;
	else if (hour < date.getHour()) return -1;

	if (minute > date.getMinute()) return 1;
	else if (minute < date.getMinute()) return -1;

	if (second > date.getSecond()) return 1;
	else if (second < date.getSecond()) return -1;

	return 0;
}

string DateTime::convertToString() {
	string dateTime = "";
	dateTime += fill(to_string(day));
	dateTime += "/";
	dateTime += fill(to_string(month));
	dateTime += "/";
	dateTime += fill(to_string(year));
	dateTime += " ";
	dateTime += fill(to_string(hour));
	dateTime += ":";
	dateTime += fill(to_string(minute));
	dateTime += ":";
	dateTime += fill(to_string(second));
	return dateTime;
}

// Utilities
string DateTime::fill(string unit) {
	// Add '0' character into unit if unit has only one character
	if (unit.size() == 1) unit.insert(unit.begin(), '0');
	return unit;
}