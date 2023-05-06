/**https://leetcode.com/problems/find-all-people-with-secret/ */
//You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
//Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.
//The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.
//Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.


/**
 * @param {number} n
 * @param {number[][]} meetings
 * @param {number} firstPerson
 * @return {number[]}
 */
var findAllPeople = function(n, meetings, firstPerson) {
    let adj = new Array(n);
    for(let i = 0; i < n; i++){
        adj[i] = new Array(n).fill(0);
    }
    for(let [u, v, time] of meetings){
        adj[u][v] = time;
        adj[v][u] = time;
    }
    let ans = new Set();
    let visited = new Set();
    let q = [firstPerson];
    visited.add(firstPerson);
    while(q.length > 0){
        let curr = q.shift();
        ans.add(curr);
        for(let i = 0; i < n; i++){
            if(adj[curr][i] > 0 && !visited.has(i)){
                q.push(i);
                visited.add(i);
            }
        }
    }
    return Array.from(ans);
    
};

    