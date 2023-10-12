/**https://leetcode.com/problems/make-array-empty/ */
//You are given an integer array nums containing distinct numbers, and you can perform the following operations until the array is empty:
//	If the first element has the smallest value, remove it
//	Otherwise, put the first element at the end of the array.
//Return an integer denoting the number of operations it takes to make nums empty.
// 
//Example 1:
//Input: nums = [3,4,-1]
//Output: 5
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[4, -1, 3]
//		
//		
//			2
//			[-1, 3, 4]
//		
//		
//			3
//			[3, 4]
//		
//		
//			4
//			[4]
//		
//		
//			5
//			[]
//		
//	
//Example 2:
//Input: nums = [1,2,4,3]
//Output: 5
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[2, 4, 3]
//		
//		
//			2
//			[4, 3]
//		
//		
//			3
//			[3, 4]
//		
//		
//			4
//			[4]
//		
//		
//			5
//			[]
//		
//	
//Example 3:
//Input: nums = [1,2,3]
//Output: 3
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[2, 3]
//		
//		
//			2
//			[3]
//		
//		
//			3
//			[]
//		
//	
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
//	All values in nums are distinct.
long long countOperationsToEmptyArray(int* nums, int numsSize){
int *queue = malloc(sizeof(int)*numsSize);
	int front = 0, rear = 0;
	
	int i = 0, j = 0;
	int *row = NULL;
	int vertex = 0;
	int result = -1;
	
	queue[rear++] = 0;
	
	while(front < rear){
		vertex = queue[front++];
		i = vertex/n;
		j = vertex%n;
		row = grid[i];
		if(j + row[j] < n){
			if(visited[vertex + row[j]] == 0){
				queue[rear++] = vertex + row[j];
				distance[vertex + row[j]] = distance[vertex] + 1;
			}
		}
		if(i + grid[i][j] < m){
			if(visited[vertex + n*grid[i][j]] == 0){
				queue[rear++] = vertex + n*grid[i][j];
				distance[vertex + n*grid[i][j]] = distance[vertex] + 1;
			}
		}
	}
	return distance[m*n-1];
}