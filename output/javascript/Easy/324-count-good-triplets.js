/**https://leetcode.com/problems/count-good-triplets/ */
//Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets._x000D_
//_x000D_
//A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:_x000D_
//_x000D_
//_x000D_
//	0 <= i < j < k < arr.length_x000D_
//	|arr[i] - arr[j]| <= a_x000D_
//	|arr[j] - arr[k]| <= b_x000D_
//	|arr[i] - arr[k]| <= c_x000D_
//_x000D_
//_x000D_
//Where |x| denotes the absolute value of x._x000D_
//_x000D_
//Return the number of good triplets._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3_x000D_
//Output: 4_x000D_
//Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)]._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1_x000D_
//Output: 0_x000D_
//Explanation: No triplet satisfies all conditions._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	3 <= arr.length <= 100_x000D_
//	0 <= arr[i] <= 1000_x000D_
//	0 <= a, b, c <= 1000_x000D_
/**
 * @param {number[]} arr
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var countGoodTriplets = function(arr, a, b, c) {
    let res = 0;
    for (let i = 0; i < arr.length - 2; i++) {
        for (let j = 1; j < arr.length - 1; j++) {
            for (let k = 2; k < arr.length; k++) {
                if (i < j && j < k && Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c) res++;
            }
        }
    }
    return res;
};