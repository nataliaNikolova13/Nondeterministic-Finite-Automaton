#include <iostream>
// #include "automat.h"
// #include "allAutomats.h"
#include "operationClass.h"

int main(){
    State state ("one", false);
    State st ("two", false);
    State sta ("three", true);
    State four ("four", true);
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
    // automat.printAutomat();
    // automat.printMatrix();
    automat.printAutomatInFile();

    Automat fromFile;
    fromFile.readAuthomatFromFile("automat.txt");
    // fromFile.printMatrix();

    Catalog catalog;
    catalog.addAutomat(automat);
    catalog.addAutomat(fromFile);
    catalog.list();
    catalog.printAutomatById(2);
    // OperationClass operationClass;
    // operationClass.list();
    // allAutomats.spp operationClass.cpp
    return 0;
}