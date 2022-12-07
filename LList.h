/**
 * @file LList.h
 * @author natalie crawford, mia silver
 * @brief 
 * @version 0.1
 * @date 2022-12-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include "Datum.h"

using namespace std;

class LList {

    /**
     * @brief Prints all elements of the LList in one row delimited by one space. Cascade-capable operation.
     * 
     * @param lhs the ostream printing the linked list
     * @param rhs the linked list being printed
     * @return ostream& the ostream value to be printed
     */
    friend ostream & operator<<(ostream &lhs, const LList &rhs);
    /**
     * @brief Obtain a value of stream to be appended to the end of the LList object. Cascade-capable operation.
     * 
     * @param lhs the istream obtaining the new value
     * @param rhs the linked list being appended
     * @return istream& the istream value to be appended
     */
    friend istream & operator>>(istream &lhs, LList &rhs);

    private:
        Datum *head;
        int length;

    public:
        /**
         * @brief Construct a new LList object
         */
        LList();

        /**
         * @brief Construct a new LList::LList object
         * 
         * @param arr the array of ints that becomes the data inside the linked list
         * @param size the size of the array/linked list
         */
        LList(int arr[], int size);
        
        /**
         * @brief Construct a new LList::LList object
         * 
         * @param rhs the Linked list object being copied into this linked list
         */
        LList(const LList &rhs);
        
        /**
         * @brief Destroy the LList::LList object
         */
        ~LList();


        /**
         * @brief Append two lists together. Cascade-capable operation
         * 
         * @param rhs the list being appended to the current linked list
         * @return const LList the new list that contains both linked lists
         */
        const LList operator+(const LList &rhs) const;
        
        /**
         * @brief Assigns the content of lhs with rhs. Cascade-capable operation.
         * 
         * @param rhs the list that contains the contents being assigned to lhs
         * @return const LList the new list
         */
        const LList operator=(const LList &rhs);


        /**
         * @brief Inserts value at the position index.
         * Adds to the beginning or end if index is out of bounds.
         * 
         * @param index the index where the new value is being added
         * @param value the value to place at the given index
         */
        void insert(int index, int value);
        
        /**
         * @brief Removes the item at the index and return the value of the removed item.
         * Removes from the beginning or end if index is out of bounds.
         * 
         * @param index the index being removed
         * @return int the value at the index being removed
         */
        int remove(int index);
        
        /**
         * @brief Determines if a given value is in the linked list.
         * 
         * @param value the value to check for
         * @return true if the value is in the linked list
         * @return false if the value is not in the linked list
         */
        bool contains(int value) const;
        

        /**
         * @brief Returns the value of the array at the given index.
         * Returns either the beginning or end if index is out of bounds.
         * 
         * @param index the index to get information from
         * @return int the value found at that index
         */
        int operator[](int index) const;
        
        /**
         * @brief Sets the value at a given index.
         * Sets either from the beginning or end if index is out of bounds.
         * 
         * @param index the index at which to set information
         * @return int& the value found at that index
         */
        int & operator[](int index);
        
        /**
         * @brief Returns the index of the first occurrence of a given value.
         * Returns -1 if not found at all.
         * 
         * @param value the value to be found in the list
         * @return int the index at which that value is found.
         */
        int indexOf(int value) const;
        
        /**
         * @brief Checks if the list is empty or not
         * 
         * @return true if the list is empty
         * @return false if the list is not empty
         */
        bool isEmpty() const;
        
        /**
         * @brief Returns the size of the list
         * 
         * @return int the size of the list
         */
        int size() const;
        
        /**
         * @brief Empties the linked list
         */
        void clear();

        /**
         * @brief compares two linked lists to determine if they are identical
         * 
         * @param rhs the linked list being compared
         * @return true if the linked lists are identical
         * @return false if the linked lists are not identical
         */
        bool operator==(const LList &rhs) const;

};

#endif //LLIST.H