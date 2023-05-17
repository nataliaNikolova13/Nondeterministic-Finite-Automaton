#include "allAutomats.h"

Catalog::Catalog(){
    this->allAutomats = new (std::nothrow) Automat[2];
    this->size = 0;
    this->capacity = 2;
}

void Catalog::clear(){
    delete[] this->allAutomats;
}

Catalog::~Catalog(){
    this->clear();
}

void Catalog::copy(const Catalog& other){
    this->allAutomats = new (std::nothrow) Automat[this->size];
    for(std::size_t i = 0; i < this->size; i++){
        this->allAutomats[i] = other.allAutomats[i];
    }
    this->size = other.size;
    this->capacity = other.capacity;
}

Catalog::Catalog(const Catalog& other){
    this->copy(other);
}

Catalog& Catalog::operator= (const Catalog& other){
    if(this!=&other){
        this->clear();
        this->copy(other);
    }
    return *this;
}

void Catalog::resize(){
    Automat* newCatalog = new (std::nothrow) Automat[this->capacity * 2];
    if(!newCatalog){
        throw "Memory problem";
        return;
    }
    for(std::size_t i = 0; i < this->size; i++){
        newCatalog[i] = this->allAutomats[i];
    }
    this->clear();
    this->allAutomats = newCatalog;
    this->capacity = this->size * 2;
}

void Catalog::addAutomat(const Automat& automat){
    if(!this->isUnique(automat.getName())){
        std::cout<<"This name already exists";
        return;
    }
    if(this->size == this->capacity){
        this->resize();
    }
   
    this->allAutomats[this->size] = automat;
    this->size = this->size + 1;
}

int Catalog::getSize() const{
    return this->size;
}

const Automat* Catalog::getAllAutomats() const{
    return this->allAutomats;
}

void Catalog::list(){
    for(std::size_t i = 0; i < this->size; i++){
        std::cout<<i+1<<" - "<<this->getAllAutomats()[i].getName()<<std::endl;
    }
}

void Catalog::printAutomatById(int id){
    this->allAutomats[id].printAutomat();
    this->allAutomats[id].printMatrix();
}

int Catalog::getId(const Automat& automat) const{
    for(std::size_t i = 0; i < this->size; i++){
        if(strcmp(this->allAutomats[i].getName(), automat.getName()) == 0){
            return i;
        }
    }
    return -1;
}

int Catalog::getIdByName(const char* name) const{
    for(std::size_t i = 0; i < this->size; i++){
        if(strcmp(this->allAutomats[i].getName(), name) == 0){
            return i;
        }
    }
    return -1;

}

void Catalog::removeAutomat(const char* name){
    std::swap(this->allAutomats[this->getIdByName(name)], this->allAutomats[this->size-1]);
    --this->size;
}

bool Catalog::isUnique(const char* name){
    for(std::size_t i = 0; i < this->size; i++){
        if(strcmp(this->allAutomats[i].getName(), name ) == 0){
            return false;
        }
    }
    return true;
}

bool Catalog::automatExsists(const char* name){
    for(std::size_t i = 0; i < this->size; i++){
        if(strcmp(this->allAutomats[i].getName(), name ) == 0){
            return true;
        }
    }
    return false;
}