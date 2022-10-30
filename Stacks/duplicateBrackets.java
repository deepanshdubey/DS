import java.io.*;
import java.util.*;

class duplicateBrackets
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack <Integer> st = new Stack<>();

        size = st.length();

        for(i=0;i<size;++i)
        {
            if(st(i)=='(')
                st.push('(');
            if(st(i)==')')
                st.pop(')');
        }

    }
}