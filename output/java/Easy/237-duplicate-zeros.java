/**https://leetcode.com/problems/duplicate-zeros/ */
//Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
//Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
// 
//Example 1:
//Input: arr = [1,0,2,3,0,4,5,0]
//Output: [1,0,0,2,3,0,0,4]
//Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
//Example 2:
//Input: arr = [1,2,3]
//Output: [1,2,3]
//Explanation: After calling your function, the input array is modified to: [1,2,3]
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 9
class Solution {
    public void duplicateZeros(int[] arr) {
        int len = arr.length;
        int[] res = new int[len];
        int i = 0, j = 0;
        while(i < len && j < len){
            res[j++] = arr[i];
            if(arr[i++] == 0){
                res[j++] = 0;
            }
        }
        for(int k = 0; k < len; k++){
            arr[k] = res[k];
        }
    }
}