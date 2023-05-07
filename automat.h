#pragma once
#include "state.h"
#include "prehod.h"
#include <cstring>
#include <iostream>

static unsigned int idsTaken = 4;

class Automat{
    private:
        int id;
        State* allStates;
        char** adjMatrix;
        unsigned int size;
        char* name;
      
        void clear();
        void copy(const Automat& other);
        void resize();
    public:

        static bool isOpened;
        static bool isSaved;

        Automat();
        Automat(const Automat& other);
        ~Automat();
        Automat& operator= (const Automat& other);
        void addPrehod(const Prehod& prehod);
        void printAutomat();
        void readAuthomatFromFile(const char* nameFile);
        void printAutomatInFile();
        bool isStateInAutomat(const State& state);
        int positionofState(const State& state);
        bool isValid();
        void printMatrix();
        State& getFirstState() const;
        const char* getName() const;
        int getId() const;
        //кои са финалните състояния?
};