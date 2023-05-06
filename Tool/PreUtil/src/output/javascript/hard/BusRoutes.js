/**https://leetcode.com/problems/bus-routes/ */
//You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
//For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
//You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
//Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.


/**
 * @param {number[][]} routes
 * @param {number} source
 * @param {number} target
 * @return {number}
 */
var numBusesToDestination = function(routes, source, target) {
    if (source === target) {
        return 0;
    }
    
    const n = routes.length;
    const graph = new Array(n).fill(0).map(() => new Array(n).fill(false));
    const routeMap = new Map();
    
    for (let i = 0; i < n; i++) {
        for (const site of routes[i]) {
            const list = routeMap.get(site) || new Array();
            for (const j of list) {
                graph[i][j] = graph[j][i] = true;
            }
            list.push(i);
            routeMap.set(site, list);
        }
    }
    
    const queue = new Array();
    const seen = new Array(n).fill(false);
    let step = 0;
    
    for (const site of routeMap.get(source) || []) {
        queue.push(site);
        seen[site] = true;
    }
    
    while (queue.length > 0) {
        step++;
        const size = queue.length;
        for (let i = 0; i < size; i++) {
            const x = queue.shift();
            for (let y = 0; y < n; y++) {
                if (graph[x][y] && !seen[y]) {
                    if (routes[y].includes(target)) {
                        return step;
                    }
                    queue.push(y);
                    seen[y] = true;
                }
            }
        }
    }
    
    return -1;
    
};

    