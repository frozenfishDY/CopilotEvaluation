/**https://leetcode.com/problems/find-all-people-with-secret/ */
//You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
//Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.
//The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.
//Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.


class FindAllPeopleWithSecret {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        List<Integer> res = new ArrayList<>();
        int[] visited = new int[n];
        visited[firstPerson] = 1;
        for (int[] meeting : meetings) {
            if (visited[meeting[0]] == 1) {
                visited[meeting[1]] = 1;
            }
            if (visited[meeting[1]] == 1) {
                visited[meeting[0]] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                res.add(i);
            }
        }
        return res;
        
    }
}
     
    