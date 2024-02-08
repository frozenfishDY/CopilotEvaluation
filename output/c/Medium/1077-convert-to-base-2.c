/**https://leetcode.com/problems/convert-to-base-2/ */
//Given an integer n, return a binary string representing its representation in base -2.
//Note that the returned string should not have leading zeros unless the string is "0".


char * baseNeg2(int n){
    char* result = (char*)malloc(sizeof(char) * 32);
    int i = 0;
    while(n != 0){
        result[i++] = n % 2 + '0';
        n = -(n / 2);
    }
    if(i == 0){
        result[i++] = '0';
    }
    result[i] = '\0';
    for(int j = 0; j < i / 2; j++){
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }
    return result;

}

    