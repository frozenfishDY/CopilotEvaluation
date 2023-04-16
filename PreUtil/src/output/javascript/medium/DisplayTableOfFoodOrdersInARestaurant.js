/**https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/ */
//Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.
//Return the restaurant's ��display table��. The ��display table�� is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is ��Table��, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.


/**
 * @param {string[][]} orders
 * @return {string[][]}
 */
var displayTable = function(orders) {
    let map = {};
    let food = new Set();
    for (let i = 0; i < orders.length; i++) {
        let table = orders[i][1];
        let item = orders[i][2];
        food.add(item);
        if (map[table]) {
            map[table].push(item);
        } else {
            map[table] = [item];
        }
    }
    let res = [];
    let header = ['Table'];
    for (let item of food) {
        header.push(item);
    }
    res.push(header);
    let tables = Object.keys(map);
    tables.sort((a, b) => a - b);
    for (let i = 0; i < tables.length; i++) {
        let table = tables[i];
        let row = [table];
        for (let j = 1; j < header.length; j++) {
            let count = 0;
            for (let k = 0; k < map[table].length; k++) {
                if (map[table][k] === header[j]) {
                    count++;
                }
            }
            row.push(count.toString());
        }
        res.push(row);
    }
    return res;
    
};

    