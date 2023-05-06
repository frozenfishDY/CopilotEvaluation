/**https://leetcode.com/problems/is-subsequence/ */
//Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


bool isSubsequence(char * s, char * t){
    int sLen = strlen(s);
    int tLen = strlen(t);
    if(sLen == 0){
        return true;
    }
    if(tLen == 0){
        return false;
    }
    int i = 0;
    int j = 0;
    while(i < sLen && j < tLen){
        if(s[i] == t[j]){
            i++;
        }
        j++;
    }
    if(i == sLen){
        return true;
    }
    return false;

}

    