import language.TotalRecord;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Set;

public class TestCProcess {
    public static void main(String[] args) throws IOException {
        TotalRecord totalRecord=new TotalRecord();
        TotalRecord.processRecordSet();
        Set<Integer> correct_set = TotalRecord.getCorrect_set();
        List<Integer> id_list=new ArrayList<>(correct_set);
        id_list.sort(Comparator.naturalOrder());
//        for(int id :id_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(id_list.size());



//        Set<Integer> c_wa_set=TotalRecord.getcRecord().getWa_set();
//        List<Integer> c_wa_List=new ArrayList<>(c_wa_set);
//        c_wa_List.sort(Comparator.naturalOrder());
//        for(int id:c_wa_List)
//        {
//            System.out.println(id);
//        }
//        System.out.println(c_wa_List.size());


//        Set<Integer> c_pa_set=TotalRecord.getcRecord().getPartially_correct_set();
//        List<Integer> c_pa_list=new ArrayList<>(c_pa_set);
//        c_pa_list.sort(Comparator.naturalOrder());
//        for(int id : c_pa_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(c_pa_list.size());


        Set<Integer> c_acc_set=TotalRecord.getcRecord().getAcc_set();
        List<Integer> c_acc_list=new ArrayList<>(c_acc_set);
        c_acc_list.sort(Comparator.naturalOrder());
        for(int id: c_acc_list)
        {
            System.out.println(id);
        }
        System.out.println(c_acc_list.size());


//        Set<Integer> c_ce_set=TotalRecord.getcRecord().getCe_set();
//        List<Integer> c_ce_list=new ArrayList<>(c_ce_set);
//        c_ce_list.sort(Comparator.naturalOrder());
//        for(int id:c_ce_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(c_ce_list.size());

//        Set<Integer> c_tle_set=TotalRecord.getcRecord().getTle_set();
//        List<Integer> c_tle_list=new ArrayList<>(c_tle_set);
//        c_tle_list.sort(Comparator.naturalOrder());
//        for(int id:c_tle_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(c_tle_list.size());

//        Set<Integer> c_re_set=TotalRecord.getcRecord().getRe_set();
//        List<Integer> c_re_list=new ArrayList<>(c_re_set);
//        c_re_list.sort(Comparator.naturalOrder());
//        for(int id:c_re_list)
//        {
//            System.out.println(id);
//        }
//        System.out.println(c_re_list.size());

    }
}
