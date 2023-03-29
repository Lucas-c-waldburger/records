//
// Created by Lucas on 3/27/2023.
//

#ifndef UNTITLED3_RECORD_H
#define UNTITLED3_RECORD_H
#include <iostream>
#include <ostream>
#include "CurrentTime.h"

struct Date {
    int month;
    int day;
    int year;

    static std::unique_ptr<int[]> getDates(std::string dateString);

    friend std::ostream& operator<<(std::ostream& stream, const Date* date);
    bool operator<(const Date* date) const;
    bool operator>(const Date* date) const;
};


class Record {
public:
    Record();
    Record(std::string& artist, std::string& album, std::string& genre, int releaseYear, int condition, int rating);
    Record(std::string& artist, std::string& album, std::string& genre, int releaseYear, int condition, int rating,
           int ID, Date dateCreated, Date dateLastEdit);

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

    int getCondition() const;
    void setCondition(int condition);

    int getRating() const;
    void setRating(int genre);

    int getID() const;
    void setID(int id);

private:
    std::string artist;
    std::string album;
    std::string genre;
    int releaseYear;
    int condition;
    int rating;
    int ID = -1;

    friend std::ostream& operator<<(std::ostream& stream, const Record* record);
    friend std::ostream& operator<<(std::ostream& stream, const Record& record);

//    friend std::istream& operator>>(std::istream& stream, const Record& record);
};

//class RecordNode : public Record {
//public:
//    using Record::Record;
//    RecordNode() = default;
//    RecordNode(std::string &artist, std::string &album, std::string &genre, int releaseYear,
//               int rating);
//
//    Record* next;
//};



#endif //UNTITLED3_RECORD_H
