import language.TotalRecord;
import org.junit.Test;
import org.xml.sax.helpers.AttributeListImpl;
import util.Pair;

import java.io.IOException;
import java.util.*;

public class TestPyRecord {

    public static void main(String[] args) throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        totalRecord.processRecordSet();
//        //ACC
//        Set<Integer> acc_set=TotalRecord.getPyRecord().getAcc_set();
//        List<Integer> acc_list=new ArrayList<>(acc_set);
//        acc_list.sort(Comparator.naturalOrder());
//        for(int id: acc_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(acc_list.size());

//        //RE
//        Set<Integer> re_set=TotalRecord.getPyRecord().getRe_set();
//        List<Integer> re_list=new ArrayList<>(re_set);
//        re_list.sort(Comparator.naturalOrder());
//        for(int id:re_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(re_list.size());

//        //WA
//        Set<Integer> wa_set=TotalRecord.getPyRecord().getWa_set();
//        List<Integer> wa_list=new ArrayList<>(wa_set);
//        wa_list.sort(Comparator.naturalOrder());
//        for(int id:wa_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(wa_list.size());

//        //TLE
//        Set<Integer> tle_set=TotalRecord.getPyRecord().getTle_set();
//        List<Integer> tle_list=new ArrayList<>(tle_set);
//        tle_list.sort(Comparator.naturalOrder());
//        for(int id:tle_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(tle_list.size());

//        //MLE
//        Set<Integer> mle_set=TotalRecord.getPyRecord().getMle_set();
//        List<Integer> mle_list=new ArrayList<>(mle_set);
//        mle_list.sort(Comparator.naturalOrder());
//        for(int id:mle_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(mle_list.size());

//        //Partially Correct
//        Set<Integer> pa_set=TotalRecord.getPyRecord().getPartially_correct_set();
//        List<Integer> pa_list=new ArrayList<>(pa_set);
//        pa_list.sort(Comparator.naturalOrder());
//        for(int id:pa_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(pa_list.size());

    }
}
