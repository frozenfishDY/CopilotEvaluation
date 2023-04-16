/**https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/ */
//You are given an array pairs, where pairs[i] = [xi, yi], and:
//There are no duplicates.
//xi < yi
//Let ways be the number of rooted trees that satisfy the following conditions:
//The tree consists of nodes whose values appeared in pairs.
//A pair [xi, yi] exists in pairs if and only if xi is an ancestor of yi or yi is an ancestor of xi.
//Note: the tree does not have to be a binary tree.
//Two ways are considered to be different if there is at least one node that has different parents in both ways.
//Return:
//0 if ways == 0
//1 if ways == 1
//2 if ways > 1
//A rooted tree is a tree that has a single root node, and all edges are oriented to be outgoing from the root.
//An ancestor of a node is any node on the path from the root to that node (excluding the node itself). The root has no ancestors.


class NumberOfWaysToReconstructATree {
    public int checkWays(int[][] pairs) {
        int n = pairs.length;
        int[] parent = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(pairs[i][0] == pairs[j][0] || pairs[i][0] == pairs[j][1] || pairs[i][1] == pairs[j][0] || pairs[i][1] == pairs[j][1]){
                    union(parent, i, j);
                }
            }
        }
        int[] count = new int[n];
        for(int i = 0; i < n; i++){
            count[find(parent, i)]++;
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(count[i] > 0){
                res++;
            }
        }
        return res == 1 ? 1 : 2;
        
        
    }
}
     
    