/**https://leetcode.com/problems/brace-expansion-ii/ */
//Under the grammar given below, strings can represent a set of lowercase words. Let R(expr) denote the set of words the expression represents.
//The grammar can best be understood through simple examples:
//Single letters represent a singleton set containing that word.
//R("a") = {"a"}
//R("w") = {"w"}
//When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
//R("{a,b,c}") = {"a","b","c"}
//R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
//When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
//R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
//R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
//Formally, the three rules for our grammar:
//For every lowercase letter x, we have R(x) = {x}.
//For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) �� R(e2) �� ...
//For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) �� R(e2)}, where + denotes concatenation, and �� denotes the cartesian product.
//Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.


/**
 * @param {string} expression
 * @return {string[]}
 */
var braceExpansionII = function(expression) {
    let n = expression.length;
    let i = 0;
    let stack = [];
    let cur = new Set();
    cur.add('');
    stack.push(cur);
    while(i < n){
        let ch = expression[i];
        if(ch == '{'){
            stack.push(new Set());
            i++;
        }
        else if(ch == '}'){
            let pre = stack.pop();
            let cur = stack[stack.length - 1];
            let temp = new Set();
            for(let s1 of pre){
                for(let s2 of cur){
                    temp.add(s2 + s1);
                }
            }
            stack[stack.length - 1] = temp;
            i++;
        }
        else if(ch == ','){
            stack.push(new Set());
            i++;
        }
        else{
            let j = i;
            while(j < n && expression[j] >= 'a' && expression[j] <= 'z'){
                j++;
            }
            let cur = stack[stack.length - 1];
            let temp = new Set();
            for(let s of cur){
                temp.add(s + expression.substring(i, j));
            }
            stack[stack.length - 1] = temp;
            i = j;
        }
    }
    let ans = [];
    for(let s of stack[0]){
        ans.push(s);
    }
    ans.sort();
    return ans;
    
};

    