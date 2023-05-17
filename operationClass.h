#include <iostream>
#include "allAutomats.h"
#pragma once

class OperationClass{
    private:
    
    public:
        OperationClass(){};
        OperationClass(const OperationClass& operationClass) = delete;
        OperationClass& operator= (const OperationClass& operationClass) = delete;
        OperationClass& operator= (OperationClass&& operationClass) = delete;

        static OperationClass& getInstance(){
            static OperationClass operationClass;
            return operationClass;
        }

        void start();
        void help();
        void open(const char* name, Catalog& catalog, Catalog& openedAutomats);
        void list(Catalog& catalog);
        void listOpened(Catalog& openedAutomats);
        void close(const char* name, Catalog& openedAutomats);
        void empty(const char* name, Catalog& openedAutomats);
        void print(const char* name, Catalog& openedAutomats);
        void save(const char* name, const char* fileName, Catalog& catalog);
        void saveas(char* name, Catalog& openedAutomats, Catalog& catalog);
        void deterministic(const char* name, Catalog& openedAutomats);
        void recognize(const char* name, const char* word, Catalog& openedAutomats);
        void unite(const char* name1, const char* name2, Catalog& openedAutomats, Catalog& catalog);
        void concat(const char* name1, const char* name2, Catalog& openedAutomats, Catalog& catalog);
        void un(const char* name, Catalog& openedAutomats, Catalog& catalog);
        void regex(Catalog& catalog, const char* regex);
};