/**https://leetcode.com/problems/jump-game-iii/ */
//Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
//Notice that you can not jump outside of the array at any time.


class JumpGameIii {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        while(!queue.isEmpty()){
            int index = queue.poll();
            if(arr[index] == 0){
                return true;
            }
            if(visited[index]){
                continue;
            }
            visited[index] = true;
            if(index + arr[index] < n){
                queue.add(index + arr[index]);
            }
            if(index - arr[index] >= 0){
                queue.add(index - arr[index]);
            }
        }
        return false;
        
        
        
    }
}

    