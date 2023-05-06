/**https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/ */
//Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
//Return the length of the shortest subarray to remove.
//A subarray is a contiguous subsequence of the array.


class ShortestSubarrayToBeRemovedToMakeArraySorted {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i == 0 || arr[i] >= arr[i - 1]){
                count++;
            }else{
                count = 1;
            }
            left[i] = count;
        }
        count = 0;
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1 || arr[i] <= arr[i + 1]){
                count++;
            }else{
                count = 1;
            }
            right[i] = count;
        }
        int res = n - 1;
        for(int i = 0; i < n - 1; i++){
            if(arr[i] <= arr[i + 1]){
                res = Math.min(res, n - left[i] - 1);
            }
            if(i > 0 && arr[i - 1] <= arr[i + 1]){
                res = Math.min(res, n - left[i - 1] - right[i + 1]);
            }
        }
        return res;
        
    }
}
     
    