#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include "Datum.h"

class LList {

    friend ostream & operator<<(ostream &lhs, const LList &rhs);
    friend istream & operator>>(istream &lhs, LList &rhs);

    private:
        Datum *first;
        Datum *last;
        Datum *temp;

    public:
        LList();
        LList(int[] arr, int size);
        LList(const LList &list);
        ~LList();

        const LList operator+(const LList &rhs) const;
        const LList operator=(const LList &rhs);

        void insert(int index, int value);
        int remove(int index);
        bool contains(int value) const;
        int get(int index) const;
        int indexOf(int value) const;
        
        bool isEmpty() const;
        int size() const;
        void clear();

        bool operator==(const LList &rhs) const;

        int operator[](int index) const;
        int & operator[](int index);

};

#endif //LLIST.H
