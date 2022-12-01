#include <iostream>
#include "LList.h"

using namespace std;

LList::LList(){
    head = tail = current = nullptr;
    length = 0;
}

LList::LList(int arr[], int size) {
    if(length <= 0) {
        head = tail = current = nullptr;
        length = 0;
    }
    else {
        length = size;
        head = current = tail = new Datum(arr[0]);
        for(int i = 1; i < length; i++) {
            Datum *temp = new Datum(arr[i]);
            current->setNext(*temp);
            current = tail = temp; 
        }
    }
}

LList::LList(const LList &list) {
    head = current = tail = list.head;
    length = list.size();
    for(int i = 1; i < length; i++) {
        Datum *temp = current->getNext();
        current->setNext(*temp);
        current = tail = temp; 
    }
}

LList::~LList() {
    //TODO
}

const LList LList::operator+(const LList &rhs) const {

}

const LList LList::operator=(const LList &rhs) {

}

void LList::insert(int index, int value) {

}

int LList::remove(int index) {

}

bool LList::contains(int value) const {

}

int LList::operator[](int index) const {

}

int & LList::operator[](int index) {

}

int LList::indexOf(int value) const {

}

bool LList::isEmpty() const {

}

int LList::size() const {

}

void LList::clear() {

}

bool LList::operator==(const LList &rhs) const {

}