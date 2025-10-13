import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        int[] b = new int[n];

        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            a[i] = parts[0].charAt(0) - '0';
            b[i] = parts[1].charAt(0) - '0';
        }

        int carry = 0;
        char[] ans = new char[n];
        for (int i = n - 1; i >= 0; i--) {
            int sum = a[i] + b[i] + carry;
            ans[i] = (char)('0' + sum % 10);
            carry = sum / 10;
        }

        System.out.println(new String(ans));
    }
}