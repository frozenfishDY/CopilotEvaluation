/**https://leetcode.com/problems/count-anagrams/ */
//You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.
//A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.
//For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
//Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 10^9 + 7.


int countAnagrams(char * s){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*100000);
    for(i=0;i<100000;i++){
        arr[i] = 0;
    }
    int len = strlen(s);
    int* arr2 = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr2[i] = 0;
    }
    for(i=0;i<len;i++){
        if(s[i]==' '){
            return 0;
        }
        int num = 0;
        for(j=i;j<len;j++){
            num = num*10 + (s[j]-'0');
            if(num<=100000){
                if(i==0){
                    arr[j] = 1;
                }
                else{
                    arr[j] = (arr[j] + arr2[i-1]) % 1000000007;
                }
            }
            else{
                break;
            }
        }
        for(j=0;j<len;j++){
            arr2[j] = arr[j];
        }
    }
    return arr[len-1];


}

    