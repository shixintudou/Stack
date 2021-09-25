using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{

    // Definition for a QuadTree node.
    public class Node
    {
        public bool val;
        public bool isLeaf;
        public Node topLeft;
        public Node topRight;
        public Node bottomLeft;
        public Node bottomRight;

        public Node()
        {
            val = false;
            isLeaf = false;
            topLeft = null;
            topRight = null;
            bottomLeft = null;
            bottomRight = null;
        }

        public Node(bool _val, bool _isLeaf)
        {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = null;
            topRight = null;
            bottomLeft = null;
            bottomRight = null;
        }

        public Node(bool _val, bool _isLeaf, Node _topLeft, Node _topRight, Node _bottomLeft, Node _bottomRight)
        {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomLeft = _bottomLeft;
            bottomRight = _bottomRight;
        }
    }


    class ForthNode
    {
        public Node Construct(int[][] grid)
        {
            if(grid.Length==1)
            {
                return new Node(grid[0][0] == 0 ? false : true, true);
            }
            bool allsame = true;
            foreach (int []i in grid)
            {
                foreach(int j in i)
                {
                    if (j != grid[0][0])
                    {
                        allsame = false;
                        break;
                    }
                }
                if (!allsame)
                    break;
            }
            if (allsame)
            {
                return new Node(grid[0][0] == 0 ? false : true, true);
            }
            else
            {
                int[][] grid1 = new int[grid.Length / 2][];//左上
                int[][] grid2 = new int[grid.Length / 2][];//右上
                int[][] grid3 = new int[grid.Length / 2][];//左下
                int[][] grid4 = new int[grid.Length / 2][];//右下
                for (int i = 0; i < grid1.Length; i++)
                {
                    grid1[i] = new int[grid[0].Length / 2];
                    grid2[i] = new int[grid[0].Length / 2];
                    grid3[i] = new int[grid[0].Length / 2];
                    grid4[i] = new int[grid[0].Length / 2];
                    for (int j = 0; j < grid1.Length; j++)
                    {
                        grid1[i][j] = grid[i][j];
                        grid2[i][j] = grid[i][j + grid.Length / 2];
                        grid3[i][j] = grid[i + grid.Length / 2][j];
                        grid4[i][j] = grid[i + grid.Length / 2][j + grid.Length / 2];
                    }
                }
                Node node = new Node();
                node.val = true;
                node.isLeaf = false;
                node.topLeft = Construct(grid1);
                node.topRight = Construct(grid2);
                node.bottomLeft = Construct(grid3);
                node.bottomRight = Construct(grid4);
                return node;
            }
        }
    }
}
