/**https://leetcode.com/problems/minimum-cost-to-hire-k-workers/ */
//There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
//We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
//Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
//Every worker in the paid group must be paid at least their minimum wage expectation.
//Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.


class MinimumCostToHireKWorkers {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][] workers = new double[n][2];
        for (int i = 0; i < n; i++) {
            workers[i][0] = (double) wage[i] / quality[i];
            workers[i][1] = quality[i];
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        PriorityQueue<Double> pq = new PriorityQueue<>((a, b) -> Double.compare(b, a));
        double res = Double.MAX_VALUE;
        double sum = 0;
        for (double[] worker : workers) {
            pq.offer(worker[1]);
            sum += worker[1];
            if (pq.size() > k) {
                sum -= pq.poll();
            }
            if (pq.size() == k) {
                res = Math.min(res, sum * worker[0]);
            }
        }
        return res;
        
    }
}
     
    