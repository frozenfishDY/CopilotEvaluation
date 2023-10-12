/**https://leetcode.com/problems/maximum-of-absolute-value-expression/ */
//Given two arrays of integers with equal lengths, return the maximum value of:_x000D_
//_x000D_
//|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|_x000D_
//_x000D_
//where the maximum is taken over all 0 <= i, j < arr1.length._x000D_
// 
//Example 1:
//Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
//Output: 13
//Example 2:
//Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
//Output: 20
// 
//Constraints:
//	2 <= arr1.length == arr2.length <= 40000
//	-10^6 <= arr1[i], arr2[i] <= 10^6
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var maxAbsValExpr = function(arr1, arr2) {
    var ans = 0;
	var n = arr1.length;
	var max1 = -Infinity;
	var max2 = -Infinity;
	var max3 = -Infinity;
	var max4 = -Infinity;
	for (var i = 0; i < n; i++) {
		max1 = Math.max(max1, arr1[i] + arr2[i] + i);
		max2 = Math.max(max2, arr1[i] - arr2[i] + i);
		max3 = Math.max(max3, arr1[i] + arr2[i] - i);
		max4 = Math.max(max4, arr1[i] - arr2[i] - i);
	}
	var min1 = Infinity;
	var min2 = Infinity;
	var min3 = Infinity;
	var min4 = Infinity;
	for (var i = 0; i < n; i++) {
		min1 = Math.min(min1, arr1[i] + arr2[i] + i);
		min2 = Math.min(min2, arr1[i] - arr2[i] + i);
		min3 = Math.min(min3, arr1[i] + arr2[i] - i);
		min4 = Math.min(min4, arr1[i] - arr2[i] - i);
	}
	ans = Math.max(ans, max1 - min1, max2 - min2, max3 - min3, max4 - min4);
	return ans;
};