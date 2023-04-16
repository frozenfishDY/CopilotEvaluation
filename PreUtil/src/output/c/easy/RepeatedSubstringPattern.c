/**https://leetcode.com/problems/repeated-substring-pattern/ */
//Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.


bool repeatedSubstringPattern(char * s){
    int len = strlen(s);
    for(int i = 1; i <= len / 2; i++){
        if(len % i == 0){
            int j = i;
            while(j < len){
                if(s[j] != s[j - i]){
                    break;
                }
                j++;
            }
            if(j == len){
                return true;
            }
        }
    }
    return false;

}

    