/**https://leetcode.com/problems/validate-binary-tree-nodes/ */
//You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
//If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
//Note that the nodes have no values and that we only use the node numbers in this problem.


/**
 * @param {number} n
 * @param {number[]} leftChild
 * @param {number[]} rightChild
 * @return {boolean}
 */
var validateBinaryTreeNodes = function(n, leftChild, rightChild) {
    let indegree = new Array(n).fill(0);
    let outdegree = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        if(leftChild[i] != -1){
            indegree[leftChild[i]]++;
            outdegree[i]++;
        }
        if(rightChild[i] != -1){
            indegree[rightChild[i]]++;
            outdegree[i]++;
        }
    }
    let root = -1;
    for(let i = 0; i < n; i++){
        if(indegree[i] == 0){
            if(root != -1){
                return false;
            }
            root = i;
        }
        if(outdegree[i] > 2){
            return false;
        }
    }
    if(root == -1){
        return false;
    }
    return true;
    
};

    