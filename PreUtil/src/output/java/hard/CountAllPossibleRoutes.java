/**https://leetcode.com/problems/count-all-possible-routes/ */
//You are given an array of distinct positive integers locations where locations[i] represents the position of city i. You are also given integers start, finish and fuel representing the starting city, ending city, and the initial amount of fuel you have, respectively.
//At each step, if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length and move to city j. Moving from city i to city j reduces the amount of fuel you have by |locations[i] - locations[j]|. Please notice that |x| denotes the absolute value of x.
//Notice that fuel cannot become negative at any point in time, and that you are allowed to visit any city more than once (including start and finish).
//Return the count of all possible routes from start to finish. Since the answer may be too large, return it modulo 10^9 + 7.


class CountAllPossibleRoutes {
    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        int n = locations.length;
        int[][] dp = new int[n][fuel + 1];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], -1);
        }
        return dfs(locations, start, finish, fuel, dp);
        
        
    }
}
     
    