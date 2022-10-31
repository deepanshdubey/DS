import java.io.*;

public class Bulb {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        float j, i;
        int n, k;
        n = Integer.parseInt(br.readLine());
        int a[] = new int[n];
        for (k = 0; k < n; k++) {
            a[k] = 1;
        }
        for (i = 2; i <= n; i++) {
            for (j = 2; j <= n; j++) {
                k = (int) j - 1;
                if (j % i == 0) {
                    if (a[k] == 0) {
                        a[k] = 1;
                    } else if (a[k] != 0) {
                        a[k] = 0;
                    }
                }
            }
        }
        for (k = 0; k < n; k++) {
            if (a[k] == 1)
            System.out.println(k + 1);
        }
    }
}