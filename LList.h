#ifndef LLIST_H
#define LLIST_H

#include <iostream>

class LList
{
    private:
    /* data */
    public:
        LList();
        LList(int[] anArray, int size);
        LList(const LList &);
        ~LList();

        const LList operator+(const LList &rhs) const;
        const LList operator=(const LList &rhs);

        void insert(const int index, const int &value);
        int remove(const int index);
        bool contains(const int &value) const;
        int get(const int index);
        int indexOf(const int &value) const;
        
        bool isEmpty() const;
        int size() const;
        void clear();

        const LList operator<<() const;
        bool operator==(const LList &rhs) const;

        int operator[](int index) const;
        int & operator[](int index);


};

#endif //LLIST.H
