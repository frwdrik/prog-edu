#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char*index_url)
{
    char http[200] = "http://";
    char index[] = "index.html";

    strcpy(index_url, strcat((strcat(http, domain)), index));
}

int main(void)
{
    char domain[] = "linux.org";
    char index_url[200];

    build_index_url(domain, index_url);

    printf("%s\n", index_url);

    return 0;
}
