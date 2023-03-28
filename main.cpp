#include <iostream>
#include "Record.h"
#include <memory>


//Record* getLast() {
//
//}

//void Create();
//
//void Read();

void updateRecord(Record* record) {
    std::unique_ptr<CurrentTime> ct = std::make_unique<CurrentTime>();
    record->dateLastEdit = Date{ct->getMonth(), ct->getDay(), ct->getYear()};
}



int main() {

    CurrentTime ct = CurrentTime();

    auto* rec = new Record();

    std::cout << rec->dateLastEdit.day;

//    Record* headRecord = new Record("The Beatles", "Abbey Road", "Rock", 1969, )
    return 0;
}
