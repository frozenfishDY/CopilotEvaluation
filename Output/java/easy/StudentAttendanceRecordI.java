/**https://leetcode.com/problems/student-attendance-record-i/ */
//You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
//'A': Absent.
//'L': Late.
//'P': Present.
//The student is eligible for an attendance award if they meet both of the following criteria:
//The student was absent ('A') for strictly fewer than 2 days total.
//The student was never late ('L') for 3 or more consecutive days.
//Return true if the student is eligible for an attendance award, or false otherwise.


class StudentAttendanceRecordI {
    public boolean checkRecord(String s) {
        int countA = 0;
        int countL = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'A'){
                countA++;
                countL = 0;
            }else if(s.charAt(i) == 'L'){
                countL++;
            }else{
                countL = 0;
            }
            if(countA >= 2 || countL >= 3){
                return false;
            }
        }
        return true;
        
    }
}

    