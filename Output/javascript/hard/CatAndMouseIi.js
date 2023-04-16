/**https://leetcode.com/problems/cat-and-mouse-ii/ */
//A game is played by a cat and a mouse named Cat and Mouse.
//The environment is represented by a grid of size rows x cols, where each element is a wall, floor, player (Cat, Mouse), or food.
//Players are represented by the characters 'C'(Cat),'M'(Mouse).
//Floors are represented by the character '.' and can be walked on.
//Walls are represented by the character '#' and cannot be walked on.
//Food is represented by the character 'F' and can be walked on.
//There is only one of each character 'C', 'M', and 'F' in grid.
//Mouse and Cat play according to the following rules:
//Mouse moves first, then they take turns to move.
//During each turn, Cat and Mouse can jump in one of the four directions (left, right, up, down). They cannot jump over the wall nor outside of the grid.
//catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a time, respectively. Cat and Mouse can jump less than the maximum length.
//Staying in the same position is allowed.
//Mouse can jump over Cat.
//The game can end in 4 ways:
//If Cat occupies the same position as Mouse, Cat wins.
//If Cat reaches the food first, Cat wins.
//If Mouse reaches the food first, Mouse wins.
//If Mouse cannot get to the food within 1000 turns, Cat wins.
//Given a rows x cols matrix grid and two integers catJump and mouseJump, return true if Mouse can win the game if both Cat and Mouse play optimally, otherwise return false.


/**
 * @param {string[]} grid
 * @param {number} catJump
 * @param {number} mouseJump
 * @return {boolean}
 */
var canMouseWin = function(grid, catJump, mouseJump) {
    let n = grid.length;
    let m = grid[0].length;
    let catPos = new Array(2);
    let mousePos = new Array(2);
    let foodPos = new Array(2);
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(grid[i][j] == 'C'){
                catPos[0] = i;
                catPos[1] = j;
            }else if(grid[i][j] == 'M'){
                mousePos[0] = i;
                mousePos[1] = j;
            }else if(grid[i][j] == 'F'){
                foodPos[0] = i;
                foodPos[1] = j;
            }
        }
    }
    let memo = new Map();
    let res = dfs(grid, catPos, mousePos, foodPos, catJump, mouseJump, memo);
    return res;
    
};

    