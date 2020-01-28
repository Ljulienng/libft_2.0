#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int     get_next_line(int fd, char **line)
{
    static char     buffer[BUFFER_SIZE + 1];
    char            buffer_temp[1];
    int             ret;
    int             ret2;
    ret = 1;

    if (fd <= -1 || line == NULL || (read(fd, buffer_temp, 0) < 0))
        return (-1);
    *line = ft_strdup("");
    while (ret && (ret2 = ft_strchr(buffer, '\n')) == -1)
    {
        if (!(*line = ft_strnjoin(*line, buffer, BUFFER_SIZE)))
            return (-1);
        if ((ret = read(fd, buffer, BUFFER_SIZE)) == 0)
        {
            return (0);
        }
        buffer[ret] = 0;
    }
    if (!(*line = ft_strnjoin(*line, buffer, ret2)))
        return (-1);
    if (ret)
        ft_strcpy(buffer, &buffer[ret2 + 1]);
    return (1);
}