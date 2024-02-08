/**https://leetcode.com/problems/stone-game-iv/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
//Also, if a player cannot make a move, he/she loses the game.
//Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.


class StoneGameIv {
    public boolean winnerSquareGame(int n) {
        boolean[] dp = new boolean[n + 1];
        dp[0] = false;
        for(int i = 1; i <= n; i++){
            boolean canWin = false;
            for(int j = 1; j * j <= i; j++){
                if(!dp[i - j * j]){
                    canWin = true;
                    break;
                }
            }
            dp[i] = canWin;
        }
        return dp[n];
        
    }
}
     
    