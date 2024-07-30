import java.util.ArrayList;
import java.util.List;

public class generateParantheses {
    public static void helper(List<String> res , int n  , int ob , int cb , String s){
            //both the brackets are balancing
            if(ob == n && cb == n){
                res.add(s);
                return;
            }

            //opening brackets
            if(ob < n){
                helper(res, n , ob+1 , cb , s + "(");
            }
             //closing brackets
            if(cb < ob){
                helper(res, n , ob , cb+1 , s + ")");
            }
    }
    public static List<String> generateParenthesis(int n) {
       List<String> res = new ArrayList<>();
       int cb = 0 , ob =0;
       helper(res , n , ob, cb,"");
       return res; 
    }

    public static void main(String[] args) {
       List<String> res = new ArrayList<>();
        res = generateParenthesis(3);
        System.out.println(res);

    }
}
