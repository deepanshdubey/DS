import java.io.IOException;
import java.util.*;
class FindInArray
{
    public static void main(String args[])throws IOException
    {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int [] arr = new int[n];

        for(int i=0;i<arr.length;i++)
        {
            arr[i]=scn.nextInt();
        }
        System.out.println("Please enter the number to search");
        n=scn.nextInt();
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]==n)
            {
                System.out.println("Element found.");
                break;
            }  
        }
    }
}