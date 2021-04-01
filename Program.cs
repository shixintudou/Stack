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
            int x, y;
            x = ToInt32(ReadLine());
            y = ToInt32(ReadLine());
            MyDfs myDfs = new MyDfs(x, y);
            myDfs.Dfs(1, 0);
            WriteLine(myDfs.min);            
            ReadKey();
        }
    }
}
