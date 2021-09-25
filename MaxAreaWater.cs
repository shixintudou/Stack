using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class MaxAreaWater
    {
        int sum = 0;
        public int MaxArea(int[] height)
        {
            int i = 0;
            int j = height.Length - 1;
            while(i<j)
            {
                int temp = (height[i] <= height[j] ? height[i] : height[j]) * (j - i);
                if (sum < temp)
                    sum = temp;
                if (height[i] < height[j])
                    i++;
                else
                    j--;
            }
            return sum;
        }
    }
}
