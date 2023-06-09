#include "operationClass.h"

void OperationClass::start(){

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

    Catalog openedAutomats;

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
        }else if(strcmp(command, "listOpened") == 0){
            this->listOpened(openedAutomats);

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

    Automat temp;
    if(!catalog.automatExsists(name)){
        std::cout<<"There is no such automat, you should create it first"<<std::endl;
        return;
    }
    temp = catalog.getAllAutomats()[catalog.getIdByName(name)];
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

void OperationClass::listOpened(Catalog& openedAutomats){
    openedAutomats.list();
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
    if(temp.regex(regex) == true){
        catalog.addAutomat(temp);
    }else{
        std::cout<<"Not a valid regex, automat not added"<<std::endl;
    }
    

}