#ifndef __LAB2_H__
#define __LAB2_H__

#define ARRAY_LEN	50
#include <stdint.h>
/* new data types */
typedef struct var {
  char n;
  double v;
} matlab_var_t;

typedef struct arr {
  char n;
  double v[ARRAY_LEN];
} matlab_arr_t;

typedef struct{
    uint32_t type;
    uint32_t mrows;
    uint32_t ncols;
    uint32_t imagf;
    uint32_t namelen;
} Fmatrix;


/* global variables, beware */
extern matlab_var_t vars[6];
extern matlab_arr_t arrs[6];


/* function declarations */
int processLine(const char *line);

matlab_var_t *find_var(char var);
matlab_arr_t *find_arr(char var);

int array(char name, double start, double stop);
int show(char name);
int show_vars(void);
int set(char name, double value);
int calc(char r, char x,char y, char op);
int showCSV(const char *filnename);
int importCSV(char var, const char *filename);
int exportCSV(char var, const char *filename);
int printhelp(void);
int exportMAT(char var, const char* filename);
int inlineArithmetic(const char * input);

#endif /* __LAB2_H__ */

