/**https://leetcode.com/problems/soup-servings/ */
//There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:
//Serve 100 ml of soup A and 0 ml of soup B,
//Serve 75 ml of soup A and 25 ml of soup B,
//Serve 50 ml of soup A and 50 ml of soup B, and
//Serve 25 ml of soup A and 75 ml of soup B.
//When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.
//Note that we do not have an operation where all 100 ml's of soup B are used first.
//Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.


class SoupServings {
    public double soupServings(int n) {
        if(n >= 4800){
            return 1.0;
        }
        int N = (n + 24) / 25;
        double[][] dp = new double[N + 1][N + 1];
        dp[0][0] = 0.5;
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                for(int x = 0; x < 4; x++){
                    int a = i + (x == 0 ? 4 : x == 1 ? 3 : x == 2 ? 2 : 1);
                    int b = j + (x == 0 ? 0 : x == 1 ? 1 : x == 2 ? 2 : 3);
                    if(a >= N && b >= N){
                        dp[i][j] += 0.25;
                    }else if(a >= N){
                        dp[i][j] += 0.25 * 1;
                    }else if(b >= N){
                        dp[i][j] += 0.25 * 0;
                    }else{
                        dp[i][j] += 0.25 * dp[a][b];
                    }
                }
            }
        }
        return dp[0][0];
        
        
    }
}

    