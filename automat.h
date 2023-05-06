#pragma once
#include "state.h"
#include "prehod.h"
#include <cstring>
#include <iostream>

static int idsTaken = 0;

class Automat{
    private:
        unsigned int id;
        // char* nameAutomat;
        State* allStates;
        char** adjMatrix;

        unsigned int size;
        // unsigned int capasity;

        void clear();
        // void clearMatrix();
        void copy(const Automat& other);
        // void copyMatrix();
        void resize();
        // void resizeMatrix();
    public:

        Automat();
        Automat(const Automat& other);
        ~Automat();
        Automat& operator= (const Automat& other);
        void addPrehod(const Prehod& prehod);
        void printAutomat();
        void readAuthomatFromFile();
        void printAutomatInFile();
        bool isStateInAutomat(const State& state);
        int positionofState(const State& state);
        bool isValid();

};