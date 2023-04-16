/**https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/ */
//You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.
//In one operation you can choose any subarray from initial and increment each value by one.
//Return the minimum number of operations to form a target array from initial.
//The test cases are generated so that the answer fits in a 32-bit integer.


int minNumberOperations(int* target, int targetSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr13[i] = 0;
    }

}

    