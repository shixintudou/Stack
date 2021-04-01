using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace Stack
{
    public struct Note<T>
    {
        public T x;
        public T y;
        public Note(T a, T b)
            {
            x=a;
            y=b;
            }
    }
   
    class Program
    {
        static void Main()
        {
            int[,] next = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
            int m, n;
            m = ToInt32(ReadLine());
            n = ToInt32(ReadLine());
            int[,] arr = new int[m, n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    arr[i, j] = ToInt32(ReadLine());
            WriteLine("地图输入完毕");
            int startx, starty;
            startx = ToInt32(ReadLine());
            starty = ToInt32(ReadLine());
            int head = 0, tail = 0, sum = 1;
            List<Note<int>> queue = new List<Note<int>>();
            bool[,] book = new bool[m, n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    book[i, j] = false;
            queue.Add(new Note<int>(startx, starty));
            tail++;
            int tx, ty;
            while(head<tail)
            {
                for(int i=0;i<4;i++)
                {
                    tx = queue[head].x + next[i, 0];
                    ty = queue[head].y + next[i, 1];
                    if (tx >= m || ty >= n || tx < 0 || ty < 0)
                    {
                        continue;
                    }
                    if(arr[tx,ty]>0&&book[tx,ty]==false)
                    {
                        sum++;
                        book[tx, ty] = true;
                        queue.Add(new Note<int>(tx, ty));
                        tail++;
                    }                    
                }
                head++;
            }
            WriteLine($"sum={sum}");
            ReadKey();
        }
    }
}
