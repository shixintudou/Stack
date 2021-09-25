using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class Bricks
    {       
        public int LeastBricks(IList<IList<int>> wall)
        {
            Dictionary<int, int> keyValues = new Dictionary<int, int>();
            foreach(IList<int> vs in wall)
            {
                int temp = 0;//key
                for(int i=0;i<vs.Count-1;i++)
                {
                    temp += vs[i];
                    if(!keyValues.ContainsKey(temp))
                    {
                        keyValues.Add(temp, 1);
                    }
                    else
                    {
                        keyValues[temp]++;
                    }
                }
            }
            int m = 0;
            foreach(var entry in keyValues)
            {
                m = Math.Max(m, entry.Value);
            }
            return wall.Count - m;
        }
    }
}
