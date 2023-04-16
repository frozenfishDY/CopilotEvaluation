/**https://leetcode.com/problems/max-chunks-to-make-sorted-ii/ */
//You are given an integer array arr.
//We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
//Return the largest number of chunks we can make to sort the array.


int maxChunksToSorted(int* arr, int arrSize){
    int* sorted = (int*)malloc(sizeof(int) * arrSize);
    memcpy(sorted, arr, sizeof(int) * arrSize);
    qsort(sorted, arrSize, sizeof(int), cmp);
    int* max = (int*)malloc(sizeof(int) * arrSize);
    int* min = (int*)malloc(sizeof(int) * arrSize);
    max[0] = arr[0];
    min[arrSize - 1] = arr[arrSize - 1];
    for(int i = 1; i < arrSize; i++){
        max[i] = max[i - 1] > arr[i] ? max[i - 1] : arr[i];
        min[arrSize - i - 1] = min[arrSize - i] < arr[arrSize - i - 1] ? min[arrSize - i] : arr[arrSize - i - 1];
    }
    int result = 0;
    for(int i = 0; i < arrSize - 1; i++){
        if(max[i] <= min[i + 1]) result++;
    }
    return result + 1;


}

    