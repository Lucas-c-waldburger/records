
#include <fstream>
#include <sstream>
#include <vector>
#include "FileHandler.h"

int FileHandler::findIDOfLast() {
    int id = 0;
    std::fstream file;
    file.open("records.csv", std::ios::in);
    if (file.is_open()) {

        std::vector<std::string> row;
        std::string rowLine, cell;

        while (!file.eof()) {

            row.clear();

            std::getline(file, rowLine);
            std::stringstream s(rowLine);

            while (std::getline(s, cell, ',')) {row.push_back(cell);}

            if (cell.empty()) {break;}

            id = std::stoi(row[6]);
            file.peek();
        }
        file.close();
    }
    return id;
}

void FileHandler::writeToCSV(Record &record, bool append) {
    std::fstream file;
    if (append) {file.open("records.csv", std::ios::out | std::ios::app);}
    else {file.open("records.csv", std::ios::out | std::ios::trunc);}

    if (file.is_open()) {
        file << record.getArtist() << ','
             << record.getAlbum() << ','
             << record.getGenre() << ','
             << record.getReleaseYear() << ','
             << record.getCondition() << ','
             << record.getRating() << ','
             << record.getID() << ','
             << &record.dateCreated << ','
             << &record.dateLastEdit << '\n';

        file.close();
    }
}

std::unique_ptr<Record> FileHandler::getRecordFromCSV(std::string& album) {

    std::unique_ptr<Record> rec;

    std::fstream file;
    file.open("records.csv", std::ios::in);
    if (file.is_open()) {
        std::vector<std::string> row;
        std::string rowLine, cell, temp;


        while (!file.eof()) {

            row.clear();

            std::getline(file, rowLine);
            std::stringstream s(rowLine);

            while (std::getline(s, cell, ',')) {row.push_back(cell);}

            if (row[1] == album) {
                std::unique_ptr<int[]> datesCreated = Date::getDates(row[7]);
                std::unique_ptr<int[]> datesLastEdit = Date::getDates(row[8]);

                rec = std::make_unique<Record>(row[0], row[1], row[2], std::stoi(row[3]),
                                               std::stoi(row[4]), std::stoi(row[5]), std::stoi(row[6]),
                                               Date{datesCreated[0], datesCreated[1],datesCreated[2]},
                                               Date{datesLastEdit[0], datesLastEdit[1], datesLastEdit[2]});
                break;
            }
        }
        file.close();
    }
    return rec;
}


std::shared_ptr<std::vector<Record>> FileHandler::getRecordsFromCSV(int cellLocatedIn, std::string& term) {
    std::shared_ptr<std::vector<Record>> records;
    records = std::make_shared<std::vector<Record>>();

    std::fstream file;
    file.open("records.csv", std::ios::in);
    if (file.is_open()) {
        std::vector<std::string> row;
        std::string rowLine, cell;
        Record rec;

        while (!file.eof()) {

            row.clear();

            std::getline(file, rowLine);
            std::stringstream s(rowLine);

            while (std::getline(s, cell, ',')) {row.push_back(cell);}

            if (term == row[cellLocatedIn]) {
                std::unique_ptr<int[]> datesCreated = Date::getDates(row[7]);
                std::unique_ptr<int[]> datesLastEdit = Date::getDates(row[8]);

                rec = Record(row[0], row[1], row[2], std::stoi(row[3]),
                             std::stoi(row[4]), std::stoi(row[5]), std::stoi(row[6]),
                             Date{datesCreated[0], datesCreated[1],datesCreated[2]},
                             Date{datesLastEdit[0], datesLastEdit[1], datesLastEdit[2]});
                records->push_back(rec);

                file.peek();
            }
        }
        file.close();
    }
    return records;
}

std::shared_ptr<std::vector<Record>> FileHandler::getRecordsFromCSV(int cellLocatedIn, int term) {
    std::shared_ptr<std::vector<Record>> records;
    records = std::make_shared<std::vector<Record>>();

    std::fstream file;
    file.open("records.csv", std::ios::in);
    if (file.is_open()) {
        std::vector<std::string> row;
        std::string rowLine, cell;
        Record rec;

        while (!file.eof()) {

            row.clear();

            std::getline(file, rowLine);
            std::stringstream s(rowLine);

            while (std::getline(s, cell, ',')) {row.push_back(cell);}

            if (term == std::stoi(row[cellLocatedIn])) {
                std::unique_ptr<int[]> datesCreated = Date::getDates(row[7]);
                std::unique_ptr<int[]> datesLastEdit = Date::getDates(row[8]);

                rec = Record(row[0], row[1], row[2], std::stoi(row[3]),
                             std::stoi(row[4]), std::stoi(row[5]), std::stoi(row[6]),
                             Date{datesCreated[0], datesCreated[1],datesCreated[2]},
                             Date{datesLastEdit[0], datesLastEdit[1], datesLastEdit[2]});
                records->push_back(rec);

                file.peek();
            }
        }
        file.close();
    }
    return records;
}

std::shared_ptr<std::vector<Record>> FileHandler::getAllRecordsFromCSV() {
    std::shared_ptr<std::vector<Record>> records;
    records = std::make_shared<std::vector<Record>>();

    std::fstream file;
    file.open("records.csv", std::ios::in);
    if (file.is_open()) {
        std::vector<std::string> row;
        std::string rowLine, cell;
        Record rec;

        while (!file.eof()) {

            row.clear();

            std::getline(file, rowLine);
            std::stringstream s(rowLine);

            while (std::getline(s, cell, ',')) {row.push_back(cell);}

            std::unique_ptr<int[]> datesCreated = Date::getDates(row[7]);
            std::unique_ptr<int[]> datesLastEdit = Date::getDates(row[8]);

            rec = Record(row[0], row[1], row[2], std::stoi(row[3]),
                         std::stoi(row[4]), std::stoi(row[5]), std::stoi(row[6]),
                         Date{datesCreated[0], datesCreated[1],datesCreated[2]},
                         Date{datesLastEdit[0], datesLastEdit[1], datesLastEdit[2]});
            records->push_back(rec);

            file.peek();
        }
        file.close();
    }
    return records;
}