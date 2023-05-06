/**https://leetcode.com/problems/find-k-pairs-with-smallest-sums/ */
//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//Define a pair (u, v) which consists of one element from the first array and one element from the second array.
//Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


class FindKPairsWithSmallestSums {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums1.length == 0 || nums2.length == 0 || k == 0){
            return res;
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (a[0] + a[1]) - (b[0] + b[1]));
        for(int i = 0; i < nums1.length && i < k; i++){
            pq.offer(new int[]{nums1[i], nums2[0], 0});
        }
        while(k-- > 0 && !pq.isEmpty()){
            int[] cur = pq.poll();
            res.add(Arrays.asList(cur[0], cur[1]));
            if(cur[2] == nums2.length - 1){
                continue;
            }
            pq.offer(new int[]{cur[0], nums2[cur[2] + 1], cur[2] + 1});
        }
        return res;
        
        
        
    }
}

    