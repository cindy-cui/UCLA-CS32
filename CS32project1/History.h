//
//  History.hpp
//  CS32project1
//
//  Created by Cindy Cui on 1/7/21.
//

#ifndef History_h
#define History_h

#include <stdio.h>
#include "globals.h"

class History
    {
      public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
        
    private:
        int n_rows;
        int n_cols;
        int r;
        int c;
        char grid[MAXROWS][MAXCOLS]; //creates a grid to record

        
        
    };


#endif /* History_hpp */
