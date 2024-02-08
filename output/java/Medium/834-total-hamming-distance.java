/**https://leetcode.com/problems/total-hamming-distance/ */
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.


class TotalHammingDistance {
    public int totalHammingDistance(int[] nums) {
        int n = nums.length;
        int res = 0;
        for(int i = 0; i < 32; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                cnt += (nums[j] >> i) & 1;
            }
            res += cnt * (n - cnt);
        }
        return res;
        
        
    }
}

    