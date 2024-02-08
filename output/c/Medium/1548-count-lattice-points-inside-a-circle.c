/**https://leetcode.com/problems/count-lattice-points-inside-a-circle/ */
//Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number of lattice points that are present inside at least one circle.
//Note:
//A lattice point is a point with integer coordinates.
//Points that lie on the circumference of a circle are also considered to be inside it.


int countLatticePoints(int** circles, int circlesSize, int* circlesColSize){
    int i, j, k, l, m, n, count = 0;
    int arr[100000] = {0};
    for(i = 0; i < circlesSize; i++){
        for(j = 0; j < 100000; j++){
            if(circles[i][0] + j * circles[i][2] < 100000){
                arr[circles[i][0] + j * circles[i][2]] = 1;
            }
        }
    }
    for(i = 0; i < 100000; i++){
        if(arr[i] == 1){
            count++;
        }
    }
    return count;

}

    