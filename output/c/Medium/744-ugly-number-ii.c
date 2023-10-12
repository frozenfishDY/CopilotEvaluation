/**https://leetcode.com/problems/ugly-number-ii/ */
//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
//Given an integer n, return the nth ugly number.
// 
//Example 1:
//Input: n = 10
//Output: 12
//Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
//Example 2:
//Input: n = 1
//Output: 1
//Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
// 
//Constraints:
//	1 <= n <= 1690
int nthUglyNumber(int n){
if (n <= 0) {
        return 0;
    }
    int *uglyNumbers = (int *)malloc(sizeof(int) * n);
    int index2 = 0, index3 = 0, index5 = 0;
    uglyNumbers[0] = 1;
    int next = 1;
    while (next < n) {
        int min = min3(uglyNumbers[index2] * 2, uglyNumbers[index3] * 3, uglyNumbers[index5] * 5);
        uglyNumbers[next] = min;
        while (uglyNumbers[index2] * 2 <= uglyNumbers[next]) {
            index2++;
        }
        while (uglyNumbers[index3] * 3 <= uglyNumbers[next]) {
            index3++;
        }
        while (uglyNumbers[index5] * 5 <= uglyNumbers[next]) {
            index5++;
        }
        next++;
    }
    return uglyNumbers[n - 1];

}