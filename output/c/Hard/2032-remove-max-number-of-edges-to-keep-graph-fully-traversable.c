/**https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/ */
//Alice and Bob have an undirected graph of n nodes and three types of edges:
//Type 1: Can be traversed by Alice only.
//Type 2: Can be traversed by Bob only.
//Type 3: Can be traversed by both Alice and Bob.
//Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
//Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.


int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        arr[i] = 0;
    }
    for(i=1;i<edgesSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<edgesSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;


}

    