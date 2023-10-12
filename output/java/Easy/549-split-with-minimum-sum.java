/**https://leetcode.com/problems/split-with-minimum-sum/ */
//Given a positive integer num, split it into two non-negative integers num1 and num2 such that:
//	The concatenation of num1 and num2 is a permutation of num.
//	
//		In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
//	
//	
//	num1 and num2 can contain leading zeros.
//Return the minimum possible sum of num1 and num2.
//Notes:
//	It is guaranteed that num does not contain any leading zeros.
//	The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.
// 
//Example 1:
//Input: num = 4325
//Output: 59
//Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
//Example 2:
//Input: num = 687
//Output: 75
//Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.
// 
//Constraints:
//	10 <= num <= 109
class Solution {
    public int splitNum(int num) {
        int[] cnt = new int[10];
        String s = String.valueOf(num);
        for (char c : s.toCharArray()) {
            cnt[c - '0']++;
        }
        int res = Integer.MAX_VALUE;
        for (int i = 1; i < 1000000000; i++) {
            int[] cnt1 = new int[10];
            int[] cnt2 = new int[10];
            String s1 = String.valueOf(i);
            String s2 = String.valueOf(num - i);
            if (s1.length() + s2.length() == s.length()) {
                for (char c : s1.toCharArray()) {
                    cnt1[c - '0']++;
                }
                for (char c : s2.toCharArray()) {
                    cnt2[c - '0']++;
                }
                boolean isValid = true;
                for (int j = 0; j < 10; j++) {
                    if (cnt[j] != cnt1[j] + cnt2[j]) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    res = Math.min(res, Integer.parseInt(s1) + Integer.parseInt(s2));
                }
            }
        }
        return res;
    }
}