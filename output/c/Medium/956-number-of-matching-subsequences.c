/**https://leetcode.com/problems/number-of-matching-subsequences/ */
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//For example, "ace" is a subsequence of "abcde".


int numMatchingSubseq(char * s, char ** words, int wordsSize){
    int count = 0;
    int length = strlen(s);
    int* index = (int*)malloc(sizeof(int) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        index[i] = 0;
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < wordsSize; j++){
            if(index[j] == -1){
                continue;
            }
            if(s[i] == words[j][index[j]]){
                index[j]++;
            }
            if(words[j][index[j]] == '\0'){
                count++;
                index[j] = -1;
            }
        }
    }
    return count;

}

    