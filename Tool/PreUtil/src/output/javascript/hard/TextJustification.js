/**https://leetcode.com/problems/text-justification/ */
//Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//For the last line of text, it should be left-justified, and no extra space is inserted between words.
//Note:
//A word is defined as a character sequence consisting of non-space characters only.
//Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//The input array words contains at least one word.


/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    let result = [];
    let i = 0;
    let n = words.length;
    while(i < n){
        let j = i + 1;
        let len = words[i].length;
        while(j < n && len + words[j].length + 1 <= maxWidth){
            len = len + words[j].length + 1;
            j++;
        }
        let spaces = maxWidth - len;
        let spacesBetween = j - i - 1;
        let spacesEach = 0;
        let spacesExtra = 0;
        if(spacesBetween > 0){
            spacesEach = Math.floor(spaces / spacesBetween);
            spacesExtra = spaces % spacesBetween;
        }
        let line = "";
        for(let k = i; k < j; k++){
            line = line + words[k];
            if(k < j - 1){
                for(let l = 0; l < spacesEach; l++){
                    line = line + " ";
                }
                if(spacesExtra > 0){
                    line = line + " ";
                    spacesExtra--;
                }
            }
        }
        for(let k = line.length; k < maxWidth; k++){
            line = line + " ";
        }
        result.push(line);
        i = j;
    }
    return result;
    
};

    