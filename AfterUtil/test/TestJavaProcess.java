import language.TotalRecord;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Set;

public class TestJavaProcess {
    public static void main(String[] args) throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        //java test info

        //ACC
        Set<Integer> acc_set = TotalRecord.getJavaRecord().getAcc_set();
        List<Integer> acc_list=new ArrayList<>(acc_set);
        acc_list.sort(Comparator.naturalOrder());
        for(int id:acc_list)
        {
            System.out.println(id);
        }
        System.out.println(acc_list.size());

//        //RE
//        Set<Integer> re_set=TotalRecord.getJavaRecord().getRe_set();
//        List<Integer> re_list=new ArrayList<>(re_set);
//        re_list.sort(Comparator.naturalOrder());
//        for(int id : re_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(re_list.size());

//        //WA
//        Set<Integer> wa_set=TotalRecord.getJavaRecord().getWa_set();
//        List<Integer> wa_list=new ArrayList<>(wa_set);
//        wa_list.sort(Comparator.naturalOrder());
//        for(int id:wa_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(wa_list.size());

//        //CE
//        Set<Integer> ce_set=TotalRecord.getJavaRecord().getCe_set();
//        List<Integer> ce_list=new ArrayList<>(ce_set);
//        ce_list.sort(Comparator.naturalOrder());
//        for(int id:ce_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(ce_list.size());

//        //TLE
//        Set<Integer> tle_set=TotalRecord.getJavaRecord().getTle_set();
//        List<Integer> tle_list=new ArrayList<>(tle_set);
//        tle_list.sort(Comparator.naturalOrder());
//        for(int id:tle_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(tle_list.size());

//        //MLE
//        Set<Integer> mle_set=TotalRecord.getJavaRecord().getMle_set();
//        List<Integer> mle_list=new ArrayList<>(mle_set);
//        mle_list.sort(Comparator.naturalOrder());
//        for(int id:mle_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(mle_list.size());

//        //partially correct
//        Set<Integer> pa_set=TotalRecord.getJavaRecord().getPartially_correct_set();
//        List<Integer> pa_list=new ArrayList<>(pa_set);
//        pa_list.sort(Comparator.naturalOrder());
//        for(int id:pa_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(pa_list.size());

    }
}
