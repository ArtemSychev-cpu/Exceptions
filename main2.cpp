#include <iostream>
#include <string>
#include <assert.h>
#include "IntegerArray.h"
#include "Bad_range.h"
#include "Bad_length.h"
#include<exception>
using namespace std;




int main()
{    
    ArrayInt array;
    
    try
    {
        ArrayInt array(10);
    }
    catch (Bad_length& e)
    {
        cout << e.what();
    }
    
    try
    {
        for (int index{ 0 }; index < 10; ++index)
            array[index] = index + 1;
    }
    catch (Bad_range& e)
    {
        cout << e.what();
    }

    try
    {
        array.resize(7);
    }
    catch (Bad_range& e)
    {
        cout << e.what();
    }
    
    try
    {
        array.insertBefore(15, 4);
    }
    catch (Bad_range& e)
    {
        cout << e.what();
    }
    
    try
    {
        array.remove(4);
    }
    catch (Bad_range& e)
    {
        cout << e.what();
    }
    catch (...)
    {
        cout << "ERROR" << endl;
    }
    
    array.insertAtEnd(34);
    array.insertAtBeginning(55);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*ArrayInt array;
    try
    {
        ArrayInt(10);
        for (int i{ 0 }; i < 10; ++i)
            array[i] = i + 1;
    }
    catch (const char* exception)
    {
        cout << "Exception:" << exception << endl;
    }
    try
    {
        

        void insertBefore(int value, int index);
        void remove(int index);
    }
    catch (ArrayInt& a)
    {
        a.Index();
    }
    catch (...)
    {
        cout << "Error" << endl;
   }*/




  return 0;
}