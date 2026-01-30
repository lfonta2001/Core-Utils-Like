#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef __uint32_t Colour;

typedef struct
{
    Colour body;
    Colour background;
    char bold; // 0 or 1 for bool
} ColoursConfigField;

typedef struct
{
    ColoursConfigField Directory;
    ColoursConfigField File;
    ColoursConfigField Symlink;
} ColoursConfig;

void load_config(ColoursConfig *conf, const char *__local_path, const char *__global_path);

void change_config(const char *__local_path, const char *__global_path);

ColoursConfig *new_def_conf(void);

void free_conf(ColoursConfig *conf);

#endif // CONFIG_H