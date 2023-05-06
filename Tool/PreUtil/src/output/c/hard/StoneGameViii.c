/**https://leetcode.com/problems/stone-game-viii/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//There are n stones arranged in a row. On each player's turn, while the number of stones is more than one, they will do the following:
//Choose an integer x > 1, and remove the leftmost x stones from the row.
//Add the sum of the removed stones' values to the player's score.
//Place a new stone, whose value is equal to that sum, on the left side of the row.
//The game stops when only one stone is left in the row.
//The score difference between Alice and Bob is (Alice's score - Bob's score). Alice's goal is to maximize the score difference, and Bob's goal is the minimize the score difference.
//Given an integer array stones of length n where stones[i] represents the value of the ith stone from the left, return the score difference between Alice and Bob if they both play optimally.


int stoneGameVIII(int* stones, int stonesSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*stonesSize);
    for(i=0;i<stonesSize;i++){
        arr13[i] = 0;
    }

}

    