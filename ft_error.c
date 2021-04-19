#include "includes/cub3d.h"

void ft_print_errors()
{
    if (MISSING_INFOS  == 1)
        printf("Error\nmissing infos");
    if (MAP_IS_MISSING == 2)
        printf("Error\nmap is missing, can't do much without a map.");
    if (ERROR_FORMAT == 3)
        printf("Error\nwrong format, try again!");
    if (MAP_IS_OPEN == 4)
        printf("Error\nthe map is open duh !");
    if (VALUE_ERROR == 5)
        printf("Error\nproblem with some values.");
    if (OPENING_ERROR == 6)
        printf("Error\nan error occured while opening the file");
}