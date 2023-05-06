/**https://leetcode.com/problems/split-array-into-fibonacci-sequence/ */
//You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].
//Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:
//0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
//f.length >= 3, and
//f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
//Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
//Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* splitIntoFibonacci(char * num, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    int length = strlen(num);
    for(int i = 1; i < length - 1; i++){
        for(int j = i + 1; j < length; j++){
            int first = 0;
            int second = 0;
            int third = 0;
            int firstLength = i;
            int secondLength = j - i;
            int thirdLength = length - j;
            if(firstLength > 1 && num[0] == '0'){
                break;
            }
            if(secondLength > 1 && num[i] == '0'){
                break;
            }
            if(thirdLength > 1 && num[j] == '0'){
                break;
            }
            if(firstLength > 10 || secondLength > 10 || thirdLength > 10){
                break;
            }
            sscanf(num, "%d%n", &first, &firstLength);
            sscanf(num + i, "%d%n", &second, &secondLength);
            sscanf(num + j, "%d%n", &third, &thirdLength);
            if(first + second == third){
                result[*returnSize] = first;
                (*returnSize)++;
                result[*returnSize] = second;
                (*returnSize)++;
                result[*returnSize] = third;
                (*returnSize)++;
                if(j + thirdLength == length){
                    return result;
                }
                int k = j + thirdLength;
                while(k < length){
                    int temp = first + second;
                    int tempLength = 0;
                    sscanf(num + k, "%d%n", &temp, &tempLength);
                    if(temp != third){
                        break;
                    }
                    first = second;
                    second = third;
                    third = temp;
                    result[*returnSize] = third;
                    (*returnSize)++;
                    k += tempLength;
                }
                if(k == length){
                    return result;
                }
                (*returnSize) -= 3;
            }
        }
    }
    *returnSize = 0;
    return result;

}

    