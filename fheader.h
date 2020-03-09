#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//////////structure for stuent details//////////////////
typedef struct dob
{ int d;
    int m;
    int y;
}dob;

typedef struct f
{ int amount;
    int sems;
}f;

typedef struct student
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
}student;


////////////structure for student details////////////


void display();
void modify();
void fee();
void delete_();
void read_stud();
void count();

//////////////////structure for festivals////////////
typedef struct fest
{ int day;
    int month;
    int year;
    int days;
    char fes[99];
}fest;

///////////////function for events ///////////////

void read_fest();
void display_fest();

////////////////////structure for student report /////////////
typedef struct cie
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
}student_rpt;

////////////////combined /////////////////////////////
typedef struct combined
{
    student_rpt r;
    student s;
} combined;
//////////////////////////////////////function for student report/////////////////////////
void rpt_updt();

void display_results();

void read_stud();

void display();

void percentage();
///////////////////////////////////structure for teacher////////////////////////////////////////////
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
//////////////////////////////function for teacher ////////////////////////////////////////////////

int xstrcmp();

void mv2bin();

void dispall();

void  modifyt();

void delt();


