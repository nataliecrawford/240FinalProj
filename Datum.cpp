#include <iostream>
#include <cstdlib>
#include "Datum.h"

using namespace std;

Datum::Datum() {
    setData(0.0);
    setNext(NULL);
}

Datum::Datum(float value) {
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

float Datum::getData() const {
    return data;
}

void Datum::setData(float value) {
    data = value;
}

Datum * Datum::getNext() const {
    return next;
}

void Datum::setNext(Datum &link) {
    next = link
}