

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    //nRows (number of rows), nCols (number of columns), sr & sc (starting coordinates), er & ec (ending coordinates)
    
    if (sr == er && sc == ec) return true;
    maze[sr][sc] = '#';
    

     
            if (maze[sr - 1][sc] == '.' && pathExists(maze, nRows, nCols, sr-1, sc, er, ec) == true){ //check that NORTH is open and there's a path
                return true;
            }
            
            if (maze[sr][sc + 1] == '.' && pathExists(maze, nRows, nCols, sr, sc+1, er, ec) == true ){ //check EAST
                return true;
            }
            
            if (maze[sr + 1][sc] == '.' && pathExists(maze, nRows, nCols, sr+1, sc, er, ec) == true){ //check SOUTH
                return true;
            }
            
            if (maze[sr][sc - 1] == '.' && pathExists(maze, nRows, nCols, sr, sc-1, er, ec) == true){ //check WEST
                return true;
            }
    
    
    return false;
}
        

