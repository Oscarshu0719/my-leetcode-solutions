int myAtoi(char *str)
{
    int i = 0;
    long num = 0;
    int len = 0;
    int flag_sign = 0;
    int flag_start = 0;

    while (i < strlen(str))
    {
        if (str[i] == ' ' && flag_start == 0)
        {
            i++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            flag_start = 1;
            num *= 10;
            num += (str[i] - '0');
            i++;

            if (num != 0)
                len++;
            if (len == 11)
                break;
        }
        else if (str[i] == '+' && flag_sign == 0 && flag_start == 0)
        {
            flag_start = 1;
            flag_sign = 1;
            i++;
        }
        else if (str[i] == '-' && flag_sign == 0 && flag_start == 0)
        {
            flag_start = 1;
            flag_sign = -1;
            num *= -1;
            i++;
        }
        else
        {
            break;
        }
    }

    if (flag_sign != 0)
        num *= flag_sign;

    if (num > INT_MAX)
        num = INT_MAX;
    else if (num < INT_MIN)
        num = INT_MIN;

    return (int)num;
}