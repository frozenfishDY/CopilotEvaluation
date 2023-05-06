/**https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/ */
//A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.
//The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.
//Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.


/**
 * @param {number[]} favorite
 * @return {number}
 */
var maximumInvitations = function(favorite) {
    let n = favorite.length;
    let adj = new Array(n);
    for(let i = 0; i < n; i++){
        adj[i] = [];
    }
    for(let i = 0; i < n; i++){
        adj[i].push(favorite[i]);
        adj[favorite[i]].push(i);
    }
    let ans = 0;
    let visited = new Set();
    let dfs = (u) => {
        visited.add(u);
        for(let v of adj[u]){
            if(!visited.has(v)){
                ans++;
                dfs(v);
            }
        }
    }
    for(let i = 0; i < n; i++){
        if(!visited.has(i)){
            dfs(i);
        }
    }
    return ans;
    
};

    