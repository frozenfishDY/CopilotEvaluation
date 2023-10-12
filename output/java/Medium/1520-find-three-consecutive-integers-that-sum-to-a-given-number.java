/**https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/ */
//Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.
// 
//Example 1:
//Input: num = 33
//Output: [10,11,12]
//Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
//10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
//Example 2:
//Input: num = 4
//Output: []
//Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
// 
//Constraints:
//	0 <= num <= 1015
class Solution {
    public long[] sumOfThree(long num) {
        long[] res = new long[3];
        for (int i = 1; i < num / 3; i++) {
            for (int j = i + 1; j < num / 2; j++) {
                long sum = (long) i * (i + 1) / 2 + (long) j * (j + 1) / 2;
                if (sum > num) {
                    break;
                }
                long k = num - sum;
                if (k >= j + 1 && k <= num / 2) {
                    res[0] = i;
                    res[1] = j;
                    res[2] = k;
                    return res;
                }
            }
        }
        return new long[0];
    }
}