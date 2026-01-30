#include "config.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

// Utils
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// Paths
#define LOCAL_COLOUR_CONFIG_PATH "%s/.config/core-utils-copy/ls-colours.config"
#define GLOBAL_COLOUR_CONFIG_PATH "/etc/core-utils-copy/ls-colours.config"

// Constants
#define ALL_FILES 'a'
#define ALMOST_ALL 'A'
#define COLOUR_CONFIG 'c'
#define LONG_INFO 'l'
#define HUMAN_SIZE 'h'
#define SHOW_SIZE 's'
#define HELP 'm'

// Flag order: longinfo/show size/all files/show . ../human size
char flags = 0;
ColoursConfig *conf;

void search(const char *path);

void help(const char *file_name);

int main(int argc, char **argv)
{
    int r;
    char *path;
    char *fpath;
    char *local_path = load_home_path(LOCAL_COLOUR_CONFIG_PATH);
    while ((r = getopt(argc, argv, "aAhlmsc")) != -1)
    {
        switch (r)
        {
        case HELP:
            help(argv[0]);
            return 0;
            break;
        case COLOUR_CONFIG:
            change_config(local_path, GLOBAL_COLOUR_CONFIG_PATH);
            return 0;
            break;
        case HUMAN_SIZE:
            flags |= 1;
            break;
        case ALMOST_ALL:
            flags |= 1 << 2;
            break;
        case ALL_FILES:
            flags |= 3 << 1;
            break;
        case SHOW_SIZE:
            flags |= 1 << 3;
            break;
        case LONG_INFO:
            flags |= 1 << 4;
            break;
        default: /* ? */
            printf("Flag %s is not valid.\n", argv[optind - 1]);
            help(argv[0]);
            return 1;
            break;
        }
    }
    if (argc - optind > 1)
    {
        printf("Last argument must be a single string or empty.\n");
        exit(EXIT_FAILURE);
    }
    if (optind < argc)
    {
        path = argv[optind];
    }
    else
    {
        path = "./";
    }
    if (strrchr(path, '/') != (strrchr(path, '\0') - 1))
    {
        fpath = path + '/';
    }
    else
    {
        fpath = path;
    }
    conf = new_def_conf();
    load_config(conf, local_path, GLOBAL_COLOUR_CONFIG_PATH);
    free(local_path);
    free_conf(conf);
    search(fpath);
    return 0;
}

void help(const char *file_name)
{
    printf("Usage: %s [FLAGS] [OBJ DIR]\n", file_name);
    printf("\n");
    printf("  Flags:\n");
    printf("    -m    Show this help message.\n");
    printf("\n");
    printf("    -a    Show all directories and files, including '.' and '..', this option takes priority over -A.\n");
    printf("    -A    Show all directories and files, without '.' and '..'.\n");
    printf("    -l    Use a long listing format.\n");
    printf("    -s    Show size of files and directories.\n");
    printf("    -h    With -s or -l show size in human readable format.\n");
}

void search(const char *path)
{
    DIR *dir = opendir(path);
    if (!dir)
        return;

    long max = pathconf(path, _PC_PATH_MAX);
    if (max == -1)
    {
        max = 4096;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        // if (!(flags & 1 << 1))
        // {
        //     if (strcmp(entry->d_name, ".") == 0 ||
        //         strcmp(entry->d_name, "..") == 0)
        //         continue;
        // }

        char fullpath[max];
        snprintf(fullpath, sizeof(fullpath), "%s%s", path, entry->d_name);

        struct stat st;
        if (lstat(fullpath, &st) == -1)
            continue;

        if (S_ISDIR(st.st_mode))
        {
            search(fullpath);
        }
        else if (S_ISREG(st.st_mode))
        {
            printf("%s\n", fullpath);
        }
    }

    closedir(dir);
}
