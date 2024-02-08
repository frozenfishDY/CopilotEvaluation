/**https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/ */
//Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
//A substring is a contiguous sequence of characters within a string.


bool queryString(char * s, int n){
    int length = strlen(s);
    int* index = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        index[i] = 0;
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < n; j++){
            if(index[j] == -1){
                continue;
            }
            if(s[i] == '1'){
                index[j]++;
            }
            if(index[j] == j + 1){
                index[j] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(index[i] != -1){
            return false;
        }
    }
    return true;

}

    