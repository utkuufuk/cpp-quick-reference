namespace multiply
{
    namespace // anonymous namespace
    {
        int first = 4;
        int second = 5;

        int calc(int a, int b)
        {
            return a * b;
        }
    }

    int getFirst()
    {
        return first;
    }

    int getSecond()
    {
        return second;
    }

    int getProduct()    
    {
        return calc(first, second);
    }
}