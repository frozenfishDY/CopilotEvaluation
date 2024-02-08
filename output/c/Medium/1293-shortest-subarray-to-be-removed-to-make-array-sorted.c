/**https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/ */
//Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
//Return the length of the shortest subarray to remove.
//A subarray is a contiguous subsequence of the array.


int findLengthOfShortestSubarray(int* arr, int arrSize){
    int start = 0;
    int end = arrSize - 1;
    while(start < end && arr[start] <= arr[start + 1]){
        start++;
    }
    if(start == end){
        return 0;
    }
    while(end > start && arr[end] >= arr[end - 1]){
        end--;
    }
    int count = end - start - 1;
    int i = 0;
    int j = end;
    while(i <= start && j < arrSize){
        if(arr[i] <= arr[j]){
            count = fmin(count, j - i - 1);
            i++;
        }else{
            j++;
        }
    }
    return count;

}

    