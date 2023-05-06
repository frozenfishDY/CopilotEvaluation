import language.TotalRecord;
import res.Result;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        //process source file:testcaseinfo.txt
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        /*
        * get all result and write result to 7 files in final_result directory :
        * testcase_info(complete).txt  : processed source file with testcase pass rate
        * correctness.txt              :  nums of questions for each status in 4 Languages(C,Java,JS,Python)
        * correctness(pattern).txt     : further process of correctness in 3 patterns(easy,medium,hard)
        * twoSituation.json:  two situation  question id in 3 patterns
                                 Has_Correct: at least one Accepted question in four Language
                                 All_Zero: 4 languages' has no passed testcases
        * c_id.json: question id of all status in c
        * java_id.json:question id of all status in java
        * js_id.json:question id of all status in Js
        * py_id.json:question id of all status in Python
        * */
        Result result=new Result();
        Result.getAllResult();

    }
}
