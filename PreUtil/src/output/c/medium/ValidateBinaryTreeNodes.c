/**https://leetcode.com/problems/validate-binary-tree-nodes/ */
//You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
//If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
//Note that the nodes have no values and that we only use the node numbers in this problem.


bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize){
    int* inDegree = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        inDegree[i] = 0;
    }
    for(int i = 0; i < n; i++){
        if(leftChild[i] != -1){
            inDegree[leftChild[i]]++;
        }
        if(rightChild[i] != -1){
            inDegree[rightChild[i]]++;
        }
    }
    int root = -1;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            if(root != -1){
                return false;
            }
            root = i;
        }
    }
    if(root == -1){
        return false;
    }
    int* queue = (int*)malloc(sizeof(int) * n);
    int queueSize = 0;
    queue[queueSize++] = root;
    for(int i = 0; i < queueSize; i++){
        int node = queue[i];
        if(leftChild[node] != -1){
            queue[queueSize++] = leftChild[node];
        }
        if(rightChild[node] != -1){
            queue[queueSize++] = rightChild[node];
        }
    }
    if(queueSize != n){
        return false;
    }
    return true;

}

    