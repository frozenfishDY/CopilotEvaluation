/**https://leetcode.com/problems/number-of-people-aware-of-a-secret/ */
//On day 1, one person discovers a secret.
//You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.
//Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 6, delay = 2, forget = 4
//Output: 5
//Explanation:
//Day 1: Suppose the first person is named A. (1 person)
//Day 2: A is the only person who knows the secret. (1 person)
//Day 3: A shares the secret with a new person, B. (2 people)
//Day 4: A shares the secret with a new person, C. (3 people)
//Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
//Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
//Example 2:
//Input: n = 4, delay = 1, forget = 3
//Output: 6
//Explanation:
//Day 1: The first person is named A. (1 person)
//Day 2: A shares the secret with B. (2 people)
//Day 3: A and B share the secret with 2 new people, C and D. (4 people)
//Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)
// 
//Constraints:
//	2 <= n <= 1000
//	1 <= delay < forget <= n
class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        int[][] dp = new int[n + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1];
                if (j >= delay) {
                    dp[i][j] = (dp[i][j] + dp[i - delay][j - delay]) % 1000000007;
                }
                if (j >= forget) {
                    dp[i][j] = (dp[i][j] - dp[i - forget][j - forget] + 1000000007) % 1000000007;
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= n; i++) {
            res = (res + dp[n][i]) % 1000000007;
        }
        return res;
    }
}