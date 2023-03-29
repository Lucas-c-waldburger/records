
#ifndef UNTITLED3_FILEHANDLER_H
#define UNTITLED3_FILEHANDLER_H
#include <vector>
#include "Record.h"


class FileHandler {
public:
    static int findIDOfLast();
    static void writeToCSV(Record &record, bool append = true);
    static std::unique_ptr<Record> getRecordFromCSV(std::string& album);
    static std::shared_ptr<std::vector<Record>> getRecordsFromCSV(int cellLocatedIn, std::string& term);
    static std::shared_ptr<std::vector<Record>> getRecordsFromCSV(int cellLocatedIn, int term);
    static std::shared_ptr<std::vector<Record>> getAllRecordsFromCSV();


private:
};


#endif //UNTITLED3_FILEHANDLER_H
