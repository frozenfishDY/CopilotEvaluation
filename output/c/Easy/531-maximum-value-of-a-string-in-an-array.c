/**https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/ */
//The value of an alphanumeric string can be defined as:
//The numeric representation of the string in base 10, if it comprises of digits only.
//The length of the string, otherwise.
//Given an array strs of alphanumeric strings, return the maximum value of any string in strs.


int maximumValue(char ** strs, int strsSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;
    int result = 0;
    int temp = 0;
    for(i = 0; i < strsSize - 1; i++){
        for(j = 0; j < strsSize - i - 1; j++){
            if(strlen(strs[j]) > strlen(strs[j + 1])){
                char *temp = strs[j];
                strs[j] = strs[j + 1];
                strs[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < strsSize; i++){
        for(j = 0; j < strlen(strs[i]); j++){
            if(strs[i][j] >= '0' && strs[i][j] <= '9'){
                flag = 1;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            temp = atoi(strs[i]);
        }else{
            temp = strlen(strs[i]);
        }
        if(temp > result){
            result = temp;
        }
    }
    return result;

}

    