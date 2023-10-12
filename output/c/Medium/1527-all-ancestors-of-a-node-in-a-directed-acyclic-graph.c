/**https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/ */
//You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).
//You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.
//Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.
//A node u is an ancestor of another node v if u can reach v via a set of edges.
// 
//Example 1:
//Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
//Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
//Explanation:
//The above diagram represents the input graph.
//- Nodes 0, 1, and 2 do not have any ancestors.
//- Node 3 has two ancestors 0 and 1.
//- Node 4 has two ancestors 0 and 2.
//- Node 5 has three ancestors 0, 1, and 3.
//- Node 6 has five ancestors 0, 1, 2, 3, and 4.
//- Node 7 has four ancestors 0, 1, 2, and 3.
//Example 2:
//Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
//Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
//Explanation:
//The above diagram represents the input graph.
//- Node 0 does not have any ancestor.
//- Node 1 has one ancestor 0.
//- Node 2 has two ancestors 0 and 1.
//- Node 3 has three ancestors 0, 1, and 2.
//- Node 4 has four ancestors 0, 1, 2, and 3.
// 
//Constraints:
//	1 <= n <= 1000
//	0 <= edges.length <= min(2000, n * (n - 1) / 2)
//	edges[i].length == 2
//	0 <= fromi, toi <= n - 1
//	fromi != toi
//	There are no duplicate edges.
//	The graph is directed and acyclic.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** getAncestors(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize, int** returnColumnSizes){
int** ret = malloc(sizeof(int*)*n);
    int i;
    int j;
    int k;
    int count;
    int left;
    int right;
    int* arr = malloc(sizeof(int)*n);
    int* visited = malloc(sizeof(int)*n);
    int* ancestor = malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i]=0;
        visited[i]=0;
        ancestor[i]=0;
    }
    for(i=0;i<edgesSize;i++){
        left=edges[i][0];
        right=edges[i][1];
        arr[right]=left;
    }
    for(i=0;i<n;i++){
        left=i;
        count=0;
        while(left!=0){
            left=arr[left];
            count++;
        }
        ancestor[i]=count;
    }
    for(i=0;i<n;i++){
        ret[i]=malloc(sizeof(int)*ancestor[i]);
        left=i;
        count=0;
        while(left!=0){
            ret[i][count]=left;
            visited[left]=1;
            left=arr[left];
            count++;
        }
    }
    *returnSize=n;
    *returnColumnSizes=ancestor;
    return ret;

=======
Suggestion 2

int** ret = malloc(sizeof(int*)*n);
    int i;
    int j;
    int k;
    int count;
    int left;
    int right;
    int* arr = malloc(sizeof(int)*n*n);
    for(i=0;i<n*n;i++){
        arr[i]=0;
    }
    for(i=0;i<edgesSize;i++){
        arr[edges[i][1]*n+edges[i][0]]=1;
    }
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<n;j++){
            if(arr[i*n+j]==1){
                count++;
            }
        }
        ret[i]=malloc(sizeof(int)*count);
        count=0;
        for(j=0;j<n;j++){
            if(arr[i*n+j]==1){
                ret[i][count++]=j;
            }
        }
        (*returnColumnSizes)[i]=count;
    }
    *returnSize=n;
    return ret;

}