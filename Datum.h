/**
 * @file Datum.h
 * @author natalie crawford, mia silver
 * @brief the datum h file
 * @version 0.1
 * @date 2022-12-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DATUM_H
#define DATUM_H

#include <iostream>

using namespace std;

class Datum {
    public:
        /**
         * @brief Construct a new Datum object
         * 
         */
        Datum();
        
        /**
         * @brief Construct a new Datum object
         * 
         * @param value the value datum contains
         */
        Datum(int value = 0);
        
        /**
         * @brief Construct a new Datum object
         * 
         * @param rhs the datum that the new datum will be the same as
         */
        Datum(const Datum &rhs);
        
        /**
         * @brief Destroy the Datum object
         * 
         */
        ~Datum();

        /**
         * @brief Get the Data object
         * 
         * @return int the value of the datum
         */
        int getData() const;

        /**
         * @brief Get the Data object
         * 
         * @return int& the memory address of the datum value
         */
        int & getData();

        /**
         * @brief Set the Data object
         * 
         * @param value what data becomes
         */
        void setData(int value);

        /**
         * @brief Get the Next object
         * 
         * @return Datum* pointer to the next datum
         */
        Datum * getNext() const;

        /**
         * @brief Set the Next object
         * 
         * @param rhs sets the next to the rhs
         */
        void setNext(Datum &rhs);
        
        /**
         * @brief Set the Next Null object
         * 
         * @return * void 
         */
        void setNextNull();

    private:
        int data;
        Datum *next;
};

#endif //DATUM.H