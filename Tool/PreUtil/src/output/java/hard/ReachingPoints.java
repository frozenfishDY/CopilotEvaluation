/**https://leetcode.com/problems/reaching-points/ */
//Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.
//The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).


class ReachingPoints {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx && ty>=sy){
            if(tx==sx && ty==sy) return true;
            if(tx>ty){
                if(ty>sy) tx%=ty;
                else return (tx-sx)%ty==0;
            }
            else{
                if(tx>sx) ty%=tx;
                else return (ty-sy)%tx==0;
            }
        }
        return false;
        
    }
}
     
    