/**https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/ */
//You are given two strings s and t consisting of only lowercase English letters.
//Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.


int appendCharacters(char * s, char * t){
    int length = strlen(t);
    int index = 0;
    for(int i = 0; i < length; i++){
        while(s[index] != '\0' && s[index] != t[i]){
            index++;
        }
        if(s[index] == '\0'){
            return -1;
        }
        index++;
    }
    return index - length - 1;

}

    