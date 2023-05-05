#include "prehod.h"
#include <fstream>

Prehod::Prehod(){
    this->to = nullptr;
    this->from = nullptr;
    this->letter = '-';
}

Prehod::Prehod(State* from, State* to, char letter){
    this->from = from;
    this->to = to;
    this->letter = letter;
}

Prehod::Prehod(const Prehod& other){
    this->to = other.to;
    this->from = other.from;
    this->letter = other.letter;
}

Prehod& Prehod::operator=(const Prehod& other){
    if(this!=&other){
        this->to = other.to;
        this->from = other.from;
        this->letter = other.letter;
    }
    return *this;
}

void Prehod::printPrehod(){
    std::cout<<this->to->getNameState()<<" => "<<this->from->getNameState()<<" with "<<this->letter<<std::endl;
}

void Prehod::readPrehodFromFile(){
    // std::
    /*
    std::ifstream dadJokes("dadJokes.txt"); 

    if (!dadJokes.is_open()) // always check if the opening is successfull
    {
        std::cout << "Problem while opening the file" << std::endl;
        return 1;
    }

    // Reading the file word by word

    char tempWord[100];
    while (!dadJokes.eof()) // reading until end of file
    {
        dadJokes >> tempWord;
        std::cout << tempWord << std::endl;
    }

    dadJokes.close();
    */
}

/*
        
        void printPrehodInFile();
        
*/