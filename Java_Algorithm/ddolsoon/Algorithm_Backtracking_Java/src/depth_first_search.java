public class depth_first_search {


    public static void DFS(int[][] a, int[] visited, int n, int v) {
        visited[v] = 1;
        System.out.println(v);

        for (int x = 0; x < n; x++) {
            if (a[v][x] == 1 && visited[x] == 0) {
                DFS(a, visited, n, x);
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


        DFS(a, visited, n, 0);

    }
}
