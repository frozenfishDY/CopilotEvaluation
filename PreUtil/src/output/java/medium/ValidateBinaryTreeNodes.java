/**https://leetcode.com/problems/validate-binary-tree-nodes/ */
//You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
//If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
//Note that the nodes have no values and that we only use the node numbers in this problem.


class ValidateBinaryTreeNodes {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] degree = new int[n];
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                degree[leftChild[i]]++;
            }
            if(rightChild[i] != -1){
                degree[rightChild[i]]++;
            }
        }
        int root = -1;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0){
                if(root != -1){
                    return false;
                }
                root = i;
            }
            if(degree[i] > 1){
                return false;
            }
        }
        if(root == -1){
            return false;
        }
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()){
            int node = queue.poll();
            if(visited[node]){
                return false;
            }
            visited[node] = true;
            if(leftChild[node] != -1){
                queue.offer(leftChild[node]);
            }
            if(rightChild[node] != -1){
                queue.offer(rightChild[node]);
            }
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
        
    }
}

    