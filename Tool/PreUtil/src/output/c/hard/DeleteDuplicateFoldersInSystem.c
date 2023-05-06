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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** deleteDuplicateFolder(char *** paths, int pathsSize, int* pathsColSize, int* returnSize, int** returnColumnSizes){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*pathsSize);
    for(i=0;i<pathsSize;i++){
        arr13[i] = 0;
    }

}

    