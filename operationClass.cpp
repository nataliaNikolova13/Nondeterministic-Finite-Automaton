#include "operationClass.h"

void OperationClass::list(){
    std::cout<<"a";
    for(std::size_t i = 0; i < this->catalog.getSize(); i++){
        std::cout<<this->catalog.getAllAutomats()[i].getId()<<" - "<<this->catalog.getAllAutomats()[i].getName()<<std::endl;
    }
}