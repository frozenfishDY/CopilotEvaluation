/**https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/ */
//You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
//The chemistry of a team is equal to the product of the skills of the players on that team.
//Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.


class DividePlayersIntoTeamsOfEqualSkill {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        long[][] dp = new long[n][n];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], -1);
        }
        return dividePlayers(skill, 0, n - 1, dp);
        
        
        
    }
}

    