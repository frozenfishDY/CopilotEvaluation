/**https://leetcode.com/problems/ransom-note/ */
//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.


bool canConstruct(char * ransomNote, char * magazine){
    int len1 = strlen(ransomNote);
    int len2 = strlen(magazine);
    if(len1 > len2){
        return false;
    }
    int arr[26] = {0};
    for(int i = 0; i < len2; i++){
        arr[magazine[i] - 'a']++;
    }
    for(int i = 0; i < len1; i++){
        arr[ransomNote[i] - 'a']--;
        if(arr[ransomNote[i] - 'a'] < 0){
            return false;
        }
    }
    return true;

}

    