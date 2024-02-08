/**https://leetcode.com/problems/longest-word-in-dictionary/ */
//Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
//If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
//Note that the word should be built from left to right with each additional character being added to the end of a previous word. 


class LongestWordInDictionary {
    public String longestWord(String[] words) {
        Arrays.sort(words);
        Set<String> set = new HashSet<>();
        String res = "";
        for(String word : words){
            if(word.length() == 1 || set.contains(word.substring(0, word.length() - 1))){
                res = word.length() > res.length() ? word : res;
                set.add(word);
            }
        }
        return res;
        
    }
}

    