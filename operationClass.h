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

        void listt(Catalog& catalog);
        void start();
};