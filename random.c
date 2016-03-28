/*************************************************************************
 * @File Name:    random.c
 * @Author:       shaozengguang
 * @Mail:         shaozg1101@126.com
 * @Created Time: 五, 03/25/2016, 17时41分56秒
 * @Copyright:    GPL 2.0
 * @Description:  
 *************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const static char *g_key = "1234567890!@#$%^&*()_+-=abcdefghijlkmnoprstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const static int g_default_len = 9;

static void usage(int argc, char *argv[]) {
    fprintf(stdout, "\
NAME \n\
    %s - Generated random string for password.\n\
    \n\
SYNOPSIS \n\
    %s [global options] command [command options] [arguments...] \n\
    \n\
GLOBAL OPTIONS \n\
    --help          - Show this message. \n\
    --len           - Generate length of string. \n\
    \n\
COMMANDS \n\
    help   - Shows a list of commands or help for one command \n\
", argv[0], argv[0]);
}

static void generate_random_key(const int len) {
    if (len <= 1) {
        fprintf(stderr, "Bad len!");
        return ;
    }

    const int key_len = strlen(g_key);
    char *buffer = (char *)malloc(len+1);
    memset(buffer, 0, len+1);
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; i ++) {
        buffer[i] = g_key[rand() % key_len];
    }

    fprintf(stdout, "%s\n", buffer);
    free(buffer);
    buffer = NULL;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        generate_random_key(g_default_len);
    } else if (argc == 2 && (0 == strcmp(argv[1], "--help") || 0 == strcmp(argv[1], "-help"))) {
        usage(argc, argv);
    } else if (argc == 3 && (0 == strcmp(argv[1], "--len") || 0 == strcmp(argv[1], "-len"))) {
        if (atoi(argv[2]) <= 0 || atoi(argv[2]) > 100000) {
            fprintf(stderr, "Bad password length.");
            return -1;
        }

        generate_random_key(atoi(argv[2]));
    } else {
        usage(argc, argv);
    }

    return 0;
}

