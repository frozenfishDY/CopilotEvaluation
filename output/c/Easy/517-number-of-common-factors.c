/**https://leetcode.com/problems/number-of-common-factors/ */
//Given two positive integers a and b, return the number of common factors of a and b.
//An integer x is a common factor of a and b if x divides both a and b.
// 
//Example 1:
//Input: a = 12, b = 6
//Output: 4
//Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
//Example 2:
//Input: a = 25, b = 30
//Output: 2
//Explanation: The common factors of 25 and 30 are 1, 5.
// 
//Constraints:
//	1 <= a, b <= 1000
int commonFactors(int a, int b){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int *c = (int*)calloc(1001, sizeof(int));
    for (i = 1; i <= a; i++) {
        if (a % i == 0) {
            c[i]++;
        }
    }
    for (i = 1; i <= b; i++) {
        if (b % i == 0) {
            c[i]++;
        }
    }
    for (i = 1; i < 1001; i++) {
        if (c[i] == 2) {
            n++;
        }
    }
    return n;
}