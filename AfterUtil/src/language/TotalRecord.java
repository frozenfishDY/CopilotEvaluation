package language;

import util.Calculator;
import util.FileUtil;
import util.Pair;

import java.io.*;
import java.util.*;

import static java.lang.System.exit;

public class TotalRecord {
    private static List<String> record_set;//set of all records from testcase_info.txt

    private static Set<Integer> correct_set;//set of question index which has at least one Accepted solution
    private static Set<Integer>  fail_set;//set of question index whose passed testcases are all 0
    private static CRecord cRecord;
    private static JavaRecord javaRecord;
    private static JSRecord jsRecord;
    private static PyRecord pyRecord;

    public static PyRecord getPyRecord() {
        return pyRecord;
    }

    public static JSRecord getJsRecord() {
        return jsRecord;
    }

    public static JavaRecord getJavaRecord() {
        return javaRecord;
    }

    public TotalRecord() throws IOException {
        List<String> res_list=new ArrayList<String>();
        //get file input stream
        FileInputStream fileInputStream=new FileInputStream("D:\\CopilotTest\\AfterUtil\\testcase_info.txt");
        //get reader buffer
        BufferedReader bufferedReader=new BufferedReader(new InputStreamReader(fileInputStream));
        String str=null;
        while((str=bufferedReader.readLine())!=null)
        {
            res_list.add(str);
        }
        record_set=res_list;
        correct_set=new HashSet<>();
        fail_set=new HashSet<>();
        cRecord=new CRecord();
        javaRecord=new JavaRecord();
        jsRecord=new JSRecord();
        pyRecord=new PyRecord();
    }

    public static void  processRecordSet() throws IOException {

        List<String> recordList=TotalRecord.getRecord_set();
        List<String> processedList=new ArrayList<>();
        if (recordList==null)
        {
            System.out.println("TestCaseInfo  Null  Error");
            exit(0);
        }
        for(int i=0;i<recordList.size();i++)
        {
            //First loop->Single Problem ,its index i+1
            String record=recordList.get(i);
            String[] child_record=record.split("\t");
            if(child_record.length!=5)
            {
                System.out.println("Problem"+i+1+"wrong,exit the program  ");
                exit(0);
            }
            String testcase_info=child_record[0];//number of total test cases
            String c_testInfo=child_record[1];//information of C solution
            String java_testInfo=child_record[2];//information of Java solution
            String js_testInfo=child_record[3];//information of JS solution
            String py_testInfo=child_record[4];//information of Python solution

            int testCaseNum=Integer.parseInt(testcase_info);
            int problemIndex=i+1;
            Pair<Integer,String> c_pair=processCRecord(testCaseNum,problemIndex,c_testInfo,cRecord);
            Pair<Integer,String> java_pair=processJavaRecord(testCaseNum,problemIndex,java_testInfo,javaRecord);
            Pair<Integer,String> js_pair=processJSRecord(testCaseNum,problemIndex,js_testInfo,jsRecord);
            Pair<Integer,String> py_pair=processPyRecord(testCaseNum,problemIndex,py_testInfo,pyRecord);
            //check empty record
            checkPairNullPointer(problemIndex,c_pair,java_pair,js_pair,py_pair);
            boolean hasAccepted=checkHasAccept(testCaseNum,c_testInfo,java_testInfo,js_testInfo,py_testInfo);
            boolean allZero=checkAllZero(problemIndex,c_pair,java_pair,js_pair,py_pair);

            if(hasAccepted)
            {
                correct_set.add(problemIndex);
            }
            if(allZero)
            {
                fail_set.add(problemIndex);
            }
            StringBuilder stringBuilder=new StringBuilder();
            stringBuilder.append(testcase_info+"\t");
            stringBuilder.append(c_testInfo+" "+"("+c_pair.getSecond()+")"+"\t");
            stringBuilder.append(java_testInfo+" "+"("+java_pair.getSecond()+")"+"\t");
            stringBuilder.append(js_testInfo+" "+"("+js_pair.getSecond()+")"+"\t");
            stringBuilder.append(py_testInfo+" "+"("+py_pair.getSecond()+")");
            processedList.add(stringBuilder.toString());
        }
        record_set=processedList;
    }

    public static void writeProcessedRecordtoFile(String filePath) throws IOException {
        FileUtil.writeStringtoFile(filePath,record_set);
    }
    //return <number of passed test cases，ratio of pass>
    public static Pair<Integer,String> processCRecord(int testCaseNum,int problemIndex,String c_testInfo,CRecord cRecord)
    {
        String[] c_str=c_testInfo.split(" ");
        int passTestNum=Integer.parseInt(c_str[0]);
        String percent= Calculator.calculatePercent(passTestNum,testCaseNum);

        Pair<Integer,String> c_pair;

        if(c_str.length==1&&passTestNum==testCaseNum)
        {
               cRecord.getAcc_set().add(problemIndex);
               c_pair=new Pair<>(passTestNum,percent);
               return c_pair;
        }
        if(c_str.length==2)
        {
            if(c_str[1].contains("WA"))
            {
                if(passTestNum>=1)
                {
                    cRecord.getPartially_correct_set().add(problemIndex);
                }
                cRecord.getWa_set().add(problemIndex);
                c_pair=new Pair<>(passTestNum,percent);
                return c_pair;
            }
            else if(c_str[1].contains("CE"))
            {
                if(passTestNum>=1)
                {
                    cRecord.getPartially_correct_set().add(problemIndex);
                }
                cRecord.getCe_set().add(problemIndex);
                c_pair=new Pair<>(passTestNum,percent);
                return c_pair;
            }
            else if(c_str[1].contains("RE"))
            {
                if(passTestNum>=1)
                {
                    cRecord.getPartially_correct_set().add(problemIndex);
                }
                cRecord.getRe_set().add(problemIndex);
                c_pair=new Pair<>(passTestNum,percent);
                return c_pair;
            }
            else if(c_str[1].contains("TLE"))
            {
                if(passTestNum>=1)
                {
                    cRecord.getPartially_correct_set().add(problemIndex);
                }
                cRecord.getTle_set().add(problemIndex);
                c_pair=new Pair<>(passTestNum,percent);
                return c_pair;
            }
            else if(c_str[1].contains("MLE"))
            {
                if(passTestNum>=1)
                {
                    cRecord.getPartially_correct_set().add(problemIndex);
                }
                cRecord.getMle_set().add(problemIndex);
                c_pair=new Pair<>(passTestNum,percent);
                return c_pair;
            }
            else {
                System.out.println("Question"+problemIndex+"C is Wrong");
                exit(0);
            }
        }

        return null;
    }

    public static Pair<Integer,String> processJavaRecord(int testCaseNum,int problemIndex,String java_testInfo,JavaRecord javaRecord)
    {
        String[] java_str=java_testInfo.split(" ");
        int passTestNum=Integer.parseInt(java_str[0]);
        String percent=Calculator.calculatePercent(passTestNum,testCaseNum);
        Pair<Integer,String> java_pair=null;

        if(java_str.length==1&&passTestNum==testCaseNum)
        {
            javaRecord.getAcc_set().add(problemIndex);
            java_pair=new Pair<>(passTestNum,percent);
            return java_pair;
        }
        if(java_str.length==2)
        {
            if(java_str[1].contains("WA"))
            {
                if(passTestNum>=1)
                {
                    javaRecord.getPartially_correct_set().add(problemIndex);
                }
                javaRecord.getWa_set().add(problemIndex);
                java_pair=new Pair<>(passTestNum,percent);
                return java_pair;

            }
            else if(java_str[1].contains("CE"))
            {
                if(passTestNum>=1)
                {
                    javaRecord.getPartially_correct_set().add(problemIndex);
                }
                javaRecord.getCe_set().add(problemIndex);
                java_pair=new Pair<>(passTestNum,percent);
                return java_pair;

            }
            else if(java_str[1].contains("RE"))
            {
                if(passTestNum>=1)
                {
                    javaRecord.getPartially_correct_set().add(problemIndex);
                }
                javaRecord.getRe_set().add(problemIndex);
                java_pair=new Pair<>(passTestNum,percent);
                return java_pair;

            }
            else if(java_str[1].contains("TLE"))
            {
                if(passTestNum>=1)
                {
                    javaRecord.getPartially_correct_set().add(problemIndex);
                }
                javaRecord.getTle_set().add(problemIndex);
                java_pair=new Pair<>(passTestNum,percent);
                return java_pair;

            }
            else if(java_str[1].contains("MLE"))
            {
                if(passTestNum>=1)
                {
                    javaRecord.getPartially_correct_set().add(problemIndex);
                }
                javaRecord.getMle_set().add(problemIndex);
                java_pair=new Pair<>(passTestNum,percent);
                return java_pair;
            }
            else {
                System.out.println("question"+problemIndex+"java language Error");
                exit(0);
            }
        }
       return null;
    }

    public static Pair<Integer,String> processJSRecord(int testCaseNum,int problemIndex,String js_testInfo,JSRecord jsRecord)
    {
        String[] js_str=js_testInfo.split(" ");
        int passTestNum=Integer.parseInt(js_str[0]);
        String percent=Calculator.calculatePercent(passTestNum,testCaseNum);
        Pair<Integer,String> js_pair=null;

        if(js_str.length==1&&passTestNum==testCaseNum)
        {
            jsRecord.getAcc_set().add(problemIndex);
            js_pair=new Pair<>(passTestNum,percent);
            return js_pair;
        }
        if(js_str.length==2)
        {
            if(js_str[1].contains("WA"))
            {
                if(passTestNum>=1)
                {
                    jsRecord.getPartially_correct_set().add(problemIndex);
                }
                jsRecord.getWa_set().add(problemIndex);
                js_pair=new Pair<>(passTestNum,percent);
                return js_pair;

            }
            else if(js_str[1].contains("RE"))
            {
                if(passTestNum>=1)
                {
                    jsRecord.getPartially_correct_set().add(problemIndex);
                }
                jsRecord.getRe_set().add(problemIndex);
                js_pair=new Pair<>(passTestNum,percent);
                return js_pair;

            }
            else if(js_str[1].contains("TLE"))
            {
                if(passTestNum>=1)
                {
                    jsRecord.getPartially_correct_set().add(problemIndex);
                }
                jsRecord.getTle_set().add(problemIndex);
                js_pair=new Pair<>(passTestNum,percent);
                return js_pair;

            }
            else if(js_str[1].contains("MLE"))
            {
                if(passTestNum>=1)
                {
                    jsRecord.getPartially_correct_set().add(problemIndex);
                }
                jsRecord.getMle_set().add(problemIndex);
                js_pair=new Pair<>(passTestNum,percent);
                return js_pair;
            }
            else {
                System.out.println("question"+problemIndex+"js language error");
                exit(0);
            }
        }
        return null;
    }

    public static Pair<Integer,String> processPyRecord(int testCaseNum,int problemIndex,String py_testInfo,PyRecord pyRecord)
    {
        String[] py_str=py_testInfo.split(" ");
        int passTestNum=Integer.parseInt(py_str[0]);
        String percent=Calculator.calculatePercent(passTestNum,testCaseNum);
        Pair<Integer,String> py_pair=null;

        if(py_str.length==1&&passTestNum==testCaseNum)
        {
            pyRecord.getAcc_set().add(problemIndex);
            py_pair=new Pair<>(passTestNum,percent);
            return py_pair;

        }
        if(py_str.length==2)
        {
            if(py_str[1].contains("WA"))
            {
                if(passTestNum>=1)
                {
                    pyRecord.getPartially_correct_set().add(problemIndex);
                }
                pyRecord.getWa_set().add(problemIndex);
                py_pair=new Pair<>(passTestNum,percent);
                return py_pair;
            }
            else if(py_str[1].contains("RE"))
            {
                if(passTestNum>=1)
                {
                    pyRecord.getPartially_correct_set().add(problemIndex);
                }
                pyRecord.getRe_set().add(problemIndex);
                py_pair=new Pair<>(passTestNum,percent);
                return py_pair;
            }
            else if(py_str[1].contains("TLE"))
            {
                if(passTestNum>=1)
                {
                    pyRecord.getPartially_correct_set().add(problemIndex);
                }
                pyRecord.getTle_set().add(problemIndex);
                py_pair=new Pair<>(passTestNum,percent);
                return py_pair;
            }
            else if(py_str[1].contains("MLE"))
            {
                if(passTestNum>=1)
                {
                    pyRecord.getPartially_correct_set().add(problemIndex);
                }
                pyRecord.getMle_set().add(problemIndex);
                py_pair=new Pair<>(passTestNum,percent);
                return py_pair;
            }
            else {
                System.out.println("question"+problemIndex+"py language error");
                exit(0);
            }
        }
       return null;
    }




    public static List<String> getRecord_set() {
        return record_set;
    }






    public static boolean checkHasAccept(int testcaseNum,String c_testInfo,String java_testInfo,String js_testInfo,String py_testInfo)
    {

        //Prevent the status of passing all test cases but code exceptions such as 98 98 (TLE), so check the length of the array
        String[] c_childInfo=c_testInfo.split(" ");
        String[] java_childInfo=java_testInfo.split(" ");
        String[] js_childInfo=js_testInfo.split(" ");
        String[] py_childInfo=py_testInfo.split(" ");
        int cPassNum=Integer.parseInt(c_childInfo[0]);
        int javaPassNum=Integer.parseInt(java_childInfo[0]);
        int jsPassNum=Integer.parseInt(js_childInfo[0]);
        int pyPassNum=Integer.parseInt(py_childInfo[0]);
        boolean cBool=false;
        boolean javaBool=false;
        boolean jsBool=false;
        boolean pyBool=false;
        if(c_childInfo.length==1&&cPassNum==testcaseNum)
        {
            cBool=true;
        }
        if(java_childInfo.length==1&&javaPassNum==testcaseNum)
        {
            javaBool=true;
        }
        if(js_childInfo.length==1&&jsPassNum==testcaseNum)
        {
            jsBool=true;
        }
        if(py_childInfo.length==1&&pyPassNum==testcaseNum)
        {
            pyBool=true;
        }

       return (cBool||javaBool||jsBool||pyBool);
    }

    public static boolean checkAllZero(int problemIndex,Pair<Integer, String> c_pair, Pair<Integer,String> java_pair,Pair<Integer,String> js_pair,Pair<Integer,String> py_pair)
    {
        boolean cBool=(c_pair.getFirst()==0&&c_pair.getSecond().equals("0%"));
        boolean javaBool=(java_pair.getFirst()==0&&java_pair.getSecond().equals("0%"));
        boolean jsBool=(js_pair.getFirst()==0&&js_pair.getSecond().equals("0%"));
        boolean pyBool=(py_pair.getFirst()==0&&py_pair.getSecond().equals("0%"));
        return (cBool&&javaBool&&jsBool&&pyBool);

    }

    public static void checkPairNullPointer(int problemIndex,Pair<Integer,String> c_pair,Pair<Integer,String> java_pair,Pair<Integer,String> js_pair,Pair<Integer,String> py_pair)
    {
        boolean pairBool=(c_pair==null||java_pair==null||js_pair==null||py_pair==null);
        boolean firstBool=(c_pair.getFirst()==null||java_pair.getFirst()==null||js_pair.getFirst()==null||py_pair.getFirst()==null);
        boolean secondBool=(c_pair.getSecond()==null||java_pair.getSecond()==null||js_pair.getSecond()==null||py_pair.getSecond()==null);
        if(pairBool||firstBool||secondBool)
        {
            System.out.println("NullPointer Error ,problemIndex: "+problemIndex);
            exit(0);
        }
    }

    public static Set<Integer> getCorrect_set() {
        return correct_set;
    }

    public static Set<Integer> getFail_set() {
        return fail_set;
    }

    public static CRecord getcRecord() {
        return cRecord;
    }
}
