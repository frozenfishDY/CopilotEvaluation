/**https://leetcode.com/problems/k-th-smallest-prime-fraction/ */
//You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
//For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
//Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize){
    int* answer = (int*)malloc(sizeof(int) * 2);
    int* count = (int*)malloc(sizeof(int) * arrSize);
    for(int i = 0; i < arrSize; i++){
        count[i] = 0;
    }
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j < arrSize; j++){
            if(arr[i] < arr[j]){
                count[i]++;
            }
        }
    }
    int* index = (int*)malloc(sizeof(int) * arrSize);
    for(int i = 0; i < arrSize; i++){
        index[i] = i;
    }
    for(int i = 0; i < arrSize; i++){
        for(int j = i + 1; j < arrSize; j++){
            if(count[i] > count[j]){
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }else if(count[i] == count[j]){
                if(arr[index[i]] > arr[index[j]]){
                    int temp = count[i];
                    count[i] = count[j];
                    count[j] = temp;
                    temp = index[i];
                    index[i] = index[j];
                    index[j] = temp;
                }
            }
        }
    }
    int* index2 = (int*)malloc(sizeof(int) * arrSize);
    for(int i = 0; i < arrSize; i++){
        index2[i] = i;
    }
    for(int i = 0; i < arrSize; i++){
        for(int j = i + 1; j < arrSize; j++){
            if(arr[index[i]] < arr[index[j]]){
                if(arr[index2[i]] < arr[index2[j]]){
                    int temp = index2[i];
                    index2[i] = index2[j];
                    index2[j] = temp;
                }
            }
        }
    }
    answer[0] = arr[index[index2[k - 1]]];
    answer[1] = arr[index2[k - 1]];
    *returnSize = 2;
    return answer;


}

    