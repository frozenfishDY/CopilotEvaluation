/**https://leetcode.com/problems/the-skyline-problem/ */
//A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
//The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:
//lefti is the x coordinate of the left edge of the ith building.
//righti is the x coordinate of the right edge of the ith building.
//heighti is the height of the ith building.
//You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.
//Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]


/**
 * @param {number[][]} buildings
 * @return {number[][]}
 */
var getSkyline = function(buildings) {
    let n = buildings.length;
    let points = [];
    for(let i = 0; i < n; i++){
        points.push([buildings[i][0], -buildings[i][2]]);
        points.push([buildings[i][1], buildings[i][2]]);
    }
    points.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    let heap = new MaxHeap();
    heap.push(0);
    let prev = 0;
    let res = [];
    for(let i = 0; i < points.length; i++){
        let [x, y] = points[i];
        if(y < 0){
            heap.push(-y);
        }else{
            heap.remove(y);
        }
        let cur = heap.top();
        if(cur != prev){
            res.push([x, cur]);
            prev = cur;
        }
    }
    return res;
    

};

    