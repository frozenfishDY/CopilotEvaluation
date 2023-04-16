package type;

import language.TotalRecord;
import org.junit.Test;
import res.Result;

import java.io.IOException;
import java.util.List;

public class TestTypeOutput {

    @Test
    public void CopilotCorrectness() throws IOException {
        TotalRecord totalRecord = new TotalRecord();
        TotalRecord.processRecordSet();
        Result result = new Result();
        Result.getAllResult();

        System.out.println(Result.getHasCorrect_result());

        List<String> correectnessOfType = TypeUtil.getCorreectnessOfType(-1);
        for(String str:correectnessOfType)
        {
            System.out.println(str);
        }
    }

    @Test
    public void testCCorrectnessType() throws IOException {
        TotalRecord totalRecord = new TotalRecord();
        TotalRecord.processRecordSet();
        Result result = new Result();
        Result.getAllResult();

        System.out.println(Result.getHasCorrect_result());

        List<String> correectnessOfType = TypeUtil.getCorreectnessOfType(0);
        for(String str:correectnessOfType)
        {
            System.out.println(str);
        }
    }

    @Test
    public void testJavaCorrectnessType() throws IOException {
        TotalRecord totalRecord = new TotalRecord();
        TotalRecord.processRecordSet();
        Result result = new Result();
        Result.getAllResult();

        System.out.println(Result.getHasCorrect_result());

        List<String> correectnessOfType = TypeUtil.getCorreectnessOfType(1);
        for(String str:correectnessOfType)
        {
            System.out.println(str);
        }
    }

    @Test
    public void testJSCorrectnessType() throws IOException {
        TotalRecord totalRecord = new TotalRecord();
        TotalRecord.processRecordSet();
        Result result = new Result();
        Result.getAllResult();

        System.out.println(Result.getHasCorrect_result());

        List<String> correectnessOfType = TypeUtil.getCorreectnessOfType(2);
        for(String str:correectnessOfType)
        {
            System.out.println(str);
        }
    }

    @Test
    public void testPythonCorrectnessType() throws IOException {
        TotalRecord totalRecord = new TotalRecord();
        TotalRecord.processRecordSet();
        Result result = new Result();
        Result.getAllResult();

        System.out.println(Result.getHasCorrect_result());

        List<String> correectnessOfType = TypeUtil.getCorreectnessOfType(3);
        for(String str:correectnessOfType)
        {
            System.out.println(str);
        }
    }


}
