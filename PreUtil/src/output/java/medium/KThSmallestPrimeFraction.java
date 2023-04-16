/**https://leetcode.com/problems/k-th-smallest-prime-fraction/ */
//You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
//For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
//Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].


class KThSmallestPrimeFraction {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> arr[a[0]] * arr[b[1]] - arr[a[1]] * arr[b[0]]);
        for(int i = 0; i < arr.length - 1; i++){
            pq.offer(new int[]{i, arr.length - 1});
        }
        while(k > 1){
            int[] cur = pq.poll();
            if(cur[1] - 1 > cur[0]){
                pq.offer(new int[]{cur[0], cur[1] - 1});
            }
            k--;
        }
        int[] res = pq.poll();
        return new int[]{arr[res[0]], arr[res[1]]};
        
    }
}

    