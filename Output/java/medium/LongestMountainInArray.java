/**https://leetcode.com/problems/longest-mountain-in-array/ */
//You may recall that an array arr is a mountain array if and only if:
//arr.length >= 3
//There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.


class LongestMountainInArray {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        for(int i = 1; i < n; i++){
            left[i] = arr[i] > arr[i - 1] ? left[i - 1] + 1 : 0;
        }
        int[] right = new int[n];
        for(int i = n - 2; i >= 0; i--){
            right[i] = arr[i] > arr[i + 1] ? right[i + 1] + 1 : 0;
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(left[i] > 0 && right[i] > 0){
                res = Math.max(res, left[i] + right[i] + 1);
            }
        }
        return res;
        
    }
}

    