/**https://leetcode.com/problems/first-unique-character-in-a-string/ */
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


int firstUniqChar(char * s){
    int count[26] = {0};
    int i = 0;
    while(s[i] != '\0'){
        count[s[i] - 'a']++;
        i++;
    }
    i = 0;
    while(s[i] != '\0'){
        if(count[s[i] - 'a'] == 1){
            return i;
        }
        i++;
    }
    return -1;

}

    