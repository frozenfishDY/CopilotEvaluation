/**https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/ */
//You are given a string s, an integer k, a letter letter, and an integer repetition.
//Return the lexicographically smallest subsequence of s of length k that has the letter letter appear at least repetition times. The test cases are generated so that the letter appears in s at least repetition times.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.


char * smallestSubsequence(char * s, int k, char letter, int repetition){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*2);
    for(i=0;i<2;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=0;i<strlen(s);i++){
        if(s[i] == '0'){
            arr[0] = (arr[0] + arr[1])%1000000007;
        }
        else{
            arr[1] = (arr[0] + arr[1])%1000000007;
        }
    }
    return arr[0];

}

    