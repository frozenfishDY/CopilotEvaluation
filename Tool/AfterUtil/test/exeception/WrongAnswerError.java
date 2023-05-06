package exeception;

import org.junit.Test;
import util.Calculator;

public class WrongAnswerError {
    @Test
    public void testWaPyPercent()
    {
        int[] nums={195,4,8};
        int total=397;
        for(int i=0;i<nums.length;i++)
        {
            System.out.print(Calculator.calculateFinalPercent(nums[i],total)+"\t" );
        }

        int[] nums1={0,27,167};
        int total1=194;
        for(int i=0;i<nums.length;i++)
        {
            System.out.print(Calculator.calculateFinalPercent(nums1[i],total1)+"\t" );
        }

    }


}
