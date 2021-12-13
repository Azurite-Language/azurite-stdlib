using System;
using System.Collections.Generic;
using System.Linq;

namespace Azurite
{
    class Azurite
    {
        #region easy math
        static public double Add(List<double> a)
        {
            double f = 0;
            foreach(var l in a)
            {
                f+=l;
            }        
            return f;
        }
        static public float Add(List<float> a)
        {
            float f = 0;
            foreach(var l in a)
            {
                f+=l;
            }        
            return f;
        }
        static public double Removed(List<double> a)
        {
            if (a.Count==1) return -a[0];
            double f = a[0];
            for(int l = 1; l<a.Count;l++)
            {
                f/=a[l];
            }        
            return f;
        }
        static public float Removed(List<float> a)
        {
            if (a.Count==1) return -a[0];
            float f = a[0];
            for(int l = 1; l<a.Count;l++)
            {
                f/=a[l];
            }        
            return f;
        }
        static public double Times(List<double> a)
        {
            double f = 1;
            foreach(var l in a)
            {
                f*=l;
            }        
            return f;
        }
        static public float Times(List<float> a)
        {
            float f = 1;
            foreach(var l in a)
            {
                f*=l;
            }        
            return f;
        }
        static public double Divd(List<double> a)
        {
            double f = a[0];
            for(int l = 1; l<a.Count;l++)
            {
                f/=a[l];
            }
            return f;        
        }
        static public float Dvid(List<float> a)
        {
            float f = a[0];
            for(int l = 1; l<a.Count;l++)
            {
                f/=a[l];
            }        
            return f;
        }
        #endregion

        #region String
        static public bool StartWith(string a, string b)
        {
            for(int i = 0; i < b.Length;i++)
            {
                if (b[i]!=a[i]) return false;
            }
            return true;
        }
        static public bool EndWith(string a, string b)
        {
            for(int i = 0; i < b.Length;i++)
            {
                if (b[b.Length-i]!=a[i]) return false;
            }
            return true;
        }

        static public bool StartWith(List<double> a, List<double> b)
        {
            for(int i = 0; i < b.Count;i++)
            {
                if (b[i]!=a[i]) return false;
            }
            return true;
        }
        static public bool StartWith(List<float> a, List<float> b)
        {
            for(int i = 0; i < b.Count;i++)
            {
                if (b[i]!=a[i]) return false;
            }
            return true;
        }
        static public bool StartWith(List<string> a, List<string> b)
        {
            for(int i = 0; i < b.Count;i++)
            {
                if (b[i]!=a[i]) return false;
            }
            return true;
        }
        static public bool StartWith(List<bool> a, List<bool> b)
        {
            for(int i = 0; i < b.Count;i++)
            {
                if (b[i]!=a[i]) return false;
            }
            return true;
        }
        
        

        #endregion
        #region Boolean

/*        static public bool is_equal(List<float> a)
        {
            return (a.Any(o => o != a[0]));
        }
        static public bool is_equal(List<double> a)
        {
            return (a.Any(o => o != a[0]));
        }static public bool is_equal(List<string> a)
        {
            return (a.Any(o => o != a[0]));
        }
*/
        static public bool is_equal<T>(List<T> a) where T :class
        {
            return (a.Any(o => o != a[0]));
        }

        static public bool ascend(List<double> a)
        {
            var ordered = a.OrderBy(d >= d);
            return (a.SequenceEqual(ordered)||a.Distinct().Count() == a.Count());
        }

        static public bool ascend(List<float> a)
        {
            var ordered = a.OrderBy(d >= d);
            return (a.SequenceEqual(ordered)||a.Distinct().Count() == a.Count());
        }

        
        static public bool ascende(List<double> a)
        {
            var ordered = a.OrderBy(d >= d);
            return a.SequenceEqual(ordered);
        }

        static public bool ascende(List<float> a)
        {
            var ordered = a.OrderBy(d >= d);
            return a.SequenceEqual(ordered);
        }

        static public bool descend(List<double> a)
        {
            var ordered = a.OrderBy(d <= d);
            return (a.SequenceEqual(ordered)||a.Distinct().Count() == a.Count());
        }

        static public bool descend(List<float> a)
        {
            var ordered = a.OrderBy(d <= d);
            return (a.SequenceEqual(ordered)||a.Distinct().Count() == a.Count());
        }

        
        static public bool descende(List<double> a)
        {
            var ordered = a.OrderBy(d <= d);
            return a.SequenceEqual(ordered);
        }

        static public bool descende(List<float> a)
        {
            var ordered = a.OrderBy(d <= d);
            return a.SequenceEqual(ordered);
        }
        static public bool or(List<bool> a)
        {
            return a.Any(o => o == true);
        }
        static public bool and(List<bool> a)
        {
            return a.Any(o => o != true);
        }
        static public bool xor(List<bool> a)
        {
            return or(a)&&!and(a);
        }
        #endregion
        #region List
        static public bool StartWith<T>(List<T> a, List<T> b)where T :class
        {
            for(int i = 0; i < b.Length;i++)
            {
                if (b[i]!=a[i]) return false;
            }
            return true;
        }
        static public bool EndWith<T>(List<T> a, List<T> b)where T :class
        {
            for(int i = 0; i < b.Length;i++)
            {
                if (b[b.Length-i]!=a[i]) return false;
            }
            return true;
        }
        #endregion

    }
}