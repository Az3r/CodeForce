
import java.util.Scanner;

public final class Scratch
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; ++i)
        {
            int n = scanner.nextInt();
            int[] heights = new int[n];
            for (int j = 0; j < n; ++j) heights[j] = scanner.nextInt();
            solve(heights);
        }
    }

    private static void solve(int[] heights)
    {
        boolean even = heights[0] % 2 == 0;
        for (int h : heights)
        {
            if (even != (h % 2 == 0))
            {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}