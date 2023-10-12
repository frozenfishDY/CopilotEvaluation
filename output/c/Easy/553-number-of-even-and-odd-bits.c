/**https://leetcode.com/problems/number-of-even-and-odd-bits/ */
//You are given a positive integer n.
//Let even denote the number of even indices in the binary representation of n (0-indexed) with value 1.
//Let odd denote the number of odd indices in the binary representation of n (0-indexed) with value 1.
//Return an integer array answer where answer = [even, odd].
// 
//Example 1:
//Input: n = 17
//Output: [2,0]
//Explanation: The binary representation of 17 is 10001. 
//It contains 1 on the 0th and 4th indices. 
//There are 2 even and 0 odd indices.
//Example 2:
//Input: n = 2
//Output: [0,1]
//Explanation: The binary representation of 2 is 10.
//It contains 1 on the 1st index. 
//There are 0 even and 1 odd indices.
// 
//Constraints:
//	1 <= n <= 1000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int o = 0;
    int *a = (int*)malloc(sizeof(int) * 2);
    while (n > 0) {
        if (n % 2 == 1) {
            if (i % 2 == 0) {
                a[0]++;
            }
            else {
                a[1]++;
            }
        }
        n /= 2;
        i++;
    }
    *returnSize = 2;
    return a;
}