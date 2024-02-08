/**https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/ */
//You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
//The chemistry of a team is equal to the product of the skills of the players on that team.
//Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.


long long dividePlayers(int* skill, int skillSize){
    long long sum = 0;
    for(int i = 0; i < skillSize; i++){
        sum += skill[i];
    }
    if(sum % skillSize != 0){
        return -1;
    }
    long long target = sum / skillSize;
    long long result = 0;
    for(int i = 0; i < skillSize; i++){
        if(skill[i] < target){
            result += target - skill[i];
        }
    }
    return result;

}

    