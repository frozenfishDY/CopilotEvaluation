/**https://leetcode.com/problems/matchsticks-to-square/ */
//You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//Return true if you can make this square and false otherwise.


class MatchsticksToSquare {
    public boolean makesquare(int[] matchsticks) {
        int n = matchsticks.length;
        if(n < 4){
            return false;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += matchsticks[i];
        }
        if(sum % 4 != 0){
            return false;
        }
        int target = sum / 4;
        Arrays.sort(matchsticks);
        int i = n - 1;
        if(matchsticks[i] > target){
            return false;
        }
        while(i >= 0 && matchsticks[i] == target){
            i--;
            n--;
        }
        return dfs(matchsticks, new int[4], i, target);
        
        
    }
}

    