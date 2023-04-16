/**https://leetcode.com/problems/longest-substring-of-one-repeating-character/ */
//You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
//The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
//Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* longestRepeating(char * s, char * queryCharacters, int* queryIndices, int queryIndicesSize, int* returnSize){
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

    