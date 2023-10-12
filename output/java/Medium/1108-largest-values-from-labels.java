/**https://leetcode.com/problems/largest-values-from-labels/ */
//There is a set of n items. You are given two integer arrays values and labels where the value and the label of the ith element are values[i] and labels[i] respectively. You are also given two integers numWanted and useLimit.
//Choose a subset s of the n elements such that:
//	The size of the subset s is less than or equal to numWanted.
//	There are at most useLimit items with the same label in s.
//The score of a subset is the sum of the values in the subset.
//Return the maximum score of a subset s.
// 
//Example 1:
//Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
//Output: 9
//Explanation: The subset chosen is the first, third, and fifth items.
//Example 2:
//Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
//Output: 12
//Explanation: The subset chosen is the first, second, and third items.
//Example 3:
//Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
//Output: 16
//Explanation: The subset chosen is the first and fourth items.
// 
//Constraints:
//	n == values.length == labels.length
//	1 <= n <= 2 * 104
//	0 <= values[i], labels[i] <= 2 * 104
//	1 <= numWanted, useLimit <= n
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        int row = values.length;
        int[][] pair = new int[row][2];
        for(int i=0; i<row; i++) {
            pair[i][0] = values[i];
            pair[i][1] = labels[i];
        }
        Arrays.sort(pair, (a, b) -> b[0] - a[0]);
        Map<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        for(int i=0; i<row; i++) {
            if(numWanted == 0) {
                break;
            }
            if(map.getOrDefault(pair[i][1], 0) < useLimit) {
                ans += pair[i][0];
                map.put(pair[i][1], map.getOrDefault(pair[i][1], 0) + 1);
                numWanted--;
            }
        }
        return ans;
    }
}