package LeetcodeSort;

import java.util.Arrays;

public class ValidPalindrome {
    public static void main(String[] args) {
        String name = "race a car";
        System.out.println(isPalindrome(name));

    }
    /*static boolean isPalindrome(String s) {
        s.strip();


    }*/
    static boolean isPalindrome(String s ){
        s.strip();
        String name =  s.toLowerCase();

        String[] str = name.split(" ");
        String nam = "";
        for (int i = 0; i < str.length; i++) {
            nam = nam + str[i];
        }

        int start = 0;
        int end = nam.length()-1;
        while (start<=end){
            if((int)s.charAt(start)<65){
                if(!(s.charAt(start) -'0'>=0 && s.charAt(start)-'0'<=9)){
                    ++start;
                    continue;
                }
            }


            if((int)s.charAt(start)>90){
                ++start;
                continue;
            }

            if((int)s.charAt(end)<65){
                if(!(s.charAt(end) -'0'>=0 && s.charAt(end)-'0'<=9)){
                    --end;
                    continue;
                }
            }


            if((int)s.charAt(end)>90){
                --end;
                continue;
            }
            if (nam.charAt(start) == nam.charAt(end)){
                start += 1;
                end -= 1;
            }else {
                return false;
            }
        }
        return true;
    }
}
