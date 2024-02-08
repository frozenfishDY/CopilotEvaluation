/**https://leetcode.com/problems/loud-and-rich/ */
//There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.
//You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).
//Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.


class LoudAndRich {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n = quiet.length;
        List<Integer>[] graph = new List[n];
        for(int i = 0; i < n; i++){
            graph[i] = new ArrayList<>();
        }
        for(int[] r : richer){
            graph[r[1]].add(r[0]);
        }
        int[] res = new int[n];
        Arrays.fill(res, -1);
        for(int i = 0; i < n; i++){
            dfs(graph, quiet, res, i);
        }
        return res;
        
        
    }
}

    