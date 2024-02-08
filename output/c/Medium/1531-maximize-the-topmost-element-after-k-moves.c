/**https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/ */
//You are given a 0-indexed integer array nums representing the contents of a pile, where nums[0] is the topmost element of the pile.
//In one move, you can perform either of the following:
//If the pile is not empty, remove the topmost element of the pile.
//If there are one or more removed elements, add any one of them back onto the pile. This element becomes the new topmost element.
//You are also given an integer k, which denotes the total number of moves to be made.
//Return the maximum value of the topmost element of the pile possible after exactly k moves. In case it is not possible to obtain a non-empty pile after k moves, return -1.


int maximumTop(int* nums, int numsSize, int k){
    int i, j;
    int max = 0;
    int arr[100000] = {0};
    for(i = 0; i < numsSize; i++){
        arr[nums[i]]++;
    }
    for(i = 0; i < k; i++){
        for(j = 0; j < 100000; j++){
            if(arr[j] > 0){
                arr[j]--;
                arr[j + 1]++;
                break;
            }
        }
    }
    for(i = 0; i < 100000; i++){
        if(arr[i] > 0){
            max = i;
        }
    }
    return max;

}

    