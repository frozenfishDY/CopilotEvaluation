/**https://leetcode.com/problems/matchsticks-to-square/ */
//You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//Return true if you can make this square and false otherwise.


bool makesquare(int* matchsticks, int matchsticksSize){
    int sum = 0;
    for(int i = 0; i < matchsticksSize; i++){
        sum += matchsticks[i];
    }
    if(sum % 4 != 0){
        return false;
    }
    int target = sum / 4;
    int* visited = (int*)malloc(sizeof(int) * matchsticksSize);
    for(int i = 0; i < matchsticksSize; i++){
        visited[i] = 0;
    }
    for(int i = 0; i < 4; i++){
        if(!dfs(matchsticks, matchsticksSize, visited, target, 0)){
            return false;
        }
    }
    return true;


}

    