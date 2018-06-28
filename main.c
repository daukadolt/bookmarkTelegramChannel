#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>


int main(int argc, char **argv) {

    FILE *configFile;

    struct passwd *pw = getpwuid(getuid());
    char *homedir = pw->pw_dir;
    char *directory = "/Projects/myGithub/bookmarkTelegramChannel/.channelConfig";


    char *text = (char*) malloc(100 * sizeof(char));
    printf("Text: ");
    scanf("%255s", text);


    // for (char **a = argv ; a != argv+argc ; a++) {
    //     for(char *p = *a ; *p != '\0' ; p++) {
    //         // code uses *p instead of argv[i][j]
    //         printf("%c", *p);
    //     }
    // }

    strcat(homedir, directory);
    printf("%s\n", homedir);
    configFile = fopen(homedir, "r");

    char token[100];
    char channel_name[100];

    if(configFile) {
        fscanf(configFile, "%s", token);
        fscanf(configFile, "%s", channel_name);
    }

    printf("%s\n%s\n",token, channel_name);

// CURL

    CURL *curl;
    CURLcode res;

    char URL[1000];
    sprintf(URL, "https://api.telegram.org/bot%s/sendMessage?chat_id=%s&text=%s", token, channel_name, text);
    




    printf("\n%s\n", URL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        /* example.com is redirected, so we tell libcurl to follow redirection */ 
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    
        /* Perform the request, res will get the return code */ 
        res = curl_easy_perform(curl);
        /* Check for errors */ 
        if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    
        /* always cleanup */ 
        curl_easy_cleanup(curl);
    }
    return 0;

    

// gcc -o dauletTest main.c
// 

}