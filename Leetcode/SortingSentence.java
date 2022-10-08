package LeetcodeString;

import java.util.Arrays;

public class SortingSentence {
    public static void main(String[] args) {
        String s = "samir3 sam2 sa1";
        String ans = sortSentence(s);
        System.out.println(ans);

    }
    static String sortSentence(String s) {
        String str[]=s.split(" ");
        String st1[]=new String[str.length];
        StringBuilder builder=new StringBuilder();
        for(String t:str)
        {
            int i=(int)t.charAt(t.length()-1)-48;
            st1[i-1]=t.substring(0, t.length()-1);
        }

        for(int i=0;i<st1.length;i++)
        {
            builder.append(st1[i]);
            builder.append(" ");
        }

        return builder.toString().trim();

    }
}
