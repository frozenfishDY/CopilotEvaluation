/**https://leetcode.com/problems/sliding-puzzle/ */
//On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
//The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
// 
//Example 1:
//Input: board = [[1,2,3],[4,0,5]]
//Output: 1
//Explanation: Swap the 0 and the 5 in one move.
//Example 2:
//Input: board = [[1,2,3],[5,4,0]]
//Output: -1
//Explanation: No number of moves will make the board solved.
//Example 3:
//Input: board = [[4,1,2],[5,0,3]]
//Output: 5
//Explanation: 5 is the smallest number of moves that solves the board.
//An example path:
//After move 0: [[4,1,2],[5,0,3]]
//After move 1: [[4,1,2],[0,5,3]]
//After move 2: [[0,1,2],[4,5,3]]
//After move 3: [[1,0,2],[4,5,3]]
//After move 4: [[1,2,0],[4,5,3]]
//After move 5: [[1,2,3],[4,5,0]]
// 
//Constraints:
//	board.length == 2
//	board[i].length == 3
//	0 <= board[i][j] <= 5
//	Each value board[i][j] is unique.
int slidingPuzzle(int** board, int boardSize, int* boardColSize){
int res = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    char *goal = "123450";
    char *start = (char *)malloc(sizeof(char) * 7);
    int idx = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) start[idx++] = board[i][j] + '0';
    }
    start[idx] = '\0';
    if (strcmp(start, goal) == 0) return res;
    queue *q = (queue *)malloc(sizeof(queue));
    init(q);
    enqueue(q, start);
    set *visited = (set *)malloc(sizeof(set));
    initSet(visited);
    while (q->size != 0) {
        int size = q->size;
        for (int i = 0; i < size; i++) {
            char *cur = dequeue(q);
            int idx = 0;
            while (cur[idx] != '0') idx++;
            int x = idx / 3, y = idx % 3;
            for (int j = 0; j < 4; j++) {
                int newX = x + dir[j][0];
                int newY = y + dir[j][1];
                if (newX < 0 || newX >= 2 || newY < 0 || newY >= 3) continue;
                int newIdx = newX * 3 + newY;
                char *next = (char *)malloc(sizeof(char) * 7);
                strcpy(next, cur);
                next[idx] = next[newIdx];
                next[newIdx] = '0';
                if (strcmp(next, goal) == 0) return res + 1;
                if (!contains(visited, next)) {
                    enqueue(q, next);
                    insert(visited, next);
                }
            }
        }
        res++;
    }
    return -1;
}
typedef struct {
    char **data;
    int size;
    int capacity;
} set;
void initSet(set *s) {
    s->data = (char **)malloc(sizeof(char *) * 100000);
    s->size = 0;
    s->capacity = 100000;
}