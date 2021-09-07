using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{

    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public class TreeSum
    {
        public int SumEvenGrandparent(TreeNode root)
        {
            if (root == null)
                return 0;
            int sum = 0;
            if(root.val%2==0)
            {
                if(root.left!=null)
                {
                    if (root.left.left != null)
                        sum += root.left.left.val;
                    if (root.left.right != null)
                        sum += root.left.right.val;
                }
                if(root.right!=null)
                {
                    if (root.right.right != null)
                        sum += root.right.right.val;
                    if (root.right.left != null)
                        sum += root.right.left.val;
                }
            }
            return sum + SumEvenGrandparent(root.left) + SumEvenGrandparent(root.right);
        }
    }
}
