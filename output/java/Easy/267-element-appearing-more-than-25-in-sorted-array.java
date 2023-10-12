/**https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/ */
//Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.
// 
//Example 1:
//Input: arr = [1,2,2,6,6,6,6,7,10]
//Output: 6
//Example 2:
//Input: arr = [1,1]
//Output: 1
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 105
class Solution {
    public int findSpecialInteger(int[] arr) {
        int len = arr.length;
        int i = 0;
        while(i < len){
            int j = i + 1;
            while(j < len && arr[j] == arr[i]){
                j++;
            }
            if(j - i > len / 4){
                return arr[i];
            }
            i = j;
        }
        return -1;
    }
}