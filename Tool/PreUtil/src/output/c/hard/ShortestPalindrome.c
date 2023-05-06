/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.


char * shortestPalindrome(char * s){
    int len = strlen(s);
    int* next = (int*)malloc(sizeof(int) * len);
    memset(next, 0, sizeof(int) * len);
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len - 1){
        if(j == -1 || s[i] == s[j]){
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
    int k = 0;
    for(int i = len - 1; i >= 0; i--){
        while(k != -1 && s[k] != s[i]){
            k = next[k];
        }
        k++;
    }
    char* res = (char*)malloc(sizeof(char) * (len * 2 - k + 1));
    memset(res, 0, sizeof(char) * (len * 2 - k + 1));
    for(int i = 0; i < len - k; i++){
        res[i] = s[len - i - 1];
    }
    for(int i = len - k; i < len * 2 - k; i++){
        res[i] = s[i - len + k];
    }
    return res;

}

    