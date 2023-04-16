/**https://leetcode.com/problems/number-of-matching-subsequences/ */
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//For example, "ace" is a subsequence of "abcde".


class NumberOfMatchingSubsequences {
    public int numMatchingSubseq(String s, String[] words) {
        int res = 0;
        Map<Character, Queue<String>> map = new HashMap<>();
        for(char c = 'a'; c <= 'z'; c++){
            map.put(c, new LinkedList<>());
        }
        for(String word : words){
            map.get(word.charAt(0)).offer(word);
        }
        for(char c : s.toCharArray()){
            Queue<String> q = map.get(c);
            int size = q.size();
            for(int i = 0; i < size; i++){
                String word = q.poll();
                if(word.length() == 1){
                    res++;
                }else{
                    map.get(word.charAt(1)).offer(word.substring(1));
                }
            }
        }
        return res;
        
        
    }
}

    