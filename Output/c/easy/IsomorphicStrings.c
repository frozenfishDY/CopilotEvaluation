/**https://leetcode.com/problems/isomorphic-strings/ */
//Given two strings s and t, determine if they are isomorphic.
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

bool isIsomorphic(char * s, char * t){
    int sLen = strlen(s);
    int tLen = strlen(t);
    if(sLen != tLen){
        return false;
    }
    int sMap[128] = {0};
    int tMap[128] = {0};
    for(int i = 0; i < sLen; i++){
        if(sMap[s[i]] != tMap[t[i]]){
            return false;
        }
        sMap[s[i]] = i + 1;
        tMap[t[i]] = i + 1;
    }
    return true;

}
    