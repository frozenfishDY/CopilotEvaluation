/**https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/ */
//There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
//Return a sorted list of the items such that:
//The items that belong to the same group are next to each other in the sorted list.
//There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
//Return any solution if there is more than one solution and return an empty list if there is no solution.


class SortItemsByGroupsRespectingDependencies {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        int[] res = new int[n];
        int[] groupCount = new int[m];
        int[] itemCount = new int[n];
        int[] groupInDegree = new int[m];
        int[] itemInDegree = new int[n];
        List<Integer>[] groupGraph = new List[m];
        List<Integer>[] itemGraph = new List[n];
        for (int i = 0; i < m; i++) {
            groupGraph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            itemGraph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
            groupCount[group[i]]++;
            for (int j : beforeItems.get(i)) {
                if (group[j] == -1) {
                    group[j] = m++;
                }
                if (group[j] != group[i]) {
                    groupGraph[group[j]].add(group[i]);
                    groupInDegree[group[i]]++;
                } else {
                    itemGraph[j].add(i);
                    itemInDegree[i]++;
                }
            }
        }
        List<Integer> groupOrder = topologicalSort(groupGraph, groupInDegree, m);
        if (groupOrder.size() == 0) {
            return new int[0];
        }
        List<Integer> itemOrder = new ArrayList<>();
        for (int i : groupOrder) {
            List<Integer> items = topologicalSort(itemGraph, itemInDegree, n);
            if (items.size() == 0) {
                return new int[0];
            }
            for (int j : items) {
                if (group[j] == i) {
                    itemOrder.add(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            res[i] = itemOrder.get(i);
        }
        return res;
        
    }
}
     
    