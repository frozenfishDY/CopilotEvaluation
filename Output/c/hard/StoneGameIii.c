/**https://leetcode.com/problems/stone-game-iii/ */
//Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
//Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.
//The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.
//The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.
//Assume Alice and Bob play optimally.
//Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.


char * stoneGameIII(int* stoneValue, int stoneValueSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr[i] = stoneValue[i];
    }
    int* arr2 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*stoneValueSize);
    for(i=0;i<stoneValueSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*stone

}

    