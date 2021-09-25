using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class ProductsSearch
    {
        public IList<IList<string>> SuggestedProducts(string[] products, string searchWord)
        {
            QuickSort(products, 0, products.Length - 1);
            IList<IList<string>> vs = new List<IList<string>>();
            List<string> newproduct = new List<string>(products);
            //foreach(string i in products)
            //{
            //    if(i[0]==searchWord[0])
            //    {
            //        pi.Add(i);
            //    }
            //    if (pi.Count == 3)
            //        break;
            //}
            //int t;
            List<string> words = new List<string>();
            List<string> removes = new List<string>();
            for (int i = 0; i < searchWord.Length; i++)
            {
                
                for (int j = 0; j < newproduct.Count; j++)
                {
                    if(newproduct[j].Length>i)
                    {
                        if (newproduct[j][i].Equals(searchWord[i]) && words.Count < 3)
                        {
                            words.Add(newproduct[j]);
                        }
                        if (!newproduct[j][i].Equals(searchWord[i]))
                        {
                            removes.Add(newproduct[j]);
                        }
                    }
                    else
                    {
                        removes.Add(newproduct[j]);
                    }
                }
                foreach (string k in removes)
                {
                    newproduct.Remove(k);
                }
                vs.Add(new List<string>(words));
                words.Clear();
                removes.Clear();
            }
            return vs;
        }
        public void QuickSort(string [] arr, int l, int r)
        {
            if (l >= r)
                return;
            int i = l;
            int j = r;
            string x = arr[l];
            while(i<j)
            {
                while (i < j && string.Compare(arr[j],x)>=0)
                    j--;
                while (i < j && string.Compare(arr[i], x) <= 0)
                    i++;
                if(i<j)
                {
                    string t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            arr[l] = arr[i];
            arr[i] = x;
            QuickSort(arr, l, i - 1);
            QuickSort(arr, i + 1, r);
        }
    }
}
