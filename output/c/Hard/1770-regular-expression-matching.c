/**https://leetcode.com/problems/regular-expression-matching/ */
//Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
//'.' Matches any single character
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).


bool isMatch(char * s, char * p){
    int i = 0, j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    int **dp = (int **)malloc((sLen + 1) * sizeof(int *));
    for(i = 0; i <= sLen; i++){
        dp[i] = (int *)malloc((pLen + 1) * sizeof(int));
    }
    dp[0][0] = 1;
    for(i = 1; i <= sLen; i++){
        dp[i][0] = 0;
    }
    for(j = 1; j <= pLen; j++){
        if(p[j - 1] == '*'){
            dp[0][j] = dp[0][j - 2];
        }else{
            dp[0][j] = 0;
        }
    }
    for(i = 1; i <= sLen; i++){
        for(j = 1; j <= pLen; j++){
            if(p[j - 1] == '*'){
                if(p[j - 2] == s[i - 1] || p[j - 2] == '.'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                }else{
                    dp[i][j] = dp[i][j - 2];
                }
            }else if(p[j - 1] == s[i - 1] || p[j - 1] == '.'){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[sLen][pLen];

}

    