#include "operationClass.h"

// OperationClass::OperationClass(){
//     this->catalog = catalog;
// }

// void OperationClass::list(){
    
//     for(std::size_t i = 0; i < this->catalog.getSize(); i++){
//         std::cout<<"a";
//         std::cout<<getInstance().catalog.getAllAutomats()[i].getId()<<" - "<<getInstance().catalog.getAllAutomats()[i].getName()<<std::endl;
//     }
// }

void OperationClass::start(){
    State state ("five", false);
    State st ("six", false);
    State sta ("seven", true);
    State four ("eight", true);
    // State nine ("nine", false);
    // state.printState();
    Prehod prehod(state, st, 'a');
    Prehod pr(state, sta, 'b');
    Prehod three(four, st, 'b');
    Prehod fourr(state, four, 'b');
    // prehod.printPrehod();
    Automat automat;
    // std::cout<<automat.getId();
    automat.addPrehod(prehod);
    automat.addPrehod(pr);
    // std::cout<<automat.getId();
    automat.addPrehod(three);
    automat.addPrehod(fourr);
    // automat.printAutomat();
    // automat.printMatrix();
    automat.printAutomatInFile();

    Automat fromFile;
    fromFile.readAuthomatFromFile("automat.txt");
    // fromFile.printMatrix();

    Catalog catalog;
    catalog.addAutomat(automat);
    catalog.addAutomat(fromFile);
    
    // catalog.printAutomatById(2);
    // std::cout<<"-----"<<std::endl;
    // catalog.printAutomatById(1);

    // Automat concat;
    // concat.concatenate(fromFile, automat);
    // catalog.addAutomat(concat);
    // catalog.list();
    // concat.printAutomat();
    // concat.printMatrix();

    Automat un;
    un.unite(fromFile, automat);
    // un.printMatrix();
    catalog.addAutomat(un);

    Automat det;
    det.readAuthomatFromFile("det.txt");
    // det.printMatrix();
    // std::cout<<std::boolalpha<<det.isDeterministic();
    catalog.addAutomat(det);

    Automat notdet;
    notdet.readAuthomatFromFile("notdet.txt");
    // std::cout<<std::boolalpha<<notdet.isDeterministic();
    catalog.addAutomat(notdet);
    catalog.list();
}

