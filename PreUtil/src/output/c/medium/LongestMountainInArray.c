/**https://leetcode.com/problems/longest-mountain-in-array/ */
//You may recall that an array arr is a mountain array if and only if:
//arr.length >= 3
//There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.


int longestMountain(int* arr, int arrSize){
    int result = 0;
    int count = 0;
    int flag = 0;
    for(int i = 1; i < arrSize; i++){
        if(arr[i] > arr[i - 1]){
            if(flag == 1){
                count++;
            }else{
                count = 2;
                flag = 1;
            }
        }else if(arr[i] < arr[i - 1]){
            if(flag == 1){
                count++;
                result = result > count ? result : count;
            }else if(flag == -1){
                count = 2;
            }
            flag = -1;
        }else{
            count = 0;
            flag = 0;
        }
    }
    return result;

}

    