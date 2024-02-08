/**https://leetcode.com/problems/closest-room/ */
//There is a hotel with n rooms. The rooms are represented by a 2D integer array rooms where rooms[i] = [roomIdi, sizei] denotes that there is a room with room number roomIdi and size equal to sizei. Each roomIdi is guaranteed to be unique.
//You are also given k queries in a 2D array queries where queries[j] = [preferredj, minSizej]. The answer to the jth query is the room number id of a room such that:
//The room has a size of at least minSizej, and
//abs(id - preferredj) is minimized, where abs(x) is the absolute value of x.
//If there is a tie in the absolute difference, then use the room with the smallest such id. If there is no such room, the answer is -1.
//Return an array answer of length k where answer[j] contains the answer to the jth query.


class ClosestRoom {
    public int[] closestRoom(int[][] rooms, int[][] queries) {
        int n = rooms.length;
        int m = queries.length;
        int[] res = new int[m];
        Arrays.fill(res, -1);
        int[][] qs = new int[m][3];
        for(int i = 0; i < m; i++){
            qs[i][0] = queries[i][0];
            qs[i][1] = queries[i][1];
            qs[i][2] = i;
        }
        Arrays.sort(rooms, (a, b) -> b[1] - a[1]);
        Arrays.sort(qs, (a, b) -> b[1] - a[1]);
        TreeSet<Integer> set = new TreeSet<>();
        int j = 0;
        for(int i = 0; i < m; i++){
            while(j < n && rooms[j][1] >= qs[i][1]){
                set.add(rooms[j][0]);
                j++;
            }
            Integer l = set.floor(qs[i][0]);
            Integer r = set.ceiling(qs[i][0]);
            if(l == null && r == null){
                continue;
            }
            if(l == null){
                res[qs[i][2]] = r;
            }else if(r == null){
                res[qs[i][2]] = l;
            }else{
                if(Math.abs(l - qs[i][0]) <= Math.abs(r - qs[i][0])){
                    res[qs[i][2]] = l;
                }else{
                    res[qs[i][2]] = r;
                }
            }
        }
        return res;
        
    }
}
     
    