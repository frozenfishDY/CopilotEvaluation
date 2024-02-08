/**https://leetcode.com/problems/count-pairs-with-xor-in-a-range/ */
//Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs.
//A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high.


int countPairs(int* nums, int numsSize, int low, int high){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr13[i] = 0;
    }

}

    