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

LList::LList(const LList &rhs) {
    head = current = tail = rhs.head;
    length = rhs.size();
    for(int i = 1; i < length; i++) {
        Datum *temp = current->getNext();
        current->setNext(*temp);
        current = tail = temp; 
    }
}

LList::~LList() {
    clear();
}

const LList LList::operator+(const LList &rhs) const {
    LList temp(*this);
    (temp.tail)->setNext(*(rhs.head));
    temp.tail = rhs.tail;
    temp.length = size() + rhs.size();
    return temp;
}

const LList LList::operator=(const LList &rhs) {
    clear();
    *this = LList(rhs);
    return *this;
}

void LList::insert(int index, int value) {
    if(index < 0 || index >= length) {
        cout << "Invalid index";
        return;
    }

    for(int i = 0; i < index - 1; i++) {
        current = current->getNext();
    } //current is now equal to index - 1
    Datum *ins = new Datum(*(current)); //ins and current are pointing to the same thing
    ins->setData(value); //resets ins to the correct value
    current->setNext(*ins); //sets current's next to be ins
    return;
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

ostream & operator<<(ostream &lhs, const LList &rhs) {
    for(int i = 0; i < rhs.size(); i++) {
        lhs << rhs[i] << " ";
    }
    return lhs;
}

istream & operator>>(istream &lhs, LList &rhs) {
    for(int i = 0; i < rhs.size(); i++) {
        lhs >> rhs[i];
    }
    return lhs;
}