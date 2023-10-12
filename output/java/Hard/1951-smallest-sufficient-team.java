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
class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
         int n = req_skills.length;
        int m = people.size();
        int[] skillSet = new int[m];
        Map<String, Integer> skillMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            skillMap.put(req_skills[i], i);
        }
        for (int i = 0; i < m; i++) {
            int skillBit = 0;
            for (String skill : people.get(i)) {
                skillBit |= 1 << skillMap.get(skill);
            }
            skillSet[i] = skillBit;
        }
        int[] dp = new int[1 << n];
        Arrays.fill(dp, Integer.MAX_VALUE / 2);
        dp[0] = 0;
        int[] prev = new int[1 << n];
        Arrays.fill(prev, -1);
        for (int i = 0; i < m; i++) {
            for (int j = dp.length - 1; j >= 0; j--) {
                if (dp[j] + 1 < dp[j | skillSet[i]]) {
                    dp[j | skillSet[i]] = dp[j] + 1;
                    prev[j | skillSet[i]] = j;
                }
            }
        }
        int[] res = new int[dp[dp.length - 1]];
        int index = dp.length - 1;
        for (int i = res.length - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if ((index & (1 << j)) != 0 && (index ^ skillSet[j]) == prev[index]) {
                    res[i] = j;
                    index = prev[index];
                    break;
                }
            }
        }
        return res;
    }
}