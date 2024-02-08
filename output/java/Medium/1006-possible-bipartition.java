/**https://leetcode.com/problems/possible-bipartition/ */
//We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
//Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.


class PossibleBipartition {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        List<Integer>[] graph = new List[n + 1];
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        for(int[] d : dislikes){
            graph[d[0]].add(d[1]);
            graph[d[1]].add(d[0]);
        }
        int[] color = new int[n + 1];
        for(int i = 1; i <= n; i++){
            if(color[i] == 0 && !dfs(graph, color, i, 1)){
                return false;
            }
        }
        return true;
        
        
        
    }
}

    