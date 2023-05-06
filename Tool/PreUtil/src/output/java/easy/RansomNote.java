/**https://leetcode.com/problems/ransom-note/ */
//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.


class RansomNote {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] count = new int[26];
        for(int i = 0; i < magazine.length(); i++){
            count[magazine.charAt(i) - 'a']++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            count[ransomNote.charAt(i) - 'a']--;
            if(count[ransomNote.charAt(i) - 'a'] < 0) return false;
        }
        return true;
        
    }
}

    