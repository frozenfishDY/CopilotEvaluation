/**https://leetcode.com/problems/network-delay-time/ */
//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
//We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
// 
//Example 1:
//Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//Output: 2
//Example 2:
//Input: times = [[1,2,1]], n = 2, k = 1
//Output: 1
//Example 3:
//Input: times = [[1,2,1]], n = 2, k = 2
//Output: -1
// 
//Constraints:
//	1 <= k <= n <= 100
//	1 <= times.length <= 6000
//	times[i].length == 3
//	1 <= ui, vi <= n
//	ui != vi
//	0 <= wi <= 100
//	All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        int max = 0;
        for(int[] time: times) {
            max = Math.max(max, time[2]);
        }
        int[] dist = new int[n+1];
        Arrays.fill(dist, max + 1);
        dist[k] = 0;
        for(int i=1; i<=n; i++) {
            for(int[] time: times) {
                int u = time[0];
                int v = time[1];
                int w = time[2];
                if(dist[u] != max + 1 && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = Math.max(ans, dist[i]);
        }
        return ans == max + 1 ? -1 : ans;
    }
}