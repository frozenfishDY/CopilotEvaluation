/**https://leetcode.com/problems/to-lower-case/ */
//Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.


char * toLowerCase(char * s){
    int len = strlen(s);
    int i = 0;
    for(i = 0; i < len; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32;
        }
    }
    return s;

}

    