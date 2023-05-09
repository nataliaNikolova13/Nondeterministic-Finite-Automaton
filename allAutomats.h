#include <iostream>
#include "automat.h"
#pragma once

class Catalog{
    private:
        Automat* allAutomats;
        std::size_t size;
        std::size_t capacity;

        void clear();
        void copy(const Catalog& other);
        void resize();
    public:
        Catalog();
        Catalog(const Catalog& other);
        Catalog& operator= (const Catalog& other);
        ~Catalog();
        void addAutomat(const Automat& automat);
        int getSize() const;
        const Automat* getAllAutomats() const;
        void list();
        void printAutomatById(int id);
        int getId(const Automat& automat) const;
        int getIdByName(const char* name) const;
        Automat& concatByID(const char* name1, const char* name2);
        // void concatenate(const Automat& first, const Automat& second);
};