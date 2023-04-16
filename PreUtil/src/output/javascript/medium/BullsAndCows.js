/**https://leetcode.com/problems/bulls-and-cows/ */
//You are playing the Bulls and Cows game with your friend.
//You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
//The number of "bulls", which are digits in the guess that are in the correct position.
//The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
//Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
//The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.


/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
    let bulls = 0;
    let cows = 0;
    let map = new Map();
    for(let i = 0; i < secret.length; i++){
        if(secret[i] === guess[i]){
            bulls++;
        }else{
            if(map.has(secret[i])){
                map.set(secret[i], map.get(secret[i]) + 1);
            }else{
                map.set(secret[i], 1);
            }
        }
    }
    for(let i = 0; i < guess.length; i++){
        if(secret[i] !== guess[i]){
            if(map.has(guess[i]) && map.get(guess[i]) > 0){
                cows++;
                map.set(guess[i], map.get(guess[i]) - 1);
            }
        }
    }
    return bulls + 'A' + cows + 'B';
    
};

    