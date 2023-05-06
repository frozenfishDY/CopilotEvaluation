package json;

import language.TotalRecord;
import org.json.JSONObject;
import res.Result;
import util.FileUtil;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class JsonUtil {

    public static void getAllJsonResult() throws IOException {
        getCJsonFile();
        getJavaJsonFile();
        getJSJSsonFile();
        getPyJsonFile();
        getAllQuestionTypeJsonFile();
    }

    public static void getAllQuestionTypeJsonFile() throws IOException {
        String array_path="D:\\CopilotTest\\AfterUtil\\type_info\\Array\\array_res.txt";
        String bfs_path="D:\\CopilotTest\\AfterUtil\\type_info\\BFS\\bfs_res.txt";
        String bs_path="D:\\CopilotTest\\AfterUtil\\type_info\\BinarySearch\\binary_search_res.txt";
        String bt_path="D:\\CopilotTest\\AfterUtil\\type_info\\BinaryTree\\binary_tree_res.txt";
        String dfs_path="D:\\CopilotTest\\AfterUtil\\type_info\\DFS\\dfs_res.txt";
        String dp_path="D:\\CopilotTest\\AfterUtil\\type_info\\DynamicProgramming\\dynamic_res.txt";
        String greedy_path="D:\\CopilotTest\\AfterUtil\\type_info\\Greedy\\greedy_res.txt";
        String hash_table_path="D:\\CopilotTest\\AfterUtil\\type_info\\HashTable\\hash_table_res.txt";
        String math_path="D:\\CopilotTest\\AfterUtil\\type_info\\Math\\math_res.txt";
        String matrix_path="D:\\CopilotTest\\AfterUtil\\type_info\\Matrix\\matrix_res.txt";
        String sorting_path="D:\\CopilotTest\\AfterUtil\\type_info\\Sorting\\sort_res.txt";
        String string_path="D:\\CopilotTest\\AfterUtil\\type_info\\String\\string_res.txt";
        createTypeJsonFile(array_path,"array");
        createTypeJsonFile(bfs_path,"bfs");
        createTypeJsonFile(bs_path,"binary_search");
        createTypeJsonFile(bt_path,"binary_tree");
        createTypeJsonFile(dfs_path,"dfs");
        createTypeJsonFile(dp_path,"dynamic_programming");
        createTypeJsonFile(greedy_path,"greedy");
        createTypeJsonFile(hash_table_path,"hash_table");
        createTypeJsonFile(math_path,"math");
        createTypeJsonFile(matrix_path,"matrix");
        createTypeJsonFile(sorting_path,"sorting");
        createTypeJsonFile(string_path,"string");




    }

    public static void createTypeJsonFile(String filePath,String typeName) throws IOException {
        List<String> record_list=FileUtil.getStringListFromFile(filePath);
        List<Integer> solved_easy=new ArrayList<>();
        List<Integer> solved_medium=new ArrayList<>();
        List<Integer> solved_hard=new ArrayList<>();
        List<Integer> unsolved_easy=new ArrayList<>();
        List<Integer> unsolved_medium=new ArrayList<>();
        List<Integer> unsolved_hard=new ArrayList<>();
        for(String str:record_list)
        {
            boolean hasSolved=false;

            String[] temp=str.split("\t");
            int index=Integer.parseInt(temp[0]);
            if(temp[2].equals("1"))
               hasSolved=true;
            if(temp[2].equals("0"))
                hasSolved=false;
            if(hasSolved)
            {
                if(index>=1&&index<=120)
                    solved_easy.add(index);
                if(index>120&&index<=630)
                    solved_medium.add(index);
                if(index>630&&index<=990)
                    solved_hard.add(index);
            }
            else {
                if(index>=1&&index<=120)
                    unsolved_easy.add(index);
                if(index>120&&index<=630)
                    unsolved_medium.add(index);
                if(index>630&&index<=990)
                    unsolved_hard.add(index);
            }

        }
        System.out.println("----"+typeName+"----");
        System.out.println("Solved:");
        System.out.println(solved_easy.size());
        System.out.println(solved_medium.size());
        System.out.println(solved_hard.size());
        System.out.println("UnSolved:");
        System.out.println(unsolved_easy.size());
        System.out.println(unsolved_medium.size());
        System.out.println(unsolved_hard.size());
        JSONObject jsonObject1=new JSONObject();//solved
        jsonObject1.put("Easy",getIdContentByStream(solved_easy));
        jsonObject1.put("Medium",getIdContentByStream(solved_medium));
        jsonObject1.put("Hard",getIdContentByStream(solved_hard));
        JSONObject jsonObject2=new JSONObject();//unsolved
        jsonObject2.put("Easy",getIdContentByStream(unsolved_easy));
        jsonObject2.put("Medium",getIdContentByStream(unsolved_medium));
        jsonObject2.put("Hard",getIdContentByStream(unsolved_hard));
        JSONObject jsonObject3=new JSONObject();
        jsonObject3.put("Solved",jsonObject1);
        jsonObject3.put("Unsolved",jsonObject2);
        String outputPath="D:\\CopilotTest\\AfterUtil\\final_result\\json\\type";
        String suffix="\\"+typeName+".json";
        outputPath=outputPath+suffix;
        FileUtil.writeStringtoJsonFile(outputPath,jsonObject3);

    }

    public static void getPyJsonFile() throws IOException {
        String filePath="D:\\CopilotTest\\AfterUtil\\final_result\\json\\py_id.json";
        int languageIndex=3;

        List<Integer> acc_easy_list=Result.getAcc_pattern_result().get(0).get(languageIndex);
        List<Integer> acc_medium_list=Result.getAcc_pattern_result().get(1).get(languageIndex);
        List<Integer> acc_hard_list=Result.getAcc_pattern_result().get(2).get(languageIndex);
        JSONObject acc_json=new JSONObject();
        acc_json.put("easy",getIdContentByStream(acc_easy_list));
        acc_json.put("medium",getIdContentByStream(acc_medium_list));
        acc_json.put("hard",getIdContentByStream(acc_hard_list));

        List<Integer> wa_easy_list=Result.getWa_pattern_result().get(0).get(languageIndex);
        List<Integer> wa_medium_list=Result.getWa_pattern_result().get(1).get(languageIndex);
        List<Integer> wa_hard_list=Result.getWa_pattern_result().get(2).get(languageIndex);
        JSONObject wa_json=new JSONObject();
        wa_json.put("easy",getIdContentByStream(wa_easy_list));
        wa_json.put("medium",getIdContentByStream(wa_medium_list));
        wa_json.put("hard",getIdContentByStream(wa_hard_list));

        //no ce status
//        List<Integer> ce_easy_list=Result.getCe_pattern_result().get(0).get(languageIndex);
//        List<Integer> ce_medium_list=Result.getCe_pattern_result().get(1).get(languageIndex);
//        List<Integer> ce_hard_list=Result.getCe_pattern_result().get(2).get(languageIndex);
//        JSONObject ce_json=new JSONObject();
//        ce_json.put("easy",getIdContentByStream(ce_easy_list));
//        ce_json.put("medium",getIdContentByStream(ce_medium_list));
//        ce_json.put("hard",getIdContentByStream(ce_hard_list));

        List<Integer> re_easy_list=Result.getRe_pattern_result().get(0).get(languageIndex);
        List<Integer> re_medium_list=Result.getRe_pattern_result().get(1).get(languageIndex);
        List<Integer> re_hard_list=Result.getRe_pattern_result().get(2).get(languageIndex);
        JSONObject re_json=new JSONObject();
        re_json.put("easy",getIdContentByStream(re_easy_list));
        re_json.put("medium",getIdContentByStream(re_medium_list));
        re_json.put("hard",getIdContentByStream(re_hard_list));

        List<Integer> tle_easy_list=Result.getTle_pattern_result().get(0).get(languageIndex);
        List<Integer> tle_medium_list=Result.getTle_pattern_result().get(1).get(languageIndex);
        List<Integer> tle_hard_list=Result.getTle_pattern_result().get(2).get(languageIndex);
        JSONObject tle_json=new JSONObject();
        tle_json.put("easy",getIdContentByStream(tle_easy_list));
        tle_json.put("medium",getIdContentByStream(tle_medium_list));
        tle_json.put("hard",getIdContentByStream(tle_hard_list));

        List<Integer> mle_easy_list=Result.getMle_pattern_result().get(0).get(languageIndex);
        List<Integer> mle_medium_list=Result.getMle_pattern_result().get(1).get(languageIndex);
        List<Integer> mle_hard_list=Result.getMle_pattern_result().get(2).get(languageIndex);
        JSONObject mle_json=new JSONObject();
        mle_json.put("easy",getIdContentByStream(mle_easy_list));
        mle_json.put("medium",getIdContentByStream(mle_medium_list));
        mle_json.put("hard",getIdContentByStream(mle_hard_list));

        List<Integer> pa_easy_list=Result.getPa_pattern_result().get(0).get(languageIndex);
        List<Integer> pa_medium_list=Result.getPa_pattern_result().get(1).get(languageIndex);
        List<Integer> pa_hard_list=Result.getPa_pattern_result().get(2).get(languageIndex);
        JSONObject pa_json=new JSONObject();
        pa_json.put("easy",getIdContentByStream(pa_easy_list));
        pa_json.put("medium",getIdContentByStream(pa_medium_list));
        pa_json.put("hard",getIdContentByStream(pa_hard_list));

        JSONObject py_json=new JSONObject();
        py_json.put("Accepted",acc_json);
        py_json.put("Wrong Answer",wa_json);
//        js_json.put("Compile Error",ce_json);
        py_json.put("Runtime Error",re_json);
        py_json.put("Time Limitted Exceeded",tle_json);
        py_json.put("Memory Limitted Exceeded",mle_json);
        py_json.put("Partially Correct",pa_json);
        FileUtil.writeStringtoJsonFile(filePath,py_json);
    }

    public static void getJSJSsonFile() throws IOException {
        String filePath="D:\\CopilotTest\\AfterUtil\\final_result\\json\\js_id.json";
        int languageIndex=2;

        List<Integer> acc_easy_list=Result.getAcc_pattern_result().get(0).get(languageIndex);
        List<Integer> acc_medium_list=Result.getAcc_pattern_result().get(1).get(languageIndex);
        List<Integer> acc_hard_list=Result.getAcc_pattern_result().get(2).get(languageIndex);
        JSONObject acc_json=new JSONObject();
        acc_json.put("easy",getIdContentByStream(acc_easy_list));
        acc_json.put("medium",getIdContentByStream(acc_medium_list));
        acc_json.put("hard",getIdContentByStream(acc_hard_list));

        List<Integer> wa_easy_list=Result.getWa_pattern_result().get(0).get(languageIndex);
        List<Integer> wa_medium_list=Result.getWa_pattern_result().get(1).get(languageIndex);
        List<Integer> wa_hard_list=Result.getWa_pattern_result().get(2).get(languageIndex);
        JSONObject wa_json=new JSONObject();
        wa_json.put("easy",getIdContentByStream(wa_easy_list));
        wa_json.put("medium",getIdContentByStream(wa_medium_list));
        wa_json.put("hard",getIdContentByStream(wa_hard_list));

         //no ce status
//        List<Integer> ce_easy_list=Result.getCe_pattern_result().get(0).get(languageIndex);
//        List<Integer> ce_medium_list=Result.getCe_pattern_result().get(1).get(languageIndex);
//        List<Integer> ce_hard_list=Result.getCe_pattern_result().get(2).get(languageIndex);
//        JSONObject ce_json=new JSONObject();
//        ce_json.put("easy",getIdContentByStream(ce_easy_list));
//        ce_json.put("medium",getIdContentByStream(ce_medium_list));
//        ce_json.put("hard",getIdContentByStream(ce_hard_list));

        List<Integer> re_easy_list=Result.getRe_pattern_result().get(0).get(languageIndex);
        List<Integer> re_medium_list=Result.getRe_pattern_result().get(1).get(languageIndex);
        List<Integer> re_hard_list=Result.getRe_pattern_result().get(2).get(languageIndex);
        JSONObject re_json=new JSONObject();
        re_json.put("easy",getIdContentByStream(re_easy_list));
        re_json.put("medium",getIdContentByStream(re_medium_list));
        re_json.put("hard",getIdContentByStream(re_hard_list));

        List<Integer> tle_easy_list=Result.getTle_pattern_result().get(0).get(languageIndex);
        List<Integer> tle_medium_list=Result.getTle_pattern_result().get(1).get(languageIndex);
        List<Integer> tle_hard_list=Result.getTle_pattern_result().get(2).get(languageIndex);
        JSONObject tle_json=new JSONObject();
        tle_json.put("easy",getIdContentByStream(tle_easy_list));
        tle_json.put("medium",getIdContentByStream(tle_medium_list));
        tle_json.put("hard",getIdContentByStream(tle_hard_list));

        List<Integer> mle_easy_list=Result.getMle_pattern_result().get(0).get(languageIndex);
        List<Integer> mle_medium_list=Result.getMle_pattern_result().get(1).get(languageIndex);
        List<Integer> mle_hard_list=Result.getMle_pattern_result().get(2).get(languageIndex);
        JSONObject mle_json=new JSONObject();
        mle_json.put("easy",getIdContentByStream(mle_easy_list));
        mle_json.put("medium",getIdContentByStream(mle_medium_list));
        mle_json.put("hard",getIdContentByStream(mle_hard_list));

        List<Integer> pa_easy_list=Result.getPa_pattern_result().get(0).get(languageIndex);
        List<Integer> pa_medium_list=Result.getPa_pattern_result().get(1).get(languageIndex);
        List<Integer> pa_hard_list=Result.getPa_pattern_result().get(2).get(languageIndex);
        JSONObject pa_json=new JSONObject();
        pa_json.put("easy",getIdContentByStream(pa_easy_list));
        pa_json.put("medium",getIdContentByStream(pa_medium_list));
        pa_json.put("hard",getIdContentByStream(pa_hard_list));

        JSONObject js_json=new JSONObject();
        js_json.put("Accepted",acc_json);
        js_json.put("Wrong Answer",wa_json);
//        js_json.put("Compile Error",ce_json);
        js_json.put("Runtime Error",re_json);
        js_json.put("Time Limitted Exceeded",tle_json);
        js_json.put("Memory Limitted Exceeded",mle_json);
        js_json.put("Partially Correct",pa_json);
        FileUtil.writeStringtoJsonFile(filePath,js_json);

    }

    public static void getJavaJsonFile() throws IOException {
        String filePath="D:\\CopilotTest\\AfterUtil\\final_result\\json\\java_id.json";
        int languageIndex=1;

        List<Integer> acc_easy_list=Result.getAcc_pattern_result().get(0).get(languageIndex);
        List<Integer> acc_medium_list=Result.getAcc_pattern_result().get(1).get(languageIndex);
        List<Integer> acc_hard_list=Result.getAcc_pattern_result().get(2).get(languageIndex);
        JSONObject acc_json=new JSONObject();
        acc_json.put("easy",getIdContentByStream(acc_easy_list));
        acc_json.put("medium",getIdContentByStream(acc_medium_list));
        acc_json.put("hard",getIdContentByStream(acc_hard_list));

        List<Integer> wa_easy_list=Result.getWa_pattern_result().get(0).get(languageIndex);
        List<Integer> wa_medium_list=Result.getWa_pattern_result().get(1).get(languageIndex);
        List<Integer> wa_hard_list=Result.getWa_pattern_result().get(2).get(languageIndex);
        JSONObject wa_json=new JSONObject();
        wa_json.put("easy",getIdContentByStream(wa_easy_list));
        wa_json.put("medium",getIdContentByStream(wa_medium_list));
        wa_json.put("hard",getIdContentByStream(wa_hard_list));


        List<Integer> ce_easy_list=Result.getCe_pattern_result().get(0).get(languageIndex);
        List<Integer> ce_medium_list=Result.getCe_pattern_result().get(1).get(languageIndex);
        List<Integer> ce_hard_list=Result.getCe_pattern_result().get(2).get(languageIndex);
        JSONObject ce_json=new JSONObject();
        ce_json.put("easy",getIdContentByStream(ce_easy_list));
        ce_json.put("medium",getIdContentByStream(ce_medium_list));
        ce_json.put("hard",getIdContentByStream(ce_hard_list));

        List<Integer> re_easy_list=Result.getRe_pattern_result().get(0).get(languageIndex);
        List<Integer> re_medium_list=Result.getRe_pattern_result().get(1).get(languageIndex);
        List<Integer> re_hard_list=Result.getRe_pattern_result().get(2).get(languageIndex);
        JSONObject re_json=new JSONObject();
        re_json.put("easy",getIdContentByStream(re_easy_list));
        re_json.put("medium",getIdContentByStream(re_medium_list));
        re_json.put("hard",getIdContentByStream(re_hard_list));

        List<Integer> tle_easy_list=Result.getTle_pattern_result().get(0).get(languageIndex);
        List<Integer> tle_medium_list=Result.getTle_pattern_result().get(1).get(languageIndex);
        List<Integer> tle_hard_list=Result.getTle_pattern_result().get(2).get(languageIndex);
        JSONObject tle_json=new JSONObject();
        tle_json.put("easy",getIdContentByStream(tle_easy_list));
        tle_json.put("medium",getIdContentByStream(tle_medium_list));
        tle_json.put("hard",getIdContentByStream(tle_hard_list));

        List<Integer> mle_easy_list=Result.getMle_pattern_result().get(0).get(languageIndex);
        List<Integer> mle_medium_list=Result.getMle_pattern_result().get(1).get(languageIndex);
        List<Integer> mle_hard_list=Result.getMle_pattern_result().get(2).get(languageIndex);
        JSONObject mle_json=new JSONObject();
        mle_json.put("easy",getIdContentByStream(mle_easy_list));
        mle_json.put("medium",getIdContentByStream(mle_medium_list));
        mle_json.put("hard",getIdContentByStream(mle_hard_list));

        List<Integer> pa_easy_list=Result.getPa_pattern_result().get(0).get(languageIndex);
        List<Integer> pa_medium_list=Result.getPa_pattern_result().get(1).get(languageIndex);
        List<Integer> pa_hard_list=Result.getPa_pattern_result().get(2).get(languageIndex);
        JSONObject pa_json=new JSONObject();
        pa_json.put("easy",getIdContentByStream(pa_easy_list));
        pa_json.put("medium",getIdContentByStream(pa_medium_list));
        pa_json.put("hard",getIdContentByStream(pa_hard_list));

        JSONObject java_json=new JSONObject();
        java_json.put("Accepted",acc_json);
        java_json.put("Wrong Answer",wa_json);
        java_json.put("Compile Error",ce_json);
        java_json.put("Runtime Error",re_json);
        java_json.put("Time Limitted Exceeded",tle_json);
        java_json.put("Memory Limitted Exceeded",mle_json);
        java_json.put("Partially Correct",pa_json);
        FileUtil.writeStringtoJsonFile(filePath,java_json);
    }

    public static void getCJsonFile() throws IOException {
        String filePath="D:\\CopilotTest\\AfterUtil\\final_result\\json\\c_id.json";
        int languageIndex=0;

        List<Integer> acc_easy_list=Result.getAcc_pattern_result().get(0).get(languageIndex);
        List<Integer> acc_medium_list=Result.getAcc_pattern_result().get(1).get(languageIndex);
        List<Integer> acc_hard_list=Result.getAcc_pattern_result().get(2).get(languageIndex);
        JSONObject acc_json=new JSONObject();
        acc_json.put("easy",getIdContentByStream(acc_easy_list));
        acc_json.put("medium",getIdContentByStream(acc_medium_list));
        acc_json.put("hard",getIdContentByStream(acc_hard_list));

        List<Integer> wa_easy_list=Result.getWa_pattern_result().get(0).get(languageIndex);
        List<Integer> wa_medium_list=Result.getWa_pattern_result().get(1).get(languageIndex);
        List<Integer> wa_hard_list=Result.getWa_pattern_result().get(2).get(languageIndex);
        JSONObject wa_json=new JSONObject();
        wa_json.put("easy",getIdContentByStream(wa_easy_list));
        wa_json.put("medium",getIdContentByStream(wa_medium_list));
        wa_json.put("hard",getIdContentByStream(wa_hard_list));


        List<Integer> ce_easy_list=Result.getCe_pattern_result().get(0).get(languageIndex);
        List<Integer> ce_medium_list=Result.getCe_pattern_result().get(1).get(languageIndex);
        List<Integer> ce_hard_list=Result.getCe_pattern_result().get(2).get(languageIndex);
        JSONObject ce_json=new JSONObject();
        ce_json.put("easy",getIdContentByStream(ce_easy_list));
        ce_json.put("medium",getIdContentByStream(ce_medium_list));
        ce_json.put("hard",getIdContentByStream(ce_hard_list));

        List<Integer> re_easy_list=Result.getRe_pattern_result().get(0).get(languageIndex);
        List<Integer> re_medium_list=Result.getRe_pattern_result().get(1).get(languageIndex);
        List<Integer> re_hard_list=Result.getRe_pattern_result().get(2).get(languageIndex);
        JSONObject re_json=new JSONObject();
        re_json.put("easy",getIdContentByStream(re_easy_list));
        re_json.put("medium",getIdContentByStream(re_medium_list));
        re_json.put("hard",getIdContentByStream(re_hard_list));

        List<Integer> tle_easy_list=Result.getTle_pattern_result().get(0).get(languageIndex);
        List<Integer> tle_medium_list=Result.getTle_pattern_result().get(1).get(languageIndex);
        List<Integer> tle_hard_list=Result.getTle_pattern_result().get(2).get(languageIndex);
        JSONObject tle_json=new JSONObject();
        tle_json.put("easy",getIdContentByStream(tle_easy_list));
        tle_json.put("medium",getIdContentByStream(tle_medium_list));
        tle_json.put("hard",getIdContentByStream(tle_hard_list));

        List<Integer> mle_easy_list=Result.getMle_pattern_result().get(0).get(languageIndex);
        List<Integer> mle_medium_list=Result.getMle_pattern_result().get(1).get(languageIndex);
        List<Integer> mle_hard_list=Result.getMle_pattern_result().get(2).get(languageIndex);
        JSONObject mle_json=new JSONObject();
        mle_json.put("easy",getIdContentByStream(mle_easy_list));
        mle_json.put("medium",getIdContentByStream(mle_medium_list));
        mle_json.put("hard",getIdContentByStream(mle_hard_list));

        List<Integer> pa_easy_list=Result.getPa_pattern_result().get(0).get(languageIndex);
        List<Integer> pa_medium_list=Result.getPa_pattern_result().get(1).get(languageIndex);
        List<Integer> pa_hard_list=Result.getPa_pattern_result().get(2).get(languageIndex);
        JSONObject pa_json=new JSONObject();
        pa_json.put("easy",getIdContentByStream(pa_easy_list));
        pa_json.put("medium",getIdContentByStream(pa_medium_list));
        pa_json.put("hard",getIdContentByStream(pa_hard_list));

        JSONObject c_json=new JSONObject();
        c_json.put("Accepted",acc_json);
        c_json.put("Wrong Answer",wa_json);
        c_json.put("Compile Error",ce_json);
        c_json.put("Runtime Error",re_json);
        c_json.put("Time Limitted Exceeded",tle_json);
        c_json.put("Memory Limitted Exceeded",mle_json);
        c_json.put("Partially Correct",pa_json);
        FileUtil.writeStringtoJsonFile(filePath,c_json);
    }

    public static void getTwoSituationJsonFile() throws IOException {
        JSONObject jsonObject1=new JSONObject();
        JSONObject jsonObject2=new JSONObject();
        JSONObject jsonObject3=new JSONObject();
        List<Integer> idList= Result.getHasCorrect_pattern_result().get(0);
        String content=getIdContentByStream(idList);
        jsonObject1.put("easy",content);

        idList=Result.getHasCorrect_pattern_result().get(1);
        content=getIdContentByStream(idList);
        jsonObject1.put("medium",content);

        idList=Result.getHasCorrect_pattern_result().get(2);
        content=getIdContentByStream(idList);
        jsonObject1.put("hard",content);

        jsonObject3.put("Has_Correct",jsonObject1);

        idList=Result.getAllZero_pattern_result().get(0);
        content=getIdContentByStream(idList);
        jsonObject2.put("easy",content);

        idList=Result.getAllZero_pattern_result().get(1);
        content=getIdContentByStream(idList);
        jsonObject2.put("medium",content);

        idList=Result.getAllZero_pattern_result().get(2);
        content=getIdContentByStream(idList);
        System.out.println(content);
        jsonObject2.put("hard",content);

        jsonObject3.put("All_Zero",jsonObject2);

        FileUtil.writeStringtoJsonFile("D:\\CopilotTest\\AfterUtil\\final_result\\json\\twoSituation.json",jsonObject3);

    }

    public static String getIdContentByStream(List<Integer> idList)
    {
        String idContent=idList.stream().map(String::valueOf).collect( Collectors.joining(","));
        return idContent;
    }

}
