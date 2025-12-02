#ifndef HISTORY_H
#define HISTORY_H

extern char history[200][200];
extern int history_count;

void add_history(const char *event);
void show_history();

#endif
