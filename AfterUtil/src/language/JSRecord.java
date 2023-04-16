package language;

import java.util.HashSet;
import java.util.Set;

public class JSRecord {
    private Set<Integer> acc_set;//set of Accepted
    private Set<Integer> wa_set;//set of Wrong Answer
    private Set<Integer> re_set;//set of Runtime Error
    private Set<Integer> tle_set;//set of Time Limit Exceed
    private Set<Integer> mle_set;//set of Memory Limit Exceed
    private Set<Integer> partially_correct_set;//set of Partially Correct

    public JSRecord() {
        acc_set=new HashSet<>();
        wa_set=new HashSet<>();
        re_set=new HashSet<>();
        tle_set=new HashSet<>();
        mle_set=new HashSet<>();
        partially_correct_set=new HashSet<>();
    }

    public Set<Integer> getAcc_set() {
        return acc_set;
    }

    public Set<Integer> getWa_set() {
        return wa_set;
    }

    public Set<Integer> getRe_set() {
        return re_set;
    }

    public Set<Integer> getTle_set() {
        return tle_set;
    }

    public Set<Integer> getMle_set() {
        return mle_set;
    }

    public Set<Integer> getPartially_correct_set() {
        return partially_correct_set;
    }
}
