/**https://leetcode.com/problems/closest-room/ */
//There is a hotel with n rooms. The rooms are represented by a 2D integer array rooms where rooms[i] = [roomIdi, sizei] denotes that there is a room with room number roomIdi and size equal to sizei. Each roomIdi is guaranteed to be unique.
//You are also given k queries in a 2D array queries where queries[j] = [preferredj, minSizej]. The answer to the jth query is the room number id of a room such that:
//The room has a size of at least minSizej, and
//abs(id - preferredj) is minimized, where abs(x) is the absolute value of x.
//If there is a tie in the absolute difference, then use the room with the smallest such id. If there is no such room, the answer is -1.
//Return an array answer of length k where answer[j] contains the answer to the jth query.


/**
 * @param {number[][]} rooms
 * @param {number[][]} queries
 * @return {number[]}
 */
var closestRoom = function(rooms, queries) {
    let result = [];
    let roomMap = new Map();
    for (let i = 0; i < rooms.length; i++) {
        let room = rooms[i];
        let roomId = room[0];
        let size = room[1];
        if (!roomMap.has(size)) {
            roomMap.set(size, []);
        }
        roomMap.get(size).push(roomId);
    }
    for (let i = 0; i < queries.length; i++) {
        let query = queries[i];
        let preferred = query[0];
        let minSize = query[1];
        let minDiff = Number.MAX_SAFE_INTEGER;
        let minRoomId = -1;
        for (let [size, roomIds] of roomMap) {
            if (size >= minSize) {
                for (let j = 0; j < roomIds.length; j++) {
                    let roomId = roomIds[j];
                    let diff = Math.abs(roomId - preferred);
                    if (diff < minDiff) {
                        minDiff = diff;
                        minRoomId = roomId;
                    } else if (diff == minDiff) {
                        minRoomId = Math.min(minRoomId, roomId);
                    }
                }
            }
        }
        result.push(minRoomId);
    }
    return result;
    
};

    