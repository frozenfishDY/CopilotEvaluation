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
/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function(arr) {
    let count = 0;
    let res = arr[0];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === res) {
            count++;
            if (count > arr.length / 4) {
                return res;
            }
        } else {
            res = arr[i];
            count = 1;
        }
    }
    return res;
};