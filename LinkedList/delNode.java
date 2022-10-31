import java.io.*;
import java.util.LinkedList;
public class delNode {
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Please enter 5 numbers in range of 1-50");
        int i,n;

        LinkedList<Integer> list = new LinkedList<>();

        for(i=0;i<5;++i)
        {
            n = Integer.parseInt(br.readLine());
            list.add(n);
        }
        System.out.println(list);
        for(i=0;i<list.size();++i)
        {
            if(list.get(i) > 25)
                list.remove(i);
        }
        // list.removeIf( -> i.get() > 25);
        System.out.println(list);
    }
}
