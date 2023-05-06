import language.TotalRecord;
import util.FileUtil;

import java.io.IOException;

public class TestWriteRecord {
    public static void main(String[] args) throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
//        for (String str:TotalRecord.getRecord_set())
//        {
//            System.out.println(str);
//        }
//        System.out.println(TotalRecord.getRecord_set().size());

        FileUtil.writeStringtoFile("D:\\CopilotTest\\AfterUtil\\testcase_info(complete).txt",TotalRecord.getRecord_set());

    }
}
