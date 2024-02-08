/**https://leetcode.com/problems/add-binary/ */
//Given two binary strings a and b, return their sum as a binary string.

char * addBinary(char * a, char * b){
    int aLen = strlen(a);
    int bLen = strlen(b);
    int maxLen = aLen > bLen ? aLen : bLen;
    char *result = (char *)malloc(sizeof(char) * (maxLen + 2));
    int carry = 0;
    int i = aLen - 1;
    int j = bLen - 1;
    int k = maxLen;
    while(i >= 0 || j >= 0){
        int aBit = i >= 0 ? a[i] - '0' : 0;
        int bBit = j >= 0 ? b[j] - '0' : 0;
        int sum = aBit + bBit + carry;
        if(sum == 0){
            result[k] = '0';
            carry = 0;
        }else if(sum == 1){
            result[k] = '1';
            carry = 0;
        }else if(sum == 2){
            result[k] = '0';
            carry = 1;
        }else if(sum == 3){
            result[k] = '1';
            carry = 1;
        }
        i--;
        j--;
        k--;
    }
    if(carry == 1){
        result[0] = '1';
        result[maxLen + 1] = '\0';
        return result;
    }else{
        result[maxLen + 1] = '\0';
        return result + 1;
    }

}
    