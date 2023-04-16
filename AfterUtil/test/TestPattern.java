import language.TotalRecord;
import org.junit.Test;
import res.Result;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class TestPattern {
    @Test
    public  void testHasCorrect() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
        List<Integer> easy_has_list=new ArrayList<>();
        List<Integer> medium_has_list=new ArrayList<>();
        List<Integer> hard_has_list=new ArrayList<>();
        for(int i=0;i<Result.getHasCorrect_result().size();i++)
        {
            int id=Result.getHasCorrect_result().get(i);
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
        Result.getHasCorrect_pattern_result().put(0,easy_has_list);
        Result.getHasCorrect_pattern_result().put(1,medium_has_list);
        Result.getHasCorrect_pattern_result().put(2,hard_has_list);
        for(int i=0;i<3;i++)
        {
            System.out.println(Result.getHasCorrect_pattern_result().get(i).size());
        }

    }

    @Test
    public void testAllZero() throws IOException {
        TotalRecord totalRecord = new TotalRecord();
        TotalRecord.processRecordSet();
        Result result = new Result();
        Result.getAllResult();
        List<Integer> easy_zero_list = new ArrayList<>();
        List<Integer> medium_zero_list = new ArrayList<>();
        List<Integer> hard_zero_list = new ArrayList<>();
        for (int i = 0; i < Result.getAllZero_result().size(); i++) {
            int id = Result.getAllZero_result().get(i);
            if (id >= 1 && id <= 120) {
                easy_zero_list.add(id);
            }
            if (id > 120 && id <= 630) {
                medium_zero_list.add(id);
            }
            if (id > 630 && id <= 990) {
                hard_zero_list.add(id);
            }
            Result.getAllZero_pattern_result().put(0, easy_zero_list);
            Result.getAllZero_pattern_result().put(1, medium_zero_list);
            Result.getAllZero_pattern_result().put(2, hard_zero_list);

        }

        for(int i=0;i<3;i++)
        {
            System.out.println(Result.getAllZero_pattern_result().get(i).size());
        }

    }


    @Test
    public void testAccPattern() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
        Result.getAccPatternResultMap();
        HashMap<Integer, List<List<Integer>>> acc_pattern_result = Result.getAcc_pattern_result();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<acc_pattern_result.get(i).size();j++)
            {
                System.out.print(acc_pattern_result.get(i).get(j).size()+" ");
            }
            System.out.println("\n");
        }

    }

    @Test
    public void testWaPattern() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
        Result.getWaPatternResultMap();
        HashMap<Integer, List<List<Integer>>> wa_pattern_result = Result.getWa_pattern_result();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<wa_pattern_result.get(i).size();j++)
            {
                System.out.print(wa_pattern_result.get(i).get(j).size()+" ");
            }
            System.out.println("\n");
        }
    }

    @Test
    public void testCePattern() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
        Result.getCePatternResultMap();
        HashMap<Integer, List<List<Integer>>> ce_pattern_result = Result.getCe_pattern_result();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<ce_pattern_result.get(i).size();j++)
            {
                System.out.print(ce_pattern_result.get(i).get(j).size()+" ");
            }
            System.out.println("\n");
        }
    }

    @Test
    public void testRePattern() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
        Result.getRePatternResultMap();
        HashMap<Integer, List<List<Integer>>> re_pattern_result = Result.getRe_pattern_result();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<re_pattern_result.get(i).size();j++)
            {
                System.out.print(re_pattern_result.get(i).get(j).size()+" ");
            }
            System.out.println("\n");
        }
    }

    @Test
    public void testTlePattern() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
        Result.getTlePatternResultMap();
        HashMap<Integer, List<List<Integer>>> tle_pattern_result = Result.getTle_pattern_result();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<tle_pattern_result.get(i).size();j++)
            {
                System.out.print(tle_pattern_result.get(i).get(j).size()+" ");
            }
            System.out.println("\n");
        }

    }

    @Test
    public void testMlePattern() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
       Result.getMlePatternResultMap();
        HashMap<Integer, List<List<Integer>>> mle_pattern_result = Result.getMle_pattern_result();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<mle_pattern_result.get(i).size();j++)
            {
                System.out.print(mle_pattern_result.get(i).get(j).size()+" ");
            }
            System.out.println("\n");
        }
    }

    @Test
    public void testPaPattern() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
        Result.getPaPatternResultMap();
        HashMap<Integer, List<List<Integer>>> pa_pattern_result = Result.getPa_pattern_result();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<pa_pattern_result.get(i).size();j++)
            {
                System.out.print(pa_pattern_result.get(i).get(j).size()+" ");
            }
            System.out.println("\n");
        }

    }

    @Test
    public void testGetContentByPattern() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();

         Result.getPatternCorrectnessOutput();

    }
}
