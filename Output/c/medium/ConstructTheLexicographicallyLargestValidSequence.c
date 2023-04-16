/**https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/ */
//Given an integer n, find a sequence that satisfies all of the following:
//The integer 1 occurs once in the sequence.
//Each integer between 2 and n occurs twice in the sequence.
//For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
//The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
//Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
//A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructDistancedSequence(int n, int* returnSize){
    int* arr = malloc(2 * n * sizeof(int));
    for(int i = 0; i < 2 * n; i++){
        arr[i] = 0;
    }
    int* used = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        used[i] = 0;
    }
    int* result = malloc(2 * n * sizeof(int));
    for(int i = 0; i < 2 * n; i++){
        result[i] = 0;
    }
    int* max = malloc(2 * n * sizeof(int));
    for(int i = 0; i < 2 * n; i++){
        max[i] = 0;
    }
    int* maxUsed = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        maxUsed[i] = 0;
    }
    int* maxResult = malloc(2 * n * sizeof(int));
    for(int i = 0; i < 2 * n; i++){
        maxResult[i] = 0;
    }
    int* maxReturnSize = malloc(sizeof(int));
    *maxReturnSize = 0;
    int* maxN = malloc(sizeof(int));
    *maxN = 0;
    int* maxUsedN = malloc(sizeof(int));
    *maxUsedN = 0;
    int* maxResultN = malloc(sizeof(int));
    *maxResultN = 0;
    int* maxReturnSizeN = malloc(sizeof(int));
    *maxReturnSizeN = 0;
    int* maxMax = malloc(sizeof(int));
    *maxMax = 0;
    int* maxMaxN = malloc(sizeof(int));
    *maxMaxN = 0;
    int* maxMaxUsed = malloc(sizeof(int));
    *maxMaxUsed = 0;
    int* maxMaxResult = malloc(sizeof(int));
    *maxMaxResult = 0;
    int* maxMaxReturnSize = malloc(sizeof(int));
    *maxMaxReturnSize = 0;
    int* maxMaxMax = malloc(sizeof(int));
    *maxMaxMax = 0;
    int* maxMaxMaxN = malloc(sizeof(int));
    *maxMaxMaxN = 0;
    int* maxMaxMaxUsed = malloc(sizeof(int));
   

}

    