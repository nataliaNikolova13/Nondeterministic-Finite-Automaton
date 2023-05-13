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


    // Automat autRegex;
    // // autRegex.regex("c(aa+bb)");
    // autRegex.regex("(ab+bb)*");
    // autRegex.printAutomat();
    // autRegex.printMatrix();
    // std::cout<<std::boolalpha<<autRegex.isValid();
    // autRegex.printAutomatInFileByName("regex.txt");

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

    // std::cout<<std::boolalpha<<catalog.isUnique("det.txt");
    // std::cout<<std::boolalpha<<catalog.isUnique("dert.txt");

    // det.un();
    // det.printAutomat();

    Catalog openedAutomats;
    // Automat temp[5];

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
            this->open(name, catalog, openedAutomats);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "list") == 0){
            this->list(catalog);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "print") == 0){
            char name[100];
            std::cin>>name;

            this->print(name, openedAutomats);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "save_as") == 0){
            char name[100];
            std::cin>>name;

            this->saveas(name, openedAutomats, catalog);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "close") == 0){
            char name[100];
            std::cin>>name;
            this->close(name, openedAutomats);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "empty") == 0){
            char name[100];
            std::cin>>name;
            this->empty(name, openedAutomats);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "deterministic") == 0){
            char name[100];
            std::cin>>name;
            this->deterministic(name, openedAutomats);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "save") == 0){
            char name[100];
            std::cin>>name;
            char nameFile[100];
            std::cin>>nameFile;

            this->save(name, nameFile, catalog);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "recognize") == 0){
            char name[100];
            std::cin>>name;
            char word[100];
            std::cin>>word;

            this->recognize(name, word, catalog);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "union") == 0){
            char name1[100];
            std::cin>>name1;
            char name2[100];
            std::cin>>name2;

            this->unite(name1, name2, openedAutomats, catalog);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "concat") == 0){
            char name1[100];
            std::cin>>name1;
            char name2[100];
            std::cin>>name2;

            this->concat(name1, name2, openedAutomats, catalog);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "un") == 0){
            char name[100];
            std::cin>>name;

            this->un(name, openedAutomats, catalog);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else if(strcmp(command, "regex") == 0){
            char regex[100];
            std::cin>>regex;

            this->regex(catalog, regex);

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }else{
            std::cout<<"Unknown command"<<std::endl;

            std::cout<<"Enter a command: ";
            std::cin>>command;
        }
    }
    
}


void OperationClass::help(){
    std::cout<<"(1) To open an automat, enter \"open\" <the name of the automat>"<<std::endl;
    std::cout<<"(2) To close an automat without saving, enter \"close\" <the name of the automat>"<<std::endl;
    std::cout<<"(3) To save an automat, enter \"save\" <the name of the automat> <filename>"<<std::endl;
    std::cout<<"(4) To save an automat in a new file, enter \" save_as\" <the name of the automat>"<<std::endl;
    std::cout<<"(5) Exit this program, enter \"exit\""<<std::endl;
    std::cout<<"(6) To list all saved automats, enter \"list\""<<std::endl;
    std::cout<<"(7) To print an automat, enter \"print\" <the name of the automat>"<<std::endl;
    std::cout<<"(8) To concat two automats, enter \"concat\" <the name of the first automat> <the name of the second automat>"<<std::endl;
    std::cout<<"(9) To unite two automats, enter \"union\" <the name of the first automat> <the name of the second automat>"<<std::endl;
    std::cout<<"(10) To check if a word is recognised by an automat, enter \"recognise\" <the name of the automat> <word>"<<std::endl;
    std::cout<<"(11) To check if the language of the automat is empty, enter \"empty\" <the name of the automat>"<<std::endl;
    std::cout<<"(12) To check if a word is deterministic, enter \"deterministic\" <the name of the automat>"<<std::endl;
    std::cout<<"(13) To create an automat from regex, enter \"regex\" <regex>"<<std::endl;
    std::cout<<"(13) To get the positive shell of an automat, enter \"un\" <the name of the automat>"<<std::endl;
}

void OperationClass::open(const char* name, Catalog& catalog, Catalog& openedAutomats){
    //to add proverka dali automat e otvoren
    //bool isOpened i isSaved в главната функция

    Automat temp;
    if(!catalog.automatExsists(name)){
        std::cout<<"There is no such automat, you should create it first"<<std::endl;
        return;
    }
    temp = catalog.getAllAutomats()[catalog.getIdByName(name)];
    // std::cout<<temp.getName()<<std::endl;
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name) == 0){
            std::cout<<"Automat is already opened"<<std::endl;
            return;
        }
    }
    openedAutomats.addAutomat(temp);
    std::cout<<"File is opened"<<std::endl;
}

void OperationClass::list(Catalog& catalog){
    catalog.list();
}

void OperationClass::close(const char* name, Catalog& openedAutomats){
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name) == 0){
            openedAutomats.removeAutomat(name);
            std::cout<<"Automat is closed"<<std::endl;
            return;
        }
    }
    std::cout<<"Automat hasn't been opened"<<std::endl;
    return;
}

void OperationClass::save(const char* name, const char* fileName, Catalog& catalog){
    if(!catalog.automatExsists(name)){
        std::cout<<"There is no such automat, you should create it first"<<std::endl;
        return;
    }
    for(int i = 0; i < catalog.getSize(); i++){
        if(strcmp(catalog.getAllAutomats()[i].getName(), name) == 0){
            // catalog.removeAutomat(name);
            Automat temp;
            temp = catalog.getAllAutomats()[i];
            temp.printAutomatInFileByName(fileName);
            std::cout<<"Automat is saved"<<std::endl;
            Automat t;
            t.readAuthomatFromFile(fileName);
            catalog.addAutomat(t);
            return;
        }
    }
    std::cout<<"No such Automat"<<std::endl;
}

void OperationClass::saveas(char* name, Catalog& openedAutomats, Catalog& catalog){
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name) == 0){
            // catalog.removeAutomat(name);
            Automat temp;
            temp = openedAutomats.getAllAutomats()[i];
            strcat(name, "(2)");
            temp.printAutomatInFileByName(name);
            std::cout<<"Automat is saved"<<std::endl;
            Automat t;
            t.readAuthomatFromFile(name);
            catalog.addAutomat(t);
            return;
        }
    }
    std::cout<<"No such Automat"<<std::endl;
}

void OperationClass::print(const char* name, Catalog& openedAutomats){
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name) == 0){
            Automat temp;
            temp = openedAutomats.getAllAutomats()[i];
            temp.printAutomat();
            // openedAutomats.removeAutomat(name);
            std::cout<<"Automat is printed"<<std::endl;
            return;
        }
    }
    std::cout<<"Automat hasn't been opened"<<std::endl;
    return;
}

void OperationClass::empty(const char* name, Catalog& openedAutomats){
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name) == 0){
            Automat temp;
            temp = openedAutomats.getAllAutomats()[i];
            std::cout<<std::boolalpha<<temp.isEmpty()<<std::endl;
            return;
        }
    }
    std::cout<<"Automat hasn't been opened"<<std::endl;
    return;
}

void OperationClass::deterministic(const char* name, Catalog& openedAutomats){
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name) == 0){
            Automat temp;
            temp = openedAutomats.getAllAutomats()[i];
            std::cout<<std::boolalpha<<temp.isDeterministic()<<std::endl;
            return;
        }
    }
    std::cout<<"Automat hasn't been opened"<<std::endl;
    return;
}

void OperationClass::recognize(const char* name, const char* word, Catalog& openedAutomats){
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name) == 0){
            Automat temp;
            temp = openedAutomats.getAllAutomats()[i];
            std::cout<<std::boolalpha<<temp.isWordRecodnised(word)<<std::endl;
            return;
        }
    }
    std::cout<<"Automat hasn't been opened"<<std::endl;
    return;
}

void OperationClass::unite(const char* name1, const char* name2, Catalog& openedAutomats, Catalog& catalog){
    Automat temp1;
    Automat temp2;
    bool f,s = false;
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name1) == 0){
            temp1 = openedAutomats.getAllAutomats()[i];
            f = true;
        }else if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name2) == 0){
            temp2 = openedAutomats.getAllAutomats()[i];
            s = true;
        }
    }
    if(f == true && s == true){
        Automat temp;
        temp.unite(temp1, temp2);
        catalog.addAutomat(temp);
        std::cout<<"Automat has been created"<<std::endl;
    }else{
        std::cout<<"Automat hasn't been opened"<<std::endl;
        return;
    }
    return;
}

void OperationClass::concat(const char* name1, const char* name2, Catalog& openedAutomats, Catalog& catalog){
    Automat temp1;
    Automat temp2;
    bool f,s = false;
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name1) == 0){
            temp1 = openedAutomats.getAllAutomats()[i];
            f = true;
        }else if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name2) == 0){
            temp2 = openedAutomats.getAllAutomats()[i];
            s = true;
        }
    }
    if(f == true && s == true){
        Automat temp;
        temp.concatenate(temp1, temp2);
        catalog.addAutomat(temp);
        std::cout<<"Automat has been created"<<std::endl;
    }else{
        std::cout<<"Automat hasn't been opened"<<std::endl;
        return;
    }
    return;
}

void OperationClass::un(const char* name, Catalog& openedAutomats, Catalog& catalog){
    Automat temp;
    for(int i = 0; i < openedAutomats.getSize(); i++){
        if(strcmp(openedAutomats.getAllAutomats()[i].getName(), name) == 0){
            temp = openedAutomats.getAllAutomats()[i];
            temp.un();
            temp.printAutomat();
            return;
        }
    }
    std::cout<<"Automat hasn't been opened"<<std::endl;
    return;    
}

void OperationClass::regex(Catalog& catalog, const char* regex){
    Automat temp;
    temp.regex(regex);
    catalog.addAutomat(temp);

}