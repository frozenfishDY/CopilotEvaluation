/**https://leetcode.com/problems/substring-with-concatenation-of-all-words/ */
//You are given a string s and an array of strings words. All the strings of words are of the same length.
//A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
//For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
//Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.


class SubstringWithConcatenationOfAllWords {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if(words.length == 0) return res;
        int wordLen = words[0].length();
        int totalLen = wordLen * words.length;
        Map<String, Integer> map = new HashMap<>();
        for(String word : words){
            map.put(word, map.getOrDefault(word, 0) + 1);
        }
        for(int i = 0; i < s.length() - totalLen + 1; i++){
            Map<String, Integer> seen = new HashMap<>();
            int j = 0;
            while(j < words.length){
                String word = s.substring(i + j * wordLen, i + (j + 1) * wordLen);
                if(!map.containsKey(word)) break;
                seen.put(word, seen.getOrDefault(word, 0) + 1);
                if(seen.get(word) > map.get(word)) break;
                j++;
            }
            if(j == words.length) res.add(i);
        }
        return res;
        
    }
}
     
    