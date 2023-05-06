/**https://leetcode.com/problems/closest-prime-numbers-in-range/ */
//Given two positive integers left and right, find the two integers num1 and num2 such that:
//left <= nums1 < nums2 <= right .
//nums1 and nums2 are both prime numbers.
//nums2 - nums1 is the minimum amongst all other pairs satisfying the above conditions.
//Return the positive integer array ans = [nums1, nums2]. If there are multiple pairs satisfying these conditions, return the one with the minimum nums1 value or [-1, -1] if such numbers do not exist.
//A number greater than 1 is called prime if it is only divisible by 1 and itself.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestPrimes(int left, int right, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 2);
    int resultSize = 0;
    int minDiff = INT_MAX;
    int minDiffNum1 = -1;
    int minDiffNum2 = -1;
    for(int i = left; i <= right; i++){
        if(isPrime(i)){
            for(int j = i + 1; j <= right; j++){
                if(isPrime(j)){
                    if(j - i < minDiff){
                        minDiff = j - i;
                        minDiffNum1 = i;
                        minDiffNum2 = j;
                    }
                    break;
                }
            }
        }
    }
    result[0] = minDiffNum1;
    result[1] = minDiffNum2;
    *returnSize = 2;
    return result;

}

    