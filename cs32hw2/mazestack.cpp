#include <string>
#include <stack>
#include <iostream>
using namespace std;


bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);


int main() {
   
    
}

class Coord
      {
        public:
          Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
          int r() const { return m_row; }
          int c() const { return m_col; }
        private:
          int m_row;
          int m_col;
      };


bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    //nRows (number of rows), nCols (number of columns), sr & sc (starting coordinates), er & ec (ending coordinates)
    
    stack <Coord> coordinates; //create a stack of coordinates
    Coord starting (sr, sc); //create coordinate for starting position
    Coord ending (er, ec); //create coordinate for ending position
    
    coordinates.push(starting); //push starting coordinate onto stack
    maze[sr][sc] = '#'; //mark starting point as discovered
    
    
    while (coordinates.empty() == false){ //while the stack is not empty
        Coord topOfStack = coordinates.top();
        maze[sr][sc] = '#'; 
        coordinates.pop(); //kill top value
        
        if (topOfStack.r()== er && topOfStack.c() == ec) return true; //reached end of maze
        else{
            if (maze[topOfStack.r() - 1][topOfStack.c()] == '.' ){ //check that NORTH is unencountered and open
                // (r-1, c)
                Coord n (topOfStack.r() - 1, topOfStack.c()); //coordinate with north position
                coordinates.push(n); //push north spot onto stack
                maze[topOfStack.r() - 1][topOfStack.c()] = '#'; //mark position as discovered
            }
            
            if (maze[topOfStack.r()][topOfStack.c() + 1] == '.' ){ //check EAST
                // (r, c+1)
                Coord e (topOfStack.r(), topOfStack.c() + 1);
                coordinates.push(e);
                maze[topOfStack.r()][topOfStack.c() + 1] = '#';
            }
            
            if (maze[topOfStack.r() + 1][topOfStack.c()] == '.' ){ //check SOUTH
                // (r+1, c)
                Coord s (topOfStack.r() + 1, topOfStack.c());
                coordinates.push(s);
                maze[topOfStack.r() + 1][topOfStack.c()] = '#';
            }
            
            if (maze[topOfStack.r()][topOfStack.c() - 1] == '.' ){ //check WEST
                // (r, c-1)
                Coord w (topOfStack.r(), topOfStack.c() - 1);
                coordinates.push(w);
                maze[topOfStack.r()][topOfStack.c() - 1] = '#';
            }
        }
        
    }
    
    return false;
    
}
        

