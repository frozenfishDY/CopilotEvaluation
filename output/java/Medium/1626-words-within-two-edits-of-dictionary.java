/**https://leetcode.com/problems/words-within-two-edits-of-dictionary/ */
//You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.
//In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.
//Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.


class WordsWithinTwoEditsOfDictionary {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        Set<String> dict = new HashSet<>(Arrays.asList(dictionary));
        List<String> res = new ArrayList<>();
        for(String query : queries){
            if(dict.contains(query)){
                res.add(query);
            }else{
                if(canEdit(query, dict)){
                    res.add(query);
                }
            }
        }
        return res;
        
        
    }
}
     
    