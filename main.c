#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>

int main() {

    FILE *configFile;

    struct passwd *pw = getpwuid(getuid());

    char *homedir = pw->pw_dir;
    char *test = "/Projects/myGithub/bookmarkTelegramChannel/.channelConfig";

    strcat(homedir, test);

    printf("%s\n", homedir);

    configFile = fopen(homedir, "r");


// gcc -o dauletTest main.c
// 

}