/**https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/ */
//There is a family tree rooted at 0 consisting of n nodes numbered 0 to n - 1. You are given a 0-indexed integer array parents, where parents[i] is the parent for node i. Since node 0 is the root, parents[0] == -1.
//There are 105 genetic values, each represented by an integer in the inclusive range [1, 105]. You are given a 0-indexed integer array nums, where nums[i] is a distinct genetic value for node i.
//Return an array ans of length n where ans[i] is the smallest genetic value that is missing from the subtree rooted at node i.
//The subtree rooted at a node x contains node x and all of its descendant nodes.


class SmallestMissingGeneticValueInEachSubtree {
    public int[] smallestMissingValueSubtree(int[] parents, int[] nums) {
        int n = parents.length;
        int[] res = new int[n];
        Arrays.fill(res, 1);
        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            map.computeIfAbsent(parents[i], x -> new ArrayList<>()).add(i);
        }
        int[] trie = new int[1 << 20];
        int[] count = new int[1 << 20];
        dfs(0, parents, map, trie, count, res, nums);
        return res;
        
        
    }
}
     
    