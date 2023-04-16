/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//Each character is decoded as one digit (0 - 9).
//No two characters can map to the same digit.
//Each words[i] and result are decoded as one number without leading zeros.
//Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.


bool isSolvable(char ** words, int wordsSize, char * result){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr[i] = -1;
    }
    int* arr2 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr2[i] = -1;
    }
    int* arr3 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr3[i] = -1;
    }
    int* arr4 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr4[i] = -1;
    }
    int* arr5 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr5[i] = -1;
    }
    int* arr6 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr6[i] = -1;
    }
    int* arr7 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr7[i] = -1;
    }
    int* arr8 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr8[i] = -1;
    }
    int* arr9 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr9[i] = -1;
    }
    int* arr10 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr10[i] = -1;
    }
    int* arr11 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr11[i] = -1;
    }
    int* arr12 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr12[i] = -1;
    }
    int* arr13 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr13[i] = -1;
    }
    int* arr14 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr = -1;
        

}

    