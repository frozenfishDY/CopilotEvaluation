/**https://leetcode.com/problems/reverse-words-in-a-string/ */
//Given an input string s, reverse the order of the words.
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//Return a string of the words in reverse order concatenated by a single space.
//Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.


char * reverseWords(char * s){
    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    result[0] = '\0';
    int i = len - 1;
    int j = len;
    while(i >= 0){
        if(s[i] == ' '){
            i--;
            continue;
        }
        j = i;
        while(i >= 0 && s[i] != ' '){
            i--;
        }
        if(result[0] != '\0'){
            strcat(result, " ");
        }
        strncat(result, s + i + 1, j - i);
    }
    return result;

}

    