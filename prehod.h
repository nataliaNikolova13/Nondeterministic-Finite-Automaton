#pragma once
#include <iostream>
#include "state.h"

const char epsilonPrehod = '-';
const char noPrehod = '*';

class Prehod{
    private:
        State from;
        State to;
        char letter;
        //Епсилон преходът ще се бележи с -
    public:
        Prehod();
        Prehod(State from, State to, char letter);
        Prehod(const Prehod& other);
        Prehod& operator=(const Prehod& other);

        State getTo() const;
        State getFrom() const;
        char getLetter() const;

        void printPrehod();
        void printPrehodInFile();
        void readPrehodFromFile();
};