/**https://leetcode.com/problems/find-center-of-star-graph/ */
//There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
//You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.


class FindCenterOfStarGraph {
    public int findCenter(int[][] edges) {
        int[] count = new int[edges.length + 1];
        for(int[] edge : edges){
            count[edge[0]]++;
            count[edge[1]]++;
        }
        for(int i = 1; i < count.length; i++){
            if(count[i] == edges.length){
                return i;
            }
        }
        return -1;
        
    }
}

    