import language.TotalRecord;
import org.junit.Test;
import res.Result;

import java.io.IOException;

public class TestResult {
    @Test
   public void testAccResult() throws IOException {
       TotalRecord totalRecord=new TotalRecord();
       TotalRecord.processRecordSet();
       Result result=new Result();
       Result.getAllResult();
       int c_acc=TotalRecord.getcRecord().getAcc_set().size();
       int java_acc=TotalRecord.getJavaRecord().getAcc_set().size();
       int js_acc=TotalRecord.getJsRecord().getAcc_set().size();
       int py_acc=TotalRecord.getPyRecord().getAcc_set().size();

       System.out.print(c_acc+" ");
       System.out.print(java_acc+" ");
       System.out.print(js_acc+" ");
       System.out.print(py_acc+" ");
       System.out.println("\n");
       for(int i=0;i<Result.getAcc_result().size();i++)
       {
           System.out.print(Result.getAcc_result().get(i).size()+" ");
       }
   }

   @Test
    public void testWaResult() throws IOException {
       TotalRecord totalRecord=new TotalRecord();
       TotalRecord.processRecordSet();
       Result result=new Result();
       Result.getAllResult();
       int c=TotalRecord.getcRecord().getWa_set().size();
       int java=TotalRecord.getJavaRecord().getWa_set().size();
       int js=TotalRecord.getJsRecord().getWa_set().size();
       int py=TotalRecord.getPyRecord().getWa_set().size();

       System.out.print(c+" ");
       System.out.print(java+" ");
       System.out.print(js+" ");
       System.out.print(py+" ");
       System.out.println("\n");
       for(int i=0;i<Result.getWa_result().size();i++)
       {
           System.out.print(Result.getWa_result().get(i).size()+" ");
       }
   }

   @Test
   public void testCEResult() throws IOException {
       TotalRecord totalRecord=new TotalRecord();
       TotalRecord.processRecordSet();
       Result result=new Result();
       Result.getAllResult();
       int c=TotalRecord.getcRecord().getCe_set().size();
       int java=TotalRecord.getJavaRecord().getCe_set().size();

       System.out.print(c+" ");
       System.out.print(java+" ");
       System.out.println("\n");
       for(int i=0;i<Result.getCe_result().size();i++)
       {
           System.out.print(Result.getCe_result().get(i).size()+" ");
       }

   }

   @Test
    public void testReResult() throws IOException {
       TotalRecord totalRecord=new TotalRecord();
       TotalRecord.processRecordSet();
       Result result=new Result();
       Result.getAllResult();
       int c=TotalRecord.getcRecord().getRe_set().size();
       int java=TotalRecord.getJavaRecord().getRe_set().size();
       int js=TotalRecord.getJsRecord().getRe_set().size();
       int py=TotalRecord.getPyRecord().getRe_set().size();

       System.out.print(c+" ");
       System.out.print(java+" ");
       System.out.print(js+" ");
       System.out.print(py+" ");
       System.out.println("\n");
       for(int i=0;i<Result.getRe_result().size();i++)
       {
           System.out.print(Result.getRe_result().get(i).size()+" ");
       }

   }

   @Test
   public void testTLEResult() throws IOException {
       TotalRecord totalRecord=new TotalRecord();
       TotalRecord.processRecordSet();
       Result result=new Result();
       Result.getAllResult();
       int c=TotalRecord.getcRecord().getTle_set().size();
       int java=TotalRecord.getJavaRecord().getTle_set().size();
       int js=TotalRecord.getJsRecord().getTle_set().size();
       int py=TotalRecord.getPyRecord().getTle_set().size();

       System.out.print(c+" ");
       System.out.print(java+" ");
       System.out.print(js+" ");
       System.out.print(py+" ");
       System.out.println("\n");
       for(int i=0;i<Result.getTle_result().size();i++)
       {
           System.out.print(Result.getTle_result().get(i).size()+" ");
       }
   }

   @Test
    public void testMLEResult() throws IOException {
       TotalRecord totalRecord=new TotalRecord();
       TotalRecord.processRecordSet();
       Result result=new Result();
       Result.getAllResult();
       int c=TotalRecord.getcRecord().getMle_set().size();
       int java=TotalRecord.getJavaRecord().getMle_set().size();
       int js=TotalRecord.getJsRecord().getMle_set().size();
       int py=TotalRecord.getPyRecord().getMle_set().size();

       System.out.print(c+" ");
       System.out.print(java+" ");
       System.out.print(js+" ");
       System.out.print(py+" ");
       System.out.println("\n");
       for(int i=0;i<Result.getMle_result().size();i++)
       {
           System.out.print(Result.getMle_result().get(i).size()+" ");
       }
   }

   @Test
   public void testPAResult() throws IOException {

       TotalRecord totalRecord=new TotalRecord();
       TotalRecord.processRecordSet();
       Result result=new Result();
       Result.getAllResult();
       int c=TotalRecord.getcRecord().getPartially_correct_set().size();
       int java=TotalRecord.getJavaRecord().getPartially_correct_set().size();
       int js=TotalRecord.getJsRecord().getPartially_correct_set().size();
       int py=TotalRecord.getPyRecord().getPartially_correct_set().size();

       System.out.print(c+" ");
       System.out.print(java+" ");
       System.out.print(js+" ");
       System.out.print(py+" ");
       System.out.println("\n");
       for(int i=0;i<Result.getPa_result().size();i++)
       {
           System.out.print(Result.getPa_result().get(i).size()+" ");
       }
   }

   @Test
    public void testAllZeroAndCorrectResult() throws IOException {
       TotalRecord totalRecord=new TotalRecord();
       TotalRecord.processRecordSet();
       Result result=new Result();
       Result.getAllResult();
       int total_correct=TotalRecord.getCorrect_set().size();
       int total_allZero=TotalRecord.getFail_set().size();

       System.out.print(total_correct+" ");
       System.out.print(total_allZero+" ");
       System.out.println("\n");
       System.out.print(Result.getHasCorrect_result().size()+" ");
       System.out.print(Result.getAllZero_result().size()+" ");
   }
}
