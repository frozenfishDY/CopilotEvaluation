#https://leetcode.com/problems/maximum-score-words-formed-by-letters/
#Given a list of words, list of  single letters (might be repeating) and score of every character.
#Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
#It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.


class Solution(object):
    def maxScoreWords(self, words, letters, score):
        """
        :type words: List[str]
        :type letters: List[str]
        :type score: List[int]
        :rtype: int
        """
        def get_score(word):
            return sum(score[ord(c) - ord('a')] for c in word)
        
        def get_score_with_letters(word, letters):
            letters = letters[:]
            for c in word:
                if c in letters:
                    letters.remove(c)
                else:
                    return 0
            return get_score(word)
        
        def get_score_with_letters_and_words(words, letters):
            letters = letters[:]
            score = 0
            for word in words:
                if all(c in letters for c in word):
                    score += get_score(word)
                    for c in word:
                        letters.remove(c)
                else:
                    return 0
            return score
        
        def get_max_score(words, letters):
            if not words:
                return 0
            if not letters:
                return 0
            word = words[0]
            score_without_word = get_max_score(words[1:], letters)
            score_with_word = get_score_with_letters(word, letters)
            if score_with_word:
                score_with_word += get_max_score(words[1:], letters)
            return max(score_without_word, score_with_word)
        
        def get_max_score_with_words(words, letters):
            if not words:
                return 0
            if not letters:
                return 0
            word = words[0]
            score_without_word = get_max_score_with_words(words[1:], letters)
            score_with_word = get_score_with_letters_and_words([word], letters)
            if score_with_word:
                score_with_word += get_max_score_with_words(words[1:], letters)
            return max(score_without_word, score_with_word)
        
        return get_max_score_with_words(words, letters)
        
        
        
    