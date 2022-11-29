#ifndef DATUM_H
#define DATUM_H

#include <cstdlib>
#include <iostream>

class Datum {
    public:
        Datum();
        Datum(float value = 0.0);
        Datum(const Datum &rhs);
        ~Datum();

        float getData() const;
        void setData(float value);

        Datum * getNext() const;
        void setNext(Datum &link);

    private:
        float data;
        Datum *next;
};

#endif //DATUM.H