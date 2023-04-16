/**https://leetcode.com/problems/stone-game-iv/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
//Also, if a player cannot make a move, he/she loses the game.
//Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.


bool winnerSquareGame(int n){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*(n+1));
    for(i=0;i<n+1;i++){
        arr[i] = 0;
    }
    for(i=1;i<n+1;i++){
        for(j=1;j*j<=i;j++){
            if(arr[i-j*j] == 0){
                arr[i] = 1;
                break;
            }
        }
    }
    return arr[n] == 1;

}

    