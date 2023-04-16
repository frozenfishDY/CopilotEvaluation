/**https://leetcode.com/problems/decode-ways/ */
//A message containing letters from A-Z can be encoded into numbers using the following mapping:
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
//"AAJF" with the grouping (1 1 10 6)
//"KJF" with the grouping (11 10 6)
//Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
//Given a string s containing only digits, return the number of ways to decode it.
//The test cases are generated so that the answer fits in a 32-bit integer.


int numDecodings(char * s){
    int len = strlen(s);
    if(len == 0){
        return 0;
    }
    int *dp = (int*)malloc(sizeof(int) * (len + 1));
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    for(int i = 2; i <= len; i++){
        if(s[i-1] == '0'){
            if(s[i-2] == '1' || s[i-2] == '2'){
                dp[i] = dp[i-2];
            }else{
                dp[i] = 0;
            }
        }else{
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] >= '1' && s[i-1] <= '6')){
                dp[i] = dp[i-1] + dp[i-2];
            }else{
                dp[i] = dp[i-1];
            }
        }
    }
    return dp[len];

}

    