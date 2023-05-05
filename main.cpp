#include <iostream>
#include "prehod.h"

int main(){
    State* state = new State("one");
    State* st = new State("two");
    // state.printState();
    Prehod prehod(state, st, 'a');
    prehod.printPrehod();
    delete state;
    delete st;
    return 0;
}