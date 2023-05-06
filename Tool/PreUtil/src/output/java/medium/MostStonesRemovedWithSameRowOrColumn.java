/**https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/ */
//On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
//A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
//Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.


class MostStonesRemovedWithSameRowOrColumn {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        int[] p = new int[n];
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    union(p, i, j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(p[i] == i){
                res++;
            }
        }
        return n - res;
        
        
    }
}

    