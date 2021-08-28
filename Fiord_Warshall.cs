using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Convert;
using static System.Console;

namespace Stack
{
    class Flord_Warshall
    {
        private int m, n, q, w, r;
        private readonly int inf;
        private int[,] e;
        public Flord_Warshall(int x)
        {
            inf = x;
        }
        public void shall()
        {
            m = ToInt32(ReadLine());
            n = ToInt32(ReadLine());
            e = new int[m+1, m+1];
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    e[i, j] = inf;
                }
            }
            for(int i=1;i<=m;i++)
            {
                e[i, i] = 0;
            }
            for(int i=1;i<=n;i++)
            {
                q = ToInt32(ReadLine());
                w = ToInt32(ReadLine());
                r = ToInt32(ReadLine());
                e[q, w] = r;
            }
            for(int k=1;k<=m;k++)
            {
                for(int i=1;i<=m;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if (e[i, j] > e[i, k] + e[k, j])
                            e[i, j] = e[i, k] + e[k, j];
                    }
                }
            }
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    Write($"{e[i, j]}   ");
                }
                WriteLine();
            }
        }

    }
}
