class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 1.00000 || n == 0)
            return 1;
        long long k = n;
        if (n < 0)
        {
            x = 1 / x;
            k = -(n + 1);
            k += 1;
        }
        return p(x, k);
    }

    double p(double &x, long long n)
    {
        if (n == 1)
            return x;
        double t = p(x, n >> 1);
        if (n % 2)
            return x * t * t;
        else
            return t * t;
    }
};