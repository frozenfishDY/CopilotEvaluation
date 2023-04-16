/**https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/ */
//You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.
//Return the minimum number of moves required so that nums has k consecutive 1's.


int minMoves(int* nums, int numsSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = 0;
    }
    int count = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i] == 1){
            arr[count] = i;
            count++;
        }
    }
    int* arr2 = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr2[i] = 0;
    }
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            arr2[i] += abs(arr[i+j] - arr[i+k/2]);
        }
    }
    int min = arr2[0];
    for(i=0;i<k;i++){
        if(arr2[i] < min){
            min = arr2[i];
        }
    }
    return min;

}

    