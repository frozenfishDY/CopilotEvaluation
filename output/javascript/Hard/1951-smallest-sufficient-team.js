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
 * @param {string[]} req_skills
 * @param {string[][]} people
 * @return {number[]}
 */
var smallestSufficientTeam = function(req_skills, people) {
    let skillMap = new Map();
    let peopleMap = new Map();
    for (let i = 0; i < req_skills.length; i++) {
        skillMap.set(req_skills[i], i);
    }
    for (let i = 0; i < people.length; i++) {
        let skill = 0;
        for (let j = 0; j < people[i].length; j++) {
            skill |= 1 << skillMap.get(people[i][j]);
        }
        peopleMap.set(i, skill);
    }
    let dp = new Map();
    dp.set(0, []);
    for (let [key, value] of peopleMap) {
        let newDp = new Map();
        for (let [key1, value1] of dp) {
            let newKey = value1 | value;
            if (!newDp.has(newKey) || newDp.get(newKey).length > value1.length + 1) {
                let newValue = [...value1, key];
                newDp.set(newKey, newValue);
            }
        }
        dp = newDp;
    }
    return dp.get(Math.pow(2, req_skills.length) - 1);

};