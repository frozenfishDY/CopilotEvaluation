/**https://leetcode.com/problems/vowel-spellchecker/ */
//Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
//For a given query word, the spell checker handles two categories of spelling mistakes:
//Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
//Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
//Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
//Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
//Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
//Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
//Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
//Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
//In addition, the spell checker operates under the following precedence rules:
//When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
//When the query matches a word up to capitlization, you should return the first such match in the wordlist.
//When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
//If the query has no matches in the wordlist, you should return the empty string.
//Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].


class VowelSpellchecker {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        String[] res = new String[queries.length];
        Set<String> set = new HashSet<>();
        Map<String, String> map = new HashMap<>();
        Map<String, String> map2 = new HashMap<>();
        for(String word : wordlist){
            set.add(word);
            String lower = word.toLowerCase();
            map.putIfAbsent(lower, word);
            String vowel = lower.replaceAll("[aeiou]", "#");
            map2.putIfAbsent(vowel, word);
        }
        for(int i = 0; i < queries.length; i++){
            if(set.contains(queries[i])){
                res[i] = queries[i];
            }else{
                String lower = queries[i].toLowerCase();
                if(map.containsKey(lower)){
                    res[i] = map.get(lower);
                }else{
                    String vowel = lower.replaceAll("[aeiou]", "#");
                    if(map2.containsKey(vowel)){
                        res[i] = map2.get(vowel);
                    }else{
                        res[i] = "";
                    }
                }
            }
        }
        return res;
        
        
        
    }
}

    