#ifndef BSQ_H
#define BSQ_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
typedef struct s_map
{
    int     nlines;
    char    empty;
    char    obstacle;
    char    full;
    char  **grid;
    int     rows;
    int     cols;
}   t_map;
int   parse_header(char *line, t_map *m);
int   read_map(FILE *fp, t_map *m);
int   validate_map(t_map *m);
void  solve(t_map *m);
void  print_map(t_map *m);
void  free_map(t_map *m);
void  map_error(t_map *m, int newline);
int   process_stream(FILE *fp, int newline);
#endif
