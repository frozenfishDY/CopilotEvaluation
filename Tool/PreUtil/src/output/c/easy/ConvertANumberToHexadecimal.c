/**https://leetcode.com/problems/convert-a-number-to-hexadecimal/ */
//Given an integer num, return a string representing its hexadecimal representation. For negative integers, two��s complement method is used.
//All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.
//Note: You are not allowed to use any built-in library method to directly solve this problem.


char * toHex(int num){
    if(num == 0){
        return "0";
    }
    char *result = (char *)malloc(sizeof(char) * 9);
    int index = 0;
    while(num != 0 && index < 8){
        int temp = num & 0xf;
        if(temp < 10){
            result[index++] = temp + '0';
        }
        else{
            result[index++] = temp - 10 + 'a';
        }
        num >>= 4;
    }
    result[index] = '\0';
    int left = 0;
    int right = index - 1;
    while(left < right){
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }
    return result;

}

    