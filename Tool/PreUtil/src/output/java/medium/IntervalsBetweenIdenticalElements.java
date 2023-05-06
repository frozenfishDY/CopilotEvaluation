/**https://leetcode.com/problems/intervals-between-identical-elements/ */
//You are given a 0-indexed array of n integers arr.
//The interval between two elements in arr is defined as the absolute difference between their indices. More formally, the interval between arr[i] and arr[j] is |i - j|.
//Return an array intervals of length n where intervals[i] is the sum of intervals between arr[i] and each element in arr with the same value as arr[i].
//Note: |x| is the absolute value of x.


class IntervalsBetweenIdenticalElements {
    public long[] getDistances(int[] arr) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int i = 0; i < arr.length; i++){
            map.putIfAbsent(arr[i], new ArrayList<>());
            map.get(arr[i]).add(i);
        }
        long[] res = new long[arr.length];
        for(int i = 0; i < arr.length; i++){
            long sum = 0;
            for(int j = 0; j < map.get(arr[i]).size() - 1; j++){
                sum += map.get(arr[i]).get(j + 1) - map.get(arr[i]).get(j);
            }
            res[i] = sum;
        }
        return res;
        
    }
}
     
    