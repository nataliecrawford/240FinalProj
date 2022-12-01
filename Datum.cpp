#include <iostream>
#include <cstdlib>
#include "Datum.h"

using namespace std;

Datum::Datum() {
    setData(0);
    setNext(NULL);
}

Datum::Datum(int value) {
    setData(value);
    setNext(NULL);
}

Datum::Datum(const Datum &rhs) {
    setData(rhs.getData());
    setNext(rhs.getNext());
}

Datum::~Datum() {
    delete [] next;
}

int Datum::getData() const {
    return data;
}

void Datum::setData(int value) {
    data = value;
}

Datum * Datum::getNext() const {
    return next;
}

void Datum::setNext(Datum &datum) {
    next = datum.getNext();
}