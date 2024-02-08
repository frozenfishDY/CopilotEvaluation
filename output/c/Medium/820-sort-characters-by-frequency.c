/**https://leetcode.com/problems/sort-characters-by-frequency/ */
//Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
//Return the sorted string. If there are multiple answers, return any of them.


char * frequencySort(char * s){
    int* count = (int*)malloc(sizeof(int) * 128);
    for(int i = 0; i < 128; i++){
        count[i] = 0;
    }
    for(int i = 0; i < strlen(s); i++){
        count[s[i]]++;
    }
    int max = 0;
    for(int i = 0; i < 128; i++){
        if(count[i] > max){
            max = count[i];
        }
    }
    char** result = (char**)malloc(sizeof(char*) * (max + 1));
    for(int i = 0; i <= max; i++){
        result[i] = (char*)malloc(sizeof(char) * (strlen(s) + 1));
        result[i][0] = '\0';
    }
    for(int i = 0; i < 128; i++){
        if(count[i] > 0){
            for(int j = 0; j < count[i]; j++){
                char temp[2];
                temp[0] = i;
                temp[1] = '\0';
                strcat(result[count[i]], temp);
            }
        }
    }
    char* finalResult = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    finalResult[0] = '\0';
    for(int i = max; i >= 0; i--){
        if(result[i][0] != '\0'){
            strcat(finalResult, result[i]);
        }
    }
    return finalResult;

}

    