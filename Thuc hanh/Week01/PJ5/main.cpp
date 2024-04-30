#include "main.h"

int main() {
    NextDay();

    return 0;
}

void NextDay() {
    time_t info = time(NULL);
    tm now;
    localtime_s(&now, &info);

    cout << "Today: " << now.tm_mday << "/" << now.tm_mon + 1 << "/" << now.tm_year + 1900 << endl;
    cout << "Next day: " << now.tm_mon + 1 << "/" << now.tm_mday + 1 << "/" << now.tm_year + 1900 << endl;
}