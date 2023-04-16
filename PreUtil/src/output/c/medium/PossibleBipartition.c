/**https://leetcode.com/problems/possible-bipartition/ */
//We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
//Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.


bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
    int* hash = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        hash[i] = -1;
    }
    for(int i = 0; i < dislikesSize; i++){
        int x = dislikes[i][0] - 1;
        int y = dislikes[i][1] - 1;
        if(hash[x] == -1 && hash[y] == -1){
            hash[x] = 0;
            hash[y] = 1;
        }else if(hash[x] == -1){
            hash[x] = 1 - hash[y];
        }else if(hash[y] == -1){
            hash[y] = 1 - hash[x];
        }else{
            if(hash[x] == hash[y]){
                return false;
            }
        }
    }
    return true;

}

    