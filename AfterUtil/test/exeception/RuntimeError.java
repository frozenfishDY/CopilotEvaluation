package exeception;

import org.junit.Test;
import util.Calculator;

public class RuntimeError {
    @Test
    public void testJSRePercent()
    {
        int[] nums={155,6,8,49,2,6};
        int total=226;
        for(int i=0;i<nums.length;i++)
        {
            System.out.print(Calculator.calculateFinalPercent(nums[i],total)+"\t" );
        }
    }

    @Test
    public void testPyRePercent()
    {
        int[] nums={158,2,1,6,2,13,41,1};
        int total=224;
        for(int i=0;i<nums.length;i++)
        {
            System.out.print(Calculator.calculateFinalPercent(nums[i],total)+"\t" );
        }

        int[] nums1={28,3};
        for(int i=0;i<nums1.length;i++)
        {
            System.out.print(Calculator.calculateFinalPercent(nums1[i],total)+"\t" );
        }

    }
}
