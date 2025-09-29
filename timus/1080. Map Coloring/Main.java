import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    static final int MXN = 102;
    @SuppressWarnings("unchecked")
    static ArrayList<Integer>[] g = (ArrayList<Integer>[]) new ArrayList[MXN];

    static boolean paint(int u, int p, int[] colors, boolean col) {
        if (colors[u] != -1) return colors[u] == (col ? 1 : 0);
        colors[u] = col ? 1 : 0;
        for (int v : g[u]) {
            if (v != p) {
                if (!paint(v, u, colors, !col)) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        int[] colors = new int[n];
        for (int i = 0; i < n; i++) colors[i] = -1;

        for (int u = 0; u < n; ++u) {
            int v;
            while ((v = sc.nextInt()) != 0) {
                g[u].add(v - 1);
                g[v - 1].add(u);
            }
        }

        boolean ok = paint(0, -1, colors, false);
        if (!ok) System.out.println(-1);
        else for (int c : colors) System.out.print(c);
    }
}