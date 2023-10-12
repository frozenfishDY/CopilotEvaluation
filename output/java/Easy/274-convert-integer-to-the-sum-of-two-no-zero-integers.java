/**https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/ */
//No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
//Given an integer n, return a list of two integers [a, b] where:
//	a and b are No-Zero integers.
//	a + b = n
//The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
// 
//Example 1:
//Input: n = 2
//Output: [1,1]
//Explanation: Let a = 1 and b = 1.
//Both a and b are no-zero integers, and a + b = 2 = n.
//Example 2:
//Input: n = 11
//Output: [2,9]
//Explanation: Let a = 2 and b = 9.
//Both a and b are no-zero integers, and a + b = 9 = n.
//Note that there are other valid answers as [8, 3] that can be accepted.
// 
//Constraints:
//	2 <= n <= 104
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int[] res = new int[2];
        for(int i = 1; i < n; i++){
            int a = i;
            int b = n - i;
            if(!containsZero(a) && !containsZero(b)){
                res[0] = a;
                res[1] = b;
                break;
            }
        }
        return res;
    }
    private boolean containsZero(int n){
        while(n != 0){
            if(n % 10 == 0) return true;
            n /= 10;
        }
        return false;
    }
}