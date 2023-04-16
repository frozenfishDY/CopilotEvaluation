/**https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/ */
//The bitwise AND of an array nums is the bitwise AND of all integers in nums.
//For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
//Also, for nums = [7], the bitwise AND is 7.
//You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.
//Return the size of the largest combination of candidates with a bitwise AND greater than 0.


class LargestCombinationWithBitwiseAndGreaterThanZero {
    public int largestCombination(int[] candidates) {
        int[] count = new int[32];
        for (int candidate : candidates) {
            int index = 0;
            while (candidate > 0) {
                if ((candidate & 1) == 1) {
                    count[index]++;
                }
                candidate >>= 1;
                index++;
            }
        }
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            if (count[i] > 0) {
                result += 1 << i;
            }
        }
        return result;
        
    }
}
     
    