/**https://leetcode.com/problems/minimum-increment-to-make-array-unique/ */
//You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
//Return the minimum number of moves to make every value in nums unique.
//The test cases are generated so that the answer fits in a 32-bit integer.


class MinimumIncrementToMakeArrayUnique {
    public int minIncrementForUnique(int[] nums) {
        int[] cnt = new int[40000];
        for(int i : nums){
            cnt[i]++;
        }
        int res = 0;
        int taken = 0;
        for(int i = 0; i < 40000; i++){
            if(cnt[i] >= 2){
                taken += cnt[i] - 1;
                res -= i * (cnt[i] - 1);
            }else if(taken > 0 && cnt[i] == 0){
                taken--;
                res += i;
            }
        }
        return res;
        
    }
}

    