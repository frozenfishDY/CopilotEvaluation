/**https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ */
//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


int strStr(char * haystack, char * needle){
    int i = 0;
    int j = 0;
    int k = 0;
    int len = strlen(needle);
    if(len == 0){
        return 0;
    }
    while(haystack[i] != '\0'){
        if(haystack[i] == needle[j]){
            k = i;
            while(haystack[k] == needle[j]){
                k++;
                j++;
                if(j == len){
                    return i;
                }
            }
            j = 0;
        }
        i++;
    }
    return -1;

}

    