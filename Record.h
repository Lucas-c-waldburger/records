//
// Created by Lucas on 3/27/2023.
//

#ifndef UNTITLED3_RECORD_H
#define UNTITLED3_RECORD_H
#include <iostream>
#include <ostream>
#include "CurrentTime.h"


//struct Date {
//    CurrentTime currentTime;
//
//    int month = currentTime.getMonth();
//    int day = currentTime.getDay();
//    int year = currentTime.getYear();
//
//    friend std::ostream& operator<<(std::ostream& stream, const Date* date);
//
//    bool operator<(const Date* date) const;
//    bool operator>(const Date* date) const;
//};

struct Date {
    int month;
    int day;
    int year;

    friend std::ostream& operator<<(std::ostream& stream, const Date* date);
    bool operator<(const Date* date) const;
    bool operator>(const Date* date) const;
};


class Record {
public:
    Record();
    Record(std::string& artist, std::string& album, std::string& genre, int releaseYear, int rating);

    Record* next;

    Date dateCreated;
    Date dateLastEdit;

    std::string getArtist() const;
    void setArtist(std::string& artist);

    std::string getAlbum() const;
    void setAlbum(std::string& album);

    std::string getGenre() const;
    void setGenre(std::string& genre);

    int getReleaseYear() const;
    void setReleaseYear(int releaseYear);

    int getRating() const;
    void setRating(int genre);

private:
    std::string artist;
    std::string album;
    std::string genre;
    int releaseYear;
    int rating;

    friend std::ostream& operator<<(std::ostream& stream, const Record* record);

//    friend std::istream& operator>>(std::istream& stream, const Record& record);
};


#endif //UNTITLED3_RECORD_H
