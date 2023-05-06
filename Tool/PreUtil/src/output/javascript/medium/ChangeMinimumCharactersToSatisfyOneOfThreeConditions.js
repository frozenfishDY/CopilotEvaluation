/**https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/ */
//You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.
//Your goal is to satisfy one of the following three conditions:
//Every letter in a is strictly less than every letter in b in the alphabet.
//Every letter in b is strictly less than every letter in a in the alphabet.
//Both a and b consist of only one distinct letter.
//Return the minimum number of operations needed to achieve your goal.


/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var minCharacters = function(a, b) {
    let map1 = new Map();
    let map2 = new Map();
    let res = Infinity;
    for(let i = 0; i < a.length; i++){
        if(map1.has(a[i])){
            map1.set(a[i], map1.get(a[i]) + 1);
        }else{
            map1.set(a[i], 1);
        }
    }
    for(let i = 0; i < b.length; i++){
        if(map2.has(b[i])){
            map2.set(b[i], map2.get(b[i]) + 1);
        }else{
            map2.set(b[i], 1);
        }
    }
    let count1 = 0;
    let count2 = 0;
    for(let i = 0; i < 26; i++){
        let c = String.fromCharCode(97 + i);
        if(map1.has(c)){
            count1 += map1.get(c);
        }
        if(map2.has(c)){
            count2 += map2.get(c);
        }
        res = Math.min(res, a.length + b.length - count1 - count2);
    }
    count1 = 0;
    count2 = 0;
    for(let i = 0; i < 25; i++){
        let c = String.fromCharCode(97 + i);
        if(map1.has(c)){
            count1 += map1.get(c);
        }
        if(map2.has(c)){
            count2 += map2.get(c);
        }
        res = Math.min(res, a.length - count1 + count2);
        res = Math.min(res, b.length - count2 + count1);
    }
    return res;
    
};

    