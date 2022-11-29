#include <iostream>
#include <cstdlib>
#include "Datum.h"

using namespace std;

Datum::Datum() : data(0.0), next(NULL) {
    setData(0.0);
    setNext(NULL);
}

Datum::Datum(float value) : data(value), next(NULL) {
    setData(value);
    setNext(NULL);
}

Datum::Datum(const Datum &rhs) : data(rhs.getData()), next(rhs.getNext()) {
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