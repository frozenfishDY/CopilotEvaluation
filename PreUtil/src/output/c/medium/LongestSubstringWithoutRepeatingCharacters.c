/**https://leetcode.com/problems/longest-substring-without-repeating-characters/ */
//Given a string s, find the length of the longest substring without repeating characters.


int lengthOfLongestSubstring(char * s){
    int i = 0;
    int j = 0;
    int k = 0;
    int max = 0;
    int count = 0;
    int len = strlen(s);
    int flag = 0;
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
        }
        count = 0;
    }
    return max;

}

    