
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "rice.h"

const char* CONFIG_DIR      = ".config/dwm";
const char* SCRIPTS_DIR = ".config/dwm/scripts";

const char* AUTOSTART_SCRIPT = "autostart.sh";
const char* VOLUME_CONTROL_SCRIPT = "scripts/volume-control.sh";
const char* BACKLIGHT_CONTROL_SCRIPT = "scripts/backlight-control.sh";

/**
 * Auto run script when dwm start
 */
int startup_script() {

    // grab HOME directory from environment
    char *home;
	if ((home = getenv("HOME")) == NULL)
		return -1;
    
    // autostart file path 
	char *path = ecalloc(1, strlen(home) + strlen(CONFIG_DIR) + strlen(AUTOSTART_SCRIPT) + 3);
    if (sprintf(path, "%s/%s/%s", home, CONFIG_DIR, AUTOSTART_SCRIPT) < 0) {
        free(path);
    }

    // run autostart script 
	if (access(path, X_OK) == 0) {
    	system(path);
        free(path);
        return 0;
    }

    free(path);
    return -2;
}

/**
 * Execute script
 *  .v -> script name
 *        script should be in scripts directory
 */
void execute_script(const Arg *args) {
    // grab HOME directory from environment
    char *home;
	if ((home = getenv("HOME")) == NULL)
		return;

    // abort if .v is null
    if (args->v == NULL) 
        return;

    char *script = ((char **)args->v)[0];

    // abort if script name is NULL
    if (script == NULL) 
        return;

    char *path = ecalloc(1, strlen(home) + strlen(SCRIPTS_DIR) + strlen(script) + 3);
    if (sprintf(path, "%s/%s/%s", home, SCRIPTS_DIR, script) < 0) {
        free(path);
        return;
    }

    // check whether script is exists
    if (access(path, X_OK) != 0) {
        free(path);
        return;
    }

	if (fork() == 0) {
		setsid();
		execvp(path, (char **)args->v);
		fprintf(stderr, "dwm: execvp %s", path);
        free(path);
		perror(" failed");
		exit(EXIT_SUCCESS);
	}
    free(path);
}



/**
 * Control Volume
 *  @action
 *      1 - decrease volume
 *      2 - increase volume
 *      3 - mute or unmute volume
 */
void control_volume(const Arg *args) {
    // grab HOME directory from environment
    char *home;
	if ((home = getenv("HOME")) == NULL)
		return;
    
    char *path = ecalloc(1, strlen(home) + strlen(CONFIG_DIR) + strlen(VOLUME_CONTROL_SCRIPT) + 3);
    if (sprintf(path, "%s/%s/%s", home, CONFIG_DIR, VOLUME_CONTROL_SCRIPT) < 0) {
        free(path);
    }
    
    // check whether script is exists
    if (access(path, X_OK) != 0) {
        free(path);
        return;
    }

    char *action = ecalloc(1, 2);
    sprintf(action, "%d", args->i);
    setenv("DWM_ACTION", action, 1);
    system(path);
    
    free(action);
    free(path);
}


/**
 * Control Backlight
 *  @action
 *      1 - decrease backlight
 *      2 - increase backlight
 */
void control_backlight(const Arg *args) {
    // grab HOME directory from environment
    char *home;
	if ((home = getenv("HOME")) == NULL)
		return;
    
    char *path = ecalloc(1, strlen(home) + strlen(CONFIG_DIR) + strlen(BACKLIGHT_CONTROL_SCRIPT) + 3);
    if (sprintf(path, "%s/%s/%s", home, CONFIG_DIR, BACKLIGHT_CONTROL_SCRIPT) < 0) {
        free(path);
    }
    
    // check whether script is exists
    if (access(path, X_OK) != 0) {
        free(path);
        return;
    }

    char *action = ecalloc(1, 2);
    sprintf(action, "%d", args->i);
    setenv("DWM_ACTION", action, 1);
    system(path);
    
    free(action);
    free(path);
}
