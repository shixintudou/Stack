using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace Stack
    {
        class Program
        {

        static void Main()
        {
            int[] arr = { 34, 565, 76, 32, 56, 7 };
            Solution solution = new Solution();
            IList<IList<int>> vs= new List<IList<int>>();
            vs = solution.Permute(arr);
            //int?[] root = { 6, 7, 8, 2, 7, 1, 3, 9, null, 1, 4, null, null, null, 5 };
            //List<TreeNode> treeNodes = new List<TreeNode>();
            //for(int i=0;i<root.Length;i++)
            //{ 
            //    if (root[i] != null)
            //        treeNodes.Add(new TreeNode((int)root[i]));
            //    else
            //        treeNodes.Add(null);
            //}
            //for(int i=0;i<treeNodes.Count;i++)
            //{
            //    if(((i+1)*2-1)<treeNodes.Count)
            //    {
            //        if (treeNodes[i] != null)
            //            treeNodes[i].left = treeNodes[(i + 1) * 2 - 1];
            //    }
            //    if (((i + 1) * 2 ) < treeNodes.Count)
            //    {
            //        if (treeNodes[i] != null)
            //            treeNodes[i].right = treeNodes[(i + 1) * 2];
            //    }
            //}
            //TreeSum treeSum = new TreeSum();
            //WriteLine(treeSum.SumEvenGrandparent(treeNodes[0]));
            foreach (List<int> vs1 in vs )
            {
                foreach(int vs2 in vs1)
                {
                    Write($"{vs2}" + " ");
                }
                WriteLine();
            }
            WriteLine(0 % 4);
            ReadKey();
            }
        }
    }

