#include "main.h"

int main() {
    Logger();
    return 0;
}

void Logger() {
    ofstream writer;
    string fileName = "log-";
    time_t info = time(NULL);
    tm now;
    localtime_s(&now, &info);
    string year = to_string(now.tm_year - 100), month = to_string(now.tm_mon + 1), day = to_string(now.tm_mday);
    if (month.size() == 1) {
        month.insert(0, "0");
    }
    if (day.size() == 1) {
        day.insert(0, "0");
    }
    fileName += year + month + day + ".txt";
    writer.open(fileName, ios::out);
    writer << "log(\"Exception tại hàm export. Lí do: Invalid input exception\");" << endl;
    writer.close();
}