/**https://leetcode.com/problems/prison-cells-after-n-days/ */
//There are 8 prison cells in a row and each cell is either occupied or vacant.
//Each day, whether the cell is occupied or vacant changes according to the following rules:
//If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
//Otherwise, it becomes vacant.
//Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
//You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
//Return the state of the prison after n days (i.e., n such changes described above).


class PrisonCellsAfterNDays {
    public int[] prisonAfterNDays(int[] cells, int n) {
        int[] res = new int[8];
        int[] temp = new int[8];
        for(int i = 0; i < 8; i++){
            temp[i] = cells[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < 7; j++){
                if(temp[j - 1] == temp[j + 1]){
                    res[j] = 1;
                }else{
                    res[j] = 0;
                }
            }
            for(int j = 0; j < 8; j++){
                temp[j] = res[j];
            }
        }
        return res;
        
        
    }
}

    