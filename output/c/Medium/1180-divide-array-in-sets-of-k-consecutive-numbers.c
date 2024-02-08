/**https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ */
//Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
//Return true if it is possible. Otherwise, return false.


bool isPossibleDivide(int* nums, int numsSize, int k){
    if(numsSize % k != 0){
        return false;
    }
    int* count = (int*)malloc(sizeof(int) * 100001);
    for(int i = 0; i < 100001; i++){
        count[i] = 0;
    }
    for(int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }
    for(int i = 0; i < 100001; i++){
        if(count[i] > 0){
            for(int j = 1; j < k; j++){
                if(count[i + j] >= count[i]){
                    count[i + j] -= count[i];
                }else{
                    return false;
                }
            }
        }
    }
    return true;

}

    