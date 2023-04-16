/**https://leetcode.com/problems/count-pairs-with-xor-in-a-range/ */
//Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs.
//A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high.


class CountPairsWithXorInARange {
    public int countPairs(int[] nums, int low, int high) {
        int n = nums.length;
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int xor = nums[i] ^ nums[j];
                if(xor >= low && xor <= high){
                    res++;
                }
            }
        }
        return res;
        
    }
}
     
    