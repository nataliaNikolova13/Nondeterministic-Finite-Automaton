#include "automat.h"
#include <fstream>

void Automat::clear(){
    delete[] this->allStates;

    for(unsigned int i = 0; i < this->size; i++){
        delete[] this->adjMatrix[i];
    }

    delete[] this->adjMatrix;
}

void Automat::copy(const Automat& other){
    this->allStates = new (std::nothrow) State[other.size];
    for(unsigned int i = 0; i < other.size; i++){
        this->allStates[i] = other.allStates[i];
    }
    this->adjMatrix = new (std::nothrow) char*[other.size];
    for(unsigned int j = 0; j < other.size; j++){
        this->adjMatrix[j] = new (std::nothrow) char[other.size];
    }

    for(unsigned int i = 0; i < other.size; i++){
        for(unsigned int j = 0; j < other.size; j++){
            this->adjMatrix[i][j] = other.adjMatrix[i][j];
        }
    }

    this->size = other.size;

    // this->nameAutomat = new (std::nothrow) char[strlen(other.nameAutomat) + 1];
    // strcpy(this->nameAutomat, other.nameAutomat);
}

Automat::~Automat(){
    this->clear();
}

void Automat::resize(){
    if(this->size==0){
        this->allStates = new (std::nothrow) State[1];
        this->adjMatrix = new (std::nothrow) char*[1];
        this->adjMatrix[0] = new (std::nothrow) char[1];
        this->size++;
    }else{
    State* tempStates = new (std::nothrow) State[this->size + 1];
    for(unsigned int i = 0; i < this->size; i++){
        tempStates[i] = this->allStates[i];
    }
    char** tempMatrix = new (std::nothrow) char*[this->size + 1];
    for(unsigned int j = 0; j < this->size + 1; j++){
        tempMatrix[j] = new (std::nothrow) char[this->size + 1];
    }
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            tempMatrix[i][j] = this->adjMatrix[i][j];
        }
    }
    this->clear();
    this->size++;
    this->allStates = tempStates;
    this->adjMatrix = tempMatrix;
    }
}

Automat::Automat(){
    this->allStates = nullptr;
    this->adjMatrix = nullptr;
    this->size = 0;
    this->id = idsTaken;
    idsTaken++;
}

Automat::Automat(const Automat& other){
    this->copy(other);
    this->id = idsTaken;
    idsTaken++;
}

Automat& Automat::operator= (const Automat& other){
    if(this!=&other){
        this->clear();
        this->copy(other);
    }
    return *this;
}

bool Automat::isStateInAutomat(const State& state){
    for(unsigned int i = 0; i < this->size; i++){
        if(strcmp(this->allStates[i].getNameState(), state.getNameState()) == 0){
            return true;
        }
    }
    return false;
}

int Automat::positionofState(const State& state){
    for(unsigned int i = 0; i < this->size; i++){
        if(strcmp(this->allStates[i].getNameState(), state.getNameState()) == 0){
            return i;
        }
    }
    return -1;
}

void Automat::addPrehod(const Prehod& prehod){
    if(!isStateInAutomat(prehod.getFrom())){
        this->resize();
        this->allStates[this->size-1] = prehod.getFrom();
        for(unsigned int i = 0; i < this->size; i++){
            for(unsigned int j = 0; j < this->size; j++){
                if(j == this->size - 1){
                    this->adjMatrix[i][j] = noPrehod;
                }
                else if(i == this->size - 1){
                    this->adjMatrix[i][j] = noPrehod;
                }
            }
        }
    }
    if(!isStateInAutomat(prehod.getTo())){
        this->resize();
        this->allStates[this->size-1] = prehod.getTo();
        for(unsigned int i = 0; i < this->size; i++){
            for(unsigned int j = 0; j < this->size; j++){
                if(j == this->size - 1){
                    this->adjMatrix[i][j] = noPrehod;
                }
                if(i == this->size - 1){
                    this->adjMatrix[i][j] = noPrehod;
                }
            }
        }
    }
    int posTo = positionofState(prehod.getTo());
    int posFrom = positionofState(prehod.getFrom());
    if(posTo != -1 && posFrom != -1){
        this->adjMatrix[posFrom][posTo] = prehod.getLetter();
    }else{
        throw "Problem";
        return;
    }
}

void Automat::printAutomat(){
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            if(this->adjMatrix[i][j] != noPrehod){
                Prehod pr(this->allStates[i], this->allStates[j], this->adjMatrix[i][j]);
                pr.printPrehod();
                // std::cout<<std::endl;
            }
        }
    }
}

/*
        тоест, че има път от нач състояние до всяко друго
        bool isValid();
        void printAutomat();
        void readAuthomatFromFile();
        void printAutomatInFile();
*/