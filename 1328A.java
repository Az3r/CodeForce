
import java.util.Scanner;

public final class Scratch
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int test_count = scanner.nextInt();
        int[][] inputs = new int[test_count][2];
        for (int i = 0; i < test_count; ++i)
        {
            inputs[i][0] = scanner.nextInt();
            inputs[i][1] = scanner.nextInt();
        }

        solve(inputs);
    }


    public static void solve(int[][] inputs)
    {
        for (int[] test : inputs) {
            int a = test[0];
            int b = test[1];

            if (a % b == 0) System.out.println(0);
            else System.out.println(b - a % b);
        }
    }
}