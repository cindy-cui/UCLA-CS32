
// Sequence.h

#ifndef Sequence_h
#define Sequence_h
#include <string> //if itemtype is modified to be a string

//using ItemType = unsigned long ;
using ItemType = std:: string; 

class Sequence
{
    
    
  public:
    Sequence();          // Create an empty sequence (i.e., one whose size() is 0).
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.
    
    Sequence (const Sequence& old); //copy constructor
    Sequence& operator = (const Sequence& old);  //assignment operator
    ~Sequence(); //destructor

    int insert(int pos, const ItemType& value);
    
    int insert(const ItemType& value);

    bool erase(int pos);

    int remove(const ItemType& value);
    
    bool get(int pos, ItemType& value) const;

    bool set(int pos, const ItemType& value);

    int find(const ItemType& value) const;

    void swap(Sequence& other);
    
  private:
    int      m_size;                     // number of items in the sequence
    
    struct Node { //private struct for nodes
        ItemType value;
        Node* next;
        Node* prev;
    };
    
    Node* head; //pointer to dummy node
    void insertAfter(Node* x, ItemType value);
    void getBefore (int pos, Node*& change);

    
    
};

// Inline implementations

inline
int Sequence::size() const
{
    return m_size;
}

inline
bool Sequence::empty() const
{
    return size() == 0;
}


//declaration of non member function


int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);


#endif

