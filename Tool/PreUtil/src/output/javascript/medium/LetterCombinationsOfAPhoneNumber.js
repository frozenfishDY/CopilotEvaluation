/**https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    let map = {
        "2": ["a", "b", "c"],
        "3": ["d", "e", "f"],
        "4": ["g", "h", "i"],
        "5": ["j", "k", "l"],
        "6": ["m", "n", "o"],
        "7": ["p", "q", "r", "s"],
        "8": ["t", "u", "v"],
        "9": ["w", "x", "y", "z"]
    };
    let result = [];
    if(digits.length == 0){
        return result;
    }
    let queue = [];
    queue.push("");
    while(queue.length > 0){
        let current = queue.shift();
        if(current.length == digits.length){
            result.push(current);
        }else{
            let digit = digits[current.length];
            let letters = map[digit];
            for(let i = 0; i < letters.length; i++){
                queue.push(current + letters[i]);
            }
        }
    }
    return result;
    
};

    