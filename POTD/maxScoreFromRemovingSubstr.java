import java.util.Stack;

public class maxScoreFromRemovingSubstr {

    private static String removeSubstring(String input, String targetPair) {
        Stack<Character> chStk = new Stack<>();

        // Iterate through each char in the input string
        for (int i = 0; i < input.length(); i++) {
            char currChar = input.charAt(i);

            // check if the current character forms the target pair with the top element in
            // the stack
            if (currChar == targetPair.charAt(1) && !chStk.isEmpty() && chStk.peek() == targetPair.charAt(0))
                chStk.pop();

            else
                chStk.push(currChar);
        }

        // reconstruct the remaining string
        StringBuilder remainingChars = new StringBuilder();
        while (!chStk.isEmpty()) {
            remainingChars.append(chStk.pop());
        }

        return remainingChars.reverse().toString();
    }

    public static int maximumGain(String s, int x, int y) {
        int maxGain = 0;
        String highPriority = x > y ? "ab" : "ba";
        String lowPriority = highPriority == "ab" ? "ba" : "ab";

        // first pass remove high priority pairs
        String stringAfterFirstPass = removeSubstring(s, highPriority);
        int removedPairsCount = (s.length() - stringAfterFirstPass.length()) / 2;

        maxGain += removedPairsCount * Math.max(x, y);

        // second pass remove low priority pairs

        String stringAfterSecondPass = removeSubstring(stringAfterFirstPass, lowPriority);
        removedPairsCount = (stringAfterFirstPass.length() - stringAfterSecondPass.length()) / 2;

        maxGain += removedPairsCount * Math.min(x, y);

        return maxGain;
    }

    public static void main(String[] args) {
        String s = "cdbcbbaaabab";
        int x = 4, y = 5;

        System.out.println("Maximum score is :: "+ maximumGain(s, x, y));
    }
}
