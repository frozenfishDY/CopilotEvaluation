package type;


import res.Result;
import util.Calculator;
import util.FileUtil;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TypeUtil {
    private static final String array_path="D:\\CopilotTest\\AfterUtil\\type_info\\Array\\array_res.txt";
    private static final String bfs_path="D:\\CopilotTest\\AfterUtil\\type_info\\BFS\\bfs_res.txt";
    private static final String bs_path="D:\\CopilotTest\\AfterUtil\\type_info\\BinarySearch\\binary_search_res.txt";
    private static final String bt_path="D:\\CopilotTest\\AfterUtil\\type_info\\BinaryTree\\binary_tree_res.txt";
    private static final String dfs_path="D:\\CopilotTest\\AfterUtil\\type_info\\DFS\\dfs_res.txt";
    private static final String dp_path="D:\\CopilotTest\\AfterUtil\\type_info\\DynamicProgramming\\dynamic_res.txt";
    private static final String greedy_path="D:\\CopilotTest\\AfterUtil\\type_info\\Greedy\\greedy_res.txt";
    private static final String hash_path="D:\\CopilotTest\\AfterUtil\\type_info\\HashTable\\hash_table_res.txt";
    private static final String math_path="D:\\CopilotTest\\AfterUtil\\type_info\\Math\\math_res.txt";
    private static final String matrix_path="D:\\CopilotTest\\AfterUtil\\type_info\\Matrix\\matrix_res.txt";
    private static final String sorting_path="D:\\CopilotTest\\AfterUtil\\type_info\\Sorting\\sort_res.txt";
    private static final String string_path="D:\\CopilotTest\\AfterUtil\\type_info\\String\\string_res.txt";

    private static final String output_path="D:\\CopilotTest\\AfterUtil\\final_result\\correctness(type)";







    public static void getAllQuestionInfoByTag() throws IOException {
        getSortedArrayQuestion(); //array
        getSortedStringQuestion();//string
        getSortedMathQuestion();//math
        getSortedHashTableQuestion();//HashTable
        getSortedDynamicQuestion();//DP
        getSortedBinaryTreeQuestion();//Binary Tree
        getSortedBinarySearchQuestion();//Binary Search
        getSortedGreedyQuestion();//Greedy
        getSortedMatrixQuestion();//Matrix
        getSortedBFSQuestion();//BFS
        getSortedDFSQuestion();//DFS
        getSortedSortingQuestion();//Sorting

    }
    /*
       -1：accepted
       0 1 2 3  C Java JavaScript Python
    * */

    public static void getTypeCorrectnessOutput() throws IOException {
        List<String> copilot_res=getCorreectnessOfType(-1);
        List<String> c_res=getCorreectnessOfType(0);
        List<String> java_res=getCorreectnessOfType(1);
        List<String> js_res=getCorreectnessOfType(2);
        List<String> py_res=getCorreectnessOfType(3);
        StringBuilder stringBuilder=new StringBuilder();
        stringBuilder.append("Column Indication:Array,String,HashTable,Dynamic Programming,Math,Sorting,Greedy,DFS,Binary Search,BFS,Martrix,Binary Tree,*Average\n");
        stringBuilder.append("Row Indication[numbers(Ratio)]:Copilot,C,Java,JavaScript,Python\n\n");
        for(int i=0;i<copilot_res.size();i++)
        {

                stringBuilder.append(copilot_res.get(i) + "\t");
                stringBuilder.append(c_res.get(i) + "\t");
                stringBuilder.append(java_res.get(i) + "\t");
                stringBuilder.append(js_res.get(i)+"\t");
                stringBuilder.append(py_res.get(i)+"\n");
        }
        FileUtil.writeStringtoFile(output_path,stringBuilder.toString());

    }


    public static List<String> getCorreectnessOfType(int languageIndex) throws IOException {
        List<String> typeList=new ArrayList<>();//restore res file
        List<Integer> checkList=new ArrayList<>();
        List<String> resList=new ArrayList<>();
        int arrayCount=0;
        int bfsCount=0;
        int bsCount=0;
        int btCount=0;
        int dfsCount=0;
        int dpCount=0;
        int greedyCount=0;
        int hashTableCount=0;
        int mathCount=0;
        int matrixCount=0;
        int sortingCount=0;
        int stringCount=0;
        if(languageIndex==-1)
        {
            checkList= Result.getHasCorrect_result();
        }
        else
        {
            checkList=Result.getAcc_result().get(languageIndex);
        }
        typeList=FileUtil.getStringListFromFile(array_path);
        System.out.println(typeList);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                arrayCount++;
        }

        resList.add(arrayCount+" "+"("+ Calculator.calculateFinalPercent(arrayCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(string_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
               stringCount++;
        }
        resList.add(stringCount+" "+"("+ Calculator.calculateFinalPercent(stringCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(hash_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                hashTableCount++;
        }
        resList.add(hashTableCount+" "+"("+ Calculator.calculateFinalPercent(hashTableCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(dp_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                dpCount++;
        }
        resList.add(dpCount+" "+"("+ Calculator.calculateFinalPercent(dpCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(math_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                mathCount++;
        }
        resList.add(mathCount+" "+"("+ Calculator.calculateFinalPercent(mathCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(sorting_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                sortingCount++;
        }
        resList.add(sortingCount+" "+"("+ Calculator.calculateFinalPercent(sortingCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(greedy_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                greedyCount++;
        }
        resList.add(greedyCount+" "+"("+ Calculator.calculateFinalPercent(greedyCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(dfs_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                dfsCount++;
        }
        resList.add(dfsCount+" "+"("+ Calculator.calculateFinalPercent(dfsCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(bs_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
               bsCount++;
        }
        resList.add(bsCount+" "+"("+ Calculator.calculateFinalPercent(bsCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(bfs_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
               bfsCount++;
        }
        resList.add(bfsCount+" "+"("+ Calculator.calculateFinalPercent(bfsCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(matrix_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                matrixCount++;
        }
        resList.add(matrixCount+" "+"("+ Calculator.calculateFinalPercent(matrixCount,typeList.size())+")");

        typeList=FileUtil.getStringListFromFile(bt_path);
        for(int i=0;i<typeList.size();i++)
        {
            String[] record=typeList.get(i).split("\t");
            if(checkList.contains(Integer.parseInt(record[0])))
                btCount++;
        }
        resList.add(btCount+" "+"("+ Calculator.calculateFinalPercent(btCount,typeList.size())+")");

        int sum=0;
        for(int i=0;i<resList.size();i++)
        {
            String[] temp=resList.get(i).split(" ");
            String percent_str=temp[1];
            percent_str=percent_str.substring(1,3);
            sum=sum+Integer.parseInt(percent_str);
        }
        sum=sum/12;
        resList.add(sum+"%");

        return resList;
    }





    public static void getSortedMathQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Math\\math.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Math\\math_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links_array = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links_array.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links_array.size(); i++) {
            String[] temp = links_array.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);


    }


    public static void getSortedArrayQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Array\\array.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Array\\array_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links_array = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links_array.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links_array.size(); i++) {
            String[] temp = links_array.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }


    public static void getSortedStringQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\String\\string.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\String\\string_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }


    public static void getSortedHashTableQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\HashTable\\hash_table.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\HashTable\\hash_table_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }


    public static void getSortedBinaryTreeQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\BinaryTree\\binary_tree.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\BinaryTree\\binary_tree_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }


    public static void getSortedDynamicQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\DynamicProgramming\\dynamic.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\DynamicProgramming\\dynamic_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }


    public static void getSortedSortingQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Sorting\\sort.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Sorting\\sort_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }


    public static void getSortedMatrixQuestion() throws IOException {

        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Matrix\\matrix.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Matrix\\matrix_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }


    public static void getSortedBinarySearchQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\BinarySearch\\binary_search.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\BinarySearch\\binary_search_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }



    public static void getSortedGreedyQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Greedy\\greedy.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\Greedy\\greedy_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }


    public static void getSortedDFSQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\DFS\\dfs.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\DFS\\dfs_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }


    public static void getSortedBFSQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\AfterUtil\\type_info\\BFS\\bfs.txt";
        String resPath = "D:\\CopilotTest\\AfterUtil\\type_info\\BFS\\bfs_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

//        System.out.println("All Question num:" + links_all.size());
//        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }
//
//        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
//        System.out.println(map.size());
//        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }

}
