int reverse(int x)
{
    int result = 0;

    if (x > INT_MAX)
    {
        return 0;
    }

    int is_negative = (x < 0);

    if (is_negative == 1)
    {
        x *= -1;
    }

    while (x > 0)
    {
        if (result > (INT_MAX / 10) || result < (INT_MIN / 10))
        {
            return 0;
        }
        result = result * 10 + (x % 10);
        x /= 10;
    }

    if (is_negative == 1)
    {
        result *= -1;
    }

    return result;
}