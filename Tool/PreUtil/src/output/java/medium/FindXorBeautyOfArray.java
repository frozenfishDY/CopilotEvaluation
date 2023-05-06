/**https://leetcode.com/problems/find-xor-beauty-of-array/ */
//You are given a 0-indexed integer array nums.
//The effective value of three indices i, j, and k is defined as ((nums[i] | nums[j]) & nums[k]).
//The xor-beauty of the array is the XORing of the effective values of all the possible triplets of indices (i, j, k) where 0 <= i, j, k < n.
//Return the xor-beauty of nums.
//Note that:
//val1 | val2 is bitwise OR of val1 and val2.
//val1 & val2 is bitwise AND of val1 and val2.


class FindXorBeautyOfArray {
    public int xorBeauty(int[] nums) {
        int n = nums.length;
        int[] cnt = new int[1 << 10];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cnt[nums[i] | nums[j]]++;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res ^= cnt[nums[i]];
        }
        return res;
        
        
        
    }
}

    