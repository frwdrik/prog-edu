void censor(char s[])
{
    int i;

    for (i = 0; s[i]; i++)
	if (s[i] == 'f' && s[i+1] == 'o' && s[i+2] == 'o')
	    s[i] = s[i+1] = s[i+2] = 'x';
}
