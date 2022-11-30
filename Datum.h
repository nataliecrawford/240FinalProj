#ifndef DATUM_H
#define DATUM_H

#include <cstdlib>
#include <iostream>

class Datum {
    public:
        Datum();
        Datum(int value = 0);
        Datum(const Datum &rhs);
        ~Datum();

        int getData() const;
        void setData(int value);

        Datum * getNext() const;
        void setNext(Datum &link);

    private:
        int data;
        Datum *next;
};

#endif //DATUM.H