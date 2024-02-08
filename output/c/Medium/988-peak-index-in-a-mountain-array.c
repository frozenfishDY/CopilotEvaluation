/**https://leetcode.com/problems/peak-index-in-a-mountain-array/ */
//An array arr a mountain if the following properties hold:
//arr.length >= 3
//There exists some i with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
//You must solve it in O(log(arr.length)) time complexity.


int peakIndexInMountainArray(int* arr, int arrSize){
    int left = 0;
    int right = arrSize - 1;
    int mid = 0;
    while(left < right){
        mid = (left + right) / 2;
        if(arr[mid] < arr[mid + 1]){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;

}

    