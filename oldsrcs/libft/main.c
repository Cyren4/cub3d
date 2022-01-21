#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char *line;
	int ret;
	int fd = open(av[1], O_RDONLY);

	if (ac == 2)
	{
		while ((ret = get_next_line(fd,&line)) > 0)
		{
			printf("%d -- %s\n", ret,line);
			free(line);
		} 
		
		printf("%d -- %s\n", ret,line);
		close(fd);
	}	
}
