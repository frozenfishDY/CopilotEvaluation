/**https://leetcode.com/problems/the-k-strongest-values-in-an-array/ */
//Given an array of integers arr and an integer k.
//A value arr[i] is said to be stronger than a value arr[j] if |arr[i] - m| > |arr[j] - m| where m is the median of the array.
//If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger than arr[j] if arr[i] > arr[j].
//Return a list of the strongest k values in the array. return the answer in any arbitrary order.
//Median is the middle value in an ordered integer list. More formally, if the length of the list is n, the median is the element in position ((n - 1) / 2) in the sorted list (0-indexed).
//For arr = [6, -3, 7, 2, 11], n = 5 and the median is obtained by sorting the array arr = [-3, 2, 6, 7, 11] and the median is arr[m] where m = ((5 - 1) / 2) = 2. The median is 6.
//For arr = [-7, 22, 17,3], n = 4 and the median is obtained by sorting the array arr = [-7, 3, 17, 22] and the median is arr[m] where m = ((4 - 1) / 2) = 1. The median is 3.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getStrongest(int* arr, int arrSize, int k, int* returnSize){
    int i, j, k, l, m, n, count = 0, *result;
    int *temp;
    temp = (int*)malloc(arrSize * sizeof(int));
    for(i = 0; i < arrSize; i++){
        temp[i] = arr[i];
    }
    for(i = 0; i < arrSize - 1; i++){
        for(j = 0; j < arrSize - i - 1; j++){
            if(temp[j] > temp[j + 1]){
                temp[j] = temp[j] + temp[j + 1];
                temp[j + 1] = temp[j] - temp[j + 1];
                temp[j] = temp[j] - temp[j + 1];
            }
        }
    }
    m = temp[(arrSize - 1) / 2];
    for(i = 0; i < arrSize - 1; i++){
        for(j = 0; j < arrSize - i - 1; j++){
            if(abs(arr[j] - m) < abs(arr[j + 1] - m)){
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
            else if(abs(arr[j] - m) == abs(arr[j + 1] - m)){
                if(arr[j] < arr[j + 1]){
                    arr[j] = arr[j] + arr[j + 1];
                    arr[j + 1] = arr[j] - arr[j + 1];
                    arr[j] = arr[j] - arr[j + 1];
                }
            }
        }
    }
    result = (int*)malloc(k * sizeof(int));
    for(i = 0; i < k; i++){
        result[i] = arr[i];
    }
    *returnSize = k;
    return result;

}

    