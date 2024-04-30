#include <iostream>
#include "Converter.h"
#include <sstream>

using namespace std;

string SolidRectangleConverter::convert(const Rectangle &info) {
    stringstream builder;
    for (int i = 0; i < info.height(); i++) {
        for (int j = 0; j < info.width(); j++) {
            builder << _fill;
        }
        builder << endl;
    }
    string result = builder.str();
    return result;
}

string HollowRectangleConverter::convert(const Rectangle &info) {
    stringstream builder;
    for (int i = 0; i < info.height(); i++) {
        for (int j = 0; j < info.width(); j++) {
            if (0 == i || info.height() - 1 == i) {
                builder << _fill;
            }
            else {
                if (0 == j || info.width() - 1 ==  j) {
                    builder << _fill;
                }
                else {
                    builder << " ";
                }
            }
        }
        builder << endl;
    }
    string result = builder.str();
    return result;
}