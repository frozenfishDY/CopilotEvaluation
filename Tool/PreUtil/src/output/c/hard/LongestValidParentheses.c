/**https://leetcode.com/problems/longest-valid-parentheses/ */
//Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.


int longestValidParentheses(char * s){
    int i = 0;
    int j = 0;
    int len = 0;
    int maxLen = 0;
    int *dp = (int *)malloc((strlen(s) + 1) * sizeof(int));
    for(i = 0; i <= strlen(s); i++){
        dp[i] = 0;
    }
    for(i = 1; i <= strlen(s); i++){
        if(s[i - 1] == '('){
            dp[i] = 0;
        }else{
            if(i - 2 >= 0 && s[i - 2] == '('){
                dp[i] = dp[i - 2] + 2;
            }else if(i - 2 >= 0 && s[i - 2] == ')'){
                if(i - dp[i - 1] - 2 >= 0 && s[i - dp[i - 1] - 2] == '('){
                    dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                }
            }
        }
        if(dp[i] > maxLen){
            maxLen = dp[i];
        }
    }
    return maxLen;

}

    