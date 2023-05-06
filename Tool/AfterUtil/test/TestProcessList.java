import language.TotalRecord;

import java.io.IOException;

public class TestProcessList {
    public static void main(String[] args) throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        for(String str:TotalRecord.getRecord_set())
        {
            System.out.println(str);
        }
        System.out.println(TotalRecord.getRecord_set().size());
    }
}
