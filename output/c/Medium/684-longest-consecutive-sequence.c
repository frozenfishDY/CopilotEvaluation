/**https://leetcode.com/problems/longest-consecutive-sequence/ */
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.


int longestConsecutive(int* nums, int numsSize){
    int max = 0;
    int* hash = (int*)calloc(numsSize, sizeof(int));
    for(int i = 0; i < numsSize; i++){
        if(hash[i] == 0){
            int count = 1;
            int num = nums[i];
            hash[i] = 1;
            for(int j = i + 1; j < numsSize; j++){
                if(nums[j] == num + 1){
                    count++;
                    num++;
                    hash[j] = 1;
                }
            }
            num = nums[i];
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] == num - 1){
                    count++;
                    num--;
                    hash[j] = 1;
                }
            }
            if(count > max){
                max = count;
            }
        }
    }
    return max;

}

    