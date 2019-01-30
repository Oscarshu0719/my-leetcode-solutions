bool isPalindrome(int x)
{
    if (x < 0)
    {
        return 0;
    }

    int a = x;
    int b = 0;

    while (a > 0)
    {
        b = b * 10 + (a % 10);
        a /= 10;
    }

    if (b == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}