﻿using System;
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
            Dfs(nums, 0, book, ref tp, ref tk);
            return tp;
        }
        public void Dfs(int[] nums, int m, bool[] book, ref IList<IList<int>> tp, ref List<int> tk)
        {
            int a = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (book[i] == true)
                    a++;
            }
            if (a == nums.Length)
            {
                tp.Add(new List<int>(tk));
                //tk.Clear();
                return;
            }

            for (int i = m; i < m + nums.Length; i++)
            {
                if (book[i % nums.Length] == false)
                {
                    book[i % nums.Length] = true;
                    for (int j = 0; j < tk.Count; j++)
                    {
                        if (tk[j] == nums[i % nums.Length])
                            tk.RemoveAt(j);
                    }
                    tk.Add(nums[i % nums.Length]);
                    Dfs(nums, i + 1, book, ref tp, ref tk);
                    book[i % nums.Length] = false;
                }

            }
            return;
        }
    }
}
