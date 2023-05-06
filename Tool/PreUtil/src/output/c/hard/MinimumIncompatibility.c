/**https://leetcode.com/problems/minimum-incompatibility/ */
//You are given an integer array nums and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.
//A subset's incompatibility is the difference between the maximum and minimum elements in that array.
//Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.
//A subset is a group integers that appear in the array with no particular order.


int minimumIncompatibility(int* nums, int numsSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = nums[i];
    }
    int max = 0;
    for(i=0;i<numsSize;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int min = max;
    for(i=0;i<numsSize;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    int dev = max - min;
    int* arr2 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr2[i] = 0;
    }
    for(i=0;i<numsSize;i++){
        if(arr[i] % 2 == 0){
            arr2[i] = 1;
        }
    }
    int flag = 1;
    while(flag){
        flag = 0;
        for(i=0;i<numsSize;i++){
            if(arr2[i] == 1){
                arr[i] = arr[i] / 2;
                if(arr[i] % 2 == 0){
                    arr2[i] = 1;
                }
                else{
                    arr2[i] = 0;
                }
                flag = 1;
            }
        }
        max = 0;
        for(i=0;i<numsSize;i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        min = max;
        for(i=0;i<numsSize;i++){
            if(arr[i] < min){
                min = arr[i];
            }
        }
        dev = (dev < max - min) ? dev : max - min;
    }
    return dev;

}

    