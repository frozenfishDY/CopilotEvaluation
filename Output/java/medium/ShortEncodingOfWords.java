/**https://leetcode.com/problems/short-encoding-of-words/ */
//A valid encoding of an array of words is any reference string s and array of indices indices such that:
//words.length == indices.length
//The reference string s ends with the '#' character.
//For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
//Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.


class ShortEncodingOfWords {
    public int minimumLengthEncoding(String[] words) {
        TrieNode root = new TrieNode();
        Map<TrieNode, Integer> nodes = new HashMap<>();
        for(int i = 0; i < words.length; i++){
            String word = words[i];
            TrieNode cur = root;
            for(int j = word.length() - 1; j >= 0; j--){
                char c = word.charAt(j);
                if(cur.children[c - 'a'] == null){
                    cur.children[c - 'a'] = new TrieNode();
                }
                cur = cur.children[c - 'a'];
            }
            nodes.put(cur, i);
        }
        int res = 0;
        for(TrieNode node : nodes.keySet()){
            if(node.count == 0){
                res += words[nodes.get(node)].length() + 1;
            }
        }
        return res;
        
        
        
    }
}

    