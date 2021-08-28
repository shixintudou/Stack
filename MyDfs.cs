using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace Stack
{
    class MyDfs
    {
        public int m, n, des, min;
        public int[,] arr;
        public bool[] book;
        public List<int> way = new List<int>();
        public MyDfs(int x, int y)
        {
            m = x;
            n = y;
            des = 5;
            min = 100;
            arr = new int[x, x];
            book = new bool[x];
            book[0] = true;
            way.Add(1);
            for (int i = 0; i < x; i++)
                for (int j = 0; j < x; j++)
                    arr[i, j] = 99;
            for (int i = 0; i < x; i++)
            {
                book[i] = false;
                arr[i, i] = 0;
            }
            for (int i = 0; i < y; i++)
            {
                int a = ToInt32(ReadLine());
                int b = ToInt32(ReadLine());
                int c = ToInt32(ReadLine());
                arr[a - 1, b - 1] = c;
            }
        }
        public void Dfs(int cur, int dis)
        {
            if (dis > min)
                return;
            if (cur == des && dis <= min)
            {
                min = dis;
                foreach (int i in way)
                {
                    if (i != des)
                        Write($"{i}->");
                    else
                        WriteLine(i);
                }
                return;
            }
            for (int i = 0; i < m; i++)
            {
                if (i + 1 != cur)
                {
                    if (arr[cur - 1, i] != 99 && book[i] == false)
                    {
                        book[i] = true;
                        way.Add(i + 1);
                        Dfs(i + 1, dis + arr[cur - 1, i]);
                        book[i] = false;
                        if (way.Count >= 1)
                            way.RemoveAt(way.Count - 1);
                    }
                }
            }
        }
    }
}