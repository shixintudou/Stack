using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class Batch
    {
        public int MaxHappyGroups(int batchSize, int[] groups)
        {
            IList<IList<int>> vs = new List<IList<int>>();
            vs = Permute(groups);
            int sum = 0;
            Random random = new Random();
            if(vs.Count<10000)
            {
                foreach (List<int> vs1 in vs)
                {
                    int temp = 0;
                    int freq = 0;
                    foreach (int i in vs1)
                    {
                        if (freq % batchSize == 0)
                            temp++;
                        freq += i;
                    }
                    if (sum < temp)
                        sum = temp;
                }
            }
            else
            {
                for(int j=0;j<10000;j++)
                {
                    int temp = 0;
                    int freq = 0;
                    foreach (int i in vs[random.Next(0, vs.Count)])
                    {
                        if (freq % batchSize == 0)
                            temp++;
                        freq += i;
                    }
                    if (sum < temp)
                        sum = temp;
                }
                
            }
            return sum;
        }
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
