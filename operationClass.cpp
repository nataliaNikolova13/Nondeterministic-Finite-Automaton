#include "operationClass.h"

// OperationClass::OperationClass(){
//     this->catalog = catalog;
// }

void OperationClass::list(){
    
    for(std::size_t i = 0; i < this->catalog.getSize(); i++){
        std::cout<<"a";
        std::cout<<getInstance().catalog.getAllAutomats()[i].getId()<<" - "<<getInstance().catalog.getAllAutomats()[i].getName()<<std::endl;
    }
}