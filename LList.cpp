#include <iostream>
#include "LList.h"

using namespace std;

LList::LList(){
    head = tail = current = nullptr;
    length = 0;
}

LList::LList(int arr[], int size) {
    if(size <= 0) {
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
    if(index < 0 || index > length) {
        cout << "Invalid index ";
        return;
    }
    current = head;
    //inserting at head
    if(index == 0) {
        Datum *ins = new Datum(value);
        ins->setNext(*(current));
        head = ins;
        length++;
        return;
    }  

    for(int i = 0; i < index - 1; i++) {
        current = current->getNext();
    } //current is now equal to index - 1
    
    Datum *ins = new Datum(*(current));
    ins->setData(value); 
    current->setNext(*ins); 
    
    if(index == length) {
        tail = ins;
    }

    length++;
    return;
}

int LList::remove(int index) {
    current = head;
    if(index >= length){
        index = length-1;
        for(int i = 0; i < index; i++) {
            current = current->getNext();
        }
        Datum *temp = current->getNext();
        int data = temp->getData();
        delete temp;
        tail = current;
        length --;
    }
    if(index <= 0){
        index = 0;
        Datum *temp = head;
        int data = temp->getData();
        head = current->getNext();
        delete temp;
        length --;
        return data;
    }
    else{
        for(int i = 0; i < index; i++) {
            current = current->getNext();
        } //current is now equal to index - 1
        int data = current->getData();
        current->setNext(*current->getNext());
        return data;
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
    if(index < 0) {
        return head->getData();
    }
    else if(index >= length) {
        return tail->getData();
    }
    
    Datum * temp = new Datum(*(head));
    for(int i = 0; i < index; i++) {
        temp = temp->getNext();
    }
        
    return temp->getData();
}

int & LList::operator[](int index) {
    if(index < 0) {
        return head->getData();
    }
    else if(index >= length) {
        return tail->getData();
    }
    
    current = head;
    for(int i = 0; i < index; i++) {
        current = current->getNext();
    }
    
    return current->getData();
}

int LList::indexOf(int value) const {
    Datum * temp = new Datum(*(head));
    for(int i = 0; i<length; i++){
        if(temp->getData() == value){
            delete temp;
            return i;
        }
        temp = temp->getNext();
    }
    delete temp;
    return -1;
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
    bool result(true);
    
    if(length == rhs.length){
        Datum  * temp = head; 
        for(int i = 0; i<length; i++){
            if(temp->getData() != rhs[i]){
                result = false;
            }
            temp = temp->getNext();
        }
       
    }
    else{
        result = false;
    }
    return result;

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