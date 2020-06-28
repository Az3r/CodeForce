
import java.util.Scanner;

public final class Scratch
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; ++i)
            solve(scanner.next());
    }

    private static void solve(String test)
    {
        int pos = test.length();
        int d = 1;
        while (pos >= 0)
        {
            int jump = 1;
            while (pos - jump >= 0 && test.charAt(pos - jump) != 'R') jump += 1;
            d = Math.max(jump, d);
            pos -= jump;
        }
        System.out.println(d);
    }
}