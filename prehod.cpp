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
    
}

