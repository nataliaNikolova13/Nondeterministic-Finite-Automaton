#include <iostream>
#include <cstring>
#pragma once

class State{
    private:
        char* name;
        bool isFinal;
        void clear();
        void copy(const State& other);
    public:
        State();
        State(const char* name, bool isFinal);
        State(const State& other);
        State& operator= (const State& other);
        const char* getNameState() const;
        void printState();
        ~State();
        void printStateInFile();
        bool isStateFinal() const;
        void makeFinal();
};