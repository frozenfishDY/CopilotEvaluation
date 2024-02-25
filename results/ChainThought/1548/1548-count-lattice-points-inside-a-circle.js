/**https://leetcode.com/problems/count-lattice-points-inside-a-circle/ */
//Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number of lattice points that are present inside at least one circle.
//Note:
//A lattice point is a point with integer coordinates.
//Points that lie on the circumference of a circle are also considered to be inside it.


/**
 * @param {number[][]} circles
 * @return {number}
 */
var countLatticePoints = function(circles) {
    let count = 0;
    for (let i = 0; i < circles.length; i++) {
        let x = circles[i][0];
        let y = circles[i][1];
        let r = circles[i][2];
        for (let j = x - r; j <= x + r; j++) {
            let y1 = Math.sqrt(r * r - (j - x) * (j - x));
            let y2 = -y1;
            if (Math.floor(y1) === y1) {
                if (y1 + y === Math.floor(y1 + y)) {
                    count++;
                }
                if (y2 + y === Math.floor(y2 + y)) {
                    count++;
                }
            }
        }
    }
    return count;
    
};

    