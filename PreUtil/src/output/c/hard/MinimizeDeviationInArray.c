/**https://leetcode.com/problems/minimize-deviation-in-array/ */
//You are given an array nums of n positive integers.
//You can perform two types of operations on any element of the array any number of times:
//If the element is even, divide it by 2.
//For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
//If the element is odd, multiply it by 2.
//For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
//The deviation of the array is the maximum difference between any two elements in the array.
//Return the minimum deviation the array can have after performing some number of operations.


int minimumDeviation(int* nums, int numsSize){
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
        if(max - min < dev){
            dev = max - min;
        }
    }
    return dev;

}

    