/**https://leetcode.com/problems/sentence-similarity-iii/ */
//A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words consist of only uppercase and lowercase English letters.
//Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. For example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in sentence2.
//Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.


class SentenceSimilarityIii {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] s1 = sentence1.split(" ");
        String[] s2 = sentence2.split(" ");
        int i = 0, j = 0;
        while (i < s1.length && j < s2.length && s1[i].equals(s2[j])) {
            i++;
            j++;
        }
        int k = s1.length - 1, l = s2.length - 1;
        while (k >= i && l >= j && s1[k].equals(s2[l])) {
            k--;
            l--;
        }
        return k < i && l < j;
        
    }
}
     
    