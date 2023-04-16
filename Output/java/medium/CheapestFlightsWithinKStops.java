/**https://leetcode.com/problems/cheapest-flights-within-k-stops/ */
//There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
//You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


class CheapestFlightsWithinKStops {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[src] = 0;
        for(int i = 0; i <= k; i++){
            int[] temp = Arrays.copyOf(dp, n);
            for(int[] flight : flights){
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                if(dp[from] != Integer.MAX_VALUE){
                    temp[to] = Math.min(temp[to], dp[from] + price);
                }
            }
            dp = temp;
        }
        return dp[dst] == Integer.MAX_VALUE ? -1 : dp[dst];
        
        
    }
}

    