/**https://leetcode.com/problems/word-break/ */
//Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
//Note that the same word in the dictionary may be reused multiple times in the segmentation.


bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int len = strlen(s);
    bool* dp = (bool*)calloc(len + 1, sizeof(bool));
    dp[0] = true;
    for(int i = 1; i <= len; i++){
        for(int j = 0; j < wordDictSize; j++){
            int wordLen = strlen(wordDict[j]);
            if(i >= wordLen && strncmp(s + i - wordLen, wordDict[j], wordLen) == 0 && dp[i - wordLen]){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];

}

    