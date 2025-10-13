import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static void solve(BufferedReader br, StringBuilder sb) throws IOException {
        String a = br.readLine();
        String b = br.readLine();
        
        int maxCommon = 0;
        for (int i = 0; i < a.length(); ++i) {
            for (int j = i + 1; j <= a.length(); ++j) {
                String sub = a.substring(i, j);
                if (b.contains(sub)) {
                    maxCommon = Math.max(maxCommon, sub.length());
                }
            }
        }

        int operations = (a.length() - maxCommon) + (b.length() - maxCommon);
        sb.append(operations).append("\n");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            solve(br, sb);
        }

        System.out.print(sb);
    }
}