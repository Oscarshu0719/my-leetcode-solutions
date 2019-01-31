static char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int check_priority(char *adjacent_symbols)
{
    int i;
    int is_higher = 0;

    if (adjacent_symbols[0] == adjacent_symbols[1])
    {
        return 0;
    }

    for (i = 0; i < 7; i++)
    {
        if (adjacent_symbols[0] == symbol[i])
        {
            is_higher = 1;
            break;
        }
        else if (adjacent_symbols[1] == symbol[i])
        {
            is_higher = 0;
            break;
        }
    }

    return is_higher;
}

static int value[7] = {1, 5, 10, 50, 100, 500, 1000};

int find_symbol(char c)
{
    int i;

    for (i = 0; i < 7; i++)
    {
        if (c == symbol[i])
        {
            return value[i];
        }
    }

    return -1;
}

// The normal format is descending.
int romanToInt(char *s)
{
    int i = 0;
    int sum = 0;

    if (strlen(s) != 0)
    {
        sum = find_symbol(s[0]);
    }

    while (i < (strlen(s) - 1))
    {
        char adj_symbols[2];
        adj_symbols[0] = s[i];
        adj_symbols[1] = s[++i];

        if (check_priority(adj_symbols) == 1)
        {
            sum = sum - 2 * find_symbol(s[(i - 1)]) + find_symbol(s[i]);
        }
        else
        {
            sum += find_symbol(s[i]);
        }
    }

    return sum;
}