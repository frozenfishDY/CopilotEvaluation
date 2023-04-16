/**https://leetcode.com/problems/minimum-interval-to-include-each-query/ */
//You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.
//You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
//Return an array containing the answers to the queries.


class MinimumIntervalToIncludeEachQuery {
    public int[] minInterval(int[][] intervals, int[] queries) {
        int n = intervals.length;
        int m = queries.length;
        int[] res = new int[m];
        Arrays.fill(res, -1);
        int[][] qs = new int[m][2];
        for(int i = 0; i < m; i++){
            qs[i][0] = queries[i];
            qs[i][1] = i;
        }
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        Arrays.sort(qs, (a, b) -> a[0] - b[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        int j = 0;
        for(int i = 0; i < m; i++){
            while(j < n && intervals[j][0] <= qs[i][0]){
                pq.offer(intervals[j]);
                j++;
            }
            while(!pq.isEmpty() && pq.peek()[1] < qs[i][0]){
                pq.poll();
            }
            if(!pq.isEmpty()){
                res[qs[i][1]] = pq.peek()[1] - pq.peek()[0] + 1;
            }
        }
        return res;
        
    }
}
     
    