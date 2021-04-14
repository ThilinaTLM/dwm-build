
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


const char* AUTOSTART_SCRIPT = "autostart.sh";
const char* CONFIG_DIR      = ".config/dwm";

/**
 * Auto run script when dwm start
 */
int startup_script() {

    // grab HOME directory from environment
    char *home;
	if ((home = getenv("HOME")) == NULL)
		return -1;
    
    // autostart file path 
    char *path;
	path = ecalloc(1, strlen(home) + strlen(CONFIG_DIR) + strlen(AUTOSTART_SCRIPT) + 3);
    if (sprintf(path, "%s/%s/%s", home, CONFIG_DIR, AUTOSTART_SCRIPT) < 0) {
        free(path);
    }

    // run autostart script 
	if (access(path, X_OK) == 0) {
    	system(path);
        return 0;
    }

    return -2;
}


