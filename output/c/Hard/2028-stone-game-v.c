/**https://leetcode.com/problems/stone-game-v/ */
//There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
//In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.
//The game ends when there is only one stone remaining. Alice's is initially zero.
//Return the maximum score that Alice can obtain.


int stoneGameV(int* stoneValue, int stoneValueSize){
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

    