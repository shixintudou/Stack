using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace Stack
{
    class Heap
    {
        List<int> heaps = new List<int>();
        void swap(int x,int y)
        {
            int t;
            t = heaps[x];
            heaps[x] = heaps[y];
            heaps[y] = t;
        }
        void siftdown(int i)
        {
            int t;
            bool flag = true;
            while(i*2<heaps.Count&&flag)
            {
                if (heaps[i] > heaps[i * 2])
                    t = i * 2;
                else
                    t = i;
                if (i * 2 + 1 < heaps.Count)
                {
                    if (heaps[t] > heaps[i * 2 + 1])
                        t = i * 2 + 1;
                }
                if (t != i)
                    swap(i, t);
                else
                    flag = false;
            }           
        }
        int deletmin()
        {
            int t = heaps[1];
            heaps.RemoveAt(1);
            siftdown(1);
            return t;
        }
        public Heap()
        {
            heaps.Add(0);
            int n = ToInt32(ReadLine());
            for(int i=0;i<n;i++)
            {
                heaps.Add(ToInt32(ReadLine()));
            }
            for(int i=heaps.Count/2;i>=1;i--)
            {
                siftdown(i);
            }
            for(int i=0;i<n;i++)
            {
                Write(deletmin() + " ");
            }
        }
    }
}
