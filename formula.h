#ifndef __FORMULA_H
#define __FORMULA_H
#define SUBSLEN 10
#define EBUFLEN 128
#define BUFLEN 1024
#define ELECTRON_MASS 0.00054857990924

#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
  char *name;
  char *symbol;
  int atomicNumber;
  int isotopecount;
  int massnumber[10];
  double isotope[10];
  double abundance[10];
  int valence;
} ellist;

typedef struct {
  char **comp;
  int *atomcount;
  int elcount;
} composition;

typedef struct {
  int *data;
  int len;
  double *mass;
} result;

typedef struct {
  char *_formula;
  double *_mass;
  double *_mz;
  double error;
  double errorDa;
  double rdbe;
} output;

// elements
double elementmass(const char *string);
double rdbe(vector<char *> compositions, vector<int> count);
double formulaMass(vector<char *> compositions, vector<int> count);

// compound
double mz(double currentmass, int finalcharge, int currentcharge,
          const char *agentformula, int agentcharge);
int frules(char *string, int countC, int countH, int countO, int countN,
           int countP, int countS, double rdbevalue, vector<char *> rules);

// formula
double *elmass(vector<char *> compositions, int size);
double delta(double measuredMass, double countedMass, const char *units);
void PFG(result *p_result, int elcount, int minimum[], int maximum[],
         double masses[], int *current, double pre_mass, double loMass,
         double hiMass);
void calculation(double currentmass, vector<char *> compositions,
                 int mincount[], int maxcount[], vector<char *> rules,
                 float tolerance = 1, int charge = 0,
                 const char *agentformula = "H", int agentcharge = 1,
                 const char *units = "ppm");
#endif
