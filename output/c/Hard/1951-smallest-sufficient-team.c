/**https://leetcode.com/problems/smallest-sufficient-team/ */
//In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.
//Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
//	For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
//Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.
//It is guaranteed an answer exists.
// 
//Example 1:
//Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
//Output: [0,2]
//Example 2:
//Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
//Output: [1,2]
// 
//Constraints:
//	1 <= req_skills.length <= 16
//	1 <= req_skills[i].length <= 16
//	req_skills[i] consists of lowercase English letters.
//	All the strings of req_skills are unique.
//	1 <= people.length <= 60
//	0 <= people[i].length <= 16
//	1 <= people[i][j].length <= 16
//	people[i][j] consists of lowercase English letters.
//	All the strings of people[i] are unique.
//	Every skill in people[i] is a skill in req_skills.
//	It is guaranteed a sufficient team exists.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSufficientTeam(char ** req_skills, int req_skillsSize, char *** people, int peopleSize, int* peopleColSize, int* returnSize){
*returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * 16);
    int **dp = (int **)malloc(sizeof(int *) * (1 << req_skillsSize));
    for (int i = 0; i < (1 << req_skillsSize); i++) {
        dp[i] = (int *)malloc(sizeof(int) * (peopleSize + 1));
    }
    memset(dp, 0xff, sizeof(int) * (1 << req_skillsSize) * (peopleSize + 1));
    dp[0][0] = 0;
    int *index = (int *)malloc(sizeof(int) * (1 << req_skillsSize));
    memset(index, 0xff, sizeof(int) * (1 << req_skillsSize));
    index[0] = -1;
    for (int i = 0; i < peopleSize; i++) {
        int skill = 0;
        for (int j = 0; j < peopleColSize[i]; j++) {
            for (int k = 0; k < req_skillsSize; k++) {
                if (strcmp(people[i][j], req_skills[k]) == 0) {
                    skill |= (1 << k);
                }
            }
        }
        for (int j = 0; j < (1 << req_skillsSize); j++) {
            if (dp[j][i] == -1) continue;
            if (dp[j][i + 1] == -1 || dp[j][i + 1] > dp[j][i]) {
                dp[j][i + 1] = dp[j][i];
                index[j] = i;
            }
            int next = j | skill;
            if (dp[next][i + 1] == -1 || dp[next][i + 1] > dp[j][i] + 1) {
                dp[next][i + 1] = dp[j][i] + 1;
                index[next] = i;
            }
        }
    }
    int k = 0;
    int j = (1 << req_skillsSize) - 1;
    while (j != 0) {
        res[k++] = index[j];
        j ^= 1 << index[j];
    }
    *returnSize = k;
    return res;
}