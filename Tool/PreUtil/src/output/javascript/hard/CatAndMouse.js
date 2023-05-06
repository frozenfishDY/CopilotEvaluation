/**https://leetcode.com/problems/cat-and-mouse/ */
//A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.
//The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.
//The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.
//During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].
//Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)
//Then, the game can end in three ways:
//If ever the Cat occupies the same node as the Mouse, the Cat wins.
//If ever the Mouse reaches the Hole, the Mouse wins.
//If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
//Given a graph, and assuming both players play optimally, return
//1 if the mouse wins the game,
//2 if the cat wins the game, or
//0 if the game is a draw.


/**
 * @param {number[][]} graph
 * @return {number}
 */
var catMouseGame = function(graph) {
    let n = graph.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < n; j++){
            dp[i].push([]);
            for(let k = 0; k < 3; k++){
                dp[i][j].push([]);
                for(let l = 0; l < 2; l++){
                    dp[i][j][k].push(-1);
                }
            }
        }
    }
    let dfs = function(mouse, cat, turn, mouseTurn){
        if(mouse === cat){
            return 2;
        }
        if(mouse === 0){
            return 1;
        }
        if(dp[mouse][cat][turn][mouseTurn] !== -1){
            return dp[mouse][cat][turn][mouseTurn];
        }
        let result = 0;
        if(mouseTurn === 1){
            result = 2;
            for(let i = 0; i < graph[mouse].length; i++){
                let newMouse = graph[mouse][i];
                let newTurn = turn;
                if(newMouse === cat){
                    newTurn = 2;
                }
                result = Math.min(result, dfs(newMouse, cat, newTurn, 0));
            }
        }else{
            result = 1;
            for(let i = 0; i < graph[cat].length; i++){
                let newCat = graph[cat][i];
                if(newCat === 0){
                    continue;
                }
                let newTurn = turn;
                if(newCat === mouse){
                    newTurn = 2;
                }
                result = Math.max(result, dfs(mouse, newCat, newTurn, 1));
            }
        }
        dp[mouse][cat][turn][mouseTurn] = result;
        return result;
    };
    return dfs(1, 2, 0, 1);
    
};

    