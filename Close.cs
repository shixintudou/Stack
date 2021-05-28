using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class Close
    {
        public bool CloseStrings(string word1, string word2)
        {
            List<char> list1 = new List<char>();
            List<char> list2 = new List<char>();
            if (word1.Length!=word2.Length)
                return false;
            if (word1 == word2)
                return true;
            char[] arr1 = word1.ToArray();
            char[] arr2 = word2.ToArray();
            Quicksort(arr1, 0, arr1.Length - 1);
            Quicksort(arr2, 0, arr2.Length - 1);
            if (arr1 == arr2)
                return true;
            list1.Add(arr1[0]);
            list2.Add(arr2[0]);
            for(int i=1;i<arr1.Length;i++)
            {
                if (arr1[i] != arr1[i - 1])
                    list1.Add(arr1[i]);
                if (arr2[i] != arr2[i - 1])
                    list2.Add(arr2[i]);
            }            
            if (list1.Count != list2.Count)
                return false;
            else if (list1.Count == list2.Count)
            {
                if(list1.Count>1)
                {
                    int[] m = new int[list1.Count];
                    int[] n = new int[list2.Count];
                    char[] m1 = new char[list1.Count];
                    char[] n1 = new char[list1.Count];
                    int k = 0, j = 0, k1 = 0, j1 = 0;
                    for (int i = 1; i < arr1.Length; i++)
                    {
                        if (arr1[i] != arr1[i - 1])
                        {
                            m1[k] = arr1[i - 1];
                            if (k == 0)
                                m[k] = i;
                            else if (k > 0)
                                m[k] = i - k1;
                            k1 += m[k];
                            k++;
                        }
                        if (arr2[i] != arr2[i - 1])
                        {
                            n1[j] = arr2[i - 1];
                            if (j == 0)
                                n[j] = i;
                            else if (j > 0)
                                n[j] = i - j1;
                            j1 += n[j];
                            j++;
                        }
                        if (i == arr1.Length - 1)
                        {
                            m1[k] = arr1[i];
                            n1[j] = arr2[i];
                            if (arr1[i] == arr1[i - 1])
                            {
                                m[k] = i + 1 - k1;
                            }
                            else
                            {
                                m[k] = 1;
                            }
                            if (arr2[i] == arr2[i - 1])
                            {
                                n[j] = i + 1 - j1;
                            }
                            else
                            {
                                n[j] = 1;
                            }
                        }
                    }
                    Quicksort(m1, 0, m1.Length - 1);
                    Quicksort(n1, 0, n1.Length - 1);
                    Quicksort1(m, 0, m.Length - 1);
                    Quicksort1(n, 0, n.Length - 1);
                    for (int i = 0; i < m.Length; i++)
                    {
                        if (m1[i] != n1[i])
                            return false;
                        if (m[i] != n[i])
                            return false;
                    }
                }
                else if(list1.Count<=1)
                {
                    if (list1[0] != list2[0])
                        return false;
                }
            }
            return true;
        }

        public void Quicksort(char[] arr,int l, int r)
        {
            int i = l, j = r;            
            if (l >= r)
                return;
            char x = arr[l];
            while (i<j)
            {
                while (i < j && arr[j] >= x)
                    j--;
                while (i < j && arr[i] <= x)
                    i++;
                if(i<j)
                {
                    char t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            arr[l] = arr[i];
            arr[i] = x;
            Quicksort(arr, l, i - 1);
            Quicksort(arr, i + 1, r);
        }
        public void Quicksort1(int[] arr, int l, int r)
        {
            int i = l, j = r;
            if (l >= r)
                return;
            int x = arr[l];
            while (i < j)
            {
                while (i < j && arr[j] >= x)
                    j--;
                while (i < j && arr[i] <= x)
                    i++;
                if (i < j)
                {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            arr[l] = arr[i];
            arr[i] = x;
            Quicksort1(arr, l, i - 1);
            Quicksort1(arr, i + 1, r);
        }
        public void Quicksort2<T>(T[] arr, int l, int r)
        {

        }
    }
}
