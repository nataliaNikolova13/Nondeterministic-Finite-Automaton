#include "state.h"

State::State(){
    this->name = nullptr;
    this->isFinal = false;
}

State::State(const char* name, bool isFinal){
    this->name = new (std::nothrow) char[strlen(name) + 1];
    if(!this->name){
        throw "Memory problem - state";
        return;
    }
    strcpy(this->name, name);
    this->isFinal = isFinal;
}

void State::clear(){
    delete[] this->name;
}

State::~State(){
    this->clear();
}

void State::copy(const State& other){
    this->name = new (std::nothrow) char[strlen(other.name) + 1];
    if(!this->name){
        throw "Memory problem - state";
        return;
    }
    strcpy(this->name, other.name);
    this->isFinal = other.isFinal;
}

State::State(const State& other){
    this->copy(other);
}

State& State::operator= (const State& other){
    if(this!=&other){
        this->clear();
        this->copy(other);
    }
    return *this;
}

const char* State::getNameState() const{
    return this->name;
}

void State::printState(){
    std::cout<<this->name;
}

bool State::isStateFinal() const{
    return this->isFinal;
}

void State::makeFinal(){
    this->isFinal = true;
}

void State::makeNotFinal(){
    this->isFinal = false;
}
//void State::printStateInFile();