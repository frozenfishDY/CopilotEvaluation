/**https://leetcode.com/problems/number-of-segments-in-a-string/ */
//Given a string s, return the number of segments in the string.
//A segment is defined to be a contiguous sequence of non-space characters.


int countSegments(char * s){
    int count = 0;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] != ' ' && (i == 0 || s[i - 1] == ' ')){
            count++;
        }
        i++;
    }
    return count;

}

    