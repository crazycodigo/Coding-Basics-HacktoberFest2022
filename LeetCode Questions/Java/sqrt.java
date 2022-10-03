// Leetcode Q.69. Sqrt(x) "https://leetcode.com/problems/sqrtx/"

public class sqrt {
    //main function
    public static void main(String [] args){
        int a=10;    
        mySqrt(a);
        System.out.println(mySqrt(a));
    }
    
    //Answer Function
    public static int mySqrt(int a){   
        int ans=0; 
        int i;
        int j;

        for(i=0;i<a;i++){
           j=i*i;
            if(j==a){
                return i;
            }

            if(j<a && j>=big(i)){
                ans=i;
        }
    }
        return ans;
    }
    
    //By Ashutosh Ray
    
}
