import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PhonePad {
    public static void main(String[] args) {
        System.out.println(letterCombinations(""));
    }
    static List<String> phoneNumber(String UnPro, String Pro){
        if (UnPro.isEmpty()){
           List<String> list = new ArrayList<>();
           list.add(Pro);
           return list;
        }
        int digit = UnPro.charAt(0) -'0';// '-' is important
        List<String> finalAns = new ArrayList<>();
        if (digit>=2 && digit<=6){
            for (int i = (digit-2)*3; i <(digit-1)*3 ; i++) {
                char ch = (char) ('a' + i);
               finalAns.addAll(phoneNumber(UnPro.substring(1), Pro + ch));
            }
        }
        else if (digit == 7){
            for (int i = (digit-2)*3; i <=(digit-1)*3 ; i++) {
                char ch = (char)('a'+i);
                finalAns.addAll(phoneNumber(UnPro.substring(1), Pro + ch));
            }
        }else if (digit == 8){
            for (int i =1+ (digit-2)*3; i <=(digit-1)*3 ; i++) {
                char ch = (char)('a'+i);
                finalAns.addAll(phoneNumber(UnPro.substring(1), Pro + ch));
            }
        }else {
            for (int i =1+ (digit-2)*3; i <=1+(digit-1)*3 ; i++) {
                char ch = (char)('a'+i);
                finalAns.addAll(phoneNumber(UnPro.substring(1), Pro + ch));
            }
        }
        return finalAns;
    }
    static  List<String> letterCombinations(String digits) {
           String Pro = "";
           return phoneNumber(digits, String.valueOf(Pro));
    }
}
