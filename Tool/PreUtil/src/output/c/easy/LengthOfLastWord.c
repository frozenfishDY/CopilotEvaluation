/**https://leetcode.com/problems/length-of-last-word/ */
//Given a string s consisting of words and spaces, return the length of the last word in the string.
//A word is a maximal substring consisting of non-space characters only.

int lengthOfLastWord(char * s){
    int len = strlen(s);
    int i = len - 1;
    int count = 0;
    while(i >= 0){
        if(s[i] == ' '){
            if(count == 0){
                i--;
                continue;
            }
            else{
                break;
            }
        }
        count++;
        i--;
    }
    return count;

}
    