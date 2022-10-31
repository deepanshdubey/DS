import java.io.*;
public class Nbulb {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m, i, j, counter = 0;
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        for (i = 1; i <= n; i++)
        {
            counter = 0;
            for (j = 1; j <= m; j++)
            {
                if ((i % j) == 0)
                {
                    counter++;
                }
            }
            if (counter % 2 != 0)
             {
                System.out.print("\t" + i);
            }
        }
    }
}
