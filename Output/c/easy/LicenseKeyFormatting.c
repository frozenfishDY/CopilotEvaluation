/**https://leetcode.com/problems/license-key-formatting/ */
//You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
//We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
//Return the reformatted license key.


char * licenseKeyFormatting(char * s, int k){
    int len = strlen(s);
    int count = 0;
    for(int i = 0; i < len; i++){
        if(s[i] != '-'){
            count++;
        }
    }
    int first = count % k;
    int second = count / k;
    char *result = (char *)malloc(sizeof(char) * (count + second + 1));
    int index = 0;
    int temp = 0;
    for(int i = 0; i < len; i++){
        if(s[i] != '-'){
            if(temp < first){
                if(s[i] >= 'a' && s[i] <= 'z'){
                    result[index++] = s[i] - 32;
                }
                else{
                    result[index++] = s[i];
                }
                temp++;
            }
            else{
                if(temp == k){
                    result[index++] = '-';
                    temp = 0;
                }
                if(s[i] >= 'a' && s[i] <= 'z'){
                    result[index++] = s[i] - 32;
                }
                else{
                    result[index++] = s[i];
                }
                temp++;
            }
        }
    }
    result[index] = '\0';
    return result;

}

    