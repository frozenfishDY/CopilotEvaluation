/**https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/ */
//You are given an array target that consists of distinct integers and another integer array arr that can have duplicates.
//In one operation, you can insert any integer at any position in arr. For example, if arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. Note that you can insert the integer at the very beginning or end of the array.
//Return the minimum number of operations needed to make target a subsequence of arr.
//A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.


int minOperations(int* target, int targetSize, int* arr, int arrSize){
    int i,j,k;
    int* arr2 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr2[i] = 0;
    }
    for(i=0;i<targetSize;i++){
        for(j=0;j<arrSize;j++){
            if(target[i] == arr[j]){
                arr2[i] = j;
                break;
            }
        }
    }
    int* arr3 = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr3[i] = 0;
    }
    int max = 0;
    for(i=0;i<targetSize;i++){
        if(arr2[i] > max){
            max = arr2[i];
        }
    }
    int min = max;
    for(i=0;i<targetSize;i++){
        if(arr2[i] < min){
            min = arr2[i];
        }
    }
    int dev = max - min;
    for(i=0;i<targetSize;i++){
        if(arr2[i] == min){
            arr3[i] = 1;
        }
    }
    int flag = 1;
    while(flag){
        flag = 0;
        for(i=0;i<targetSize;i++){
            if(arr3[i] == 1){
                arr2[i] = arr2[i] + 1;
                if(arr2[i] > max){
                    max = arr2[i];
                }
                if(arr2[i] < min){
                    min = arr2[i];
                }
                flag = 1;
            }
        }
        dev = (dev < max - min) ? dev : max - min;
        for(i=0;i<targetSize;i++){
            if(arr2[i] == min){
                arr3[i] = 1;
            }
        }
    }
    return dev;

}

    