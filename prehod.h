#pragma once
#include "state.h"

const char epsilonPrehod = '-';

class Prehod{
    private:
        State* from;
        State* to;
        char letter;
        //Епсилон преходът ще се бележи с -
    public:
        Prehod();
        Prehod(const State* from, const State* to, char letter);
        Prehod(const Prehod& other);
        Prehod& operator=(const Prehod& other);
        void printPrehod();
        void printPrehodInFile();
        void readPrehodFromFile();
};