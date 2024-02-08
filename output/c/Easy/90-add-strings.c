/**https://leetcode.com/problems/add-strings/ */
//Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
//You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.


char * addStrings(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 > len2 ? len1 : len2;
    char *result = (char *)malloc(sizeof(char) * (len + 2));
    int index = 0;
    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    while(i >= 0 || j >= 0){
        int temp = carry;
        if(i >= 0){
            temp += num1[i] - '0';
            i--;
        }
        if(j >= 0){
            temp += num2[j] - '0';
            j--;
        }
        result[index++] = temp % 10 + '0';
        carry = temp / 10;
    }
    if(carry != 0){
        result[index++] = carry + '0';
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

    