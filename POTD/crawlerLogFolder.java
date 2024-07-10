// import java.util.Scanner;

public class crawlerLogFolder {
    public static int minOperations(String[] logs) {
        int count = 0;
        for (String log : logs) {
            if (log.equals("../")) {
                if (count > 0)
                    count--;
            } else if (!log.equals("./"))
                count++;
        }
        return count;
    }

    public static void main(String[] args) {
        String[] logs = { "d1/", "d2/", "../", "d21/", "./" };

        int ans = minOperations(logs);
        System.out.println(ans);
    }
}