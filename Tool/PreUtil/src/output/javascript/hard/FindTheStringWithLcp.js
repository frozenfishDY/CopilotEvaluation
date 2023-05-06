/**https://leetcode.com/problems/find-the-string-with-lcp/ */
//We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:
//lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].
//Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.
//A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.


/**
 * @param {number[][]} lcp
 * @return {string}
 */
var findTheString = function(lcp) {
    let n = lcp.length;
    let result = "";
    let visited = new Set();
    let dfs = function(index, word){
        if(index === n){
            if(result === "" || word < result){
                result = word;
            }
            return;
        }
        for(let i = 0; i < n; i++){
            if(!visited.has(i)){
                let prefix = lcp[index][i];
                let next = word + String.fromCharCode(97 + i);
                if(result !== "" && next > result){
                    continue;
                }
                visited.add(i);
                dfs(index + 1, next.substring(next.length - prefix));
                visited.delete(i);
            }
        }
    }
    dfs(0, "");
    return result;
    
    
};

    