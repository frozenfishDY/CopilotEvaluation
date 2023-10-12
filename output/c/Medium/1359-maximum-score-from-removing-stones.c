/**https://leetcode.com/problems/maximum-score-from-removing-stones/ */
//You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).
//Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.
// 
//Example 1:
//Input: a = 2, b = 4, c = 6
//Output: 6
//Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
//- Take from 1st and 3rd piles, state is now (1, 4, 5)
//- Take from 1st and 3rd piles, state is now (0, 4, 4)
//- Take from 2nd and 3rd piles, state is now (0, 3, 3)
//- Take from 2nd and 3rd piles, state is now (0, 2, 2)
//- Take from 2nd and 3rd piles, state is now (0, 1, 1)
//- Take from 2nd and 3rd piles, state is now (0, 0, 0)
//There are fewer than two non-empty piles, so the game ends. Total: 6 points.
//Example 2:
//Input: a = 4, b = 4, c = 6
//Output: 7
//Explanation: The starting state is (4, 4, 6). One optimal set of moves is:
//- Take from 1st and 2nd piles, state is now (3, 3, 6)
//- Take from 1st and 3rd piles, state is now (2, 3, 5)
//- Take from 1st and 3rd piles, state is now (1, 3, 4)
//- Take from 1st and 3rd piles, state is now (0, 3, 3)
//- Take from 2nd and 3rd piles, state is now (0, 2, 2)
//- Take from 2nd and 3rd piles, state is now (0, 1, 1)
//- Take from 2nd and 3rd piles, state is now (0, 0, 0)
//There are fewer than two non-empty piles, so the game ends. Total: 7 points.
//Example 3:
//Input: a = 1, b = 8, c = 8
//Output: 8
//Explanation: One optimal set of moves is to take from the 2nd and 3rd piles for 8 turns until they are empty.
//After that, there are fewer than two non-empty piles, so the game ends.
// 
//Constraints:
//	1 <= a, b, c <= 105
int maximumScore(int a, int b, int c){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int len = strlen(s);
    int min = 0;
    int tmp = 0;
    int count = 0;
    int flag = 0;
    int *visited = (int*)malloc(sizeof(int) * len);
    memset(visited, 0, sizeof(int) * len);
    char *str = (char*)malloc(sizeof(char) * len + 1);
    strcpy(str, s);
    char *str2 = (char*)malloc(sizeof(char) * len + 1);
    strcpy(str2, s);
    for(i = 0; i < len; i++)
    {
        min = i;
        for(j = i + 1; j < len; j++)
        {
            if(str[j] < str[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            tmp = str[i];
            str[i] = str[min];
            str[min] = tmp;
        }
    }
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(str[i] == str2[j] && visited[j] == 0)
            {
                visited[j] = 1;
                count++;
            }
        }
        if(count == len)
        {
            flag = 1;
        }
        else
        {
            count = 0;
            memset(visited, 0, sizeof(int) * len);
        }
    }
    if(flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}