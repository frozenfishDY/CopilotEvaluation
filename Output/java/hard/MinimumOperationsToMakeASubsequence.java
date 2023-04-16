/**https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/ */
//You are given an array target that consists of distinct integers and another integer array arr that can have duplicates.
//In one operation, you can insert any integer at any position in arr. For example, if arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. Note that you can insert the integer at the very beginning or end of the array.
//Return the minimum number of operations needed to make target a subsequence of arr.
//A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.


class MinimumOperationsToMakeASubsequence {
    public int minOperations(int[] target, int[] arr) {
        int n = target.length;
        int m = arr.length;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            map.put(target[i], i);
        }
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < m; i++){
            if(map.containsKey(arr[i])){
                list.add(map.get(arr[i]));
            }
        }
        int[] dp = new int[list.size()];
        int len = 0;
        for(int num : list){
            int i = Arrays.binarySearch(dp, 0, len, num);
            if(i < 0){
                i = -(i + 1);
            }
            dp[i] = num;
            if(i == len){
                len++;
            }
        }
        return n - len;
        
    }
}
     
    