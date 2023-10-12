/**https://leetcode.com/problems/task-scheduler/ */
//Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
//However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
//Return the least number of units of times that the CPU will take to finish all the given tasks.
// 
//Example 1:
//Input: tasks = ["A","A","A","B","B","B"], n = 2
//Output: 8
//Explanation: 
//A -> B -> idle -> A -> B -> idle -> A -> B
//There is at least 2 units of time between any two same tasks.
//Example 2:
//Input: tasks = ["A","A","A","B","B","B"], n = 0
//Output: 6
//Explanation: On this case any permutation of size 6 would work since n = 0.
//["A","A","A","B","B","B"]
//["A","B","A","B","A","B"]
//["B","B","B","A","A","A"]
//...
//And so on.
//Example 3:
//Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
//Output: 16
//Explanation: 
//One possible solution is
//A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
// 
//Constraints:
//	1 <= task.length <= 104
//	tasks[i] is upper-case English letter.
//	The integer n is in the range [0, 100].
int leastInterval(char* tasks, int tasksSize, int n){
int* count = (int*)malloc(sizeof(int) * 26);
    memset(count, 0, sizeof(int) * 26);
    for (int i = 0; i < tasksSize; i++) {
        count[tasks[i] - 'A']++;
    }
    int max = 0;
    int maxCount = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            maxCount = 1;
        } else if (count[i] == max) {
            maxCount++;
        }
    }
    int res = (max - 1) * (n + 1) + maxCount;
    return res > tasksSize ? res : tasksSize;
}