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
    }
}