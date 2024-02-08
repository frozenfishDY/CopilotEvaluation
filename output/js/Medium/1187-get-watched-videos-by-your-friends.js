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
 * @param {string[][]} watchedVideos
 * @param {number[][]} friends
 * @param {number} id
 * @param {number} level
 * @return {string[]}
 */
var watchedVideosByFriends = function(watchedVideos, friends, id, level) {
    var n = friends.length;
	var queue = [];
	var visited = Array(n).fill(false);
	queue.push(id);
	visited[id] = true;
	var count = 0;
	while (queue.length > 0) {
		var size = queue.length;
		for (var i = 0; i < size; i++) {
			var cur = queue.shift();
			for (var j = 0; j < friends[cur].length; j++) {
				if (!visited[friends[cur][j]]) {
					queue.push(friends[cur][j]);
					visited[friends[cur][j]] = true;
				}
			}
		}
		count++;
		if (count == level) {
			break;
		}
	}
	var map = {};
	while (queue.length > 0) {
		var cur = queue.shift();
		for (var i = 0; i < watchedVideos[cur].length; i++) {
			if (map[watchedVideos[cur][i]] == null) {
				map[watchedVideos[cur][i]] = 1;
			} else {
				map[watchedVideos[cur][i]]++;
			}
		}
	}
	var res = [];
	for (var key in map) {
		res.push(key);
	}
	res.sort((a, b) => {
		if (map[a] == map[b]) {
			return a.localeCompare(b);
		} else {
			return map[a] - map[b];
		}
	});
	return res;
};