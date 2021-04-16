#ifndef RICE_H
#define RICE_H

typedef union {
	int i;
	unsigned int ui;
	float f;
	const void *v;
} Arg;

int startup_script();
void control_volume(const Arg *arg);
void control_backlight(const Arg *args);
void execute_script(const Arg *args);
#endif
