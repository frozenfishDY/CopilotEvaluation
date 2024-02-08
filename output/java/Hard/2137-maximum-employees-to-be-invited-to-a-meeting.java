/**https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/ */
//A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.
//The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.
//Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.


class MaximumEmployeesToBeInvitedToAMeeting {
    public int maximumInvitations(int[] favorite) {
        int n = favorite.length;
        int[] visited = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                res += dfs(favorite, visited, i);
            }
        }
        return res;
        
        
    }
}
     
    