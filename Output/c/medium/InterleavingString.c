/**https://leetcode.com/problems/interleaving-string/ */
//Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
//An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
//s = s1 + s2 + ... + sn
//t = t1 + t2 + ... + tm
//|n - m| <= 1
//The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
//Note: a + b is the concatenation of strings a and b.


bool isInterleave(char * s1, char * s2, char * s3){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    if(len1 + len2 != len3){
        return false;
    }
    bool dp[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            else if(i == 0){
                dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            }
            else if(j == 0){
                dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            }
            else{
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    return dp[len1][len2];

}

    