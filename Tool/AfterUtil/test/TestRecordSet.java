import language.TotalRecord;

import java.io.IOException;

public class TestRecordSet {
    public static void main(String[] args) throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        for(String str:TotalRecord.getRecord_set()){
            System.out.println(str);
        }


    }
}
