/**https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/ */
//You are given a 0-indexed string text and another 0-indexed string pattern of length 2, both of which consist of only lowercase English letters.
//You can add either pattern[0] or pattern[1] anywhere in text exactly once. Note that the character can be added even at the beginning or at the end of text.
//Return the maximum number of times pattern can occur as a subsequence of the modified text.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.


long long maximumSubsequenceCount(char * text, char * pattern){
    long long i, j;
    long long count = 0;
    long long arr[100000] = {0};
    for(i = 0; i < strlen(text); i++){
        if(text[i] == pattern[0]){
            arr[i]++;
        }
    }
    for(i = 0; i < strlen(text); i++){
        if(text[i] == pattern[1]){
            for(j = 0; j < i; j++){
                arr[i] += arr[j];
            }
        }
    }
    for(i = 0; i < strlen(text); i++){
        count += arr[i];
    }
    return count;

}

    