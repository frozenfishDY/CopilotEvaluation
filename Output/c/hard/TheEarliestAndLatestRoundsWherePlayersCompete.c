/**https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/ */
//There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n based on their initial standing position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).
//The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row competes against the ith player from the end of the row, and the winner advances to the next round. When the number of players is odd for the current round, the player in the middle automatically advances to the next round.
//For example, if the row consists of players 1, 2, 4, 6, 7
//Player 1 competes against player 7.
//Player 2 competes against player 6.
//Player 4 automatically advances to the next round.
//After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).
//The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete against each other. If any two other players compete against each other, either of them might win, and thus you may choose the outcome of this round.
//Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and the latest possible round number in which these two players will compete against each other, respectively.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* earliestAndLatest(int n, int firstPlayer, int secondPlayer, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr13[i] = 0;
    }
    int* arr14 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr14[i] = 0;
    }
    int* arr15

}

    