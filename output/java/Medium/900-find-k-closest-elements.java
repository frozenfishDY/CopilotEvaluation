/**https://leetcode.com/problems/find-k-closest-elements/ */
//Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
//An integer a is closer to x than an integer b if:
//	|a - x| < |b - x|, or
//	|a - x| == |b - x| and a < b
// 
//Example 1:
//Input: arr = [1,2,3,4,5], k = 4, x = 3
//Output: [1,2,3,4]
//Example 2:
//Input: arr = [1,2,3,4,5], k = 4, x = -1
//Output: [1,2,3,4]
// 
//Constraints:
//	1 <= k <= arr.length
//	1 <= arr.length <= 104
//	arr is sorted in ascending order.
//	-104 <= arr[i], x <= 104
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int n = arr.length;
        List<Integer> result = new ArrayList<>();
        int index = Arrays.binarySearch(arr, x);
        if (index < 0) {
            index = -index - 1;
        }
        int left = index - 1, right = index;
        while (k > 0) {
            if (left >= 0 && right < n) {
                if (x - arr[left] <= arr[right] - x) {
                    result.add(arr[left--]);
                } else {
                    result.add(arr[right++]);
                }
            } else if (left >= 0) {
                result.add(arr[left--]);
            } else {
                result.add(arr[right++]);
            }
            k--;
        }
        Collections.sort(result);
        return result;
    }
}