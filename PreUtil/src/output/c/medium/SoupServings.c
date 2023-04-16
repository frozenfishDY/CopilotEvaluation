/**https://leetcode.com/problems/soup-servings/ */
//There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:
//Serve 100 ml of soup A and 0 ml of soup B,
//Serve 75 ml of soup A and 25 ml of soup B,
//Serve 50 ml of soup A and 50 ml of soup B, and
//Serve 25 ml of soup A and 75 ml of soup B.
//When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.
//Note that we do not have an operation where all 100 ml's of soup B are used first.
//Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.


double soupServings(int n){
    if(n >= 4800){
        return 1;
    }
    double dp[200][200] = {0};
    dp[0][0] = 0.5;
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            if(i == 0 && j == 0){
                continue;
            }
            int a = i - 100 >= 0 ? i - 100 : 0;
            int b = j - 75 >= 0 ? j - 75 : 0;
            int c = j - 50 >= 0 ? j - 50 : 0;
            int d = i - 25 >= 0 ? i - 25 : 0;
            dp[i][j] = 0.25 * (dp[a][j] + dp[b][c] + dp[i][c] + dp[d][j]);
        }
    }
    return dp[(n + 24) / 25][(n + 24) / 25];

}

    