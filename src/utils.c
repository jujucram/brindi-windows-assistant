#include <ctype.h>
#include "utils.h"

void toLowerCase(char *str) {
    for (; *str; str++)
        *str = tolower(*str);
}
