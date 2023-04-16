/**https://leetcode.com/problems/flower-planting-with-no-adjacent/ */
//You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.
//All gardens have at most 3 paths coming into or leaving it.
//Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
//Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.


class FlowerPlantingWithNoAdjacent {
    public int[] gardenNoAdj(int n, int[][] paths) {
        int[] res = new int[n];
        List<Integer>[] g = new List[n];
        for(int i = 0; i < n; i++){
            g[i] = new ArrayList<>();
        }
        for(int[] p : paths){
            g[p[0] - 1].add(p[1] - 1);
            g[p[1] - 1].add(p[0] - 1);
        }
        for(int i = 0; i < n; i++){
            boolean[] used = new boolean[5];
            for(int j : g[i]){
                used[res[j]] = true;
            }
            for(int j = 1; j <= 4; j++){
                if(!used[j]){
                    res[i] = j;
                    break;
                }
            }
        }
        return res;
        
    }
}

    