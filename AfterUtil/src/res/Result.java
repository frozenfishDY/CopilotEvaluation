package res;

import json.JsonUtil;
import language.*;
import type.TypeUtil;
import util.Calculator;
import util.FileUtil;

import java.io.IOException;
import java.util.*;

import static java.lang.System.exit;

public class Result {

    private static List<Integer> hasCorrect_result;
    private static List<Integer> allZero_result;
    private  static List<List<Integer>> acc_result;
    private static  List<List<Integer>> ce_result;
    private static  List<List<Integer>> re_result;
    private static List<List<Integer>> wa_result;
    private static List<List<Integer>> tle_result;
    private static List<List<Integer>> mle_result;
    private static List<List<Integer>> pa_result;//partially correct status

    /*
    * Map's key indicates pattern:  0->easy   1->medium   2-hard
    * List<List<String>>  indicates corresponding status'slist   List<c_list,java_list,js_list,py_list>
               0(C)   1(java)   2(js)   3(py)
     0(easy)
     1(medium)
     2(hard)
    * */
    private static HashMap<Integer,List<Integer>> hasCorrect_pattern_result;
    private static HashMap<Integer,List<Integer>> allZero_pattern_result;
    private static HashMap<Integer,List<List<Integer>>> acc_pattern_result;
    private static HashMap<Integer,List<List<Integer>>> ce_pattern_result;
    private static HashMap<Integer,List<List<Integer>>> re_pattern_result;
    private static HashMap<Integer,List<List<Integer>>> wa_pattern_result;
    private static HashMap<Integer,List<List<Integer>>> tle_pattern_result;
    private static HashMap<Integer,List<List<Integer>>> mle_pattern_result;
    private static HashMap<Integer,List<List<Integer>>> pa_pattern_result;

    public static HashMap<Integer, List<Integer>> getHasCorrect_pattern_result() {
        return hasCorrect_pattern_result;
    }

    public static HashMap<Integer, List<Integer>> getAllZero_pattern_result() {
        return allZero_pattern_result;
    }

    public static HashMap<Integer, List<List<Integer>>> getAcc_pattern_result() {
        return acc_pattern_result;
    }

    public static HashMap<Integer, List<List<Integer>>> getCe_pattern_result() {
        return ce_pattern_result;
    }

    public static HashMap<Integer, List<List<Integer>>> getRe_pattern_result() {
        return re_pattern_result;
    }

    public static HashMap<Integer, List<List<Integer>>> getWa_pattern_result() {
        return wa_pattern_result;
    }

    public static HashMap<Integer, List<List<Integer>>> getTle_pattern_result() {
        return tle_pattern_result;
    }

    public static HashMap<Integer, List<List<Integer>>> getMle_pattern_result() {
        return mle_pattern_result;
    }

    public static HashMap<Integer, List<List<Integer>>> getPa_pattern_result() {
        return pa_pattern_result;
    }

    public Result() {
        hasCorrect_result=new ArrayList<Integer>();
        allZero_result=new ArrayList<Integer>();
        acc_result=new ArrayList<>();
        ce_result=new ArrayList<>();
        re_result=new ArrayList<>();
        wa_result=new ArrayList<>();
        tle_result=new ArrayList<>();
        mle_result=new ArrayList<>();
        pa_result=new ArrayList<>();
        hasCorrect_pattern_result=new HashMap<>();
        allZero_pattern_result=new HashMap<>();
        acc_pattern_result=new HashMap<>();
        ce_pattern_result=new HashMap<>();
        re_pattern_result=new HashMap<>();
        wa_pattern_result=new HashMap<>();
        tle_pattern_result=new HashMap<>();
        mle_pattern_result=new HashMap<>();
        pa_pattern_result=new HashMap<>();
    }

    public static void getAllResult() throws IOException {
        hasCorrect_result=sortSet(TotalRecord.getCorrect_set());
        allZero_result=sortSet(TotalRecord.getFail_set());

        CRecord cRecord = TotalRecord.getcRecord();
        JavaRecord javaRecord=TotalRecord.getJavaRecord();
        JSRecord jsRecord=TotalRecord.getJsRecord();
        PyRecord pyRecord=TotalRecord.getPyRecord();
        List<Integer> c_acc_list=sortSet(cRecord.getAcc_set());
        List<Integer> java_acc_list=sortSet(javaRecord.getAcc_set());
        List<Integer> js_acc_list=sortSet(jsRecord.getAcc_set());
        List<Integer> py_acc_list=sortSet(pyRecord.getAcc_set());

        acc_result.add(c_acc_list);
        acc_result.add(java_acc_list);
        acc_result.add(js_acc_list);
        acc_result.add(py_acc_list);

        List<Integer> c_ce_list=sortSet(cRecord.getCe_set());
        List<Integer> java_ce_list=sortSet(javaRecord.getCe_set());
        ce_result.add(c_ce_list);
        ce_result.add(java_ce_list);

        List<Integer> c_re_list=sortSet(cRecord.getRe_set());
        List<Integer> java_re_list=sortSet(javaRecord.getRe_set());
        List<Integer> js_re_list=sortSet(jsRecord.getRe_set());
        List<Integer> py_re_list=sortSet(pyRecord.getRe_set());

        re_result.add(c_re_list);
        re_result.add(java_re_list);
        re_result.add(js_re_list);
        re_result.add(py_re_list);

        List<Integer> c_wa_list=sortSet(cRecord.getWa_set());
        List<Integer> java_wa_list=sortSet(javaRecord.getWa_set());
        List<Integer> js_wa_list=sortSet(jsRecord.getWa_set());
        List<Integer> py_wa_list=sortSet(pyRecord.getWa_set());

        wa_result.add(c_wa_list);
        wa_result.add(java_wa_list);
        wa_result.add(js_wa_list);
        wa_result.add(py_wa_list);

        List<Integer> c_tle_list=sortSet(cRecord.getTle_set());
        List<Integer> java_tle_list=sortSet(javaRecord.getTle_set());
        List<Integer> js_tle_list=sortSet(jsRecord.getTle_set());
        List<Integer> py_tle_list=sortSet(pyRecord.getTle_set());

        tle_result.add(c_tle_list);
        tle_result.add(java_tle_list);
        tle_result.add(js_tle_list);
        tle_result.add(py_tle_list);

        List<Integer> c_mle_list=sortSet(cRecord.getMle_set());
        List<Integer> java_mle_list=sortSet(javaRecord.getMle_set());
        List<Integer> js_mle_list=sortSet(jsRecord.getMle_set());
        List<Integer> py_mle_list=sortSet(pyRecord.getMle_set());

        mle_result.add(c_mle_list);
        mle_result.add(java_mle_list);
        mle_result.add(js_mle_list);
        mle_result.add(py_mle_list);

        List<Integer> c_pa_list=sortSet(cRecord.getPartially_correct_set());
        List<Integer> java_pa_list=sortSet(javaRecord.getPartially_correct_set());
        List<Integer> js_pa_list=sortSet(jsRecord.getPartially_correct_set());
        List<Integer> py_pa_list=sortSet(pyRecord.getPartially_correct_set());

        pa_result.add(c_pa_list);
        pa_result.add(java_pa_list);
        pa_result.add(js_pa_list);
        pa_result.add(py_pa_list);

        getHasPatternResultMap();
        getAllZeroPatternResultMap();
        getAccPatternResultMap();
        getWaPatternResultMap();
        getCePatternResultMap();
        getRePatternResultMap();
        getTlePatternResultMap();
        getMlePatternResultMap();
        getPaPatternResultMap();

        //get result files:
        TotalRecord.writeProcessedRecordtoFile("D:\\CopilotTest\\AfterUtil\\final_result\\testcase_info(complete).txt");//testcase_info(complete).txt
        Result.getCorrectnessOutPut();//correctness.txt
        Result.getPatternCorrectnessOutput();//correctness(pattern).txt
        TypeUtil.getAllQuestionInfoByTag();
        TypeUtil.getTypeCorrectnessOutput();
        JsonUtil.getAllJsonResult();

    }

    public static List<Integer> sortSet(Set<Integer> idSet)
    {
        if(idSet==null)
        {
            System.out.println("Null Set Error");
            exit(0);
        }
        List<Integer> idList=new ArrayList<>(idSet);
        idList.sort(Comparator.naturalOrder());
        return idList;
    }

    public static void getCorrectnessOutPut() throws IOException {
        StringBuilder stringBuilder=new StringBuilder();
        List<Integer> num_list=new ArrayList<>();
        stringBuilder.append("----ACC----\n");
        for(int i=0;i<Result.getAcc_result().size();i++)
        {
            int num=Result.getAcc_result().get(i).size();
            String percent= Calculator.calculateFinalPercent(num,990);
            stringBuilder.append(num+" "+"("+percent+")"+"\t");
        }

        stringBuilder.append("\n\n");
        stringBuilder.append("----WA----\n");
        for(int i=0;i<Result.getWa_result().size();i++)
        {
            int num=Result.getWa_result().get(i).size();
            String percent= Calculator.calculateFinalPercent(num,990);
            stringBuilder.append(num+" "+"("+percent+")"+"\t");
        }
        stringBuilder.append("\n\n");
        stringBuilder.append("----CE----\n");
        for(int i=0;i<Result.getCe_result().size();i++)
        {
            int num=Result.getCe_result().get(i).size();
            String percent= Calculator.calculateFinalPercent(num,990);
            stringBuilder.append(num+" "+"("+percent+")"+"\t");
        }

        stringBuilder.append("\n\n");
        stringBuilder.append("----RE----\n");
        for(int i=0;i<Result.getRe_result().size();i++)
        {
            int num=Result.getRe_result().get(i).size();
            String percent= Calculator.calculateFinalPercent(num,990);
            stringBuilder.append(num+" "+"("+percent+")"+"\t");
        }

        stringBuilder.append("\n\n");
        stringBuilder.append("----TLE----\n");
        for(int i=0;i<Result.getTle_result().size();i++)
        {
            int num=Result.getTle_result().get(i).size();
            String percent= Calculator.calculateFinalPercent(num,990);
            stringBuilder.append(num+" "+"("+percent+")"+"\t");
        }

        stringBuilder.append("\n\n");
        stringBuilder.append("----MLE----\n");

        for(int i=0;i<Result.getMle_result().size();i++)
        {
            int num=Result.getMle_result().get(i).size();
            String percent= Calculator.calculateFinalPercent(num,990);
            stringBuilder.append(num+" "+"("+percent+")"+"\t");
        }

        stringBuilder.append("\n\n");
        stringBuilder.append("----Partially Correct----\n");
        for(int i=0;i<Result.getPa_result().size();i++)
        {
            int num=Result.getPa_result().get(i).size();
            String percent= Calculator.calculateFinalPercent(num,990);
            stringBuilder.append(num+" "+"("+percent+")"+"\t");
        }

        stringBuilder.append("\n\n");
        stringBuilder.append("----HasAccepted  and  Allzero----\n");
        int num=Result.getHasCorrect_result().size();
        String percent=Calculator.calculateFinalPercent(num,990);
        stringBuilder.append(num+" "+"("+percent+")"+"\n");
        num=Result.getAllZero_result().size();
        percent=Calculator.calculateFinalPercent(num,990);
        stringBuilder.append(num+" "+"("+percent+")");
        FileUtil.writeStringtoFile("D:\\CopilotTest\\AfterUtil\\final_result\\correctness.txt",stringBuilder.toString());
    }

    public static void getPatternCorrectnessOutput() throws IOException {
        String easy_content=getCorrectnessContentByPattern(0);
        String medium_content=getCorrectnessContentByPattern(1);
        String hard_content=getCorrectnessContentByPattern(2);
        String content=easy_content+medium_content+hard_content;
        FileUtil.writeStringtoFile("D:\\CopilotTest\\AfterUtil\\final_result\\correctness(pattern).txt",content);
    }

    public static String getCorrectnessContentByPattern(int patternIndex)
    {
        String titile=null;
        int questionNum=0;
        if(patternIndex==0)
        {
            titile="Easy";
            questionNum=120;

        }
        else if(patternIndex==1)
        {
            titile="Medium";
            questionNum=510;
        }

        else if(patternIndex==2)
        {
            titile="Hard";
            questionNum=360;
        }

        else
        {
            System.out.println("patternIndex Error ");
            exit(0);
        }


        StringBuilder stringBuilder=new StringBuilder();

        //Bulid Easy Content
        stringBuilder.append("******"+titile+"******\n");
        stringBuilder.append("----HasAccepted----\n");
        int num=hasCorrect_pattern_result.get(patternIndex).size();
        String percent=Calculator.calculateFinalPercent(num,questionNum);
        stringBuilder.append(num+" "+"("+percent+")\n");

        stringBuilder.append("\n----AllZero----\n");
        num=allZero_pattern_result.get(patternIndex).size();
        percent=Calculator.calculateFinalPercent(num,questionNum);
        stringBuilder.append(num+" "+"("+percent+")\n");

        stringBuilder.append("\n----Accepted----\n");
        for(int i=0;i<acc_pattern_result.get(patternIndex).size();i++)
        {
            num=acc_pattern_result.get(patternIndex).get(i).size();
            percent=Calculator.calculateFinalPercent(num,questionNum);
            stringBuilder.append(num+" "+"("+percent+")\t");

        }
        stringBuilder.append("\n");
        stringBuilder.append("\n----Wrong Answer----\n");
        for(int i=0;i<wa_pattern_result.get(patternIndex).size();i++)
        {
            num=wa_pattern_result.get(patternIndex).get(i).size();
            percent=Calculator.calculateFinalPercent(num,questionNum);
            stringBuilder.append(num+" "+"("+percent+")\t");

        }
        stringBuilder.append("\n");
        stringBuilder.append("\n----Compile Error----\n");
        for(int i=0;i<ce_pattern_result.get(patternIndex).size();i++)
        {
            num=ce_pattern_result.get(patternIndex).get(i).size();
            percent=Calculator.calculateFinalPercent(num,questionNum);
            stringBuilder.append(num+" "+"("+percent+")\t");
        }
        stringBuilder.append("\n");
        stringBuilder.append("\n----Runtime Error----\n");
        for(int i=0;i<re_pattern_result.get(patternIndex).size();i++)
        {
            num=re_pattern_result.get(patternIndex).get(i).size();
            percent=Calculator.calculateFinalPercent(num,questionNum);
            stringBuilder.append(num+" "+"("+percent+")\t");
        }
        stringBuilder.append("\n");
        stringBuilder.append("\n----Time Limitted Exceeded----\n");
        for(int i=0;i<tle_pattern_result.get(patternIndex).size();i++)
        {
            num=tle_pattern_result.get(patternIndex).get(i).size();
            percent=Calculator.calculateFinalPercent(num,questionNum);
            stringBuilder.append(num+" "+"("+percent+")\t");
        }
        stringBuilder.append("\n");
        stringBuilder.append("\n----Memory Limitted Exceeded----\n");
        for(int i=0;i<mle_pattern_result.get(patternIndex).size();i++)
        {
            num=mle_pattern_result.get(patternIndex).get(i).size();
            percent=Calculator.calculateFinalPercent(num,questionNum);
            stringBuilder.append(num+" "+"("+percent+")\t");
        }
        stringBuilder.append("\n");
        stringBuilder.append("\n----Partially Correct----\n");
        for(int i=0;i<pa_pattern_result.get(patternIndex).size();i++)
        {
            num=pa_pattern_result.get(patternIndex).get(i).size();
            percent=Calculator.calculateFinalPercent(num,questionNum);
            stringBuilder.append(num+" "+"("+percent+")\t");
        }
        stringBuilder.append("\n\n");
        return stringBuilder.toString();
    }

    public static void getPaPatternResultMap()
    {
        List<List<Integer>> easy_list=new ArrayList<>();
        List<List<Integer>> medium_list=new ArrayList<>();
        List<List<Integer>> hard_list=new ArrayList<>();
        List<Integer> c_easy_list=new ArrayList<>();
        List<Integer> java_easy_list=new ArrayList<>();
        List<Integer> js_easy_list=new ArrayList<>();
        List<Integer> py_easy_list=new ArrayList<>();
        List<Integer> c_medium_list=new ArrayList<>();
        List<Integer> java_medium_list=new ArrayList<>();
        List<Integer> js_medium_list=new ArrayList<>();
        List<Integer> py_medium_list=new ArrayList<>();
        List<Integer> c_hard_list=new ArrayList<>();
        List<Integer> java_hard_list=new ArrayList<>();
        List<Integer> js_hard_list=new ArrayList<>();
        List<Integer> py_hard_list=new ArrayList<>();
        for(int i=0;i<pa_result.size();i++)
        {
            for(int j=0;j<pa_result.get(i).size();j++)
            {
                int id=pa_result.get(i).get(j);
                if(i==0)
                {
                    if(id>=1&&id<=120)
                        c_easy_list.add(id);
                    if(id>120&&id<=630)
                        c_medium_list.add(id);
                    if(id>630&&id<=990)
                        c_hard_list.add(id);
                }
                if(i==1)
                {
                    if(id>=1&&id<=120)
                        java_easy_list.add(id);
                    if(id>120&&id<=630)
                        java_medium_list.add(id);
                    if(id>630&&id<=990)
                        java_hard_list.add(id);
                }
                if(i==2)
                {
                    if(id>=1&&id<=120)
                        js_easy_list.add(id);
                    if(id>120&&id<=630)
                        js_medium_list.add(id);
                    if(id>630&&id<=990)
                        js_hard_list.add(id);
                }
                if(i==3)
                {
                    if(id>=1&&id<=120)
                        py_easy_list.add(id);
                    if(id>120&&id<=630)
                        py_medium_list.add(id);
                    if(id>630&&id<=990)
                        py_hard_list.add(id);
                }
            }//end of internal For
        }//end of For
        easy_list.add(c_easy_list);
        easy_list.add(java_easy_list);
        easy_list.add(js_easy_list);
        easy_list.add(py_easy_list);
        pa_pattern_result.put(0,easy_list);

        medium_list.add(c_medium_list);
        medium_list.add(java_medium_list);
        medium_list.add(js_medium_list);
        medium_list.add(py_medium_list);
        pa_pattern_result.put(1,medium_list);

        hard_list.add(c_hard_list);
        hard_list.add(java_hard_list);
        hard_list.add(js_hard_list);
        hard_list.add(py_hard_list);

        pa_pattern_result.put(2,hard_list);

    }

    public static void getMlePatternResultMap()
    {
        List<List<Integer>> easy_list=new ArrayList<>();
        List<List<Integer>> medium_list=new ArrayList<>();
        List<List<Integer>> hard_list=new ArrayList<>();
        List<Integer> c_easy_list=new ArrayList<>();
        List<Integer> java_easy_list=new ArrayList<>();
        List<Integer> js_easy_list=new ArrayList<>();
        List<Integer> py_easy_list=new ArrayList<>();
        List<Integer> c_medium_list=new ArrayList<>();
        List<Integer> java_medium_list=new ArrayList<>();
        List<Integer> js_medium_list=new ArrayList<>();
        List<Integer> py_medium_list=new ArrayList<>();
        List<Integer> c_hard_list=new ArrayList<>();
        List<Integer> java_hard_list=new ArrayList<>();
        List<Integer> js_hard_list=new ArrayList<>();
        List<Integer> py_hard_list=new ArrayList<>();
        for(int i=0;i<mle_result.size();i++)
        {
            for(int j=0;j<mle_result.get(i).size();j++)
            {
                int id=mle_result.get(i).get(j);
                if(i==0)
                {
                    if(id>=1&&id<=120)
                        c_easy_list.add(id);
                    if(id>120&&id<=630)
                        c_medium_list.add(id);
                    if(id>630&&id<=990)
                        c_hard_list.add(id);
                }
                if(i==1)
                {
                    if(id>=1&&id<=120)
                        java_easy_list.add(id);
                    if(id>120&&id<=630)
                        java_medium_list.add(id);
                    if(id>630&&id<=990)
                        java_hard_list.add(id);
                }
                if(i==2)
                {
                    if(id>=1&&id<=120)
                        js_easy_list.add(id);
                    if(id>120&&id<=630)
                        js_medium_list.add(id);
                    if(id>630&&id<=990)
                        js_hard_list.add(id);
                }
                if(i==3)
                {
                    if(id>=1&&id<=120)
                        py_easy_list.add(id);
                    if(id>120&&id<=630)
                        py_medium_list.add(id);
                    if(id>630&&id<=990)
                        py_hard_list.add(id);
                }
            }//end of internal For
        }//end of For
        easy_list.add(c_easy_list);
        easy_list.add(java_easy_list);
        easy_list.add(js_easy_list);
        easy_list.add(py_easy_list);
        mle_pattern_result.put(0,easy_list);

        medium_list.add(c_medium_list);
        medium_list.add(java_medium_list);
        medium_list.add(js_medium_list);
        medium_list.add(py_medium_list);
        mle_pattern_result.put(1,medium_list);

        hard_list.add(c_hard_list);
        hard_list.add(java_hard_list);
        hard_list.add(js_hard_list);
        hard_list.add(py_hard_list);

        mle_pattern_result.put(2,hard_list);

    }

    public static void getTlePatternResultMap()
    {
        List<List<Integer>> easy_list=new ArrayList<>();
        List<List<Integer>> medium_list=new ArrayList<>();
        List<List<Integer>> hard_list=new ArrayList<>();
        List<Integer> c_easy_list=new ArrayList<>();
        List<Integer> java_easy_list=new ArrayList<>();
        List<Integer> js_easy_list=new ArrayList<>();
        List<Integer> py_easy_list=new ArrayList<>();
        List<Integer> c_medium_list=new ArrayList<>();
        List<Integer> java_medium_list=new ArrayList<>();
        List<Integer> js_medium_list=new ArrayList<>();
        List<Integer> py_medium_list=new ArrayList<>();
        List<Integer> c_hard_list=new ArrayList<>();
        List<Integer> java_hard_list=new ArrayList<>();
        List<Integer> js_hard_list=new ArrayList<>();
        List<Integer> py_hard_list=new ArrayList<>();
        for(int i=0;i<tle_result.size();i++)
        {
            for(int j=0;j<tle_result.get(i).size();j++)
            {
                int id=tle_result.get(i).get(j);
                if(i==0)
                {
                    if(id>=1&&id<=120)
                        c_easy_list.add(id);
                    if(id>120&&id<=630)
                        c_medium_list.add(id);
                    if(id>630&&id<=990)
                        c_hard_list.add(id);
                }
                if(i==1)
                {
                    if(id>=1&&id<=120)
                        java_easy_list.add(id);
                    if(id>120&&id<=630)
                        java_medium_list.add(id);
                    if(id>630&&id<=990)
                        java_hard_list.add(id);
                }
                if(i==2)
                {
                    if(id>=1&&id<=120)
                        js_easy_list.add(id);
                    if(id>120&&id<=630)
                        js_medium_list.add(id);
                    if(id>630&&id<=990)
                        js_hard_list.add(id);
                }
                if(i==3)
                {
                    if(id>=1&&id<=120)
                        py_easy_list.add(id);
                    if(id>120&&id<=630)
                        py_medium_list.add(id);
                    if(id>630&&id<=990)
                        py_hard_list.add(id);
                }
            }//end of internal For
        }//end of For
        easy_list.add(c_easy_list);
        easy_list.add(java_easy_list);
        easy_list.add(js_easy_list);
        easy_list.add(py_easy_list);
        tle_pattern_result.put(0,easy_list);

        medium_list.add(c_medium_list);
        medium_list.add(java_medium_list);
        medium_list.add(js_medium_list);
        medium_list.add(py_medium_list);
        tle_pattern_result.put(1,medium_list);

        hard_list.add(c_hard_list);
        hard_list.add(java_hard_list);
        hard_list.add(js_hard_list);
        hard_list.add(py_hard_list);

        tle_pattern_result.put(2,hard_list);

    }

    public static void getRePatternResultMap()
    {
        List<List<Integer>> easy_list=new ArrayList<>();
        List<List<Integer>> medium_list=new ArrayList<>();
        List<List<Integer>> hard_list=new ArrayList<>();
        List<Integer> c_easy_list=new ArrayList<>();
        List<Integer> java_easy_list=new ArrayList<>();
        List<Integer> js_easy_list=new ArrayList<>();
        List<Integer> py_easy_list=new ArrayList<>();
        List<Integer> c_medium_list=new ArrayList<>();
        List<Integer> java_medium_list=new ArrayList<>();
        List<Integer> js_medium_list=new ArrayList<>();
        List<Integer> py_medium_list=new ArrayList<>();
        List<Integer> c_hard_list=new ArrayList<>();
        List<Integer> java_hard_list=new ArrayList<>();
        List<Integer> js_hard_list=new ArrayList<>();
        List<Integer> py_hard_list=new ArrayList<>();
        for(int i=0;i<re_result.size();i++)
        {
            for(int j=0;j<re_result.get(i).size();j++)
            {
                int id=re_result.get(i).get(j);
                if(i==0)
                {
                    if(id>=1&&id<=120)
                        c_easy_list.add(id);
                    if(id>120&&id<=630)
                        c_medium_list.add(id);
                    if(id>630&&id<=990)
                        c_hard_list.add(id);
                }
                if(i==1)
                {
                    if(id>=1&&id<=120)
                        java_easy_list.add(id);
                    if(id>120&&id<=630)
                        java_medium_list.add(id);
                    if(id>630&&id<=990)
                        java_hard_list.add(id);
                }
                if(i==2)
                {
                    if(id>=1&&id<=120)
                        js_easy_list.add(id);
                    if(id>120&&id<=630)
                        js_medium_list.add(id);
                    if(id>630&&id<=990)
                        js_hard_list.add(id);
                }
                if(i==3)
                {
                    if(id>=1&&id<=120)
                        py_easy_list.add(id);
                    if(id>120&&id<=630)
                        py_medium_list.add(id);
                    if(id>630&&id<=990)
                        py_hard_list.add(id);
                }
            }//end of internal For
        }//end of For
        easy_list.add(c_easy_list);
        easy_list.add(java_easy_list);
        easy_list.add(js_easy_list);
        easy_list.add(py_easy_list);
        re_pattern_result.put(0,easy_list);

        medium_list.add(c_medium_list);
        medium_list.add(java_medium_list);
        medium_list.add(js_medium_list);
        medium_list.add(py_medium_list);
        re_pattern_result.put(1,medium_list);

        hard_list.add(c_hard_list);
        hard_list.add(java_hard_list);
        hard_list.add(js_hard_list);
        hard_list.add(py_hard_list);

        re_pattern_result.put(2,hard_list);

    }

    public static void getCePatternResultMap()
    {
        List<List<Integer>> easy_list=new ArrayList<>();
        List<List<Integer>> medium_list=new ArrayList<>();
        List<List<Integer>> hard_list=new ArrayList<>();
        List<Integer> c_easy_list=new ArrayList<>();
        List<Integer> c_medium_list=new ArrayList<>();
        List<Integer> c_hard_list=new ArrayList<>();
        List<Integer> java_easy_list=new ArrayList<>();
        List<Integer> java_medium_list=new ArrayList<>();
        List<Integer> java_hard_list=new ArrayList<>();

        for(int i=0;i<ce_result.size();i++)
        {
            for(int j=0;j<ce_result.get(i).size();j++)
            {
                int id=ce_result.get(i).get(j);
                if(i==0)
                {
                    if(id>=1&&id<=120)
                        c_easy_list.add(id);
                    if(id>120&&id<=630)
                        c_medium_list.add(id);
                    if(id>630&&id<=990)
                        c_hard_list.add(id);
                }
                if(i==1)
                {
                    if(id>=1&&id<=120)
                        java_easy_list.add(id);
                    if(id>120&&id<=630)
                        java_medium_list.add(id);
                    if(id>630&&id<=990)
                        java_hard_list.add(id);
                }
            }//end of internal for
        }//end of for
        easy_list.add(c_easy_list);
        easy_list.add(java_easy_list);
        ce_pattern_result.put(0,easy_list);

        medium_list.add(c_medium_list);
        medium_list.add(java_medium_list);
        ce_pattern_result.put(1,medium_list);
        hard_list.add(c_hard_list);
        hard_list.add(java_hard_list);
        ce_pattern_result.put(2,hard_list);

    }

    public static void getWaPatternResultMap()
    {
        List<List<Integer>> easy_list=new ArrayList<>();
        List<List<Integer>> medium_list=new ArrayList<>();
        List<List<Integer>> hard_list=new ArrayList<>();
        List<Integer> c_easy_list=new ArrayList<>();
        List<Integer> java_easy_list=new ArrayList<>();
        List<Integer> js_easy_list=new ArrayList<>();
        List<Integer> py_easy_list=new ArrayList<>();
        List<Integer> c_medium_list=new ArrayList<>();
        List<Integer> java_medium_list=new ArrayList<>();
        List<Integer> js_medium_list=new ArrayList<>();
        List<Integer> py_medium_list=new ArrayList<>();
        List<Integer> c_hard_list=new ArrayList<>();
        List<Integer> java_hard_list=new ArrayList<>();
        List<Integer> js_hard_list=new ArrayList<>();
        List<Integer> py_hard_list=new ArrayList<>();
        for(int i=0;i<wa_result.size();i++)
        {
            for(int j=0;j<wa_result.get(i).size();j++)
            {
                int id=wa_result.get(i).get(j);
                if(i==0)
                {
                    if(id>=1&&id<=120)
                        c_easy_list.add(id);
                    if(id>120&&id<=630)
                        c_medium_list.add(id);
                    if(id>630&&id<=990)
                        c_hard_list.add(id);
                }
                if(i==1)
                {
                    if(id>=1&&id<=120)
                        java_easy_list.add(id);
                    if(id>120&&id<=630)
                        java_medium_list.add(id);
                    if(id>630&&id<=990)
                        java_hard_list.add(id);
                }
                if(i==2)
                {
                    if(id>=1&&id<=120)
                        js_easy_list.add(id);
                    if(id>120&&id<=630)
                        js_medium_list.add(id);
                    if(id>630&&id<=990)
                        js_hard_list.add(id);
                }
                if(i==3)
                {
                    if(id>=1&&id<=120)
                        py_easy_list.add(id);
                    if(id>120&&id<=630)
                        py_medium_list.add(id);
                    if(id>630&&id<=990)
                        py_hard_list.add(id);
                }
            }//end of internal For
        }//end of For
        easy_list.add(c_easy_list);
        easy_list.add(java_easy_list);
        easy_list.add(js_easy_list);
        easy_list.add(py_easy_list);
        wa_pattern_result.put(0,easy_list);

        medium_list.add(c_medium_list);
        medium_list.add(java_medium_list);
        medium_list.add(js_medium_list);
        medium_list.add(py_medium_list);
        wa_pattern_result.put(1,medium_list);

        hard_list.add(c_hard_list);
        hard_list.add(java_hard_list);
        hard_list.add(js_hard_list);
        hard_list.add(py_hard_list);

        wa_pattern_result.put(2,hard_list);
    }

    public static void getAccPatternResultMap()
    {
        List<List<Integer>> easy_list=new ArrayList<>();
        List<List<Integer>> medium_list=new ArrayList<>();
        List<List<Integer>> hard_list=new ArrayList<>();
        List<Integer> c_easy_list=new ArrayList<>();
        List<Integer> java_easy_list=new ArrayList<>();
        List<Integer> js_easy_list=new ArrayList<>();
        List<Integer> py_easy_list=new ArrayList<>();
        List<Integer> c_medium_list=new ArrayList<>();
        List<Integer> java_medium_list=new ArrayList<>();
        List<Integer> js_medium_list=new ArrayList<>();
        List<Integer> py_medium_list=new ArrayList<>();
        List<Integer> c_hard_list=new ArrayList<>();
        List<Integer> java_hard_list=new ArrayList<>();
        List<Integer> js_hard_list=new ArrayList<>();
        List<Integer> py_hard_list=new ArrayList<>();
        for(int i=0;i<acc_result.size();i++)
        {
            for(int j=0;j<acc_result.get(i).size();j++)
            {
                int id=acc_result.get(i).get(j);
                if(i==0)
                {
                    if(id>=1&&id<=120)
                        c_easy_list.add(id);
                    if(id>120&&id<=630)
                        c_medium_list.add(id);
                    if(id>630&&id<=990)
                        c_hard_list.add(id);
                }
                if(i==1)
                {
                    if(id>=1&&id<=120)
                        java_easy_list.add(id);
                    if(id>120&&id<=630)
                        java_medium_list.add(id);
                    if(id>630&&id<=990)
                        java_hard_list.add(id);
                }
                if(i==2)
                {
                    if(id>=1&&id<=120)
                        js_easy_list.add(id);
                    if(id>120&&id<=630)
                        js_medium_list.add(id);
                    if(id>630&&id<=990)
                        js_hard_list.add(id);
                }
                if(i==3)
                {
                    if(id>=1&&id<=120)
                        py_easy_list.add(id);
                    if(id>120&&id<=630)
                        py_medium_list.add(id);
                    if(id>630&&id<=990)
                        py_hard_list.add(id);
                }
            }//end of internal For
        }//end of For
        easy_list.add(c_easy_list);
        easy_list.add(java_easy_list);
        easy_list.add(js_easy_list);
        easy_list.add(py_easy_list);
        acc_pattern_result.put(0,easy_list);

        medium_list.add(c_medium_list);
        medium_list.add(java_medium_list);
        medium_list.add(js_medium_list);
        medium_list.add(py_medium_list);
        acc_pattern_result.put(1,medium_list);

        hard_list.add(c_hard_list);
        hard_list.add(java_hard_list);
        hard_list.add(js_hard_list);
        hard_list.add(py_hard_list);

        acc_pattern_result.put(2,hard_list);

    }

    public static void getAllZeroPatternResultMap()
    {
        List<Integer> easy_zero_list=new ArrayList<>();
        List<Integer> medium_zero_list=new ArrayList<>();
        List<Integer> hard_zero_list=new ArrayList<>();
        for(int i=0;i<allZero_result.size();i++)
        {
            int id=allZero_result.get(i);
            if(id>=1&&id<=120)
            {
                easy_zero_list.add(id);
            }
            if(id>120&&id<=630)
            {
                medium_zero_list.add(id);
            }
            if(id>630&&id<=990)
            {
                hard_zero_list.add(id);
            }
            allZero_pattern_result.put(0,easy_zero_list);
            allZero_pattern_result.put(1,medium_zero_list);
            allZero_pattern_result.put(2,hard_zero_list);

        }
    }

    public static void getHasPatternResultMap()
    {
        List<Integer> easy_has_list=new ArrayList<>();
        List<Integer> medium_has_list=new ArrayList<>();
        List<Integer> hard_has_list=new ArrayList<>();
        for(int i=0;i<hasCorrect_result.size();i++)
        {
            int id=hasCorrect_result.get(i);
            if(id>=1&&id<=120)
            {
                easy_has_list.add(id);
            }
            if(id>120&&id<=630)
            {
                medium_has_list.add(id);
            }
            if(id>630&&id<=990)
            {
                hard_has_list.add(id);
            }
        }
        hasCorrect_pattern_result.put(0,easy_has_list);
        hasCorrect_pattern_result.put(1,medium_has_list);
        hasCorrect_pattern_result.put(2,hard_has_list);
    }

    public static List<Integer> getHasCorrect_result() {
        return hasCorrect_result;
    }

    public static List<Integer> getAllZero_result() {
        return allZero_result;
    }

    public static List<List<Integer>> getAcc_result() {
        return acc_result;
    }

    public static List<List<Integer>> getCe_result() {
        return ce_result;
    }

    public static List<List<Integer>> getRe_result() {
        return re_result;
    }

    public static List<List<Integer>> getWa_result() {
        return wa_result;
    }

    public static List<List<Integer>> getTle_result() {
        return tle_result;
    }

    public static List<List<Integer>> getMle_result() {
        return mle_result;
    }

    public static List<List<Integer>> getPa_result() {
        return pa_result;
    }
}
