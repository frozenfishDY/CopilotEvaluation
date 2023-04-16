#https://leetcode.com/problems/vowel-spellchecker/
#Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
#For a given query word, the spell checker handles two categories of spelling mistakes:
#Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
#Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
#Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
#Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
#Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
#Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
#Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
#Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
#In addition, the spell checker operates under the following precedence rules:
#When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
#When the query matches a word up to capitlization, you should return the first such match in the wordlist.
#When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
#If the query has no matches in the wordlist, you should return the empty string.
#Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].


class Solution(object):
    def spellchecker(self, wordlist, queries):
        """
        :type wordlist: List[str]
        :type queries: List[str]
        :rtype: List[str]
        """
        wordset = set(wordlist)
        cap = {}
        vowel = {}
        for word in wordlist:
            w_lower = word.lower()
            if w_lower not in cap:
                cap[w_lower] = word
            w_novowel = re.sub('[aeiou]', '#', w_lower)
            if w_novowel not in vowel:
                vowel[w_novowel] = word
        ans = []
        for query in queries:
            q_lower = query.lower()
            if query in wordset:
                ans.append(query)
            elif q_lower in cap:
                ans.append(cap[q_lower])
            else:
                q_novowel = re.sub('[aeiou]', '#', q_lower)
                if q_novowel in vowel:
                    ans.append(vowel[q_novowel])
                else:
                    ans.append("")
        return ans
        

    