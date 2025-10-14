import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int n = Integer.parseInt(br.readLine());
        HashMap<String, Integer> count = new HashMap<>();
        Set<String> printed = new HashSet<>();

        for (int i = 0; i < n; ++i) {
            String name = br.readLine();
            count.put(name, count.getOrDefault(name, 0) + 1);
            if (count.get(name) > 1 && !printed.contains(name)) {
                sb.append(name).append("\n");
                printed.add(name);
            }      
        }

        System.out.print(sb);
    }
}