/**https://leetcode.com/problems/satisfiability-of-equality-equations/ */
//You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
//Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.


/**
 * @param {string[]} equations
 * @return {boolean}
 */
var equationsPossible = function(equations) {
    let n = equations.length;
    let parent = new Array(26);
    for(let i = 0; i < 26; i++){
        parent[i] = i;
    }
    for(let i = 0; i < n; i++){
        if(equations[i][1] == '='){
            let x = equations[i][0].charCodeAt(0) - 'a'.charCodeAt(0);
            let y = equations[i][3].charCodeAt(0) - 'a'.charCodeAt(0);
            union(x, y);
        }
    }
    for(let i = 0; i < n; i++){
        if(equations[i][1] == '!'){
            let x = equations[i][0].charCodeAt(0) - 'a'.charCodeAt(0);
            let y = equations[i][3].charCodeAt(0) - 'a'.charCodeAt(0);
            if(find(x) == find(y)){
                return false;
            }
        }
    }
    return true;
    
    
};

    