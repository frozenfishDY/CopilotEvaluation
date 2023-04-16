/**https://leetcode.com/problems/delete-duplicate-folders-in-system/ */
//Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.
//For example, ["one", "two", "three"] represents the path "/one/two/three".
//Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.
//For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
///a
///a/x
///a/x/y
///a/z
///b
///b/x
///b/x/y
///b/z
//However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.
//Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.
//Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.


class DeleteDuplicateFoldersInSystem {
    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        Map<String, Integer> map = new HashMap<>();
        Map<Integer, List<Integer>> graph = new HashMap<>();
        Map<Integer, String> content = new HashMap<>();
        int n = paths.size();
        for (int i = 0; i < n; i++) {
            List<String> path = paths.get(i);
            int cur = 0;
            for (String s : path) {
                if (!graph.containsKey(cur)) {
                    graph.put(cur, new ArrayList<>());
                }
                if (!map.containsKey(s)) {
                    map.put(s, map.size());
                }
                int next = map.get(s);
                graph.get(cur).add(next);
                cur = next;
            }
            content.put(cur, path.get(path.size() - 1));
        }
        Set<Integer> visited = new HashSet<>();
        Set<Integer> marked = new HashSet<>();
        dfs(0, graph, content, visited, marked);
        List<List<String>> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<String> path = paths.get(i);
            int cur = 0;
            List<String> list = new ArrayList<>();
            for (String s : path) {
                if (marked.contains(cur)) {
                    break;
                }
                list.add(s);
                cur = map.get(s);
            }
            if (list.size() == path.size()) {
                res.add(list);
            }
        }
        return res;


                       





        
    }
}
     
    