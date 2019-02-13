char *countAndSay(int n)
{
    char *s, *t;
    s = (char *)malloc(10000 * sizeof(char));
    t = (char *)malloc(10000 * sizeof(char));
    strcpy(s, "1");
    strcpy(t, "");

    int cnt = 1;
    char tmp[3];
    int i;
    for (i = 2; i <= n; i++)
    {
        int len = strlen(s);
        int j;
        for (j = 0; j < len; j++)
        {
            if (s[j] == s[j + 1])
            {
                cnt++;
            }
            else
            {
                tmp[0] = cnt + '0';
                tmp[1] = s[j];
                tmp[2] = '\0';
                strcat(t, tmp);
                cnt = 1;
            }
        }
        strcpy(s, t);
        strcpy(t, "");
    }

    return s;
}