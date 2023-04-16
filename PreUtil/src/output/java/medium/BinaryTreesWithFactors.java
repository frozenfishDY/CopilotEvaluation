/**https://leetcode.com/problems/binary-trees-with-factors/ */
//Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
//We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.
//Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.


class BinaryTreesWithFactors {
    public int numFactoredBinaryTrees(int[] arr) {
        int n = arr.length;
        long res = 0;
        long mod = (long)1e9 + 7;
        Arrays.sort(arr);
        Map<Integer, Long> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            map.put(arr[i], 1L);
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    map.put(arr[i], (map.get(arr[i]) + map.get(arr[j]) * map.getOrDefault(arr[i] / arr[j], 0L)) % mod);
                }
            }
            res = (res + map.get(arr[i])) % mod;
        }
        return (int)res;
        
    }
}

    