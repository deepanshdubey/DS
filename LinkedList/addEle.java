import java.util.LinkedList;

public class addEle {
    public static void main(String args[])
    {
        LinkedList<Integer> list = new LinkedList<Integer>();
        list.add(1);
        list.add(5);
        list.add(7);
        list.add(3);
        list.add(8);
        list.add(2);
        list.add(3);
        System.out.println(list);
        System.out.println(list.indexOf(7));
     }
}
