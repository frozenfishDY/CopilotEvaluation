/**https://leetcode.com/problems/accounts-merge/ */
//Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.


/**
 * @param {string[][]} accounts
 * @return {string[][]}
 */
var accountsMerge = function(accounts) {
    let map = new Map();
    for(let i = 0; i < accounts.length; i++){
        for(let j = 1; j < accounts[i].length; j++){
            if(map.has(accounts[i][j])){
                map.set(accounts[i][j], map.get(accounts[i][j]).concat([i]));
            }else{
                map.set(accounts[i][j], [i]);
            }
        }
    }
    let visited = new Array(accounts.length).fill(false);
    let result = [];
    for(let i = 0; i < accounts.length; i++){
        if(!visited[i]){
            let set = new Set();
            let queue = [i];
            while(queue.length > 0){
                let index = queue.shift();
                if(!visited[index]){
                    visited[index] = true;
                    for(let j = 1; j < accounts[index].length; j++){
                        set.add(accounts[index][j]);
                    }
                    for(let j = 1; j < accounts[index].length; j++){
                        for(let k = 0; k < map.get(accounts[index][j]).length; k++){
                            if(!visited[map.get(accounts[index][j])[k]]){
                                queue.push(map.get(accounts[index][j])[k]);
                            }
                        }
                    }
                }
            }
            let arr = Array.from(set);
            arr.sort();
            arr.unshift(accounts[i][0]);
            result.push(arr);
        }
    }
    return result;
    
};

    