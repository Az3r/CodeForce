using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Reflection;
using System.Security.Cryptography.X509Certificates;
using System.Threading;
using System.Threading.Tasks;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string[] first = Console.ReadLine().Split(' ');
                string[] second = Console.ReadLine().Split(' ');

                int[] xy = (from str in first select int.Parse(str)).ToArray();
                int[] ab = (from str in second select int.Parse(str)).ToArray();
                Console.WriteLine(Solve(xy[0], xy[1], ab[0], ab[1]));
            }
        }

        static long Solve(int x, int y, int a, int b)
        {
            long left = Math.Min(x, y);
            long right = Math.Max(x, y);

            if (b < 2 * a) return left * b + (right - left) * a;
            else return a * (left + right);

        }
    }
}
