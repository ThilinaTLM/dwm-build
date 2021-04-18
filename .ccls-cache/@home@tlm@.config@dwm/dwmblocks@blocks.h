// Convert to full path

#define PATH(script) "/home/tlm/.config/dwm/dwmblocks/blocks/" script

//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/             /*Update Interval*/	        /*Update Signal*/
    {"",        "echo ''",                  0,                              0},
    {"",        PATH("mem"),                2,                              2},
    {"",        PATH("sb-clock"),           1,                              3},
    {"",        PATH("vol-amixer"),        10,                             10},
    {"",        PATH("bat"),               10,                             20},
    {"",        PATH("sb-internet"),       10,                              5},
    {"",        "echo ''",                  0,                              0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
