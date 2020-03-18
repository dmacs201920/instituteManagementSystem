#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//////////STURCTURE FOR STUDENT DETAILS//////////////////
typedef struct dob
{ int d;
    int m;
    int y;
}dob;

typedef struct f
{ int amount;
    int sems;
}f;

typedef struct stud
{  int ser;
    char F_name[20];
    char L_name[20];
    int regd_no;
    dob dt;
    int age;
    char gender[10];
    char department[20];
    int yoj;
    f a;
}stud;
///////FUNCTION NAMES FOR STUDENT DETAILS///////////
void display();
void modify();
void fee();
void delete_();
void read_stud();
int count();

//////////////////STRUCTURE FOR FESTIVALS AND EVENTS////////////
typedef struct fest
{ int day;
    int month;
    int year;
    int days;
    char fes[99];
}fest;

///////////////FUNCTION NAMES FOR FESTIVALS AND EVENTS///////////////

void read_fest();
void display_fest();

////////////////////STRUCTURE FOR STUDENT REPORTS /////////////



///////////////////////////////////STRUCTURE FOR TEACHER DETAILS////////////////////////////////////////////
typedef struct name
{
    char in[20];
    char sur[20];
}name;

typedef struct
{
    char firstyr[30];
    char secondyr[30];
    char thirdyr[30];
}subject;

typedef struct 
{  
    int serial;
    name  tname;
    int yoj;
    char dept[20];
    subject even;
    subject odd;
}teacher;
//////////////////////////////FUNCTION NAMES FOR TEACHER DETAILS////////////////////////////////////////////////

int xstrcmp();

void mv2bin();

void dispall();

void  modifyt();

void delt();

///////////////////////STRUCTURE FOR ATHLETICS AND EXTRA CURRICULAR ACTIVITIES/////////////////////////////////

typedef struct champ
{ int regd;
  int track;//no. of track events participated
  int field;//no. of field events participated
  int first;//no. of first places
  int second;//no. of second places
  int third;//no. of third places
}champ;

typedef struct dec
{ int regd;
  int points;
}dec;

////////FUNCTIONS FOR ATHLETIC EVENTS////

void r_sports();
void points();
void champion();

//////////////STUDENTS REPORTS///////////

typedef struct 
{
    float u601;
    float u602;
    float u603;
    float u604;
    float u605;
}cie;

typedef struct 
{
    float cie_a;
    float cie_b;
    float cie_c;
}percent;

typedef struct student_rpt
{   int regd_no;
    cie cie1;
    cie cie2;
    cie cie3;
    float cie[3];
    percent per;
    float fper;
    int rnk;
    int drnk;
    char grd;
}student_rpt;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rpt_updt();

void display_results();

void read_stud();

void display();

void percentage();

void rank();

int gcd(int p, int q);

void ratio();

int  dept_rank(char sub[]);

void dept_mark(int m);
///////////////////////////////student attendance header files and functions////////////////////////////////////
typedef struct atten
{ int regi;
  int pre_days;
}atten;

typedef struct cal
{ int regis;
  int abs_days;
  float percent;
}cal;

void read_attend();
void cal_attend();
void attend();

/////////////////////////password header files and functions/////////////////////
typedef struct password
{ char pass[15];
  int len;
}password;

 void encrypt(char *,char *file);
void  decrypt(char* ,char *file);
int  verify_pass(char *);
































