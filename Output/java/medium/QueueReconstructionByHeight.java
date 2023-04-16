/**https://leetcode.com/problems/queue-reconstruction-by-height/ */
//You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
//Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).


class QueueReconstructionByHeight {
    public int[][] reconstructQueue(int[][] people) {
        int n = people.length;
        Arrays.sort(people, (a, b) -> {
            if(a[0] != b[0]){
                return b[0] - a[0];
            }else{
                return a[1] - b[1];
            }
        });
        List<int[]> list = new ArrayList<>();
        for(int i = 0; i < n; i++){
            list.add(people[i][1], people[i]);
        }
        int[][] res = new int[n][2];
        for(int i = 0; i < n; i++){
            res[i] = list.get(i);
        }
        return res;
        
    }
}

    