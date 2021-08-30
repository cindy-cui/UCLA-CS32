
#ifndef Game_h
#define Game_h

#include <stdio.h>
#include "City.h"

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();

        // Mutators
    void play();

  private:
    City* m_city;
};
#endif /* Game_hpp */
