package exeception;

import org.junit.Test;
import util.Calculator;

public class CompileError {
    @Test
    public void calculateCPercent()
    {
        int total=325;
        int[] nums={38,56,96,88,46,1};
        for(int i=0;i<nums.length;i++)
        {
            System.out.print(Calculator.calculateFinalPercent(nums[i],total)+"\t" );
        }


    }

    @Test
    public void calculateJavaPercent()
    {
        int total=241;
        int[] nums={208,12,6,8,5,2};
        for(int i=0;i<nums.length;i++)
        {
            System.out.print(Calculator.calculateFinalPercent(nums[i],total)+"\t" );
        }

        int udfTotal=208;
        int[] two={23,70};
        for(int i=0;i<two.length;i++)
        {
            System.out.print(Calculator.calculateFinalPercent(two[i],udfTotal)+"\t" );
        }

    }
}
