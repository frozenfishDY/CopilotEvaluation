/**https://leetcode.com/problems/fizz-buzz/ */
//Given an integer n, return a string array answer (1-indexed) where:
//answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
//answer[i] == "Fizz" if i is divisible by 3.
//answer[i] == "Buzz" if i is divisible by 5.
//answer[i] == i (as a string) if none of the above conditions are true.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char **result = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i < n; i++){
        result[i] = (char *)malloc(sizeof(char) * 10);
        if((i + 1) % 3 == 0 && (i + 1) % 5 == 0){
            sprintf(result[i], "FizzBuzz");
        }else if((i + 1) % 3 == 0){
            sprintf(result[i], "Fizz");
        }else if((i + 1) % 5 == 0){
            sprintf(result[i], "Buzz");
        }else{
            sprintf(result[i], "%d", i + 1);
        }
    }
    *returnSize = n;
    return result;

}

    