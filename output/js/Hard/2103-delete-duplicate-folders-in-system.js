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


/**
 * @param {string[][]} paths
 * @return {string[][]}
 */
var deleteDuplicateFolder = function(paths) {
    let result = [];
    let map = new Map();
    for (let i = 0; i < paths.length; i++) {
        let path = paths[i];
        let current = map;
        for (let j = 0; j < path.length; j++) {
            let folder = path[j];
            if (!current.has(folder)) {
                current.set(folder, new Map());
            }
            current = current.get(folder);
        }
    }
    let visited = new Set();
    let stack = [];
    stack.push([map, []]);
    while (stack.length > 0) {
        let node = stack.pop();
        let current = node[0];
        let path = node[1];
        if (visited.has(current)) {
            continue;
        }
        visited.add(current);
        let keys = current.keys();
        let key = keys.next();
        while (!key.done) {
            let folder = key.value;
            let subPath = [...path, folder];
            stack.push([current.get(folder), subPath]);
            key = keys.next();
        }
        if (current.size > 1) {
            let keys = current.keys();
            let key = keys.next();
            while (!key.done) {
                let folder = key.value;
                let subPath = [...path, folder];
                result.push(subPath);
                key = keys.next();
            }
        }
    }
    return result;
    
};

    