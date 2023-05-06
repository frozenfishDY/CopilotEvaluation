/**https://leetcode.com/problems/swap-adjacent-in-lr-string/ */
//In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.


/**
 * @param {string} start
 * @param {string} end
 * @return {boolean}
 */
var canTransform = function(start, end) {
    let n = start.length;
    let i = 0;
    let j = 0;
    while(i < n && j < n){
        while(i < n && start[i] == "X"){
            i++;
        }
        while(j < n && end[j] == "X"){
            j++;
        }
        if((i < n) ^ (j < n)){
            return false;
        }
        if(i < n && j < n){
            if(start[i] != end[j]){
                return false;
            }
            if(start[i] == "L" && i < j){
                return false;
            }
            if(start[i] == "R" && i > j){
                return false;
            }
        }
        i++;
        j++;
    }
    return true;
    
};

    