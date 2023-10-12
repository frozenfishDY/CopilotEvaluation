/**https://leetcode.com/problems/replace-words/ */
//In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
//Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
//Return the sentence after the replacement.
// 
//Example 1:
//Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
//Output: "the cat was rat by the bat"
//Example 2:
//Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
//Output: "a a b c"
// 
//Constraints:
//	1 <= dictionary.length <= 1000
//	1 <= dictionary[i].length <= 100
//	dictionary[i] consists of only lower-case letters.
//	1 <= sentence.length <= 106
//	sentence consists of only lower-case letters and spaces.
//	The number of words in sentence is in the range [1, 1000]
//	The length of each word in sentence is in the range [1, 1000]
//	Every two consecutive words in sentence will be separated by exactly one space.
//	sentence does not have leading or trailing spaces.
class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (String word : dictionary) {
            trie.insert(word);
        }
        StringBuilder sb = new StringBuilder();
        for (String word : sentence.split(" ")) {
            sb.append(trie.getShortestPrefix(word));
            sb.append(" ");
        }
        return sb.substring(0, sb.length() - 1);
    }
    class TrieNode {
        TrieNode[] children;
        boolean isWord;
        public TrieNode() {
            children = new TrieNode[26];
        }
    }
    class Trie {
        TrieNode root;
        public Trie() {
            root = new TrieNode();
        }
        public void insert(String word) {
            TrieNode cur = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (cur.children[index] == null) {
                    cur.children[index] = new TrieNode();
                }
                cur = cur.children[index];
            }
            cur.isWord = true;
        }
        public String getShortestPrefix(String word) {
            TrieNode cur = root;
            int i = 0;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (cur.children[index] == null) {
                    break;
                }
                cur = cur.children[index];
                i++;
                if (cur.isWord) {
                    return word.substring(0, i);
                }
            }
            return word;
        }
    }
}