//import com.alibaba.fastjson.JSONObject;
import json.JsonUtil;
import language.TotalRecord;
import org.json.JSONObject;
import org.junit.Test;
import res.Result;


import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;


public class TestJson {

    @Test
    public void testSituationJson() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();

        JsonUtil.getTwoSituationJsonFile();
    }

    @Test
    public void testCJsonFile() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();

        JsonUtil.getCJsonFile();
    }

    @Test
    public void testJavaJsonFile() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();

        JsonUtil.getJavaJsonFile();

    }

    @Test
    public void testJSJsonFile() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();

        JsonUtil.getJSJSsonFile();

    }

    @Test
    public void testPyJsonFile() throws IOException {

        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();

        JsonUtil.getPyJsonFile();

    }
}
