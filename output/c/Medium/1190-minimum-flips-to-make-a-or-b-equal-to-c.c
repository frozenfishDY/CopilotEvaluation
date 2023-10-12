/**https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/ */
//Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation)._x000D_
//Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: a = 2, b = 6, c = 5_x000D_
//Output: 3_x000D_
//Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: a = 4, b = 2, c = 7_x000D_
//Output: 1_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: a = 1, b = 2, c = 3_x000D_
//Output: 0_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= a <= 10^9_x000D_
//	1 <= b <= 10^9_x000D_
//	1 <= c <= 10^9_x000D_


int minFlips(int a, int b, int c){
int res = 0;
    while (a || b || c) {
        int a1 = a & 1;
        int b1 = b & 1;
        int c1 = c & 1;
        if (c1 == 0) {
            res += a1 + b1;
        } else {
            res += (a1 + b1 == 0 ? 1 : 0);
        }
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return res;
}