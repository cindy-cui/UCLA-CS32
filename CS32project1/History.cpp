#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;
#include "History.h"
#include "globals.h"


History :: History(int nRows, int nCols){
    n_rows = nRows;
    n_cols = nCols;
    for (int i = 0; i < n_rows; i++) //fill grid with .'s
        for (int j = 0; j < n_cols; j++)
            grid[i][j] = '.'; //0 times
    

}


bool History:: record(int r, int c){ //updates grid when preach is unsuccessful
    if (r > n_rows || c > n_cols){
        return false;
    }
    
    if (isalpha(grid[r-1][c-1]) && grid[r-1][c-1] != 'Z'){ //is an alphabetic letter alr
       grid[r-1][c-1]++; //increase 1 to move to next letter
   }
    
    if (grid[r-1][c-1] == '.'){
        grid[r-1][c-1] = 'A';
    }
    return true;
}


void History :: display()const{
    clearScreen();

    for (int y = 0; y < n_rows; y++) //displaying the grid
    {
        for (int z = 0; z < n_cols; z++){
            cout << grid[y][z];
        }
        cout << endl;
    }
    cout << endl;//empty line after the history grid

}
