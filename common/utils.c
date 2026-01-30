#include "utils.h"

char *load_home_path(const char *pseudo_path)
{
    char *home = getenv("HOME");
    if (!home)
    {
        fprintf(stderr, "Couldn't get home path");
        return NULL;
    }

    size_t size = strlen(home) + strlen(pseudo_path) - 1;
    char *fullPath;
    fullPath = malloc(size);
    snprintf(fullPath, sizeof(home) + sizeof(pseudo_path), pseudo_path, home);
    return fullPath;
}