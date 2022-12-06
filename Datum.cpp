#include <iostream>
#include "Datum.h"

using namespace std;

Datum::Datum() {
    setData(0);
    next = nullptr;
}

Datum::Datum(int value) {
    setData(value);
    next = nullptr;
}

Datum::Datum(const Datum &rhs) {
    setData(rhs.getData());
    next = rhs.getNext();
}

Datum::~Datum() {
    //delete [] next;
}

int Datum::getData() const {
    return data;
}

int & Datum::getData() {
    return data;
}

void Datum::setData(int value) {
    data = value;
}

Datum * Datum::getNext() const {
    return next;
}

void Datum::setNext(Datum &rhs) {
    next = &rhs;
}

void Datum::setNextNull(){
    next = nullptr;
}