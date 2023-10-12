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
int splitNum(int num){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int *a = (int*)calloc(10, sizeof(int));
    while (num > 0) {
        a[num % 10]++;
        num /= 10;
    }
    for (i = 1; i < 10; i++) {
        if (a[i] > 0) {
            for (j = 0; j < a[i]; j++) {
                if (k % 2 == 0) {
                    m = m * 10 + i;
                } else {
                    n = n * 10 + i;
                }
                k++;
            }
        }
    }
    return m + n;
}