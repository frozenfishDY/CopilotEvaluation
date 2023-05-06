/**https://leetcode.com/problems/moving-stones-until-consecutive-ii/ */
//There are some stones in different positions on the X-axis. You are given an integer array stones, the positions of the stones.
//Call a stone an endpoint stone if it has the smallest or largest position. In one move, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.
//In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.
//The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
//Return an integer array answer of length 2 where:
//answer[0] is the minimum number of moves you can play, and
//answer[1] is the maximum number of moves you can play.


class MovingStonesUntilConsecutiveIi {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int max = Math.max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);
        int min = Integer.MAX_VALUE;
        int i = 0;
        for(int j = 0; j < n; j++){
            while(stones[j] - stones[i] >= n){
                i++;
            }
            if(j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2){
                min = Math.min(min, 2);
            }else{
                min = Math.min(min, n - (j - i + 1));
            }
        }
        return new int[]{min, max};
        
        
    }
}

    