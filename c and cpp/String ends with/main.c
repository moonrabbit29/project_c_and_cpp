#include <stdbool.h>
#include <string.h>

bool solution(const char *string, const char *ending)
{
    int len = strlen(string) - strlen(ending);
    return len < 0 ?false :strcmp(string + len, ending) == 0;
}
