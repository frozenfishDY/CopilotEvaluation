/**https://leetcode.com/problems/most-popular-video-creator/ */
//You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.
//The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.
//If multiple creators have the highest popularity, find all of them.
//If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
//Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.


/**
 * @param {string[]} creators
 * @param {string[]} ids
 * @param {number[]} views
 * @return {string[][]}
 */
var mostPopularCreator = function(creators, ids, views) {
    let map = new Map();
    let max = 0;
    for (let i = 0; i < creators.length; i++) {
        let creator = creators[i];
        let id = ids[i];
        let view = views[i];
        if (map.has(creator)) {
            let video = map.get(creator);
            video[0] += view;
            if (video[0] > max) {
                max = video[0];
            }
            if (video[0] === max) {
                if (video[1] > id) {
                    video[1] = id;
                }
            }
            map.set(creator, video);
        } else {
            map.set(creator, [view, id]);
            if (view > max) {
                max = view;
            }
        }
    }
    let result = [];
    for (let [creator, video] of map) {
        if (video[0] === max) {
            result.push([creator, video[1]]);
        }
    }
    return result;
    
    
};

    