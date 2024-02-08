/**https://leetcode.com/problems/count-binary-substrings/ */
//Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
//Substrings that occur multiple times are counted the number of times they occur.


int countBinarySubstrings(char * s){
    int len = strlen(s);
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < len){
        j = i;
        while(j < len && s[j] == s[i]){
            j++;
        }
        int k = j;
        while(k < len && s[k] != s[i] && k - j < j - i){
            k++;
        }
        if(k - j == j - i){
            count++;
        }
        i = j;
    }
    return count;

}

    