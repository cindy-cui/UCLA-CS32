
#include "Sequence.h"
  #include <iostream>
  #include <cassert>
  using namespace std;

  int main()
  {
     
      Sequence x;
      //test empty
      assert(x.empty() == true);
      
      assert(x.insert(0, 0) == 0);
      assert(x.empty() == false);
      
      //test first insert
      assert(x.insert(1,1) == 1);
      ItemType b;
      assert(x.get(1,b) == true && b == 1);
      assert(x.insert(2,2) == 2);
      assert(x.insert(3,3) == 3);
      assert(x.insert(4,4) == 4);
      assert(x.insert(5,5) == 5);

      assert(x.insert(-10, 4) == -1);
      assert(x.insert(100000,5) == -1);
      
      
      //test second insert
      assert(x.insert(10) == 6);
      assert(x.size() == 7);
      
      //test erase
      
      assert(x.erase(0) == true);
      assert(x.size() == 6);
      assert(x.erase(10) == false);
      assert(x.erase(-5) == false);
      
      ItemType a;
      assert(x.get(0,a) == true && a == 1);
      
      //test remove
      assert(x.remove(5) == 1);
      assert(x.size() == 5);
      assert(x.remove(123012) == 0);
      
      //test set
      assert(x.set(0, 15)== true);
      assert(x.get(0, a) == true && a == 15);
      assert(x.set(-3, 10) == false);
      assert(x.set(50, 10) == false);
      
      //test find
      assert(x.find(15) == 0);
      assert(x.find(123123) == -1);
      
      Sequence y;
      for (int i = 0; i < 10; i++){
          y.insert(0, 10);
      }
      
      y.swap(x);
      assert(x.size() == 10);
      assert(y.size() == 5);

      cout <<"passed all tests" << endl; 
  }



