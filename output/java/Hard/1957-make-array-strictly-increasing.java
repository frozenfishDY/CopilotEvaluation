/**https://leetcode.com/problems/make-array-strictly-increasing/ */
//Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
//In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
//If there is no way to make arr1 strictly increasing, return -1.
// 
//Example 1:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
//Output: 1
//Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
//Example 2:
//Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
//Output: 2
//Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
//Example 3:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
//Output: -1
//Explanation: You can't make arr1 strictly increasing.
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 2000
//	0 <= arr1[i], arr2[i] <= 10^9
// 
class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        int len1 = arr1.length;
        int len2 = arr2.length;
        Arrays.sort(arr2);
        Map<Integer, Integer> dp = new HashMap<>();
        dp.put(-1, 0);
        for(int num : arr1){
            Map<Integer, Integer> cur = new HashMap<>();
            for(int key : dp.keySet()){
                if(num > key){
                    cur.put(num, Math.min(cur.getOrDefault(num, Integer.MAX_VALUE), dp.get(key)));
                }
                int index = binarySearch(arr2, key);
                if(index < len2){
                    cur.put(key, Math.min(cur.getOrDefault(key, Integer.MAX_VALUE), dp.get(key) + 1));
                }
            }
            dp = cur;
        }
        int res = Integer.MAX_VALUE;
        for(int key : dp.keySet()){
            res = Math.min(res, dp.get(key));
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
    private int binarySearch(int[] arr, int target){
        int res = Arrays.binarySearch(arr, target);
        if(res < 0){
            res = -res - 1;
        }
        return res;
    }
}