#include "state.h"

State::State(){
    this->name = nullptr;
}

State::State(const char* name){
    this->name = new (std::nothrow) char[strlen(name) + 1];
    if(!this->name){
        throw "Memory problem - state";
        return;
    }
    strcpy(this->name, name);
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