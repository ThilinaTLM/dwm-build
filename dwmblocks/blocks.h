// Convert to full path

#define PATH(script) "/home/tlm/.config/dwm/dwmblocks/blocks/" script

//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/             /*Update Interval*/	        /*Update Signal*/
    {"",        "echo ' '",                 0,                              0},
    {"",        PATH("sb-clock"),           1,                              1},
    {"",        PATH("sb-memory"),          2,                              2},
    {"",        "echo ' '",                 0,                              0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
