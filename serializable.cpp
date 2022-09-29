/*standard cpp headers*/
#include <iostream>
using namespace std;

/*
 This is Serialisation class and it is abstract class. Any class derived from this class must implement 'toString' method
*/

class Serializable
{
public:
    /* pure virtual function */
    /* 'Serializable' class does not know what 'toString' method will do */
    /*it is the responsibility of derived class to implement this method */
    /*each class has its own 'toString' implementation. */

    virtual string toString() const = 0;
};