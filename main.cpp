#include <iostream>
#include "automat.h"

int main(){
    State state ("one");
    State st ("two");
    State sta ("three");
    // state.printState();
    Prehod prehod(state, st, 'a');
    Prehod pr(state, sta, 'b');
    // prehod.printPrehod();
    Automat automat;
    automat.addPrehod(prehod);
    automat.addPrehod(pr);
    automat.printAutomat();
    return 0;
}