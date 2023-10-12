/**https://leetcode.com/problems/get-watched-videos-by-your-friends/ */
//There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.
//Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 
// 
//Example 1:
//Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
//Output: ["B","C"] 
//Explanation: 
//You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
//Person with id = 1 -> watchedVideos = ["C"] 
//Person with id = 2 -> watchedVideos = ["B","C"] 
//The frequencies of watchedVideos by your friends are: 
//B -> 1 
//C -> 2
//Example 2:
//Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
//Output: ["D"]
//Explanation: 
//You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).
// 
//Constraints:
//	n == watchedVideos.length == friends.length
//	2 <= n <= 100
//	1 <= watchedVideos[i].length <= 100
//	1 <= watchedVideos[i][j].length <= 8
//	0 <= friends[i].length < n
//	0 <= friends[i][j] < n
//	0 <= id < n
//	1 <= level < n
//	if friends[i] contains j, then friends[j] contains i
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** watchedVideosByFriends(char *** watchedVideos, int watchedVideosSize, int* watchedVideosColSize, int** friends, int friendsSize, int* friendsColSize, int id, int level, int* returnSize){
*returnSize = 0;
    int *visited = (int *)malloc(sizeof(int) * watchedVideosSize);
    memset(visited, 0, sizeof(int) * watchedVideosSize);
    int *queue = (int *)malloc(sizeof(int) * friendsSize);
    int queueSize = 0;
    queue[queueSize++] = id;
    visited[id] = 1;
    while (queueSize && level) {
        int curSize = queueSize;
        while (curSize--) {
            int cur = queue[0];
            for (int i = 0; i < queueSize - 1; ++i) {
                queue[i] = queue[i + 1];
            }
            --queueSize;
            for (int i = 0; i < friendsColSize[cur]; ++i) {
                if (!visited[friends[cur][i]]) {
                    queue[queueSize++] = friends[cur][i];
                    visited[friends[cur][i]] = 1;
                }
            }
        }
        --level;
    }
    int *freq = (int *)malloc(sizeof(int) * 100);
    memset(freq, 0, sizeof(int) * 100);
    for (int i = 0; i < queueSize; ++i) {
        for (int j = 0; j < watchedVideosColSize[queue[i]]; ++j) {
            ++freq[watchedVideos[queue[i]][j][0] - 'A'];
        }
    }
    char **res = (char **)malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; ++i) {
        res[i] = (char *)malloc(sizeof(char) * 9);
        memset(res[i], 0, sizeof(char) * 9);
    }
    *returnSize = 0;
    for (int i = 0; i < 100; ++i) {
        if (freq[i]) {
            strcpy(res[*returnSize], "A");
            res[*returnSize][0] += i;
            ++*returnSize;
        }
    }
    qsort(res, *returnSize, sizeof(char *), cmp);
    return res;

}