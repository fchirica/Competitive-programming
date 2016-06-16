/* Alin Burta - C.N. "B.P. Hasdeu Buzau */
//da, fur cu nerusinare de la domn prof.
//imi e foarte rusine cu fapta mea

#include <fstream>
#include <string.h>
#define Fin  "dir.in"
#define Fout "dir.out"
#define LGM  3001
#define MaxS 256

using namespace std;

typedef char *TStiva[MaxS];
TStiva ST;
char *Sir;		//Sirul dat
int VF;			//varful stivei
char *Rez[MaxS];        //tablou pentru memorarea solutiilor
int NrSol;              //numarul solutiilor
ofstream g(Fout);
void citire();
void rezolvare();
void afisare();
void init();
void Add(char *s);
char* Del();


int main()
  {
   init();
   citire();
   rezolvare();
   afisare();
   return 0;
  }


void rezolvare()
 {
  int i,j,N;
  int inc, sf, term;

  N=strlen(Sir)-1;
  char *dirC=new char[MaxS];
  //determin directorul radacina si-l introduc in stiva
  dirC[0]='\0';
  i=0;
  while(Sir[i]!='(') dirC[i]=Sir[i], i++;
  dirC[i]='\0';
  Add(dirC);
  //cat timp stiva e nevida
  while(VF)
   {
    term=0;
    if(Sir[i]==')') {Del();i++;continue; }
    if(Sir[i]=='(' && Sir[i]==')') VF--;
    else
     {
      //caut folder
      while(i<=N && !strchr(",(",Sir[i])) i++;
      if(i<N) inc=i,i++;
      else term=1;
      while(i<=N && !strchr(",()",Sir[i])) i++;
      if(i<=N) sf=i;
      else term=1;

      if(!term)
       {
	j=inc+1; while(j<sf) dirC[j-inc-1]=Sir[j],j++; dirC[sf-inc-1]='\0';
	if(strchr("(,",Sir[inc]) && Sir[sf]=='(')
	   {
	    //inserez folderul in stiva
	    Add(dirC);
	    }
	else
	 {
	   //am gasit un nume de fisier
	   if(strcmp(dirC,"")!=0)
	     {
	      //compun calea catre fisier si memorez rezultatul
	      NrSol++;
	      char *tmp=new char[MaxS];
	      char *bkslash="\\";
	      tmp[0]='\0';
	      for(j=1;j<=VF;j++) {strcat(tmp,ST[j]); strcat(tmp,bkslash);}
	      strcat(tmp,dirC);
	      Rez[NrSol]=new char[strlen(tmp)+1];
	      strcpy(Rez[NrSol],tmp);
	     }
	 }
       }
      else Del();
     }
   }
 }

void afisare()
 {
  int i,ok=1;
  char *tmp=new char[MaxS];
  //sortez alfabetic caile gasite

  while(ok)
   {
    ok=0;
    for(i=1;i<NrSol;i++)
      if(strcmp(Rez[i],Rez[i+1])>0)
	{
	 strcpy(tmp,Rez[i]);
	 strcpy(Rez[i],Rez[i+1]);
	 strcpy(Rez[i+1],tmp);
	 ok=1;
	}
   }

  g<<NrSol<<'\n';
  for(i=1;i<=NrSol;i++) g<<Rez[i]<<'\n';
  g.close();
 }


void citire()
 {
  ifstream f(Fin);
  f.get(Sir,3000,'\n');
  f.get();
  f.close();
 }

void init()
 {
  int i;
  Sir=new char[LGM];
  VF=0;
  NrSol=0;
 }

void Add(char *s)
 {
  if(VF<MaxS) VF++, ST[VF]=strdup(s);
 }

char* Del()
 {
  if(VF) {VF--; return ST[VF+1];}
  return NULL;
 }

