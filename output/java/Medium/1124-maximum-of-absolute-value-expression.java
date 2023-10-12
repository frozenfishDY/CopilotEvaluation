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
class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int ans = 0;
        for(int i = 0; i < arr1.length; i++) {
            for(int j = 0; j < arr2.length; j++) {
                ans = Math.max(ans, Math.abs(arr1[i]-arr1[j])+Math.abs(arr2[i]-arr2[j])+Math.abs(i-j));
            }
        }
        return ans;
    }
}