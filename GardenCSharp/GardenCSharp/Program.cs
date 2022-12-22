using System;

namespace GardenCSharp
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            const int lmax = 3000;
            string[] input;
            int m;
            int n;
            input = Console.ReadLine().Split(" ");
            m = int.Parse(input[0]);
            n = int.Parse(input[1]);

            int[,] a = new int[301, 301];
            int[] col = new int[301];
            int[,] row = new int[2, 301];


            for (int i = 0; i < m; i++)
            {
                input = Console.ReadLine().Split(" ");
                for (int j = 0; j < n; j++)
                    a[i, j] = int.Parse(input[j]);
            }

            int res = -lmax;
            for (int i = 1; i <= m; i++)
            {
                for (int k = 1; k <= n; k++)
                {
                    col[k] = 0;
                    row[0, k] = row[0, k - 1] + a[i, k];
                }
                for (int j = i + 1; j <= m; j++)
                {
                    for (int k = 1; k <= n; k++)
                        row[1, k] = row[1, k - 1] + a[j, k];

                    int best = lmax;
                    for (int k = 1; k <= n; k++)
                    {
                        res = (res > col[k] + row[0, k] + row[1, k] - best) ? res : col[k] + row[0, k] + row[1, k] - best;
                        best = (best > row[0, k - 1] + row[1, k - 1] - col[k]) ? row[0, k - 1] + row[1, k - 1] - col[k] : best;
                    }

                    for (int k = 1; k <= n; k++)
                        col[k] = col[k] + a[j, k];
                }
            }
            Console.Write(res);
        }
    }
}