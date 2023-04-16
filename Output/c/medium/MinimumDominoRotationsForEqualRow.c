/**https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/ */
//In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
//We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
//Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
//If it cannot be done, return -1.


int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize){
    int* hash = (int*)malloc(sizeof(int) * 7);
    for(int i = 0; i < 7; i++){
        hash[i] = 0;
    }
    for(int i = 0; i < topsSize; i++){
        hash[tops[i]]++;
    }
    for(int i = 0; i < bottomsSize; i++){
        hash[bottoms[i]]++;
    }
    int max = -1;
    int maxIndex = -1;
    for(int i = 0; i < 7; i++){
        if(hash[i] >= max){
            max = hash[i];
            maxIndex = i;
        }
    }
    int topCount = 0;
    int bottomCount = 0;
    for(int i = 0; i < topsSize; i++){
        if(tops[i] != maxIndex && bottoms[i] != maxIndex){
            return -1;
        }
        if(tops[i] != maxIndex){
            topCount++;
        }
        if(bottoms[i] != maxIndex){
            bottomCount++;
        }
    }
    return topCount < bottomCount ? topCount : bottomCount;

}

    