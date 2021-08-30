#include "Sequence.h"
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;


Sequence:: Sequence(){    // Create an empty sequence (i.e., one with no items)
    sizeOfArray = 0;
}

bool Sequence:: empty() const{  // Return true if the sequence is empty, otherwise false.
    if (sizeOfArray == 0){
        return true;
    }
    return false; 
}


int Sequence:: size() const{    // Return the number of items in the sequence.
    return sizeOfArray;
}


int Sequence :: insert(int pos, const ItemType& value){
    if (pos < 0) return -1;
    if (pos > size() || pos >= DEFAULT_MAX_ITEMS) return -1;
    
    if (pos == size()){ //pos is meant to be added to the end of the array
        seq[pos] = value;
        sizeOfArray++;
        return pos;
    }
    ItemType temp = seq[pos];
    ItemType temp2;
    seq[pos] = value;
    for (int i = pos+1; i < size() + 1; i++){
        temp2 = seq[i];
        seq[i] = temp;
        temp = temp2;
    }
    sizeOfArray++;
    return pos;
}

int Sequence:: insert(const ItemType& value){
    int p = size()-1; //smallest less than value
    if (size() == DEFAULT_MAX_ITEMS) return -1;
    if (size() == 0){
        insert(0, value);
        p = 0;
        return p;
    }
    
    bool changed = false;
    for (int i = 0; i < size(); i++){
        if (seq[i] >= value && seq[i] < seq[p] ){ //element i greater than value and less than the value at current p
            p = i;
            changed = true; //indicate that there's a valid item that satisfies
        }
    }
    if (p == size()-1 && seq[p] >= value) changed = true; // if the last element is the valid one
    
    if (changed == false) p = size(); // if no valid item, p is size()
    insert(p, value); //insert value into position p
    return p;
}


bool Sequence:: erase(int pos){
    if (pos < 0 || pos >= size()) return false;
    for (int i = pos; i < size()-1; i++){
        seq[i] = seq[i+1]; //shift all elements left
    }
    sizeOfArray --; //decrement size of array
    return true;
}


int Sequence:: remove(const ItemType& value){
    int removed = 0; //counter for removed items
    if (size() == 0) return 0;
    
    for (int i = 0; i < size(); i++){
        if (seq[i] == value){
            removed++; //increment counter
            erase(i); //erase item at i
            i--; 
        }
    }
    return removed;
}

 bool Sequence:: get(int pos, ItemType& value) const{
    if (pos < 0 || pos >= size()) return false;
    value = seq[pos];
    return true;
}


bool Sequence:: set(int pos, const ItemType& value){
    if (pos < 0 || pos >= size()) return false;
    seq[pos] = value;
    return true;
}

 int Sequence:: find(const ItemType& value) const{
    int p = 0;
    for (int i = 0; i < size(); i++){
        if (seq[i] == value){
            p = i;
            return p;
        }
    }
    p = -1;
    return p;
}


void Sequence:: swap(Sequence& other){
   
    int max = size();
    if (other.size() > max){
        max = other.size();//finding max of two sizes
    }
    ItemType temp; //to hold when swapping
    
    for (int j = 0; j < max; j++){
        temp = seq[j];
        seq[j] = other.seq[j]; //copy other's array into seq
        other.seq[j] = temp; //swap
    }
 
    
    int tempSize = size();
    sizeOfArray = other.size(); //copy size
    other.sizeOfArray = tempSize; //swap
    
}


