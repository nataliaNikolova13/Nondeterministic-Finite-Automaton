#include <iostream>
#include "automat.h"

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
    automat.addPrehod(prehod);
    automat.addPrehod(pr);
    automat.addPrehod(three);
    automat.printAutomat();
    // automat.printMatrix();

    Automat fromFile;
    fromFile.readAuthomatFromFile("automat.txt");
    fromFile.printMatrix();
    return 0;
}