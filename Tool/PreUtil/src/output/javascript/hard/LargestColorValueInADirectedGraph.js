/**https://leetcode.com/problems/largest-color-value-in-a-directed-graph/ */
//There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
//You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
//A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
//Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.


/**
 * @param {string} colors
 * @param {number[][]} edges
 * @return {number}
 */
var largestPathValue = function(colors, edges) {
    let result = 0;
    let colorMap = new Map();
    let nodeMap = new Map();
    let visited = new Array(colors.length).fill(0);
    let queue = [];
    for (let i = 0; i < colors.length; i++) {
        let color = colors[i];
        if (!colorMap.has(color)) {
            colorMap.set(color, 1);
        } else {
            colorMap.set(color, colorMap.get(color) + 1);
        }
        if (!nodeMap.has(i)) {
            nodeMap.set(i, []);
        }
    }
    for (let i = 0; i < edges.length; i++) {
        let edge = edges[i];
        let node1 = edge[0];
        let node2 = edge[1];
        let list = nodeMap.get(node1);
        list.push(node2);
        nodeMap.set(node1, list);
    }
    for (let i = 0; i < colors.length; i++) {
        if (visited[i] === 0) {
            queue.push(i);
            visited[i] = 1;
            while (queue.length > 0) {
                let node = queue.shift();
                let list = nodeMap.get(node);
                for (let j = 0; j < list.length; j++) {
                    let next = list[j];
                    if (visited[next] === 0) {
                        queue.push(next);
                        visited[next] = 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
    }
    for (let i = 0; i < colors.length; i++) {
        let color = colors[i];
        result = Math.max(result, colorMap.get(color));
    }
    return result;

    
};

    