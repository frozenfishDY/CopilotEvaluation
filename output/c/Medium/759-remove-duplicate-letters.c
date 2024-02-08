/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.


char * removeDuplicateLetters(char * s){
    int* count = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        count[i] = 0;
    }
    int sSize = strlen(s);
    for(int i = 0; i < sSize; i++){
        count[s[i] - 'a']++;
    }
    int* visited = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        visited[i] = 0;
    }
    char* result = (char*)malloc(sizeof(char) * (sSize + 1));
    int resultSize = 0;
    for(int i = 0; i < sSize; i++){
        count[s[i] - 'a']--;
        if(visited[s[i] - 'a'] == 1){
            continue;
        }
        while(resultSize > 0 && result[resultSize - 1] > s[i] && count[result[resultSize - 1] - 'a'] > 0){
            visited[result[resultSize - 1] - 'a'] = 0;
            resultSize--;
        }
        result[resultSize++] = s[i];
        visited[s[i] - 'a'] = 1;
    }
    result[resultSize] = '\0';
    return result;

}

    