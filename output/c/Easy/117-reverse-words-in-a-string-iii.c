/**https://leetcode.com/problems/reverse-words-in-a-string-iii/ */
//Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


char * reverseWords(char * s){
    int len = strlen(s);
    int i = 0;
    int j = 0;
    int temp = 0;
    while(i < len){
        if(s[i] == ' '){
            i++;
            continue;
        }
        j = i;
        while(j < len && s[j] != ' '){
            j++;
        }
        j--;
        while(i < j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        i = j + 1;
    }
    return s;

}

    