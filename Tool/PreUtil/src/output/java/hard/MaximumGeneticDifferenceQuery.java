/**https://leetcode.com/problems/maximum-genetic-difference-query/ */
//There is a rooted tree consisting of n nodes numbered 0 to n - 1. Each node's number denotes its unique genetic value (i.e. the genetic value of node x is x). The genetic difference between two genetic values is defined as the bitwise-XOR of their values. You are given the integer array parents, where parents[i] is the parent for node i. If node x is the root of the tree, then parents[x] == -1.
//You are also given the array queries where queries[i] = [nodei, vali]. For each query i, find the maximum genetic difference between vali and pi, where pi is the genetic value of any node that is on the path between nodei and the root (including nodei and the root). More formally, you want to maximize vali XOR pi.
//Return an array ans where ans[i] is the answer to the ith query.


class MaximumGeneticDifferenceQuery {
    public int[] maxGeneticDifference(int[] parents, int[][] queries) {
        int n = parents.length;
        int[] res = new int[queries.length];
        Map<Integer, List<int[]>> map = new HashMap<>();
        for(int i = 0; i < queries.length; i++){
            map.computeIfAbsent(queries[i][0], x -> new ArrayList<>()).add(new int[]{i, queries[i][1]});
        }
        int[] trie = new int[1 << 20];
        int[] count = new int[1 << 20];
        dfs(0, parents, map, trie, count, res);
        return res;
        
    }
}
     
    