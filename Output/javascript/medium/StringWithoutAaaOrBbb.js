/**https://leetcode.com/problems/string-without-aaa-or-bbb/ */
//Given two integers a and b, return any string s such that:
//s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
//The substring 'aaa' does not occur in s, and
//The substring 'bbb' does not occur in s.


/**
 * @param {number} a
 * @param {number} b
 * @return {string}
 */
var strWithout3a3b = function(a, b) {
    let ans = [];
    while(a > 0 || b > 0){
        let writeA = false;
        let l = ans.length;
        if(l >= 2 && ans[l - 1] == ans[l - 2]){
            if(ans[l - 1] == 'b'){
                writeA = true;
            }
        }else{
            if(a >= b){
                writeA = true;
            }
        }
        if(writeA){
            ans.push('a');
            a--;
        }else{
            ans.push('b');
            b--;
        }
    }
    return ans.join('');
    
};

    