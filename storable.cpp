#ifndef storable_cpp
#define storable_cpp

/*include custom headers.*/

#include "serializable.cpp"
/*include standard cpp headers*/

#include <string>
#include <iostream>
using namespace std;

/*
    Storable is a class which can be stored in a file.
    Anything which is storable must have 'recordId'(used as a unique key)
    it is derived from 'serializable'.Anything which is 'storable' must be
    'serializable'(must have 'toString' method)
*/

class Storable : public Serializable
{
protected:
    /*Unique recordId which acts as a primary key to find data.*/
    /*This property is protected, so only derived class can access it directly*/

    long recordId;

public:
    /*
        constructor:
        input: recordId
    */
    Storable(long recordId)
    {
        this->recordId = recordId;
    }
    long getRecordId() const
    {
        return this->recordId;
    }

    /* pure virtual function.*/
    /* Every subclass of this class must provide a suitable way to set 'this' object from 'Storable * s' */
    /* This is similar to copy constructor.*/

    virtual void setDataFrom(Storable *s) = 0;

    /* Friend declaration */
    /* Table and Database can access private member of this class.*/
    /* Table class : It sets 'recordId' of object inside 'addNewRecord' method.*/
    /* Database class: It sets 'recordId' of object inside 'addNewRecord' method.*/

    template <class T>
    friend class Table;
    friend class Database;
};

#endif