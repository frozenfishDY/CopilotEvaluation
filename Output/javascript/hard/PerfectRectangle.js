/**https://leetcode.com/problems/perfect-rectangle/ */
//Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
//Return true if all the rectangles together form an exact cover of a rectangular region.


/**
 * @param {number[][]} rectangles
 * @return {boolean}
 */
var isRectangleCover = function(rectangles) {
    let n = rectangles.length;
    let minx = Infinity;
    let miny = Infinity;
    let maxx = -Infinity;
    let maxy = -Infinity;
    let area = 0;
    let set = new Set();
    for(let i = 0; i < n; i++){
        let [x1, y1, x2, y2] = rectangles[i];
        minx = Math.min(minx, x1);
        miny = Math.min(miny, y1);
        maxx = Math.max(maxx, x2);
        maxy = Math.max(maxy, y2);
        area += (x2 - x1) * (y2 - y1);
        let s1 = x1 + "," + y1;
        let s2 = x1 + "," + y2;
        let s3 = x2 + "," + y1;
        let s4 = x2 + "," + y2;
        if(set.has(s1)){
            set.delete(s1);
        }else{
            set.add(s1);
        }
        if(set.has(s2)){
            set.delete(s2);
        }else{
            set.add(s2);
        }
        if(set.has(s3)){
            set.delete(s3);
        }else{
            set.add(s3);
        }
        if(set.has(s4)){
            set.delete(s4);
        }else{
            set.add(s4);
        }
    }
    if(set.size !== 4){
        return false;
    }
    if(!set.has(minx + "," + miny) || !set.has(minx + "," + maxy) || !set.has(maxx + "," + miny) || !set.has(maxx + "," + maxy)){
        return false;
    }
    return area === (maxx - minx) * (maxy - miny);
    
};

    