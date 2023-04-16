/**https://leetcode.com/problems/unique-substrings-in-wraparound-string/ */
//We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//Given a string s, return the number of unique non-empty substrings of s are present in base.


int findSubstringInWraproundString(char * s){
    int* count = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        count[i] = 0;
    }
    int len = strlen(s);
    int max = 0;
    for(int i = 0; i < len; i++){
        if(i > 0 && (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25)){
            max++;
        }else{
            max = 1;
        }
        int index = s[i] - 'a';
        if(count[index] < max){
            count[index] = max;
        }
    }
    int result = 0;
    for(int i = 0; i < 26; i++){
        result += count[i];
    }
    return result;

}

    