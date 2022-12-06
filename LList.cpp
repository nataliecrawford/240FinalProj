#include <iostream>
#include "LList.h"

using namespace std;

LList::LList(){
    head = nullptr;
    length = 0;
}

LList::LList(int arr[], int size) {
    if(size <= 0) {
        head = nullptr;
        length = 0;
    }
    else {
        length = size;
        head = new Datum(arr[0]);
        Datum *current = head;
        for(int i = 1; i < length; i++) {
            Datum *temp = new Datum(arr[i]);
            current->setNext(*temp);
            current = temp;
        }
    }
}

LList::LList(const LList &rhs) {
    length = rhs.size();
    int arr[length];
    for(int i = 0; i < rhs.size(); i++) {
        arr[i] = rhs[i];
    }
    
    head = new Datum(arr[0]);
    Datum *current = head;
    for(int i = 1; i < length; i++) {
        Datum *temp = new Datum(arr[i]);
        current->setNext(*temp);
        current = temp;
    }
}

LList::~LList() {
    if(head != nullptr) {
        clear();
    }
}

const LList LList::operator+(const LList &rhs) const {
    Datum *current = head;
    int arr[length+ rhs.size()];
    for(int i = 0; i < length; i++) {
        arr[i] = current->getData();
        current = current->getNext();
    }
    
    for(int i = 0; i<rhs.size(); i++){
        arr[length + i] = rhs[i];
    }

    return LList(arr, length + rhs.size());
}

const LList LList::operator=(const LList &rhs) {
    clear();
    length = rhs.size();
    int arr[length];
    for(int i = 0; i < rhs.size(); i++) {
        arr[i] = rhs[i];
    }
    
    head = new Datum(arr[0]);
    Datum *current = head;
    for(int i = 1; i < length; i++) {
        Datum *temp = new Datum(arr[i]);
        current->setNext(*temp);
        current = temp;
    }
    return LList(arr, length);
}

void LList::insert(int index, int value) {
    Datum *current = head;
    //inserting at head
    if(index <= 0) {
        Datum *ins = new Datum(value);
        ins->setNext(*(current));
        head = ins;
        length++;
        return;
    }  

    //inserting at tail
    if(index >= length) {
        for(int i = 0; i < index - 1; i++) {
            current = current->getNext();
        } //current is now equal to index - 1
        Datum *ins = new Datum(*(current));
        ins->setData(value); 
        current->setNext(*ins); 
        length++;
        return;
    }

    //inserting in the middle
    for(int i = 0; i < index - 1; i++) {
        current = current->getNext();
    } //current is now equal to index - 1
    Datum *ins = new Datum(*(current));
    ins->setData(value); 
    current->setNext(*ins);
    length++;
    return;
}

int LList::remove(int index) {
    
    if (length <= 0){
        cout<<"cannot remove anything because nothing is in the linked list, size is <=0...";
        return -1;
    }
    
    Datum *current = head;
    if(index >= length){
        index = length-1;
        for(int i = 0; i < index-1; i++) {
            current = current->getNext();
        }
        Datum *temp = current->getNext();
        int data = temp->getData();
        current->setNextNull();
        delete temp;
        length --;
        return data;
    }
    if(index <= 0){
        index = 0;
        current = head;
        Datum *temp = new Datum(*head);
        int data = temp->getData();
        head = current->getNext();
        current = head;
        delete temp;
        length --;
        return data;
    }
    else {
        for(int i = 0; i < index - 1; i++) {
            current = current->getNext();
        } 
        Datum *del = current->getNext();
        int data = del->getData();
        current->setNext(*del->getNext());
        delete del;
        length--;
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
    if(head==nullptr){
        cout<<"empty";
        return 0;
    }
    if(index < 0) {
        return head->getData();
    }
    else if(index >= length) {
        index = length - 1;
    }
    
    Datum temp = *head;
    for(int i = 0; i < index; i++) {
        temp = *(temp.getNext());
    }
    int value = temp.getData();

    //delete temp;
    return value;
}

int & LList::operator[](int index) {
    if(head==nullptr){
        cout<<"empty";
        //return -1;
    }
    if(index < 0) {
        return head->getData();
    }
    else if(index >= length) {
        index = length - 1;
    }
    
    Datum *current = head;
    for(int i = 0; i < index; i++) {
        current = current->getNext();
    }
    
    return current->getData();
}

int LList::indexOf(int value) const {
    if(head==nullptr){
        //cout<<"empty";
        return -1;
    }
    Datum temp = *head;
    for(int i = 0; i<length; i++){
        if(temp.getData() == value){
            return i;
        }
        if(i <length-1){
            temp = *(temp.getNext());
        }
    }
    return -1;
}

bool LList::isEmpty() const {
    return length == 0;
}

int LList::size() const {
    return length;
}

void LList::clear() {
    if(head == nullptr) { //list is already empty
        return;
    }
    
    Datum *current = head;
    while(head->getNext() != nullptr) {
        current = head;
        head = head->getNext();
        delete current;
    }
    
    delete head;

    length = 0;
    return;
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
    rhs.insert(rhs.size(), 0);
    lhs >> rhs[rhs.size()];
    return lhs;
}