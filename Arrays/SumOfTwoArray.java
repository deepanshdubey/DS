import java.io.IOException;
import java.util.*;
public class SumOfTwoArray
{
    public static void main(String args[])throws IOException
    {
        Scanner scn=new Scanner(System.in);

        int n,m,i,temp,base,carry=0;

        m=scn.nextInt();
        int[] arr1= new int[m];
        for(i=0;i<m;i++)
        {
            arr1[i]=scn.nextInt();
        }

        n=scn.nextInt();
        int[] arr2= new int[n];
        for(i=0;i<n;i++)
        {
            arr2[i]=scn.nextInt();
        }
        
        int[] arr3=new int[Math.max(n, m)];
        
        if(m>n)
        {
            for(i=0;i<m;i++)
            {
                temp = arr1[m-1]+arr2[n-1] + carry;
                if(temp>10)
                {
                    base = temp%10;
                    arr3[m]=base;
                    carry = 1;
                }
                else
                {
                    base = temp;
                    arr3[m-1]=base;
                }
            }
        }
        for(i=0;i<m;i++)
        {
            System.out.print("\t"+arr3[i]+"\t");
        }
    }
}
