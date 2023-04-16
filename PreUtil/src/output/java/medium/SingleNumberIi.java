/**https://leetcode.com/problems/single-number-ii/ */
//Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.


class SingleNumberIi {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            int sum = 0;
            for(int num : nums){
                sum += (num >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
        
        
    }
}

    