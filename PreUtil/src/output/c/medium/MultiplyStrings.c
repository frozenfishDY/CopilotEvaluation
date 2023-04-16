/**https://leetcode.com/problems/multiply-strings/ */
//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.


char * multiply(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2;
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    for(int i = 0; i < len; i++){
        result[i] = '0';
    }
    for(int i = len1 - 1; i >= 0; i--){
        for(int j = len2 - 1; j >= 0; j--){
            int temp = (num1[i] - '0') * (num2[j] - '0');
            int sum = temp + (result[i + j + 1] - '0');
            result[i + j + 1] = sum % 10 + '0';
            result[i + j] += sum / 10;
        }
    }
    int i = 0;
    while(result[i] == '0'){
        i++;
    }
    if(i == len){
        return "0";
    }
    return result + i;

}

    