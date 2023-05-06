/**https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/ */
//There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.
//A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.
//For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.
//Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.
//Notice that the distance between the two cities is the number of edges in the path between them.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSubgraphsForEachDiameter(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
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
    return arr;

}

    