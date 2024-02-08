/**https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/ */
//You are given two 0-indexed integer arrays nums and multipliers of size n and m respectively, where n >= m.
//You begin with a score of 0. You want to perform exactly m operations. On the ith operation (0-indexed) you will:
//Choose one integer x from either the start or the end of the array nums.
//Add multipliers[i] * x to your score.
//Note that multipliers[0] corresponds to the first operation, multipliers[1] to the second operation, and so on.
//Remove x from nums.
//Return the maximum score after performing m operations.


int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = nums[i];
    }
    int* arr2 = (int*)malloc(sizeof(int)*multipliersSize);
    for(i=0;i<multipliersSize;i++){
        arr2[i] = multipliers[i];
    }
    int max = 0;
    for(i=0;i<multipliersSize;i++){
        if(arr2[i] > max){
            max = arr2[i];
        }
    }
    int* arr3 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr3[i] = 0;
    }
    for(i=0;i<multipliersSize;i++){
        for(j=0;j<numsSize;j++){
            if(arr2[i] == arr[j]){
                arr3[j] = 1;
            }
        }
    }
    int* arr4 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr4[i] = 0;
    }
    for(i=0;i<numsSize;i++){
        if(arr3[i] == 1){
            arr4[i] = arr[i];
        }
    }
    int* arr5 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr5[i] = 0;
    }
    int count = 0;
    for(i=0;i<numsSize;i++){
        if(arr4[i] != 0){
            arr5[count] = arr4[i];
            count++;
        }
    }
    int* arr6 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr6[i] = 0;
    }
    for(i=0;i<numsSize;i++){
        if(arr5[i] != 0){
            arr6[i] = arr5[i] * arr2[i];
        }
    }
    int sum = 0;
    for(i=0;i<numsSize;i++){
        sum += arr6[i];
    }
    return sum;


}

    