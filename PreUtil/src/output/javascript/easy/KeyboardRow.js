/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//In the American keyboard:
//the first row consists of the characters "qwertyuiop",
//the second row consists of the characters "asdfghjkl", and
//the third row consists of the characters "zxcvbnm".


/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(words) {
    let ans = [];
    let row1 = "qwertyuiop";
    let row2 = "asdfghjkl";
    let row3 = "zxcvbnm";
    for(let i = 0; i < words.length; i++){
        let word = words[i].toLowerCase();
        let row = 0;
        for(let j = 0; j < word.length; j++){
            if(row1.includes(word[j])){
                if(row == 0){
                    row = 1;
                }else if(row == 2){
                    row = 0;
                    break;
                }
            }else if(row2.includes(word[j])){
                if(row == 0){
                    row = 2;
                }else if(row == 1){
                    row = 0;
                    break;
                }
            }else if(row3.includes(word[j])){
                if(row == 0){
                    row = 3;
                }else if(row == 1){
                    row = 0;
                    break;
                }
            }
        }
        if(row != 0){
            ans.push(words[i]);
        }
    }
    return ans;
    
};

    