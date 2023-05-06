/**https://leetcode.com/problems/snakes-and-ladders/ */
//You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.
//You start on square 1 of the board. In each move, starting from square curr, do the following:
//Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
//This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
//If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
//The game ends when you reach the square n2.
//A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.
//Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
//For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
//Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.


class SnakesAndLadders {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        int[] arr = new int[n * n];
        int idx = 0;
        for(int i = n - 1; i >= 0; i--){
            if((n - i) % 2 == 0){
                for(int j = 0; j < n; j++){
                    arr[idx++] = board[i][j];
                }
            }else{
                for(int j = n - 1; j >= 0; j--){
                    arr[idx++] = board[i][j];
                }
            }
        }
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        boolean[] visited = new boolean[n * n];
        visited[0] = true;
        int res = 0;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int curr = q.poll();
                if(curr == n * n - 1){
                    return res;
                }
                for(int j = 1; j <= 6; j++){
                    int next = curr + j;
                    if(next >= n * n){
                        break;
                    }
                    if(arr[next] != -1){
                        next = arr[next] - 1;
                    }
                    if(!visited[next]){
                        visited[next] = true;
                        q.offer(next);
                    }
                }
            }
            res++;
        }
        return -1;
        
        
    }
}

    