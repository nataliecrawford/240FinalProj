#include "LList.h"
#include <iostream>

using namespace std;

LList::LList(){

}

LList::LList(int arr[], int size) {

}

LList::LList(const LList &list) {

}

LList::~LList() {
    
}

const LList LList::operator+(const LList &rhs) const {

}

const LList LList::operator=(const LList &rhs) {

}

void LList::insert(int index, int value) {

}

int LList::remove(int index) {
    if(index > length){
        index = length-1;
    }
    if(index <length){
        index = 0;
    }



}

bool LList::contains(int value) const {
    Datum * temp = head;
    for(int i = 0; i<length; i++){
        if(temp->getData() == value){
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

int LList::operator[](int index) const {

}

int & LList::operator[](int index) {

}

int LList::indexOf(int value) const {
    Datum * temp = head;
    for(int i = 0; i<length; i++){
        if(temp->getData() == value){
            return i;
        }
        temp = temp->getNext();
    }

}

bool LList::isEmpty() const {
    return length == 0;

}

int LList::size() const {
    return length;
}

void LList::clear() {
    while(head->getNext() != nullptr){
        current = head;
        head = head->getNext();
        delete current;
    }
    length = 0;
}

bool LList::operator==(const LList &rhs) const {

}