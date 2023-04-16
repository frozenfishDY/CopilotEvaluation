/**https://leetcode.com/problems/restore-ip-addresses/ */
//A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
//For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** restoreIpAddresses(char * s, int* returnSize){
    int len = strlen(s);
    char **result = (char**)malloc(sizeof(char*) * 1000);
    int resultSize = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            for(int k = 1; k <= 3; k++){
                for(int l = 1; l <= 3; l++){
                    if(i + j + k + l == len){
                        int a = atoi(s);
                        int b = atoi(s + i);
                        int c = atoi(s + i + j);
                        int d = atoi(s + i + j + k);
                        if(a <= 255 && b <= 255 && c <= 255 && d <= 255){
                            char *temp = (char*)malloc(sizeof(char) * (len + 4));
                            sprintf(temp, "%d.%d.%d.%d", a, b, c, d);
                            if(strlen(temp) == len + 3){
                                result[resultSize++] = temp;
                            }
                        }
                    }
                }
            }
        }
    }
    *returnSize = resultSize;
    return result;

}

    