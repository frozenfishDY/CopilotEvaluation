/**https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/ */
//You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.
//You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built.
//Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 10^9 + 7.


class CountWaysToBuildRoomsInAnAntColony {
    public int waysToBuildRooms(int[] prevRoom) {
        int n = prevRoom.length;
        int[] count = new int[n];
        int[] dp = new int[n];
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 1; i < n; i++){
            adj.get(prevRoom[i]).add(i);
        }
        dfs(adj, count, dp, 0);
        return dp[0];
        
        
    }
}
     
    