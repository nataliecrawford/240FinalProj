#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include "Datum.h"

using namespace std;

class LList {

    friend ostream & operator<<(ostream &lhs, const LList &rhs);
    friend istream & operator>>(istream &lhs, LList &rhs);

    private:
        Datum *head;
        Datum *tail;
        Datum *current;
        int length;

    public:
        LList();
        LList(int arr[], int size);
        LList(const LList &rhs);
        ~LList();

        const LList operator+(const LList &rhs) const;
        const LList operator=(const LList &rhs);

        void insert(int index, int value);
        int remove(int index);
        bool contains(int value) const;
        
        int operator[](int index) const;
        int & operator[](int index);
        
        int indexOf(int value) const;
        
        bool isEmpty() const;
        int size() const;
        void clear();

        bool operator==(const LList &rhs) const;

};

#endif //LLIST.H