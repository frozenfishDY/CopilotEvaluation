/**https://leetcode.com/problems/number-of-boomerangs/ */
//You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//Return the number of boomerangs.


/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfBoomerangs = function(points) {
    let n = points.length;
    let result = 0;
    for(let i = 0; i < n; i++){
        let map = new Map();
        for(let j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            let distance = getDistance(points[i], points[j]);
            if(map.has(distance)){
                map.set(distance, map.get(distance) + 1);
            }else{
                map.set(distance, 1);
            }
        }
        for(let [key, value] of map){
            result += value * (value - 1);
        }
    }
    return result;
    
    
    
};

    