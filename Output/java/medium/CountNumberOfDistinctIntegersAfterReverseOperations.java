/**https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/ */
//You are given an array nums consisting of positive integers.
//You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
//Return the number of distinct integers in the final array.


class CountNumberOfDistinctIntegersAfterReverseOperations {
    public int countDistinctIntegers(int[] nums) {
        int[] count = new int[100000];
        for (int num : nums) {
            count[reverse(num)]++;
        }
        int result = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0) {
                result++;
            }
        }
        return result;
        
        
    }
}
     
    