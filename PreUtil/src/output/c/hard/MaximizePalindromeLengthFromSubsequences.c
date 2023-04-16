/**https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/ */
//You are given two strings, word1 and word2. You want to construct a string in the following manner:
//Choose some non-empty subsequence subsequence1 from word1.
//Choose some non-empty subsequence subsequence2 from word2.
//Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
//Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.
//A subsequence of a string s is a string that can be made by deleting some (possibly none) characters from s without changing the order of the remaining characters.
//A palindrome is a string that reads the same forward as well as backward.


int longestPalindrome(char * word1, char * word2){
    int i,j,k;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int len = len1 + len2;
    char* word = (char*)malloc(sizeof(char)*(len+1));
    for(i=0;i<len1;i++){
        word[i] = word1[i];
    }
    for(i=0;i<len2;i++){
        word[i+len1] = word2[i];
    }
    word[len] = '\0';
    int* arr = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr[i] = 0;
    }
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(word[i] == word[j]){
                arr[i] = arr[i] + 1;
            }
        }
    }
    int max = 0;
    for(i=0;i<len;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int sum = 0;
    for(i=0;i<len;i++){
        if(arr[i] == max){
            sum = sum + 1;
        }
    }
    return sum;

}

    