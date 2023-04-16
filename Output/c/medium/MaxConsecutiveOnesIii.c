/**https://leetcode.com/problems/max-consecutive-ones-iii/ */
//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.


int longestOnes(int* nums, int numsSize, int k){
    int i = 0;
    int j = 0;
    int count = 0;
    int max = 0;
    int flag = 0;
    for(i = 0; i < numsSize; i++){
        for(j = i; j < numsSize; j++){
            if(nums[j] == 0){
                count++;
            }
            if(count > k){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            flag = 0;
            count = 0;
            continue;
        }
        if(j - i > max){
            max = j - i;
        }
        count = 0;
    }
    return max;

}

    