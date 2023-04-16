/**https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/ */
//Let's define a function countUniqueChars(s) that returns the number of unique characters on s.
//For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
//Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.
//Notice that some substrings can be repeated so in this case you have to count the repeated ones too.


int uniqueLetterString(char * s){
    int len = strlen(s);
    int* last = (int*)malloc(sizeof(int) * 26);
    int* next = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        last[i] = -1;
        next[i] = -1;
    }
    for(int i = 0; i < len; i++){
        next[s[i] - 'A'] = i;
    }
    int result = 0;
    for(int i = 0; i < len; i++){
        int c = s[i] - 'A';
        result += (i - last[c]) * (next[c] - i);
        last[c] = i;
    }
    return result;

}

    