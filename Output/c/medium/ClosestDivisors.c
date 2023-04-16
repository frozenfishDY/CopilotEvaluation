/**https://leetcode.com/problems/closest-divisors/ */
//Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
//Return the two integers in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestDivisors(int num, int* returnSize){
    int* result = malloc(sizeof(int) * 2);
    int minDiff = INT_MAX;
    for(int i = 1; i * i <= num + 2; i++){
        if((num + 1) % i == 0){
            int diff = abs(i - (num + 1) / i);
            if(diff < minDiff){
                minDiff = diff;
                result[0] = i;
                result[1] = (num + 1) / i;
            }
        }
        if((num + 2) % i == 0){
            int diff = abs(i - (num + 2) / i);
            if(diff < minDiff){
                minDiff = diff;
                result[0] = i;
                result[1] = (num + 2) / i;
            }
        }
    }
    *returnSize = 2;
    return result;

}

    