/**https://leetcode.com/problems/custom-sort-string/ */
//You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
//Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
//Return any permutation of s that satisfies this property.


char * customSortString(char * order, char * s){
    int* count = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        count[i] = 0;
    }
    for(int i = 0; i < strlen(s); i++){
        count[s[i] - 'a']++;
    }
    char* result = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    result[0] = '\0';
    for(int i = 0; i < strlen(order); i++){
        for(int j = 0; j < count[order[i] - 'a']; j++){
            char temp[2];
            temp[0] = order[i];
            temp[1] = '\0';
            strcat(result, temp);
        }
        count[order[i] - 'a'] = 0;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < count[i]; j++){
            char temp[2];
            temp[0] = i + 'a';
            temp[1] = '\0';
            strcat(result, temp);
        }
    }
    return result;


}

    