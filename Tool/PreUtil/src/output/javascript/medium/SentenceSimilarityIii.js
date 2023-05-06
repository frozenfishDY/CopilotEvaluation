/**https://leetcode.com/problems/sentence-similarity-iii/ */
//A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words consist of only uppercase and lowercase English letters.
//Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. For example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in sentence2.
//Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.


/**
 * @param {string} sentence1
 * @param {string} sentence2
 * @return {boolean}
 */
var areSentencesSimilar = function(sentence1, sentence2) {
    let s1 = sentence1.split(" ");
    let s2 = sentence2.split(" ");
    let i = 0;
    let j = 0;
    let k = s1.length - 1;
    let l = s2.length - 1;
    while (i < s1.length && j < s2.length && s1[i] === s2[j]) {
        i++;
        j++;
    }
    while (k >= 0 && l >= 0 && s1[k] === s2[l]) {
        k--;
        l--;
    }
    return i > k && j > l;
    
};

    