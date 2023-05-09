#include <iostream>
#include "allAutomats.h"
#pragma once

class OperationClass{
    private:
        // Catalog catalog;
        // OperationClass(){};
        // void clear();
    public:
        OperationClass(){};
        OperationClass(const OperationClass& operationClass) = delete;
        OperationClass& operator= (const OperationClass& operationClass) = delete;
        OperationClass& operator= (OperationClass&& operationClass) = delete;

        static OperationClass& getInstance(){
            static OperationClass operationClass;
            return operationClass;
        }

        // void listt(Catalog& catalog);
        void start();
        void help();
        void open(const char* name, Catalog& catalog, Catalog& openedAutomats);
        void list(Catalog& catalog);
        void close(const char* name, Catalog& openedAutomats);
        void empty(const char* name, Catalog& openedAutomats);
        void print(const char* name, Catalog& openedAutomats);
        void save(const char* name, const char* fileName, Catalog& catalog);
        void saveas(char* name, Catalog& openedAutomats, Catalog& catalog);
        void deterministic(const char* name, Catalog& openedAutomats);
        void recognize(const char* name, const char* word, Catalog& openedAutomats);
        void unite(const char* name1, const char* name2, Catalog& openedAutomats, Catalog& catalog);
        void concat(const char* name1, const char* name2, Catalog& openedAutomats, Catalog& catalog);
};