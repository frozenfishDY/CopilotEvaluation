/**https://leetcode.com/problems/sum-of-scores-of-built-strings/ */
//You are building a string s of length n one character at a time, prepending each new character to the front of the string. The strings are labeled from 1 to n, where the string with length i is labeled si.
//For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.
//The score of si is the length of the longest common prefix between si and sn (Note that s == sn).
//Given the final string s, return the sum of the score of every si.


long long sumScores(char * s){
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

    