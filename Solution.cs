using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class Solution
    {
        public IList<IList<int>> Permute(int[] nums)
        {
            IList<IList<int>> tp = new List<IList<int>>();
            List<int> tk = new List<int>();
            bool[] book = new bool[nums.Length];
            for (int i = 0; i < nums.Length; i++)
                book[i] = false;
            tp.Add(new List<int>(tk));
            Dfs(nums, 0, book, ref tp, ref tk);
            return tp;
        }
        public void Dfs(int []nums,int m,bool[]book,ref IList<IList<int>> tp,ref List<int> tk)
        {
            for(int i=m;i<nums.Length-1;i++)
            {
                if (book[i] == false)
                    continue;
                tp.Add(tk);
                tk.RemoveRange(0, tk.Count);
                return;
            }
            for(int i=m;i<nums.Length-1;i++)
            {
                if (book[i] == false)
                {
                    book[i] = true;
                    tk.Add(nums[i]);
                    Dfs(nums, i + 1, book, ref tp, ref tk);
                }
                book[i] = false; 
            }
        }
    }
}
