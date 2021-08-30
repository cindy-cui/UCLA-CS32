
#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

// CONSTRUCTOR

Sequence::Sequence()
{
    m_size = 0;
    head = new Node; //create dummy node
    head->next = head;
    head->prev = head;
}

// DESTRUCTOR

Sequence:: ~Sequence (){
    Node*f = head->next; //start with index 0
    while (f!= head){
        Node*n = f->next;
        delete f; //delete node
        f = n;
    }
   delete head; //delete the dummy node
}

// COPY CONSTRUCTOR

Sequence:: Sequence (const Sequence& old){
    m_size = 0;
    head = new Node; //initialize new sequence
    head->next = head;
    head->prev = head;
    
    if (old.size() != 0){
        Node *m = old.head->next; //have pointer loop through old
        for (int i = 0; i < old.size(); i++){
            this->insert(i, m->value); //copy value over
            m = m-> next; // move to next
        }
    }
  
}

// ASSIGNMENT OPERATOR

Sequence& Sequence:: operator = (const Sequence& old) {
    if (&old == this) return *this;
    m_size = 0;
    head = new Node; //initialize new sequence
    head->next = head;
    head->prev = head;
    
    
    Node*f = head->next;
    
    if(this->size() > 0){
        while (f!= head){ //have pointer loop through sequence
            Node*n = f->next;
            delete f; //delete all nodes in current sequence
            f = n;
        }
    }
    
    if (old.size() != 0){
        Node *m = old.head->next; //pointer to loop through old
        for (int i = 0; i < old.size(); i++){
            this->insert(i, m->value); //copy value over
            m = m-> next; // move to next
        }
    }

    return *this; //return sequence
}


// 1ST INSERT FUNCTION

int Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos > size() ) //no default max size anymore
    return -1;
    if (pos == 0){ //check if inserting at front
        insertAfter(head, value);
        m_size++; //increment size
        return 0; 
    }
    
    Node* z;
    getBefore(pos, z); // sets z as a pointer to the node before pos
    insertAfter(z, value); // insert value after the node z points to
    
    m_size++; //increment size
    return pos;
}

// 2ND INSERT FUNCTION

int Sequence::insert(const ItemType& value)
{
    int p = -1;
    if (size() == 0){ //if sequence is empty
        insertAfter(head, value); //insert directly after head
        m_size++;
        return 0;
    }
    
    int counter = 0;
    for (Node*f = head->next; f!= head; f = f->next){ //loop to move p thru the nodes
        if (value <= f->value) {//value at this position is >= value & value is less than current min
            p = counter;
            break; 
        }
        counter++;
    }
    
    if (p == -1) p = size();
    Node* temp;
    getBefore(p, temp); //have temp point to node before position p
    insertAfter(temp, value); //insert into position p
    m_size++;
    return p;
}
     
// ERASE FUNCTION

bool Sequence::erase(int pos)
{
    if (pos < 0  ||  pos >= size()) //check valid size
    return false;
   
    Node* prior;
    getBefore(pos, prior); //gets the node before pos
    
    Node* x;
    x = prior->next; //node at position pos
    
    x->next->prev = prior; //move node after pos's prev pointer
    prior->next = x->next;
    delete x;
   x = nullptr;
    
    m_size--; //decrement size
    return true;
}

// REMOVE FUNCTION

int Sequence::remove(const ItemType& value)
{
    int erased = 0;
    
    int counter = 0;
    for (Node*p = head; p!= head->prev ; p = p->next){ //loop through sequence
        if(p->next->value == value){ //check value
            erase(counter); //erase if value matches
            erased++;
            counter--; //decrement counter for index number
            p = p->prev; //move pointer back
        }
        counter++;
    }
    return erased;
}

// GET FUNCTION
     
bool Sequence ::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= size())
        return false;
   
    
    int counter = 0;
    for (Node*p = head->next; p!= head; p = p->next){ //loop to move p thru the nodes
        if (counter == pos) {
            value = p->value; //set value parameter
            return true;
        }
        counter++;
    }
    return false;
}

// SET FUNCTION

bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= size()) //check valid size
        return false;

    Node* temp;
    getBefore(pos, temp); //get the node before position
    temp->next->value = value; //set the value
    return true;
}

// FIND FUNCTION

int Sequence::find(const ItemType& value) const
{
    int counter = 0;
    for (Node*f = head->next; f!= head; f = f->next){ //loop to move f thru the nodes
        if (f->value == value) { // value found
            return counter;
        }
        counter++;
    }
    return -1;
}

// SWAP FUNCTION

void Sequence::swap(Sequence& other)
{
      // Swap heads' prev's next pointer
    
    head->prev->next = other.head;
    other.head->prev->next = head;

    //swap heads' nexts' pointers
    Node* temp = head->next;
    Node* temp2 = other.head->next; //temp variables to hold pointers to nexts'
    head->next = temp2;
    other.head->next = temp;
    
    //swap nexts' previous pointers
    temp->prev = other.head;
    Node* temp3 = head->prev; //temp variable for head's prev
    head->prev = other.head->prev;
    other.head->prev = temp3;
    
      // Swap sizes

    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}

//PRIVATE MEMBER FUNCTIONS


void Sequence::insertAfter(Node* x, ItemType value){
    //node x is one node before the position we want to insert at
    
    Node* temp = new Node;
    temp-> value = value; //put value into temp node
    temp->next = x->next; //connect temp to next
    x-> next = temp; //connect x to temp
    temp->prev = x;

    temp->next->prev = temp;

}


void Sequence:: getBefore(int pos, Node*& change){
    int counter = 1; //counter to keep track of position
    //1 because we're looking for the node before pos and not at pos
    if (pos == 0) {
        change = head; //head is the node before element 0 (dummy node)
        return;
    }
    
    for (Node*p = head->next; p!= head; p = p->next){ //loop to move p thru the nodes
        if (counter == pos) {
            change = p;
            return;
        }
        counter++;
    }
}




//NON MEMBER FUNCTIONS

// SUBSEQUENCE FUNCTION

int subsequence(const Sequence& seq1, const Sequence& seq2){
    if(seq1.size() == 0 || seq2.size() == 0) return -1; //if either sequence is empty
    if(seq2.size() > seq1.size()) return -1; //if size of seq 2 is greater than seq 1
    
    ItemType value2; //to hold the value of seq2's element
    ItemType value1; //to hold the value of seq1's element
    int counter = 0;
    for (int j = 0; j < seq1.size() - seq2.size() + 1; j++){ //loop thru seq 1 (for starting point)
        for (int i = 0; i < seq2.size(); i++){ //loop thru seq2
            seq2.get(i, value2); //get value at index i
            seq1.get(j+i, value1); //get value of 'starting point' in seq1 where we're looking for seq2
            
            if (value1 != value2){
                counter = 0;
                break; //break out of loop
            }
            counter++; //loop continues and counter increments if match
        }
        
        if (counter == seq2.size()) return j;
    }
    return -1;
}


// INTERLEAVE FUNCTION

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result){

    if(seq1.size() == 0 && seq2.size() == 0){
        if (result.size() != 0){ //if result is not empty
            while(result.size() > 0)
                result.erase(0);  //erase all pre existing elements
        }
        
        return; //if both are empty

    }
    
    if (seq1.size() == 0){ //check if seq1 is empty
        if (result.size() != 0){ //if result is not empty
            while(result.size() > 0)
                result.erase(0);  //erase all pre existing elements
        }

        result = seq2;
        return;
    }
    if(seq2.size() == 0){ //check if seq2 is empty
        if (result.size() != 0){ //if result is not empty
            while(result.size() > 0)
                result.erase(0);  //erase all pre existing elements
        }

        result = seq1;
        return;
    }
    
  
    
    Sequence  a = seq1; //make copies of both sequences
    Sequence  b = seq2;
     
    if (result.size() != 0){ //if result is not empty
        while(result.size() > 0)
            result.erase(0);  //erase all pre existing elements
    }

    
    int addedFromA = 0; //keep track of how many elements were added from each seq
    int addedFromB = 0;
    int lastIndex = 0; //keep track of the index in result
    ItemType valueOfElement; //to hold values retrieved

    for (int i = 0; i < (a.size() + b.size()); i++){ //loop to insert into result
        if (addedFromA == a.size() || addedFromB == b.size()){ //if finished adding from one seq
            break; //break out of for loop
        }
        if (i%2 == 0){ //even numbers add from seq1
            a.get(addedFromA, valueOfElement); //get the value at pos
            result.insert(i, valueOfElement);
            addedFromA++;
        }
        else{ //odd numbers add from seq2
            b.get(addedFromB, valueOfElement);
            result.insert(i, valueOfElement);
            addedFromB++;
        }
        lastIndex = i;
    }
    
    //to account for remaining elements
    if(b.size() == a.size()){ //last element
        b.get(addedFromB, valueOfElement);
        result.insert(lastIndex +1, valueOfElement);
        addedFromB++;
    }
    
    
    if (b.size() > a.size()){ //remaining elements if b > a
        for (int i = lastIndex+1 ; i < (a.size() + b.size()); i++){ //start with index
            b.get(addedFromB, valueOfElement); //get next value in B
            result.insert(i, valueOfElement); //insert into next position of result
            addedFromB++;
        }
    }
    
    else if (a.size() > b.size()){ //remaining elements if a > b
        for (int i = lastIndex+1 ; i < (a.size() + b.size()); i++){ //start with index
            a.get(addedFromA, valueOfElement);
            result.insert(i, valueOfElement);
            addedFromA++; 
        }
    }
    
    
}
