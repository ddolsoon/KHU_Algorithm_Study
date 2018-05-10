import java.util.LinkedList;
import java.util.Queue;

public class breadth_first_search {

    public static void BFS(int[][] a, int[] visited, int n, int v) {
        Queue<Integer> q = new LinkedList();
        q.add(v);
        while (!q.isEmpty()) {
            int x = q.remove();
            System.out.println(x);

            visited[x] = 1;
            for (int y = 0; y < n; y++) {
                if (a[x][y] == 1 && visited[y] == 0) {
                    q.add(y);
                    visited[y] = 1;
                }
            }
        }
    }

    public static void main(String[] args) {

        int n = 8;
        int[][] a = {
                {0, 1, 1, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 0, 1, 0, 0},
                {1, 1, 0, 1, 1, 1, 1, 0},
                {1, 0, 1, 0, 1, 0, 1, 0},
                {0, 0, 1, 1, 0, 0, 1, 1},
                {0, 1, 1, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0}};

        int[] visited = new int[8];


        BFS(a, visited, n, 0);


    }
}
