/**https://leetcode.com/problems/plus-one/ */
//You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
//Increment the large integer by one and return the resulting array of digits.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = digitsSize - 1;
    int carry = 1;
    while(i >= 0 && carry == 1){
        if(digits[i] == 9){
            digits[i] = 0;
            carry = 1;
        }else{
            digits[i] += 1;
            carry = 0;
        }
        i--;
    }
    if(carry == 1){
        int *result = (int *)malloc(sizeof(int) * (digitsSize + 1));
        result[0] = 1;
        for(int i = 0; i < digitsSize; i++){
            result[i + 1] = digits[i];
        }
        *returnSize = digitsSize + 1;
        return result;
    }else{
        *returnSize = digitsSize;
        return digits;
    }

}
    