//
// Created by Lucas on 3/27/2023.
//

#ifndef UNTITLED3_CURRENTTIME_H
#define UNTITLED3_CURRENTTIME_H

#include <ctime>


class CurrentTime {
public:
    CurrentTime();
    ~CurrentTime();

    time_t now;
    tm *localTime;

    int getMonth() const;
    int getDay() const;
    int getYear() const;

private:
    int month;
    int day;
    int year;

};


#endif //UNTITLED3_CURRENTTIME_H
