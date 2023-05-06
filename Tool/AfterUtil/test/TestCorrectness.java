import language.TotalRecord;
import org.junit.Test;
import res.Result;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TestCorrectness {

    @Test
    public void testGetCorrectness() throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Result result=new Result();
        Result.getAllResult();
        Result.getCorrectnessOutPut();
    }

    @Test
    public  void testPatternCorrectness() throws IOException {
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



}
