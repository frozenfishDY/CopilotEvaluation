/**https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ */
//Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
//Return true if it is possible. Otherwise, return false.


class DivideArrayInSetsOfKConsecutiveNumbers {
    public boolean isPossibleDivide(int[] nums, int k) {
        int n = nums.length;
        if(n % k != 0){
            return false;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for(int num : nums){
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int key : map.keySet()){
            pq.add(key);
        }
        while(!pq.isEmpty()){
            int start = pq.poll();
            int count = map.get(start);
            for(int i = start; i < start + k; i++){
                if(!map.containsKey(i)){
                    return false;
                }
                map.put(i, map.get(i) - count);
                if(map.get(i) == 0){
                    map.remove(i);
                }
            }
        }
        return true;
        
        
        
    }
}

    