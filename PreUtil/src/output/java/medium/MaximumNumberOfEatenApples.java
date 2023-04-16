/**https://leetcode.com/problems/maximum-number-of-eaten-apples/ */
//There is a special kind of apple tree that grows apples every day for n days. On the ith day, the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.
//You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.
//Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.


class MaximumNumberOfEatenApples {
    public int eatenApples(int[] apples, int[] days) {
        int n = apples.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int res = 0;
        for(int i = 0; i < n; i++){
            if(apples[i] > 0){
                pq.offer(new int[]{i + days[i], apples[i]});
            }
            while(!pq.isEmpty() && (pq.peek()[0] <= i || pq.peek()[1] == 0)){
                pq.poll();
            }
            if(!pq.isEmpty()){
                int[] cur = pq.poll();
                cur[1]--;
                res++;
                if(cur[1] > 0){
                    pq.offer(cur);
                }
            }
        }
        int i = n;
        while(!pq.isEmpty()){
            while(!pq.isEmpty() && (pq.peek()[0] <= i || pq.peek()[1] == 0)){
                pq.poll();
            }
            if(!pq.isEmpty()){
                int[] cur = pq.poll();
                cur[1]--;
                res++;
                if(cur[1] > 0){
                    pq.offer(cur);
                }
            }
            i++;
        }
        return res;
        
    }
}
     
    