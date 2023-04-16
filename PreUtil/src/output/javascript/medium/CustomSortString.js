/**https://leetcode.com/problems/custom-sort-string/ */
//You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
//Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
//Return any permutation of s that satisfies this property.


/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
var customSortString = function(order, s) {
    let n = s.length;
    let m = order.length;
    let result = '';
    let orderMap = new Map();
    for(let i = 0; i < m; i++){
        orderMap.set(order[i], i);
    }
    let arr = s.split('');
    arr.sort((a, b) => {
        if(orderMap.has(a) && orderMap.has(b)){
            return orderMap.get(a) - orderMap.get(b);
        }else if(orderMap.has(a)){
            return -1;
        }else if(orderMap.has(b)){
            return 1;
        }else{
            return 0;
        }
    });
    return arr.join('');
    
};

    