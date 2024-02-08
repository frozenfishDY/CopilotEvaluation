/**https://leetcode.com/problems/reverse-string-ii/ */
//Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
//If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.


char * reverseStr(char * s, int k){
    int len = strlen(s);
    int i = 0;
    int j = 0;
    int temp = 0;
    while(i < len){
        if(i + k <= len){
            j = i + k - 1;
        }
        else{
            j = len - 1;
        }
        while(i < j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        i += k;
    }
    return s;

}

    