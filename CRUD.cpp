
#include "CRUD.h"

void CRUD::setRecordData(Record &rec) {
    std::string artist;
    std::cout << "Enter Artist: ";
    std::getline(std::cin, artist);
    std::cout << '\n';

    std::string album;
    std::cout << "Enter Album: ";
    std::getline(std::cin, album);
    std::cout << '\n';

    std::string genre;
    std::cout << "Enter Genre: ";
    std::getline(std::cin, genre);
    std::cout << '\n';

    std::string releaseYear;
    std::cout << "Enter Release Year: ";
    std::getline(std::cin, releaseYear);
    std::cout << '\n';

    std::string condition;
    std::cout << "Enter Condition: ";
    std::getline(std::cin, condition);
    std::cout << '\n';

    std::string rating;
    std::cout << "Enter Rating: ";
    std::getline(std::cin, rating);
    std::cout << '\n';

    if (!artist.empty()) {rec.setArtist(artist);}
    if (!album.empty()) {rec.setAlbum(album);}
    if (!genre.empty()) {rec.setGenre(genre);}
    if (!releaseYear.empty()) {rec.setReleaseYear(std::stoi(releaseYear));}
    if (!condition.empty()) {rec.setCondition(std::stoi(condition));}
    if (!rating.empty()) {rec.setRating(std::stoi(rating));}
    if (rec.getID() == -1) {rec.setID(FileHandler::findIDOfLast() + 1);} // ID initialized as -1, meaning the record
                                                                         // passed through is a newly created one
                                                                         // instead of a record pulled from db
}

std::unique_ptr<Record> CRUD::getRecord () {
    std::string enterPrompt = "Album";
    std::string requestedAlbum = getReadInput(enterPrompt);
    std::unique_ptr<Record> record = FileHandler::getRecordFromCSV(requestedAlbum);
    return record;
}

void CRUD::createRecord() {
    std::unique_ptr<Record> rec = std::make_unique<Record>();
    setRecordData(*rec);
    FileHandler::writeToCSV(*rec);
}

void CRUD::readRecord() {
    std::unique_ptr<Record> record = getRecord();
    if (record == nullptr) {std::cout << "No albums with that name found in database";}
    else {std::cout << record;}
}

void CRUD::readRecordsByArtist() {
    std::string enterPrompt = "Artist";
    std::string requestedArtist = getReadInput(enterPrompt);

    std::shared_ptr<std::vector<Record>> records;
    records = FileHandler::getRecordsFromCSV(0, requestedArtist);

    if (records->empty()) {
        std::cout << "No albums by '" << requestedArtist << "' found in database";
    }
    else {
        std::cout << records->size() << " Album(s) by " << records->front().getArtist() << " found: \n\n";
        for (Record& rec : *records) {
            std::cout << rec << '\n';
        }
    }
}

void CRUD::readRecordsByGenre() {
    std::string enterPrompt = "Genre";
    std::string requestedGenre = getReadInput(enterPrompt);

    std::shared_ptr<std::vector<Record>> records;
    records = FileHandler::getRecordsFromCSV(2, requestedGenre);

    if (records->empty()) {
        std::cout << "No albums in genre '" << requestedGenre << "' found in database";
    }
    else {
        std::cout << records->size() << " Album(s) in genre " << records->front().getGenre() << " found: \n\n";
        for (Record& rec : *records) {
            std::cout << rec << '\n';
        }
    }
}

void CRUD::readRecordsByReleaseYear() {
    std::string inputPrompt = "Release Year";
    std::string requestedReleaseYear = getReadInput(inputPrompt);

    std::shared_ptr<std::vector<Record>> records;
    records = FileHandler::getRecordsFromCSV(3, requestedReleaseYear);

    if (records->empty()) {
        std::cout << "No albums with release year '" << requestedReleaseYear << "' found in database";
    }
    else {
        std::cout << records->size() << " Album(s) with release year " << records->front().getReleaseYear() << " found: \n\n";
        for (Record& rec : *records) {
            std::cout << rec << '\n';
        }
    }
}


std::string CRUD::getReadInput(std::string& enterPrompt) {
    std::string readInput;
    std::cout << "Enter " << enterPrompt << ": ";
    std::getline(std::cin, readInput);
    return readInput;
}

bool CRUD::getConfirm(std::string& operation) {
    char confirm;
    std::cout << operation << " this entry? (y/n): ";
    std::cin >> confirm;
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    if (std::tolower(confirm) == 'y') {return true;}
    return false;
}

void CRUD::updateRecord() {
    std::shared_ptr<std::vector<Record>> records = FileHandler::getAllRecordsFromCSV();

    std::string enterPrompt = "Album name";
    std::string albumName = getReadInput(enterPrompt);

    for (Record& rec : *records) {
        if (albumName == rec.getAlbum()) {
            std::cout << rec << '\n';

            std::string operation = "Update";
            if (getConfirm(operation)) {
                std::cout << "(To skip over a field, just hit ENTER)\n";
                setRecordData(rec);
                std::unique_ptr<CurrentTime> ct = std::make_unique<CurrentTime>();
                rec.dateLastEdit.month = ct->getMonth();
                rec.dateLastEdit.day = ct->getDay();
                rec.dateLastEdit.year = ct->getYear();
                break;
            }
            else return;
        }
    }

    for (int i = 0; i < records->size(); i++) {
        if (i == 0) {FileHandler::writeToCSV((*records)[i], false);}
        else {FileHandler::writeToCSV((*records)[i]);}
    }
}

void CRUD::deleteRecord() {
    std::shared_ptr<std::vector<Record>> records = FileHandler::getAllRecordsFromCSV();

    std::string enterPrompt = "Album ID";
    int id = std::stoi(getReadInput(enterPrompt));

    for (int i = 0; i < records->size(); i++) {
        if (id == (*records)[i].getID()) {
            std::cout << (*records)[i] << '\n';

            std::string operation = "Delete";
            if (getConfirm(operation)) {
                records->erase(records->begin() + i);
                break;
            }
            else return;
        }
    }
    for (int i = 0; i < records->size(); i++) {
        if (i == 0) {FileHandler::writeToCSV((*records)[i], false);}
        else {FileHandler::writeToCSV((*records)[i]);}
    }
}