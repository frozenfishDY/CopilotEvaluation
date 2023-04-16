/**https://leetcode.com/problems/orderly-queue/ */
//You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..
//Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.


char * orderlyQueue(char * s, int k){
    int len = strlen(s);
    if(k == 1){
        char* res = (char*)malloc(sizeof(char) * (len + 1));
        memset(res, 0, sizeof(char) * (len + 1));
        strcpy(res, s);
        for(int i = 0; i < len; i++){
            char* temp = (char*)malloc(sizeof(char) * (len + 1));
            memset(temp, 0, sizeof(char) * (len + 1));
            for(int j = 0; j < len; j++){
                temp[j] = s[(i + j) % len];
            }
            if(strcmp(temp, res) < 0){
                strcpy(res, temp);
            }
        }
        return res;
    }else{
        char* res = (char*)malloc(sizeof(char) * (len + 1));
        memset(res, 0, sizeof(char) * (len + 1));
        strcpy(res, s);
        qsort(res, len, sizeof(char), cmp);
        return res;
    }

}

    