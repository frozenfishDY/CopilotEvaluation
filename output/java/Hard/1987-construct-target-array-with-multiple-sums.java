/**https://leetcode.com/problems/construct-target-array-with-multiple-sums/ */
//You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :
//let x be the sum of all elements currently in your array.
//choose index i, such that 0 <= i < n and set the value of arr at index i to x.
//You may repeat this procedure as many times as needed.
//Return true if it is possible to construct the target array from arr, otherwise, return false.


class ConstructTargetArrayWithMultipleSums {
    public boolean isPossible(int[] target) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        long sum = 0;
        for(int num : target){
            sum += num;
            pq.add(num);
        }
        while(!pq.isEmpty()){
            int curr = pq.poll();
            sum -= curr;
            if(curr == 1 || sum == 1) return true;
            if(curr < sum || sum == 0 || curr % sum == 0) return false;
            curr %= sum;
            sum += curr;
            pq.add(curr);
        }
        return true;
        
    }
}
     
    