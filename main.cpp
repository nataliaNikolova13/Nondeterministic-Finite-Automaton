#include <iostream>
// #include "automat.h"
// #include "allAutomats.h"
#include "operationClass.h"

int main(){
    State state ("one");
    State st ("two");
    State sta ("three");
    State four ("four");
    // state.printState();
    Prehod prehod(state, st, 'a');
    Prehod pr(state, sta, 'b');
    Prehod three(four, st, 'b');
    // prehod.printPrehod();
    Automat automat;
    // std::cout<<automat.getId();
    automat.addPrehod(prehod);
    automat.addPrehod(pr);
    // std::cout<<automat.getId();
    automat.addPrehod(three);
    automat.printAutomat();
    // automat.printMatrix();

    Automat fromFile;
    fromFile.readAuthomatFromFile("automat.txt");
    fromFile.printMatrix();

    Catalog catalog;
    catalog.addAutomat(automat);
    catalog.addAutomat(fromFile);
    catalog.print();

    // OperationClass operationClass;
    // operationClass.list();
    // allAutomats.spp operationClass.cpp
    return 0;
}