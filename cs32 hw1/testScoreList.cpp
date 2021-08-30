#include "Sequence.h"
#include "ScoreList.h"
#include <iostream>
#include <cassert>
using namespace std;

int main (){
    
    
    ScoreList a;
    
    //test add
    assert (a.add(80) == true);
    assert (a.add(90) == true);
    assert (a.add(85) == true);
    assert (a.add(100) == true);
    assert (a.add(-20) == false);
    assert (a.add(140) == false);
    assert(a.size() == 4);
    //80, 90, 85, 100
    
    
    //test remove
    assert(a.remove(80) == true);
    //90, 85, 100
    assert(a.remove(95) == false);
    
    //test minimum
    assert(a.minimum() == 85);
    //test maximum
    assert(a.maximum() == 100);
    
    cout <<"all tests passed" << endl; 
}


