package LeetcodeString;

public class LengthOfLastWord {
    public static void main(String[] args) {
        String name = "Samie bha u  ";
        int ans = lengthOfLastWord(name);
        System.out.println(ans);


    }
    static int  lengthOfLastWord(String s) {
        s = s.strip();
        String[] str = s.split(" ");
        int ans = str[str.length-1].length();
        return ans;
    }
}

