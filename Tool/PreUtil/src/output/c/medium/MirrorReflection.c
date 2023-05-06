/**https://leetcode.com/problems/mirror-reflection/ */
//There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
//The square room has walls of length p and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.
//Given the two integers p and q, return the number of the receptor that the ray meets first.
//The test cases are guaranteed so that the ray will meet a receptor eventually.


int mirrorReflection(int p, int q){
    int m = 1;
    int n = 1;
    while(m * p != n * q){
        n++;
        m = n * q / p;
    }
    if(m % 2 == 0){
        return 2;
    }else if(n % 2 == 0){
        return 0;
    }else{
        return 1;
    }

}

    