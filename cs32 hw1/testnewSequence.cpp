
#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;


int main()
{
    

    //test 1st constructor
    Sequence s;
    //test 1st insert function
    assert(s.insert(0, 1) == 0);
    assert(s.insert(1, 1) == 1);
    assert(s.insert(20000, 1) == -1);
    assert(s.insert(-5, 2) == -1);
    
    assert(s.size() == 2);
    
    //test 2nd insert function
    assert(s.insert(20) != -1);
    assert(s.insert(10) != -1);
    assert(s.size() == 4);

    //test erase
    assert(s.erase(3) == true);
    assert(s.size() == 3);
    assert(s.erase(2000) == false);
    
    //test remove
    assert(s.remove(1) == 2);
    assert(s.size() == 1);
    assert(s.remove(102301) == 0);

    ItemType x = 190;
    ItemType y;
    //test set and get
    assert(s.set(0, x) == true);
    assert(s.get(0, y) == true);
    assert(y == 190);
    
    //test find
    assert(s.find(x) == 0);

    
    cout << "Passed all 1st constructor tests" << endl;
             
    
    //test 2nd constructor
    
    Sequence f(5);
    assert(f.insert(0,0)== 0);
    assert(f.insert(1, 1) == 1);
    assert (f.insert(2, 2) == 2);
    assert(f.insert(3, 3) == 3);
    assert(f.insert(4, 4) == 4);
    

    assert(f.insert(5, 5) == -1);
    assert(f.insert(5) == -1);
    
    s.swap(f);
    assert(s.size() == 5);
    ItemType e;
    assert(s.get(0, e) == true && e == 0);
    assert(s.get(4, e) == true && e == 4);
    //check max size swap
    assert(s.insert(5) == -1);
    
    cout << "Passed all 2nd constructor tests" << endl;

 
 
    
    //tester in spec
    Sequence a(1000);   // a can hold at most 1000 items
     Sequence b(5);      // b can hold at most 5 items
     Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
     ItemType v = 1.50;

       // No failures inserting 5 items into b
     for (int k = 0; k < 5; k++)
         assert(b.insert(v) != -1);

       // Failure if we try to insert a sixth item into b
     assert(b.insert(v) == -1);

       // When two Sequences' contents are swapped, their capacities are
       // swapped as well:
     a.swap(b);
     assert(a.insert(v) == -1  &&  b.insert(v) != -1);
    cout << "Passed all tests in spec" << endl; 
 
}



