#include "ScoreList.h"
#include "Sequence.h"
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;

ScoreList:: ScoreList (){
    numScores = 0; 
}

bool ScoreList:: add(unsigned long score){
    if (score >= 0 && score <= 100 && numScores < DEFAULT_MAX_ITEMS){ //check validity
        if (scores.insert(numScores, score)!= -1){ //add to end of list
            numScores++; //increment number of scores
            return true;
        }
    }
    return false;
}


bool ScoreList:: remove(unsigned long score){
    if (scores.find(score) != -1 ){ //find smallest occurrence p of score
        if( scores.erase(scores.find(score)) == true){ //remove item at this position
            numScores--; //decrement score counter
            return true;
        }
    }
    return false;
}

int ScoreList:: size() const{
    return numScores; 
} // Return the number of scores in the list.

unsigned long ScoreList:: minimum() const{
    if (numScores == 0) return NO_SCORE;
    unsigned long min;
    scores.get(0, min); //put 0th element in min
    unsigned long holder;
    for (int i = 0; i < scores.size(); i++){
        scores.get(i, holder);
        if (holder < min) min = holder;
    }
    return min;
}
  // Return the lowest-valued score in the score list.  If the list is
  // empty, return NO_SCORE.



unsigned long ScoreList:: maximum() const{
    if (numScores == 0) return NO_SCORE;
    unsigned long max;
    scores.get(0, max); //put 0th element in min
    unsigned long holder;
    for (int i = 0; i < scores.size(); i++){
        scores.get(i, holder);
        if (holder > max) max = holder;
    }
    return max;
}
  // Return the highest-valued score in the score list.  If the list is
  // empty, return NO_SCORE.




