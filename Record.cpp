//
// Created by Lucas on 3/27/2023.
//

#include "Record.h"
#include <memory>


Record::Record() {
    std::unique_ptr<CurrentTime> ct = std::make_unique<CurrentTime>();
    dateCreated = Date{ct->getMonth(), ct->getDay(), ct->getYear()};
    dateLastEdit = dateCreated;
}

Record::Record(std::string& artist, std::string& album, std::string& genre, int releaseYear, int condition, int rating) : Record() {
    this->artist = artist;
    this->album = album;
    this->genre = genre;
    this->releaseYear = releaseYear;
    this->condition = condition;
    this->rating = rating;
}

Record::Record(std::string& artist, std::string& album, std::string& genre, int releaseYear, int condition, int rating,
               int ID, Date dateCreated, Date dateLastEdit) : artist{artist}, album{album}, genre{genre},
               releaseYear{releaseYear}, condition{condition}, rating{rating}, ID{ID}, dateCreated{dateCreated},
               dateLastEdit{dateLastEdit} {}

std::string Record::getArtist () const {
    return artist;
}

void Record::setArtist(std::string& artist)  {
    this->artist = artist;
}

std::string Record::getAlbum() const {
    return album;
}

void Record::setAlbum(std::string& album) {
    this->album = album;
}

std::string Record::getGenre() const {
    return genre;
}

void Record::setGenre(std::string& genre) {
    this->genre = genre;
}

int Record::getReleaseYear() const {
    return releaseYear;
}

void Record::setReleaseYear(int releaseYear) {
    this->releaseYear = releaseYear;
}

int Record::getCondition() const {
    return condition;
}

void Record::setCondition(int condition) {
    this->condition = condition;
}

int Record::getRating() const {
    return rating;
}

void Record::setRating(int rating) {
    this->rating = rating;
}

int Record::getID() const {
    return ID;
}

void Record::setID(int id) {
    this->ID = id;
}

std::ostream& operator<<(std::ostream& stream, const Record* record) {
    stream << "---------------------------\n"
           << "Artist: " << record->getArtist() << '\n'
           << "Album: " << record->getAlbum() << '\n'
           << "Release Year: " << record->getReleaseYear() << '\n'
           << "Genre: " << record->getGenre() << '\n'
           << "Condition: " << record->getCondition() << '\n'
           << "Rating: " << record->getRating() << '\n'
           << "Album ID: " << record->getID() << '\n'
           << "Date Created: " << &record->dateCreated << '\n'
           << "Date of Last Edit: " << &record->dateLastEdit << '\n'
           << "---------------------------\n" << std::endl;

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Record& record) {
    stream << "---------------------------\n"
           << "Artist: " << record.getArtist() << '\n'
           << "Album: " << record.getAlbum() << '\n'
           << "Release Year: " << record.getReleaseYear() << '\n'
           << "Genre: " << record.getGenre() << '\n'
           << "Condition: " << record.getCondition() << '\n'
           << "Rating: " << record.getRating() << '\n'
           << "Album ID: " << record.getID() << '\n'
           << "Date of Entry: " << &record.dateCreated << '\n'
           << "Date of Last Edit: " << &record.dateLastEdit << '\n'
           << "---------------------------\n" << std::endl;


    return stream;
}

std::unique_ptr<int[]> Date::getDates(std::string dateString) {
    std::string monthToken = dateString.substr(0, dateString.find('/'));
    dateString.erase(0, dateString.find('/') + 1);
    std::string dayToken = dateString.substr(0, dateString.find('/'));
    dateString.erase(0, dateString.find('/') + 1);
    std::string yearToken = dateString.substr(0);

    std::unique_ptr<int[]> dates(new int[3]);
    dates[0] = std::stoi(monthToken);
    dates[1] = std::stoi(dayToken);
    dates[2] = std::stoi(yearToken);

    return dates;

}

std::ostream &operator<<(std::ostream& stream, const Date* date) {
    stream << date->month << '/' << date->day << '/' << date->year;
    return stream;
}

bool Date::operator<(const Date* date) const {
    if (this->year < date->year) {
        return true;
    }
    else if (this->year == date->year) {
        if (this->month < date->month) {
            return true;
        }
        else if (this->month == date->month) {
            if (this->day < date->day) {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator>(const Date* date) const {
    if (this->year > date->year) {
        return true;
    }
    else if (this->year == date->year) {
        if (this->month > date->month) {
            return true;
        }
        else if (this->month == date->month) {
            if (this->day > date->day) {
                return true;
            }
        }
    }
    return false;
}

//RecordNode::RecordNode(std::string &artist, std::string &album, std::string &genre, int releaseYear,
//int rating) : Record(artist, album, genre, releaseYear, rating) {};

