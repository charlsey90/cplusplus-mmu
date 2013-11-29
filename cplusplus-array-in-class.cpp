
/* Copyright Charles Teh 2013
 *
 * feel free to use explore and use this code
 * for your understanding and projects :)
 * Email: charlsey90@gmail.com
 */
 
/* Arrays inside a class
 *
 * I've been attempting to declare arrays in class. Not a problem during attribute declaration,
 * but I'm unable to initialize the arrays with a default value inside a constructor.
 * Below is the method I have written to replace the default constructor features with a function.
 * Feel free to experiment around.
 */

#include <iostream>

using namespace std;

class Item {

private:
    int id;             // normal attribute
    int multiInt[4];    // multi integer variable using array
    char multiChar[4];  // multi character variable using array

public:

    /*
     * this is how I intialize the array for int and char, since
     * the constructors are not capable of initializing array as I'm not too sure.
     * let me know if there's a better way.
     */

    Item( int id = 1):id(id) // Note that I am unable to
                             // declare the constructor with a
                             // default value for multiInt & multiChar.
                             // The values are declared inside the
                             // Item constructor function instead.
    {

         
        for (int i = 0; i < getMultiIntSize(); i++ )
            multiInt[i] = i;

        for (int i = 0; i < getMultiCharSize(); i++ )
            multiChar[i] = 'N';
    };

    /*
     * getMultiIntSize() and getMultiCharSize() is a function to determine the array size
     * since size() does not work in classes.
     */
     
    int getMultiIntSize()
    {
        int size;
        size = sizeof multiInt / sizeof(int);
        return size;
    }

    int getMultiCharSize()
    {
        char size;
        size = sizeof multiChar / sizeof(char);
        return size;
    }
    
    /*
     * getID() returns the id inside the Class.
     *
     */

    int getID(){ return id; }


    /*
     * printMulti() prints out the variables inside the array for integers and
     * characters using a FOR loop. the getMultiIntSize() and getMultiCharSize()
     * is particularly useful as I do not need to redeclare the sizes again
     * inside the FOR loop.
     */

    void printMulti()
    {
        cout << "ID " << getID() << " Multi Integer Array: ";

        for (int i = 0; i < getMultiIntSize(); i++ )
        {
            cout << multiInt[i];

            if (i != getMultiIntSize()-1)
                cout << ",";
        }

        cout << endl;

        cout << "ID " << getID() << " Multi Character Array: ";

        for (int i = 0; i < getMultiCharSize(); i++ )
        {
            cout << multiChar[i];

            if (i != getMultiCharSize()-1)
                cout << ",";
        }


    }
    
    /*
     * printItem() prints out everything including the ID variable - a proof of concept
     * showing that these functions can be nested inside a functin.
     */

    void printItem()
    {
        cout <<"ID: " << id << endl;
        printMulti();

        cout << endl;

    }
};

int main()
{
    Item* i = new Item;

    i->printItem();
    return 0;
}
