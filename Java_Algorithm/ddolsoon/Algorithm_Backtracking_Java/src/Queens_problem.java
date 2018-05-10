public class Queens_problem {

    public static void printCol(int [] col) {

        System.out.printf("[ ");
        for(int i=0;i< col.length;i++) {
            System.out.print(col[i] + " ");
        }
        System.out.printf("]");
        System.out.println();
    }

    public static boolean promising(int i, int[] col) {
        int k = 0;
        boolean sw = true;
        while (k < i && sw == true) {
            if (col[i] == col[k] || Math.abs(col[i] - col[k]) == i - k) {
                sw = false;
            }
            k += 1;

        }

        return sw;
    }

    public static void queens(int n, int i, int[] col) {
        if (promising(i, col) == true) {
            if (i == n - 1) {
                printCol(col);
            } else {
                for (int j = 0; j < n; j++) {
                    col[i + 1] = j;
                    queens(n, i + 1, col);
                }
            }
        }

    }

    public static void main(String[] args) {

        int n = 5;
        int[] col = new int[n];
        queens(n, -1, col);
    }
}
