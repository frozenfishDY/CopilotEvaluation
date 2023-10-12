/**https://leetcode.com/problems/next-greater-numerically-balanced-number/ */
//An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
//Given an integer n, return the smallest numerically balanced number strictly greater than n.
// 
//Example 1:
//Input: n = 1
//Output: 22
//Explanation: 
//22 is numerically balanced since:
//- The digit 2 occurs 2 times. 
//It is also the smallest numerically balanced number strictly greater than 1.
//Example 2:
//Input: n = 1000
//Output: 1333
//Explanation: 
//1333 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times. 
//It is also the smallest numerically balanced number strictly greater than 1000.
//Note that 1022 cannot be the answer because 0 appeared more than 0 times.
//Example 3:
//Input: n = 3000
//Output: 3133
//Explanation: 
//3133 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times.
//It is also the smallest numerically balanced number strictly greater than 3000.
// 
//Constraints:
//	0 <= n <= 106
class Solution {
    public int nextBeautifulNumber(int n) {
        String s = String.valueOf(n + 1);
        int[] count = new int[10];
        for (char c : s.toCharArray()) {
            count[c - '0']++;
        }
        for (int i = 0; i <= 9; i++) {
            if (count[i] != 0) {
                count[i]--;
                for (int j = 0; j <= 9; j++) {
                    if (count[j] != 0) {
                        count[j]--;
                        for (int k = 0; k <= 9; k++) {
                            if (count[k] != 0) {
                                count[k]--;
                                for (int l = 0; l <= 9; l++) {
                                    if (count[l] != 0) {
                                        count[l]--;
                                        return i * 1000 + j * 100 + k * 10 + l;
                                    }
                                }
                                count[k]++;
                            }
                        }
                        count[j]++;
                    }
                }
                count[i]++;
            }
        }
        return -1;
    }
}