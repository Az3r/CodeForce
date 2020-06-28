
import java.util.Arrays;
import java.util.Scanner;

public final class Scratch
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int[] test_cases = new int[t];
        for (int i = 0; i < test_cases.length; ++i)
            test_cases[i] = scanner.nextInt();
        solve(test_cases);
    }

    private static void solve(int[] test_cases)
    {
        for (int n : test_cases)
        {
            int[] output = new int[n];
            if (n == 1) output[0] = -1;
            else
            {
                Arrays.fill(output, 3);
                output[0] = 2;
            }
            for (int digit : output) System.out.print(digit);
            System.out.println();
        }
    }
}