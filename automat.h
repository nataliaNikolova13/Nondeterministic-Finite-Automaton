#pragma once
#include "state.h"
#include "prehod.h"
#include <cstring>
#include <iostream>

// static unsigned int idsTaken = -1;

class Automat{
    private:
        // int id;
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
        char* getName() const;
        // int getId() const;
        int getSize() const;
        void concatenate(const Automat& first, const Automat& second);
        void unite(const Automat& first, const Automat& second);
        bool isDeterministic();
        //кои са финалните състояния?
};