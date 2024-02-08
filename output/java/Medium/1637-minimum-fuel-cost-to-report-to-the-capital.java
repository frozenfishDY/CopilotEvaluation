/**https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/ */
//There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
//There is a meeting for the representatives of each city. The meeting is in the capital city.
//There is a car in each city. You are given an integer seats that indicates the number of seats in each car.
//A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.
//Return the minimum number of liters of fuel to reach the capital city.


class MinimumFuelCostToReportToTheCapital {
    public long minimumFuelCost(int[][] roads, int seats) {
        int n = roads.length + 1;
        List<List<int[]>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++){
            graph.add(new ArrayList<>());
        }
        for(int[] road : roads){
            graph.get(road[0]).add(new int[]{road[1], 1});
            graph.get(road[1]).add(new int[]{road[0], 1});
        }
        long[] dp = new long[n];
        Arrays.fill(dp, Long.MAX_VALUE);
        dp[0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{0, 0});
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            int city = cur[0];
            long cost = cur[1];
            if(cost > dp[city]){
                continue;
            }
            for(int[] next : graph.get(city)){
                int nextCity = next[0];
                long nextCost = cost + next[1];
                if(nextCost < dp[nextCity]){
                    dp[nextCity] = nextCost;
                    pq.offer(new int[]{nextCity, (int)nextCost});
                }
            }
        }
        long res = 0;
        for(int i = 1; i < n; i++){
            res += dp[i];
        }
        return res;
        
    }
}

    