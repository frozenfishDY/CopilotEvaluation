/**https://leetcode.com/problems/longest-common-prefix/ */
//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string "".

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0){
        return "";
    }
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;
    char *result = (char *)malloc(100 * sizeof(char));
    while(strs[0][i] != '\0'){
        for(j = 1; j < strsSize; j++){
            if(strs[0][i] != strs[j][i]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
        result[k] = strs[0][i];
        k++;
        i++;
    }
    result[k] = '\0';
    return result;

}
    