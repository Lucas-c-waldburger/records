#include <iostream>
#include "Record.h"
#include "CRUD.h"
#include <memory>


#include <utility>

//Record* find(Record* currentRecord, std::string& album) {
//    while (currentRecord != nullptr) {
//        if (currentRecord->getAlbum() == album) {return currentRecord;}
//        currentRecord = currentRecord->next;
//    }
//    return nullptr;
//}


//void setRecordData(Record &rec) {
//    std::string artist;
//    std::cout << "Enter Artist: ";
//    std::getline(std::cin, artist);
//    std::cout << '\n';
//
//    std::string album;
//    std::cout << "Enter Album: ";
//    std::getline(std::cin, album);
//    std::cout << '\n';
//
//    std::string genre;
//    std::cout << "Enter Genre: ";
//    std::getline(std::cin, genre);
//    std::cout << '\n';
//
//    int releaseYear = -1;
//    std::cout << "Enter Release Year: ";
//    std::cin >> releaseYear;
//    std::cout << '\n';
//
//    int condition = -1;
//    std::cout << "Enter Condition: ";
//    std::cin >> condition;
//    std::cout << '\n';
//
//    int rating = -1;
//    std::cout << "Enter Rating: ";
//    std::cin >> rating;
//    std::cout << '\n';
//
//    if (!artist.empty()) {rec.setArtist(artist);}
//    if (!album.empty()) {rec.setAlbum(album);}
//    if (!genre.empty()) {rec.setGenre(genre);}
//    if (releaseYear != -1) {rec.setReleaseYear(releaseYear);}
//    if (condition != -1) {rec.setCondition(condition);}
//    if (rating != -1) {rec.setRating(rating);}
//
//}

//void updateRecord(Record* record) {
//    setRecordData(record);
//    std::unique_ptr<CurrentTime> ct = std::make_unique<CurrentTime>();
//    record->dateLastEdit = Date{ct->getMonth(), ct->getDay(), ct->getYear()};
//}

//void writeToCSV(Record &record) {
//    std::fstream file;
//    file.open("records.csv", std::ios::out | std::ios::app);
//    if (file.is_open()) {
//        file << record.getArtist() << ','
//             << record.getAlbum() << ','
//             << record.getGenre() << ','
//             << record.getReleaseYear() << ','
//             << record.getCondition() << ','
//             << record.getRating() << ','
//             << &record.dateLastEdit << ','
//             << &record.dateLastEdit;
//
//        file.close();
//    }
//}



//std::unique_ptr<Record> getRecordFromCSV(std::string& album) {
//
//    std::unique_ptr<Record> rec;
//
//    std::fstream file;
//    file.open("records.csv", std::ios::in);
//    if (file.is_open()) {
//        std::vector<std::string> row;
//        std::string rowLine, cell;
//
//
//        while (!file.eof()) {
//
//            row.clear();
//
//            std::getline(file, rowLine);
//            std::stringstream s(rowLine);
//
//            while (std::getline(s, cell, ',')) {
//                row.push_back(cell);
//            }
//            if (row[1] == album) {
//                std::unique_ptr<int[]> datesCreated = getDates(row[5]);
//                std::unique_ptr<int[]> datesLastEdit = getDates(row[6]);
//
//                rec = std::make_unique<Record>(row[0], row[1], row[2], std::stoi(row[3]),
//                                               std::stoi(row[4]), std::stoi(row[5]),
//                                               Date{datesCreated[0], datesCreated[1],datesCreated[2]},
//                                               Date{datesLastEdit[0], datesLastEdit[1], datesLastEdit[2]});
//                break;
//            }
//        }
//        file.close();
//    }
//    return rec;
//}
//
//
//std::shared_ptr<std::vector<Record>> getRecordsFromCSV(int cellLocatedIn, std::string& term) {
//    std::shared_ptr<std::vector<Record>> records;
//    records = std::make_shared<std::vector<Record>>();
//
//    std::fstream file;
//    file.open("records.csv", std::ios::in);
//    if (file.is_open()) {
//        std::vector<std::string> row;
//        std::string rowLine, cell;
//        Record rec;
//
//        while (!file.eof()) {
//
//            row.clear();
//
//            std::getline(file, rowLine);
//            std::stringstream s(rowLine);
//
//            while (std::getline(s, cell, ',')) {
//                row.push_back(cell);
//            }
//
//
//
//            if (term == row[cellLocatedIn] || stoi(term) == std::stoi(row[cellLocatedIn])) {
//                std::unique_ptr<int[]> datesCreated = getDates(row[5]);
//                std::unique_ptr<int[]> datesLastEdit = getDates(row[6]);
//
//                rec = Record(row[0], row[1], row[2], std::stoi(row[3]),
//                             std::stoi(row[4]), std::stoi(row[5]),
//                             Date{datesCreated[0], datesCreated[1],datesCreated[2]},
//                             Date{datesLastEdit[0], datesLastEdit[1], datesLastEdit[2]});
//                records->push_back(rec);
//            }
//        }
//        file.close();
//    }
//    return records;
//}
//
//std::shared_ptr<std::vector<Record>> getAllRecordsFromCSV() {
//    std::shared_ptr<std::vector<Record>> records;
//    records = std::make_shared<std::vector<Record>>();
//
//    std::fstream file;
//    file.open("records.csv", std::ios::in);
//    if (file.is_open()) {
//        std::vector<std::string> row;
//        std::string rowLine, cell;
//        Record rec;
//
//        while (!file.eof()) {
//
//            row.clear();
//
//            std::getline(file, rowLine);
//            std::stringstream s(rowLine);
//
//            while (std::getline(s, cell, ',')) {
//                row.push_back(cell);
//            }
//
//            std::unique_ptr<int[]> datesCreated = getDates(row[5]);
//            std::unique_ptr<int[]> datesLastEdit = getDates(row[6]);
//
//            rec = Record(row[0], row[1], row[2], std::stoi(row[3]),
//                         std::stoi(row[4]), std::stoi(row[5]),
//                         Date{datesCreated[0], datesCreated[1],datesCreated[2]},
//                         Date{datesLastEdit[0], datesLastEdit[1], datesLastEdit[2]});
//            records->push_back(rec);
//        }
//        file.close();
//    }
//    return records;
//}




//std::string getReadInput(std::string& enterPrompt) {
//    std::string readInput;
//    std::cout << "Enter " << enterPrompt << ": ";
//    std::getline(std::cin, readInput);
//    return readInput;
//}

//void readRecord() {
//    std::string enterPrompt = "Album";
//    std::string requestedAlbum = getReadInput(enterPrompt);
//
//    std::unique_ptr<Record> record;
//    record = getRecordFromCSV(requestedAlbum);
//    if (record == nullptr) {std::cout << "No album named '" << requestedAlbum << "' found in database";}
//    else {std::cout << record;}
//}
//
//void readRecordsByArtist() {
//    std::string enterPrompt = "Artist";
//    std::string requestedArtist = getReadInput(enterPrompt);
//
//    std::shared_ptr<std::vector<Record>> records;
//    records = getRecordsFromCSV(0, requestedArtist);
//
//    if (records->empty()) {
//        std::cout << "No albums by '" << requestedArtist << "' found in database";
//    }
//    else {
//        std::cout << records->size() << " Album(s) by " << records->front().getArtist() << " found: \n\n";
//        for (Record& rec : *records) {
//            std::cout << rec << '\n';
//        }
//    }
//}
//
//void readRecordsByGenre() {
//    std::string enterPrompt = "Genre";
//    std::string requestedGenre = getReadInput(enterPrompt);
//
//    std::shared_ptr<std::vector<Record>> records;
//    records = getRecordsFromCSV(2, requestedGenre);
//
//    if (records->empty()) {
//        std::cout << "No albums in genre '" << requestedGenre << "' found in database";
//    }
//    else {
//        std::cout << records->size() << " Album(s) in genre " << records->front().getGenre() << " found: \n\n";
//        for (Record& rec : *records) {
//            std::cout << rec << '\n';
//        }
//    }
//}
//
//void readRecordsByReleaseYear() {
//    std::string inputPrompt = "Release Year";
//    std::string requestedReleaseYear = getReadInput(inputPrompt);
//
//    std::shared_ptr<std::vector<Record>> records;
//    records = getRecordsFromCSV(3, requestedReleaseYear);
//
//    if (records->empty()) {
//        std::cout << "No albums with release year '" << requestedReleaseYear << "' found in database";
//    }
//    else {
//        std::cout << records->size() << " Album(s) with release year " << records->front().getReleaseYear() << " found: \n\n";
//        for (Record& rec : *records) {
//            std::cout << rec << '\n';
//        }
//    }
//}

//
//std::unique_ptr<Record> findRecord(std::string& album) {
//
//}

int main() {
    CurrentTime ct = CurrentTime();

    bool continueProgram = true;

    while (continueProgram) {
        std::string homeSelection;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n'
                  << "Welcome to Megan's Vinyl Database!\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n'
                  << "What would you like to do?\n"
                  << "(type the word in brackets and hit ENTER)\n\n"
                  << "{ create } - enter a new album into the database\n"
                  << "{ view } - View your albums\n"
                  << "{ update } - edit an existing album\n"
                  << "{ delete } - remove an album from the database\n"
                  << "{ exit }\n\n";

        std::cin >> homeSelection;
        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

        if (homeSelection == "create") {
            std::cout << "--------CREATE NEW--------\n";
            std::cin.clear();
            CRUD::createRecord();
        }
        if (homeSelection == "view") {
            std::string viewSelection;
            std::cout << "View albums by...\n\n"
                      << "{ name }\n"
                      << "{ artist }\n"
                      << "{ genre }\n"
                      << "{ year }\n";
            std::cin >> viewSelection;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

            if (viewSelection == "name") {
                CRUD::readRecord();
            }
            if (viewSelection == "artist") {
                CRUD::readRecordsByArtist();
            }
            if (viewSelection == "genre") {
                CRUD::readRecordsByGenre();
            }
            if (viewSelection == "year") {
                CRUD::readRecordsByReleaseYear();
            }

        }
        if (homeSelection == "update") {
            std::cout << "--------UPDATE--------\n";
            CRUD::updateRecord();
        }
        if (homeSelection == "delete") {
            std::cout << "--------DELETE--------\n";
            CRUD::deleteRecord();
        }
        if (homeSelection == "exit") {
            continueProgram = false;
        }
        else {
            std::cout << "\nPlease enter a valid selection!\n";
        }
    }

    return 0;
}