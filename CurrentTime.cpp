//
// Created by Lucas on 3/27/2023.
//

#include "CurrentTime.h"

CurrentTime::CurrentTime() {
    now = time(nullptr);
    localTime = localtime(&now);
    month = localTime->tm_mon + 1;
    day = localTime->tm_mday;
    year = localTime->tm_year + 1900;
}

CurrentTime::~CurrentTime() {
    localTime = nullptr;
}

int CurrentTime::getMonth() const {
    return month;
}

int CurrentTime::getDay() const {
    return day;
}

int CurrentTime::getYear() const {
    return year;
}