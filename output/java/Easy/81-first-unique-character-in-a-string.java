/**https://leetcode.com/problems/first-unique-character-in-a-string/ */
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


class FirstUniqueCharacterInAString {
    public int firstUniqChar(String s) {
        int[] count = new int[26];
        for(int i = 0; i < s.length(); i++){
            count[s.charAt(i) - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(count[s.charAt(i) - 'a'] == 1){
                return i;
            }
        }
        return -1;
        
    }
}

    