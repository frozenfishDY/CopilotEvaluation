/**https://leetcode.com/problems/number-of-different-subsequences-gcds/ */
//You are given an array nums that consists of positive integers.
//The GCD of a sequence of numbers is defined as the greatest integer that divides all the numbers in the sequence evenly.
//For example, the GCD of the sequence [4,6,16] is 2.
//A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
//For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
//Return the number of different GCDs among all non-empty subsequences of nums.


class NumberOfDifferentSubsequencesGcds {
    public int countDifferentSubsequenceGCDs(int[] nums) {
        int n = nums.length;
        int max = 0;
        for(int num : nums){
            max = Math.max(max, num);
        }
        boolean[] seen = new boolean[max + 1];
        for(int num : nums){
            seen[num] = true;
        }
        int res = 0;
        for(int i = 1; i <= max; i++){
            int gcd = 0;
            for(int j = i; j <= max; j += i){
                if(seen[j]){
                    gcd = gcd(gcd, j);
                }
            }
            if(gcd == i){
                res++;
            }
        }
        return res;
        
        
    }
}
     
    