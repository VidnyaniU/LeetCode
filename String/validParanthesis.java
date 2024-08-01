import java.util.Stack;

public class validParanthesis {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for (char ch : s.toCharArray()) {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else {
                if (st.isEmpty())
                    return false;
                if (ch == ')' && st.peek() != '(')
                    return false;
                if (ch == ']' && st.peek() != '[')
                    return false;
                if (ch == '}' && st.peek() != '{')
                    return false;
                st.pop();
            }
        }
        return (st.isEmpty());
    }

    public boolean isValidP(String s) {
        while (true) {
            if (s.contains("()"))
                s = s.replace("()", "");
            else if (s.contains("[]"))
                s = s.replace("[]", "");
            else if (s.contains("{}"))
                s = s.replace("{}", "");
            else {
                return s.isEmpty();
            }
        }
    }
}
