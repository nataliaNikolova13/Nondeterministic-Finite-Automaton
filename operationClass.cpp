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
    /*
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
    // std::cout<<std::boolalpha<<det.isEmpty();
    // int b = 0;
    // det.howManyWordsAreRead(0, b);
    // std::cout<<b<<std::endl;
    catalog.addAutomat(det);

    Automat notdet;
    // std::cout<<std::boolalpha<<notdet.isEmpty();
    notdet.readAuthomatFromFile("notdet.txt");
    // std::cout<<std::boolalpha<<notdet.isDeterministic();
    catalog.addAutomat(notdet);


    catalog.list();
    
    // std::cout<<std::boolalpha<<det.isWordRecodnised("aa");
    */

    Catalog catalog;
    Automat fromFile;
    fromFile.readAuthomatFromFile("automat.txt");
    catalog.addAutomat(fromFile);
    Automat det;
    det.readAuthomatFromFile("det.txt");
    catalog.addAutomat(det);
    Automat notdet;
    notdet.readAuthomatFromFile("notdet.txt");
    catalog.addAutomat(notdet);

    Automat temp[5];

    char command[50];
    std::cout<<"Enter a command: ";
    std::cin>>command;
    while(strcmp(command, "exit") != 0){
        if(strcmp(command, "help") == 0){
            this->help();

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "open") == 0){
            char name[100];
            std::cin>>name;
            this->open(name, catalog, temp);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "list") == 0){
            this->list(catalog);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "save") == 0){


            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else{
            std::cout<<"Unknown command";

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }
    }
    
    // std::cout<<command;
    // std::cin.getline(command, 50);

    // if(strcmp(command, "help") == 0){
    //     this->help();
    // }else{
    //     std::cout<<"Unknown command";
    // }
    // std::cout<<command;
}


void OperationClass::help(){
    std::cout<<"(1) To open an automat, enter \"open\" <the name of the automat>"<<std::endl;
    std::cout<<"(2) To close an automat with saving, enter \"close\" <the name of the automat>"<<std::endl;
    std::cout<<"(3) To save an automat, enter \"save\" <the name of the automat>"<<std::endl;
    std::cout<<"(4) To save an automat in a new file, enter \" save as\" <the name of the automat>"<<std::endl;
    std::cout<<"(5) Exit this program, enter \"exit\""<<std::endl;
    std::cout<<"(6) To list all saved automats, enter \"list\""<<std::endl;
    std::cout<<"(7) To print an automat, enter \"print\" <the name of the automat>"<<std::endl;
    std::cout<<"(8) To concat two automats, enter \"concat\" <the name of the first automat> <the name of the second automat>"<<std::endl;
    std::cout<<"(9) To unite two automats, enter \"unite\" <the name of the first automat> <the name of the second automat>"<<std::endl;
    std::cout<<"(10) To check if a word is recognised by an automat, enter \"recognise\" <the name of the automat> <word>"<<std::endl;
    std::cout<<"(11) To check if the language of the automat is empty, enter \"empty\" <the name of the automat>"<<std::endl;
}

void OperationClass::open(const char* name, Catalog& catalog, Automat* temp){
    //to add proverka dali automat e otvoren
    //bool isOpened i isSaved в главната функция
    // Automat temp;
    // for(int i = 0; i < 5; i++){
    //     if(!temp[i]){

    //     }
    // }
    
    // temp = catalog.getAllAutomats()[catalog.getIdByName(name)];
}

void OperationClass::list(Catalog& catalog){
    catalog.list();
}
