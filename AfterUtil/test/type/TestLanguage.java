package type;

import language.TotalRecord;
import org.junit.Test;
import res.Result;
import util.Calculator;
import util.FileUtil;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static java.lang.System.exit;
import static java.lang.System.in;

public class TestLanguage {
    private final int array_solved = 332;
    private final int string_solved = 145;
    private final int hash_solved = 99;
    private final int dp_solved = 145;
    private final int math_solved = 112;
    private final int sorting_solved = 84;
    private final int greedy_solved = 70;
    private final int dfs_solved = 75;
    private final int bs_solved = 51;
    private final int bfs_solved = 57;
    private final int matrix_solved = 42;
    private final int bt_solved = 65;

    @Test
    public void testTypeLanguage() throws IOException {
        TotalRecord totalRecord = new TotalRecord();
        TotalRecord.processRecordSet();
        Result result = new Result();
        Result.getAllResult();

        List<String> res_list = FileUtil.getStringListFromFile("D:\\CopilotTest\\AfterUtil\\type_info\\BinaryTree\\binary_tree_res.txt");
        List<String> acc_list = new ArrayList<>();
        for (String srt : res_list) {
            String[] temp = srt.split("\t");
            if (temp[2].equals("1"))
                acc_list.add(srt);
        }
        System.out.println(acc_list.size());
        if (acc_list.size() != bt_solved) {
            System.out.println("Error");
            exit(0);
        }

        List<Integer> c_acc_list = Result.getAcc_result().get(0);
        List<Integer> java_acc_list = Result.getAcc_result().get(1);
        List<Integer> js_acc_list = Result.getAcc_result().get(2);
        List<Integer> py_acc_list = Result.getAcc_result().get(3);
        int c_count = 0;
        int java_count = 0;
        int js_count = 0;
        int py_count = 0;
        for (String str : acc_list) {
            String[] temp = str.split("\t");
            int index = Integer.parseInt(temp[0]);
            if (c_acc_list.contains(index))
                c_count++;
            if (java_acc_list.contains(index))
                java_count++;
            if (js_acc_list.contains(index))
                js_count++;
            if (py_acc_list.contains(index))
                py_count++;
        }
        String c_percent = Calculator.calculateFinalPercent(c_count, bt_solved);
        String java_percent = Calculator.calculateFinalPercent(java_count, bt_solved);
        String js_percent = Calculator.calculateFinalPercent(js_count, bt_solved);
        String py_percent = Calculator.calculateFinalPercent(py_count, bt_solved);
        System.out.println(c_count + " " + "(" + c_percent + ")" + "\t" + java_count + " " + "(" + java_percent + ")" + "\t" + js_count + " " + "(" + js_percent + ")" + "\t" + py_count + " " + "(" + py_percent + ")");
    }

    @Test
    public void testPercent()
    {
        int[] nums1={36,39,30,39,46,15,33,40,45,28,33,49};
        int[] nums2={77,81,76,83,79,82,77,57,86,72,81,51};
        int[] nums3={70,70,77,66,66,67,69,83,71,72,74,88};
        int[] nums4={53,46,53,41,58,46,46,45,47,49,60,54};
        int sum=0;
        for(int i=0;i<nums1.length;i++)
        {
            sum=sum+nums1[i];
        }
        double x=sum*1.0;
        double y=nums1.length*1.0;
        System.out.println(x/y);

        sum=0;
        for(int i=0;i<nums2.length;i++)
        {
            sum=sum+nums2[i];
        }
        x =sum*1.0;
        y=nums2.length*1.0;
        System.out.println(x/y);

        sum=0;
        for(int i=0;i<nums3.length;i++)
        {
            sum=sum+nums3[i];
        }
        x =sum*1.0;
        y=nums3.length*1.0;
        System.out.println(x/y);

        sum=0;
        for(int i=0;i<nums4.length;i++)
        {
            sum=sum+nums4[i];
        }
        x =sum*1.0;
        y=nums4.length*1.0;
        System.out.println(x/y);


    }

}


