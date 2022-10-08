package LeetcodeString;

public class GoalParser {
    public static void main(String[] args) {
        String command = "G()(al)";
        String ans = interpret(command);
        System.out.println(ans);

    }
    static String interpret(String command) {
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < command.length(); i++) {
            if (command.charAt(i) == 'G') str.append('G');
            else if (command.charAt(i) == '('){
                if(command.charAt(i+1) == ')'){
                    str.append('o');
                    i++;
                }else if (command.charAt(i+1) == 'a'){
                    str.append("al");
                    i+=2;
                }
            }
        }
        return new String(str);
    }
}
