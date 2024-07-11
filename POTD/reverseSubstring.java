import java.util.Stack;
// Reverse Substrings Between Each Pair of Parentheses
public class reverseSubstring {
    public String reverseParentheses(String s) {
        Stack<Character> stk = new Stack<>();

        for (char ch : s.toCharArray()) {
            if (ch == ')') {
                StringBuilder temp = new StringBuilder();

                while (!stk.isEmpty() && stk.peek() != '(') {
                    temp.append(stk.pop());
                }
                stk.pop();

                for (char rev_ch : temp.toString().toCharArray())
                    stk.push(rev_ch);
            } else {
                stk.push(ch);
            }
        }

        StringBuilder res = new StringBuilder();
        while (!stk.isEmpty()) {
            res.insert(0, stk.pop());
        }

        return res.toString();

    }

    public static void main(String[] args) {
        System.out.println();
    }
}
