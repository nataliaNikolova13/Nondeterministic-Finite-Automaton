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
    // std::cout<<"a";
    this->allStates = new (std::nothrow) State[other.size];
    for(unsigned int i = 0; i < other.size; i++){
        this->allStates[i] = other.allStates[i];
    }
    // std::cout<<"b";
    this->adjMatrix = new (std::nothrow) char*[other.size];
    for(unsigned int j = 0; j < other.size; j++){
        this->adjMatrix[j] = new (std::nothrow) char[other.size];
    }
    // std::cout<<"c";

    for(unsigned int i = 0; i < other.size; i++){
        for(unsigned int j = 0; j < other.size; j++){
            this->adjMatrix[i][j] = other.adjMatrix[i][j];
        }
    }
    // std::cout<<"d";

    this->size = other.size;
    // std::cout<<"e";

    if(other.name == nullptr){
        this->name = nullptr;
        // std::cout<<"fgggg";
    }else{
        this->name = new (std::nothrow) char[strlen(other.name) + 1];
        if(!this->name){
            throw "Memory problem";
            return;
        }
        strcpy(this->name, other.name);
    }
    
}

Automat::~Automat(){
    this->clear();
    delete[] this->name;
}

char* Automat::getName() const{
    // std::cout<<"x";
    return this->name;
}

// int Automat::getId() const{
//     // std::cout<<"id";
//     return this->id;
// }

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
    for(unsigned int i = 0; i < this->size +1; i++){
        for(unsigned int j = 0; j < this->size + 1; j++){
            if(i ==this->size || j == this->size){
                tempMatrix[i][j] = noPrehod;
                // std::cout<<"u";
            }else{
                tempMatrix[i][j] = this->adjMatrix[i][j];
            }
            
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
    // this->id = idsTaken;
    // idsTaken++;
    this->name = new (std::nothrow) char[17];
    strcpy(this->name, "Unknown_name.txt");
}

Automat::Automat(const Automat& other){
    this->copy(other);
    // this->id = idsTaken;
    // idsTaken++;
}

Automat& Automat::operator= (const Automat& other){
    // std::cout<<"copy";
    if(this!=&other){
        this->clear();
        // std::cout<<"clear";
        delete[] this->name;
        // std::cout<<"name";
        this->copy(other);
        // std::cout<<"ggrrtg";
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

void Automat::printMatrix(){
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            std::cout<<this->adjMatrix[i][j];
        }
        std::cout<<std::endl;}
}

void Automat::readAuthomatFromFile(const char* nameFile){
    delete[] this->name;
    this->name = new (std::nothrow) char[strlen(nameFile) + 1];
    strcpy(this->name, nameFile);
    std::ifstream file (nameFile);
    if(!file.is_open()){
        throw "Problem";
        return;
    }
    char temp[100];
    int counter = 0;
    State from;
    State to;
    while(!file.eof()){
        file >> temp;
        // std::cout<<temp<<std::endl;
        if(temp[0] == 'F' && temp[1] == 'i' && temp[2] == 'n'){
            counter = -1;
            // std::cout<<"m";
        }
        else if(counter == 0){
            from = State(temp, false);
            counter++;
        }else if(counter == 2){
            to = State(temp, false);
            counter++;
        }else if(counter == 4){
            Prehod prehod (from, to, temp[0]);
            this->addPrehod(prehod);
            counter = 0;
            // std::cout<<"f";
        }else if(counter == -1){
            // std::cout<<"l";
            int pos = this->positionofState(State(temp, true));
            this->allStates[pos].makeFinal();
        }
        else{
            counter++;
        }
    }
    file.close();
}

State& Automat::getFirstState() const{
    return this->allStates[0];
}

void Automat::printAutomatInFile(){
    std::ofstream file(this->name);
    if(!file.is_open()){
        throw "Memory problem";
        return;
    }
    // file<<
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++){
            if(this->adjMatrix[i][j] != noPrehod){
                Prehod pr(this->allStates[i], this->allStates[j], this->adjMatrix[i][j]);
                // pr.printPrehod();
                // std::cout<<std::endl;
                file<<pr.getFrom().getNameState()<<" => "<<pr.getTo().getNameState()<<" with "<<pr.getLetter()<<"\n";
            }
        }
    }
    file<<"FinalStates: ";
    
    for(unsigned int i = 0; i < this->size; i++){
        
        if(this->allStates[i].isStateFinal()){
            file<<this->allStates[i].getNameState()<<" ";
        }
    }
    file.close();
}

int Automat::getSize() const{
    return this->size;
}

void Automat::concatenate(const Automat& first, const Automat& second){
    this->copy(first);

    for(int i = 0; i < second.getSize(); i++){

        this->resize();
        this->allStates[i + first.getSize()] = second.allStates[i];
        }

    for(int i = 0; i < second.getSize(); i++){
        for(int j = 0; j < second.getSize(); j++){
            if(second.adjMatrix[i][j] != '*'){
                this->adjMatrix[first.getSize()+i][first.getSize()+j] = second.adjMatrix[i][j];
            }
        }
    }
    for(int i = 0; i < first.getSize(); i++){
        if(first.allStates[i].isStateFinal()){
            // std::cout<<i<<std::endl;
            Prehod temp(first.allStates[i], second.getFirstState(), epsilonPrehod);
            this-> addPrehod(temp);
            first.allStates[i].makeNotFinal();
        }
    }
    // this->id = idsTaken;
    // idsTaken++;
    char buffer[100];
    strcpy(buffer, "concat");
    strcat(buffer, "_");
    strcat(buffer, first.getName());
    strcat(buffer, "_");
    strcat(buffer, second.getName());
    delete[] this->name;
    this->name = nullptr;
    this->name = new (std::nothrow) char[strlen(buffer) + 1];
    strcpy(this->name, buffer);
    this->size = first.getSize() + second.getSize();
}


void Automat::unite(const Automat& first, const Automat& second){
    State start("start", false);
    Prehod toFirst(start, State("nextToStart_F", false), epsilonPrehod);
    this->addPrehod(toFirst);

    for(int i = 0; i < first.getSize(); i++){
        this->resize();
        this->allStates[i+2] = first.allStates[i];
        }
    for(int i = 0; i < first.getSize(); i++){
        for(int j = 0; j < first.getSize(); j++){
            if(first.adjMatrix[i][j] != '*'){
                this->adjMatrix[2+i][2+j] = first.adjMatrix[i][j];
            }
        }
        }
    Prehod fix(this->allStates[1], this->allStates[2], epsilonPrehod);
    this->addPrehod(fix);

    Prehod toSecond(start, State("nextToStart_S", false), epsilonPrehod);
    this->addPrehod(toSecond);
    // this->printMatrix();
    // std::cout<<this->size<<std::endl;
    int s = this->size;

    for(int i = 0; i < second.getSize(); i++){
        this->resize();
        this->allStates[i + s] = first.allStates[i];
        }

    for(int i = 0; i < second.getSize(); i++){
        for(int j = 0; j < second.getSize(); j++){
            if(second.adjMatrix[i][j] != '*'){
                this->adjMatrix[s+i][s+j] = second.adjMatrix[i][j];
            }
        }
        }
    Prehod fix2(this->allStates[s-1], this->allStates[s], epsilonPrehod);
    this->addPrehod(fix2);
    char buffer[100];
    strcpy(buffer, "union");
    strcat(buffer, "_");
    strcat(buffer, first.getName());
    strcat(buffer, "_");
    strcat(buffer, second.getName());
    delete[] this->name;
    this->name = nullptr;
    this->name = new (std::nothrow) char[strlen(buffer) + 1];
    strcpy(this->name, buffer);
    this->size = 3 + first.getSize() + second.getSize();
}

bool thereAreDuplicates(char* row, int s){
    for(int i = 0; i < s; i++){
        for(int j = i+1; j < s; j++){
            if(row[i] == row[j] && row[i] != noPrehod && row[j] != noPrehod){
                return true;
            }
        }
    }
    return false;
}

bool Automat::isDeterministic(){
    for(std::size_t i = 0; i < this->getSize(); i++){
        if(thereAreDuplicates(this->adjMatrix[i], this->getSize())){
            return false;
        }
    }
    return true;
}

void Automat::howManyWordsAreRead(int pos, int& b){
    for(std::size_t i = 0; i < this->getSize(); i++){
        if(this->adjMatrix[pos][i] != noPrehod){
            if(this->allStates[i].isStateFinal()){
                b++;
                this->howManyWordsAreRead(i, b);
            }
            else{
                this->howManyWordsAreRead(i, b);
            }

        }
    }
}

bool Automat::isEmpty(){
    int b = 0;
    // det.howManyWordsAreRead(0, b);
    // std::cout<<b<<std::endl;
    this->howManyWordsAreRead(0, b);
    if(b > 0){
        return false;
    }else{
        true;
    }
    return true;
}

void Automat::isRecognised(const char* word, int& posInWord, int& posInAutomat){
    // this->getFirstState();
    for(int i = 0; i < this->size; i++){
        if(this->adjMatrix[posInAutomat][i] == word[posInWord]){
            posInWord++;
            posInAutomat = i;
            this->isRecognised(word, posInWord, posInAutomat);
        }
    }
}

bool Automat::isWordRecodnised(const char* word){
    int posInWord = 0;
    int posInAutomat = 0;
    this->isRecognised(word, posInWord, posInAutomat);
    // std::cout<<posInWord;
    if(posInWord == strlen(word)){
        return true;
    }
    return false;

}

/*
        тоест, че има път от нач състояние до всяко друго
        bool isValid();
        void printAutomat();
        void readAuthomatFromFile();
        void printAutomatInFile();
*/