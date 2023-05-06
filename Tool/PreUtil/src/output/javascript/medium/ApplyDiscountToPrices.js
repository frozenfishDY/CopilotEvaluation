/**https://leetcode.com/problems/apply-discount-to-prices/ */
//A sentence is a string of single-space separated words where each word can contain digits, lowercase letters, and the dollar sign '$'. A word represents a price if it is a sequence of digits preceded by a dollar sign.
//For example, "$100", "$23", and "$6" represent prices while "100", "$", and "$1e5" do not.
//You are given a string sentence representing a sentence and an integer discount. For each word representing a price, apply a discount of discount% on the price and update the word in the sentence. All updated prices should be represented with exactly two decimal places.
//Return a string representing the modified sentence.
//Note that all prices will contain at most 10 digits.


/**
 * @param {string} sentence
 * @param {number} discount
 * @return {string}
 */
var discountPrices = function(sentence, discount) {
    let words = sentence.split(" ");
    for (let i = 0; i < words.length; i++) {
        if (words[i].charAt(0) === "$") {
            let price = parseInt(words[i].substring(1));
            let discountPrice = (price - (price * discount / 100)).toFixed(2);
            words[i] = "$" + discountPrice;
        }
    }
    return words.join(" ");
    
};

    