#include "includes/cub3d.h"

int is_whitespace(char c)
{
    if ((c <= 9 && c >= 13) || c == 32)
        return(1);
}
