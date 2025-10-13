import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int n = Integer.parseInt(br.readLine());
        string aStr, bStr;
        for (int i = 0; i < n; ++i) {
            string line = br.readLine();
            char ch1 = line[0];
            char ch2 = line[2];
            aStr.append(ch1);
            bStr.append(ch2);
        }

        BigInteger a = new BigInteger(aStr);
        BigInteger b = new BigInteger(bStr);
        BigInteger c = a.add(b);
        
        System.out.print(c);
    }
}