package util;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import org.json.JSONObject;

import javax.lang.model.type.ArrayType;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileUtil {
    public static void writeStringtoFile(String filePath, List<String> content) throws IOException {

        FileOutputStream fileOutputStream=new FileOutputStream(filePath);

        BufferedWriter bufferedWriter=new BufferedWriter(new OutputStreamWriter(fileOutputStream));

        for(int i=0;i<content.size();i++)
        {
               bufferedWriter.write(content.get(i)+"\n");
               bufferedWriter.flush();
        }

        fileOutputStream.close();
        bufferedWriter.close();

    }

    public static void writeStringtoFile(String filePath,String content) throws IOException {
        //创建文件输出流
        FileOutputStream fileOutputStream=new FileOutputStream(filePath);
        //创建writer缓冲池
        BufferedWriter bufferedWriter=new BufferedWriter(new OutputStreamWriter(fileOutputStream));

        bufferedWriter.write(content);
        bufferedWriter.flush();

        fileOutputStream.close();
        bufferedWriter.close();

    }

    public static void writeStringtoJsonFile(String filePath, JSONObject jsonObject) throws IOException {

        FileOutputStream fileOutputStream=new FileOutputStream(filePath);

        BufferedWriter bufferedWriter=new BufferedWriter(new OutputStreamWriter(fileOutputStream));

        Gson  gson = new GsonBuilder().setPrettyPrinting().create();
        String content=gson.toJson(jsonObject);
        bufferedWriter.write(content);
        bufferedWriter.flush();

        fileOutputStream.close();
        bufferedWriter.close();
    }


    public static List<String> getStringListFromFile(String filePath) throws IOException {
        List<String> content=new ArrayList<>();


        FileInputStream fileInputStream=new FileInputStream(filePath);

        BufferedReader bufferedReader=new BufferedReader(new InputStreamReader(fileInputStream));
        String str=null;
        while((str=bufferedReader.readLine())!=null)
        {
            content.add(str);
        }
        fileInputStream.close();;
        bufferedReader.close();
        return content;
    }
}
