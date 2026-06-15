
#include "bsq.h"
int process_stream(FILE *fp, int newline)
{
    t_map m;
	m.cols = 0;
	m.empty = 0;
	m.full = 0;
	m.grid = NULL;
	m.nlines = 0;
	m.obstacle = 0;
	m.rows = 0;
    if (!read_map(fp, &m) || !validate_map(&m))
    {
        map_error(&m, newline);
        return (1);
    }
    solve(&m);
    print_map(&m);
    if (newline)
        printf("\n");
    free_map(&m);
    return (0);
}

int parse_header(char *line, t_map *m)
{
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[--len] = '\0';

    char e, o, f;
    int  n;
    if (sscanf(line, "%d %c %c %c", &n, &e, &o, &f) != 4 || n <= 0)
        return (0);
    if (e == o || e == f || o == f)
        return (0);

    m->nlines   = n;
    m->empty    = e;
    m->obstacle = o;
    m->full     = f;
    return (1);
}

/* ─── Map reading ─────────────────────────────────────────────── */

int read_map(FILE *fp, t_map *m)
{
    char   *line = NULL;
    size_t  cap  = 0;
    ssize_t len;

    len = getline(&line, &cap, fp);
    if (len <= 0 || !parse_header(line, m))
    {
        free(line);
        return (0);
    }
    free(line);
    line = NULL;
    cap  = 0;

    m->grid = calloc(m->nlines, sizeof(char *));
    if (!m->grid)
        return (0);

    m->rows = 0;
    m->cols = -1;

    while ((len = getline(&line, &cap, fp)) > 0)
    {
        if (line[len - 1] == '\n')
            line[--len] = '\0';
        if (m->rows >= m->nlines)
        {
            free(line);
            return (0);
        }
        if (m->cols == -1)
            m->cols = (int)len;
        else if ((int)len != m->cols)
        {
            free(line);
            return (0);
        }
        m->grid[m->rows++] = line;
        line = NULL;
        cap  = 0;
    }
    free(line);
    return (1);
}
int validate_map(t_map *m)
{
    if (m->rows <= 0 || m->cols <= 0)
        return (0);
    if (m->rows != m->nlines)
        return (0);
    for (int r = 0; r < m->rows; r++)
    {
        for (int c = 0; c < m->cols; c++)
        {
            char ch = m->grid[r][c];
            if (ch != m->empty && ch != m->obstacle)
                return (0);
        }
    }
    return (1);
}
void solve(t_map *m)
{
    if (m->rows == 0 || m->cols == 0)
        return;
    int **dp = calloc(m->rows, sizeof(int *));
    if (!dp)
        return;
    for (int r = 0; r < m->rows; r++)
    {
        dp[r] = calloc(m->cols, sizeof(int));
        if (!dp[r])
        {
            for (int i = 0; i < r; i++)
                free(dp[i]);
            free(dp);
            return;
        }
    }
    int best_size = 0;
    int best_r    = 0;
    int best_c    = 0;
    for (int r = 0; r < m->rows; r++)
    {
        for (int c = 0; c < m->cols; c++)
        {
            if (m->grid[r][c] == m->obstacle)
            {
                dp[r][c] = 0;
                continue;
            }
            int val;
            if (r > 0 && c > 0)
            {
                int top  = dp[r - 1][c];
                int left = dp[r][c - 1];
                int diag = dp[r - 1][c - 1];
                int mn   = top < left ? top : left;
                mn       = mn < diag ? mn : diag;
                val      = mn + 1;
            }
            else
                val = 1;
            dp[r][c] = val;
            if (val > best_size)
            {
                best_size = val;
                best_r    = r;
                best_c    = c;
            }
        }
    }
    if (best_size > 0)
    {
        int top_r = best_r - best_size + 1;
        int top_c = best_c - best_size + 1;
        for (int r = top_r; r <= best_r; r++)
            for (int c = top_c; c <= best_c; c++)
                m->grid[r][c] = m->full;
    }

    for (int r = 0; r < m->rows; r++)
        free(dp[r]);
    free(dp);
}
void print_map(t_map *m)
{
    for (int r = 0; r < m->rows; r++)
        fprintf(stdout, "%s\n", m->grid[r]);
}

void map_error(t_map *m, int newline)
{
    fprintf(stderr, "map error\n");
    if (newline)
        fprintf(stderr, "\n");
    free_map(m);
}

void free_map(t_map *m)
{
    if (m->grid)
    {
        for (int r = 0; r < m->rows; r++)
            free(m->grid[r]);
        free(m->grid);
        m->grid = NULL;
    }
}
int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;

    int ret = 0;
    for (int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");
        if (!fp)
        {
            fprintf(stderr, "map error\n");
            if (i < argc - 1)
                fprintf(stderr, "\n");
            ret = 1;
            continue;
        }
        if (process_stream(fp, argc > 2) != 0)
            ret = 1;
        fclose(fp);
    }
    return (ret);
}