
#ifndef UNTITLED3_CRUD_H
#define UNTITLED3_CRUD_H
#include "FileHandler.h"
#include "Record.h"

class CRUD {
public:
    static void setRecordData(Record &rec);

    static std::unique_ptr<Record> getRecord();

    static void createRecord();

    static void readRecord();
    static void readRecordsByArtist();
    static void readRecordsByGenre();
    static void readRecordsByReleaseYear();
    static std::string getReadInput(std::string& enterPrompt);
    static bool getConfirm(std::string& operation);

    static void updateRecord();

    static void deleteRecord();


};


#endif //UNTITLED3_CRUD_H
