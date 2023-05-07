#include "prehod.h"
#include <fstream>

Prehod::Prehod(){
    this->to = State(nullptr, false);
    this->from = State(nullptr, false);
    this->letter = '-';
}

Prehod::Prehod(State from, State to, char letter){
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

State Prehod::getTo() const{
    return this->to;
}

State Prehod::getFrom() const{
    return this->from;
}

char Prehod::getLetter() const{
    return this->letter;
}

void Prehod::printPrehod(){
    std::cout<<this->from.getNameState()<<" => "<<this->to.getNameState()<<" with "<<this->letter<<std::endl;
}

void Prehod::readPrehodFromFile(){
    // std::ifstream file
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