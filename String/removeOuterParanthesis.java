public class removeOuterParanthesis {
    public String removeOuterParentheses(String s) {
        int count =0 ;
        StringBuilder str = new StringBuilder();
        if (s=="")return s; 
        int n  = s.length();
        for( int i = 0 ; i < n ; i++){

            if(s.charAt(i)=='('){
                if(count  > 0 )str.append("(");

            count++;
            }

            else if (s.charAt(i) == ')') {
            count--;
                if(count > 0)str.append(")");
            }
        }

        return str.toString();
    }
}
