/**https://leetcode.com/problems/cinema-seat-allocation/ */
//A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.
//Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.
//Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.


/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function(n, reservedSeats) {
    let count = 0;
    let map = new Map();
    for (let i = 0; i < reservedSeats.length; i++) {
        let row = reservedSeats[i][0];
        let col = reservedSeats[i][1];
        if (!map.has(row)) {
            map.set(row, new Set());
        }
        map.get(row).add(col);
    }
    for (let i = 1; i <= n; i++) {
        let set = map.get(i);
        if (set === undefined) {
            count += 2;
        } else {
            if (!set.has(2) && !set.has(3) && !set.has(4) && !set.has(5)) {
                count++;
            }
            if (!set.has(6) && !set.has(7) && !set.has(8) && !set.has(9)) {
                count++;
            }
            if (!set.has(4) && !set.has(5) && !set.has(6) && !set.has(7)) {
                count++;
            }
        }
    }
    return count;
    
};

    