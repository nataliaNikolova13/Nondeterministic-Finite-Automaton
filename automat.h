#pragma once
#include "state.h"
#include "prehod.h"
#include <cstring>
#include <iostream>

class Automat{
    private:
        State* allStates;
        char** adjMatrix;
        unsigned int size;
        char* name;
      
        void clear();
        void copy(const Automat& other);
        void resize();
    public:

        Automat();
        Automat(const Automat& other);
        ~Automat();
        Automat& operator= (const Automat& other);
        void addPrehod(const Prehod& prehod);
        void printAutomat();
        void readAuthomatFromFile(const char* nameFile);
        void printAutomatInFile();
        void printAutomatInFileByName(const char* nameFile);
        bool isStateInAutomat(const State& state);
        int positionofState(const State& state);
        void printMatrix();
        State& getFirstState() const;
        const char* getName() const;
        int getSize() const;
        void concatenate(const Automat& first, const Automat& second);
        void unite(const Automat& first, const Automat& second);
        bool isDeterministic();
        void howManyWordsAreRead(int pos, int& b);
        bool isEmpty();
        void isRecognised(const char* word, int& posInWord, int& posInAutomat);
        bool isWordRecodnised(const char* word);
        bool regex(const char* regex);
        void un();
};