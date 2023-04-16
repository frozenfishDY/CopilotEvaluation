/**https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/ */
//There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
//Return a sorted list of the items such that:
//The items that belong to the same group are next to each other in the sorted list.
//There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
//Return any solution if there is more than one solution and return an empty list if there is no solution.


/**
 * @param {number} n
 * @param {number} m
 * @param {number[]} group
 * @param {number[][]} beforeItems
 * @return {number[]}
 */
var sortItems = function(n, m, group, beforeItems) {
    let groupGraph = new Map();
    let itemGraph = new Map();
    let groupDegree = new Map();
    let itemDegree = new Map();
    let groupItems = new Map();
    let id = m;
    for(let i = 0; i < n; i++){
        if(group[i] == -1){
            group[i] = id;
            id++;
        }
        if(!groupItems.has(group[i])){
            groupItems.set(group[i], []);
        }
        groupItems.get(group[i]).push(i);
        groupDegree.set(group[i], 0);
        itemDegree.set(i, 0);
        groupGraph.set(group[i], []);
        itemGraph.set(i, []);
    }
    for(let i = 0; i < n; i++){
        let curGroup = group[i];
        for(let j of beforeItems[i]){
            let prevGroup = group[j];
            if(curGroup != prevGroup){
                groupGraph.get(prevGroup).push(curGroup);
                groupDegree.set(curGroup, groupDegree.get(curGroup) + 1);
            }
            itemGraph.get(j).push(i);
            itemDegree.set(i, itemDegree.get(i) + 1);
        }
    }
    let groupOrder = topologicalSort(groupGraph, groupDegree);
    if(groupOrder.length == 0){
        return [];
    }
    let ans = [];
    for(let curGroup of groupOrder){
        let items = groupItems.get(curGroup);
        let itemOrder = topologicalSort(itemGraph, itemDegree, items);
        if(itemOrder.length == 0){
            return [];
        }
        ans.push(...itemOrder);
    }
    return ans;
    
    
};

    