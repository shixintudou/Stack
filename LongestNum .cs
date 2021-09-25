using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class LongestNum
    {
        public int LongestConsecutive(int[] nums)
        {
            HashSet<int> hash = new HashSet<int>();
            foreach(int num in nums)
            {
                hash.Add(num);
            }
            int len = 0;
            foreach(int num in nums)
            {
                if(!hash.Contains(num-1))
                {
                    int temp = num;
                    while(hash.Contains(temp+1))
                    {
                        temp++;
                    }
                    len = Math.Max(temp - num + 1, len);
                }
            }
            return len;
        }
    }
}
