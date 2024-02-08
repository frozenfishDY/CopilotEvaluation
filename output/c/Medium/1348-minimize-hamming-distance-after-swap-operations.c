/**https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/ */
//You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
//The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
//Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.


int minimumHammingDistance(int* source, int sourceSize, int* target, int targetSize, int** allowedSwaps, int allowedSwapsSize, int* allowedSwapsColSize){
    int* arr = malloc(sourceSize * sizeof(int));
    for(int i = 0; i < sourceSize; i++){
        arr[i] = i;
    }
    for(int i = 0; i < allowedSwapsSize; i++){
        int a = allowedSwaps[i][0];
        int b = allowedSwaps[i][1];
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    int* arr2 = malloc(sourceSize * sizeof(int));
    for(int i = 0; i < sourceSize; i++){
        arr2[i] = 0;
    }
    for(int i = 0; i < sourceSize; i++){
        int a = arr[i];
        int b = i;
        if(arr2[a] == 0){
            arr2[a] = b;
        }
        else{
            int temp = arr2[a];
            arr2[a] = b;
            arr2[b] = temp;
        }
    }
    int count = 0;
    for(int i = 0; i < sourceSize; i++){
        if(arr2[i] != 0){
            int a = arr2[i];
            int b = i;
            if(source[a] != target[b]){
                count++;
            }
        }
    }
    return count;

}

    