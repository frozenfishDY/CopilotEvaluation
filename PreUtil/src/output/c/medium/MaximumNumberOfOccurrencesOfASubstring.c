/**https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/ */
//Given a string s, return the maximum number of ocurrences of any substring under the following rules:
//The number of unique characters in the substring must be less than or equal to maxLetters.
//The substring size must be between minSize and maxSize inclusive.


int maxFreq(char * s, int maxLetters, int minSize, int maxSize){
    int result = 0;
    int length = strlen(s);
    int* count = (int*)malloc(sizeof(int) * 26);
    int* map = (int*)malloc(sizeof(int) * 100000);
    for(int i = 0; i < 100000; i++){
        map[i] = 0;
    }
    for(int i = 0; i < length; i++){
        int unique = 0;
        for(int j = 0; j < 26; j++){
            count[j] = 0;
        }
        for(int j = i; j < length; j++){
            if(count[s[j] - 'a'] == 0){
                unique++;
            }
            count[s[j] - 'a']++;
            if(unique > maxLetters){
                break;
            }
            if(j - i + 1 >= minSize && j - i + 1 <= maxSize){
                map[(s[i] - 'a') * 10000 + (s[j] - 'a') * 100 + (j - i + 1)]++;
                if(map[(s[i] - 'a') * 10000 + (s[j] - 'a') * 100 + (j - i + 1)] > result){
                    result = map[(s[i] - 'a') * 10000 + (s[j] - 'a') * 100 + (j - i + 1)];
                }
            }
        }
    }
    return result;

}

    