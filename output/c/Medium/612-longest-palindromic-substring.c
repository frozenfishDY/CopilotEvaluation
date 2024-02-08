/**https://leetcode.com/problems/longest-palindromic-substring/ */
//Given a string s, return the longest palindromic substring in s.


char * longestPalindrome(char * s){
    int i = 0;
    int j = 0;
    int k = 0;
    int len = strlen(s);
    int max = 0;
    int count = 0;
    int flag = 0;
    char* result = NULL;
    for(i = 0; i < len; i++){
        for(j = i; j < len; j++){
            for(k = i; k < j; k++){
                if(s[k] == s[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                flag = 0;
                break;
            }
            count++;
        }
        if(count > max){
            max = count;
            result = (char*)malloc(sizeof(char) * (max + 1));
            for(k = 0; k < max; k++){
                result[k] = s[i + k];
            }
            result[k] = '\0';
        }
        count = 0;
    }
    return result;

}

    