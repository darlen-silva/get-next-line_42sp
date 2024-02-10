# get_next_line 
This is a simple implementation of the get_next_line function, similar to the
[fgets](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm)
function in C and [getline](https://www.tutorialspoint.com/getline-string-in-cplusplus) in C++.

The get_next_line is an individual project at [42](https://www.42sp.org.br) that
requires the creation of a function similar to [getline](https://www.tutorialspoint.com/getline-string-in-cplusplus)
from C++ and [fgets](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm)
from C. This function allows reading a file line by line when called in a loop.

#### Objectives
- Unix logic

#### Skills
- Unix
- Rigor
- Algorithms & AI

## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/darlen-silva/get-next-line_42sp && cd get-next-line_42sp/
```
```bash
cc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c
./a.out
```

### A main.c example:
```c
#include <stdio.h>
#include <fcntl.h>
#include "./get_next_line.h"

int main(void)
{
    char *line;
    int  fd;

    // change <file> to a name of a existing file.
    fd = open("./<file>", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

Made by:<br />
Darlen Silva 👋 [See my linkedin](https://www.linkedin.com/in/darlen-silva/)
