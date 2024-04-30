#pragma once

class Date {
private:
    int _day;
    int _month;
    int _year;

public:
    // Constructor
    Date();

    // Accessor
    int getDay();
    int getMonth();
    int getYear();
    void setDay(int);
    void setMonth(int);
    void setYear(int);

    // Operation
    void input();
    void output();
};