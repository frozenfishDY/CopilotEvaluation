package util;

import java.text.DecimalFormat;

public class Calculator {
    public static String calculatePercent(int x,int y)
    {
        double xx=x*1.0;
        double yy=y*1.0;
        double rate=xx/yy;
        DecimalFormat df=new DecimalFormat("##.##%");
        String percent;

        if(Math.abs(rate)<0.000000000001)
        {
            percent="0%";
        }
        else if(x==y)
        {
            percent="100%";
        }
        else {
            percent= df.format(rate);
        }
        return percent;
    }

    public static String calculateFinalPercent(int x,int y)
    {
        double xx=x*1.0;
        double yy=y*1.0;
        double rate=xx/yy;
        DecimalFormat df=new DecimalFormat("##%");
        String percent;
        if(Math.abs(rate)<0.01)
        {
            DecimalFormat smallDf=new DecimalFormat("##.#%");
            percent=smallDf.format(rate);
        }
        else if(x==y)
        {
            percent="100%";
        }
        else {
            percent=df.format(rate);
        }
        return percent;
    }

    public static String calculateTripple(int x,int y,int total)
    {
        String str1=calculateFinalPercent(x,total);
        String str2=calculateFinalPercent(y,total);
        return str1+"\t"+str2;
    }
}
