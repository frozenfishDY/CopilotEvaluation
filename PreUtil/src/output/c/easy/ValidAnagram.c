/**https://leetcode.com/problems/valid-anagram/ */
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


bool isAnagram(char * s, char * t){
    int len1 = strlen(s);
    int len2 = strlen(t);
    if(len1 != len2){
        return false;
    }
    int arr[26] = {0};
    for(int i = 0; i < len1; i++){
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0){
            return false;
        }
    }
    return true;

}

    