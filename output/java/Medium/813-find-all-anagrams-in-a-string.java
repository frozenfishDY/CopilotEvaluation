/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


class FindAllAnagramsInAString {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int[] map = new int[26];
        for(char c : p.toCharArray()){
            map[c - 'a']++;
        }
        int left = 0;
        int right = 0;
        int count = p.length();
        while(right < s.length()){
            if(map[s.charAt(right++) - 'a']-- >= 1){
                count--;
            }
            if(count == 0){
                res.add(left);
            }
            if(right - left == p.length() && map[s.charAt(left++) - 'a']++ >= 0){
                count++;
            }
        }
        return res;
        
    }
}

    