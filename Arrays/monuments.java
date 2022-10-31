import java.io.*;
class monuments
{
    public static void main(String args[])throws IOException
    {
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        int i,j,n,m,k=0,l=0,p, size;
        System.out.println("Input Row x Column");
        m = Integer.parseInt(br.readLine());
        n = Integer.parseInt(br.readLine());
        size = n*m;

        int[][] arr = new int[m][n];
        int[] brr = new int[200];

        for(i=0;i<m;++i)
        {
            for(j=0;j<n;++j)
            {
                arr[i][j] = Integer.parseInt(br.readLine());
            }
        }

        //LOGIC
         System.out.println("--------------------------------");
         for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {   
                k = 0; p = m;
                if(i%2==0)
                    // System.out.println();
                    brr[l++] = arr[k++][i];
                if(i%2!=0)
                    brr[l++] = arr[p--][i];
                System.out.println(arr[i][j]);
            }
        }

        for(i=0;i<size+1;++i)
        {
            System.out.print("\n--------------------------------" + brr[i]);
        }
    }
}
