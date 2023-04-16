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


/**
 * @param {string[]} wordlist
 * @param {string[]} queries
 * @return {string[]}
 */
var spellchecker = function(wordlist, queries) {
    let result = [];
    let set = new Set(wordlist);
    let map1 = new Map();
    let map2 = new Map();
    for(let word of wordlist){
        let lower = word.toLowerCase();
        if(!map1.has(lower)){
            map1.set(lower, word);
        }
        let noVowel = lower.replace(/[aeiou]/g, "#");
        if(!map2.has(noVowel)){
            map2.set(noVowel, word);
        }
    }
    for(let query of queries){
        if(set.has(query)){
            result.push(query);
        }else{
            let lower = query.toLowerCase();
            if(map1.has(lower)){
                result.push(map1.get(lower));
            }else{
                let noVowel = lower.replace(/[aeiou]/g, "#");
                if(map2.has(noVowel)){
                    result.push(map2.get(noVowel));
                }else{
                    result.push("");
                }
            }
        }
    }
    return result;
    
    
};

    