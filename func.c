
//////////FUNCTIONS FOR INSTITUTE MANAGEMENT PROGRAM/////////////////

#include"fheader.h"
stud s;
student_rpt r;
char stdname[30];
fest E;
champ c;
dec d;
atten a;
cal ca;
teacher t;
password p;
/////////FUNCTIONS FOR STUDENT DETAILS(ADMINISTRATIVE WORK)////////////////////////////////////////////////////////////////////////////////////////
/////THE FUNCTION DISPLAYS THE STUDENT DETAILS(WRITTEN BY UTSAV RAI(173248))//////////////
void display()
{   int c,i;
    FILE *ft;

    ft=fopen("studentb.txt","r+");
    if(ft==NULL)
    { puts("cannot open the file\n");
	exit(1);
    }
    rewind(ft);
            printf("SERIs.NO\tFIRSTNAME\tLASTNAME\tREGDNO\tDATEOFBIRTH\tAGE\tGENDER\tDEPARTMENT\tYEAROFJOINING\tAMOUNT\tSEMESTER\n");
    { fread(&s,sizeof(s),1,ft);
	while(!feof(ft))
	{ 
	    printf("%d\t%s\t%s\t%d\t%d-%d-%d\t%d\t%s\t%s\t%d\t%d\t%d\n",s.ser,s.F_name,s.L_name,s.regd_no,s.dt.d,s.dt.m,s.dt.y,s.age,s.gender,s.department,s.yoj,s.a.amount,s.a.sems);
	    fread(&s,sizeof(s),1,ft);
	}  
    }
    fclose(ft);
}
/////////THE FUNCTION MODIFIES THE STUDENT DETAILS BASED ON A PARTICULAR CHOICE(EX:NAME,REGD_NO,YEAR OF JOINING,etc)(WRITTEN BY UTSAV-173248)/////////
void modify()
{  
    FILE *ft,*fr;
    int i,choice;

    ft=fopen("studentb.txt","rb+");
    if(ft==NULL)
    { puts("cannot open the file\n");
	exit(1);
    }
    char f_name[30],l_name[30];
    char any='y';
    while(any=='y')
    {
	printf("Enter the first name of the student for modification\n");
	scanf(" %s",f_name);
	printf("Enter the last name of the student for modification\n");
	scanf(" %s",l_name);
	printf("Enter the registration number\n");
	scanf(" %d",&i);
	rewind(ft);
	while((fread(&s,sizeof(s),1,ft))==1)
	{ if ((strcmp(s.F_name,f_name))==0 && (strcmp(s.L_name,l_name))==0)
	    { if(s.regd_no==i)
		printf("WHAT YOU WANT TO MODIFY?\n");
		printf("1)FIRST_NAME\n");
		printf("2)LAST_NAME\n");
		printf("3)REGISTRAION NUMBER\n");
		printf("4)DATE_OF_BIRTH(dd/mm/yy)\n");
		printf("5)AGE\n");
		printf("6)GENDER\n");
		printf("7)DEPARTMENT\n");
		printf("8)YEAR_OF_JOINING\n");
		scanf("%d",&choice);
		switch(choice)
		 { 
		     case 1:
			    printf("ENTER THE FIRST NAME:");
			    scanf("%s",s.F_name);
			    break;

		    case 2:
			    printf("ENTER THE LAST NAME:");
			    scanf("%s",s.L_name);
			    break;

		    case 3:
		           printf("ENTER THE REGISTRATION NUMBER:");
			   scanf("%d",&s.regd_no);
			   break;

		    case 4:
		           printf("ENTER THE DATE OF BIRTH:");
			   scanf("%d %d %d",&s.dt.d,&s.dt.m,&s.dt.y);
			   break;

		    case 5:
		           printf("ENTER THE AGE:");
			   scanf("%d",&s.age);
			   break;

	            case 6:
		           printf("ENTER THE GENDER:");
			   scanf("%s",s.gender);
			   break;

	            case 7:
			   printf("ENTER THE DEPARTMENT:");
			   scanf("%s",s.department);
			   break;

	            case 8:
			   printf("ENTER YEAR OF JOINING:");
			   scanf("%d",&s.yoj);
			   break;

	            default:
			    printf("wrong option\n");
	      }
		fseek(ft,-1*sizeof(s),1);
		fwrite(&s,sizeof(s),1,ft);
		break;
	}
      }
	printf("Modify any other record(y/n):");
	any=getchar();
    }
    fclose(ft);
}

//////////FUNCTION FOR THE SUBMISSIION OF FEES AND ITS MODIFICATIONS FOR EACH STUDENT///////////////////////////////
///////KEEPS RECORDS FOR EACH SEMESTER FEES AND FEE FOR EACH SEMESTER IS TAKEN TO BE RS.10000////////////////////////
////////(WRITTEN BY :UTSAV RAI(173248))////////////////////////////////////////////////////////////////
void fee()
{  
    FILE *ft;

    ft=fopen("studentb.txt","rb+");
    if(ft==NULL)
    { puts("cannot open the file\n");
	exit(1);
    }

    char any='y';
    int amt, sem,take,i;

    rewind(ft);

    while(any=='y')
    {
	printf("Enter the name of the combined for updating his fee submission:");
	scanf("%s",stdname);
	printf("\n");
	printf("Enter the registration number:");
	scanf("%d",&i);
	printf("\n");
	while((fread(&s,sizeof(s),1,ft))==1)
	{ 
	    if((strcmp(s.F_name,stdname))==0)
	    { 
		if(s.regd_no==i)
		{ if(s.a.amount==0 && s.a.sems==0)/////IF THE STUDENT IS PAYING FOR THE 1ST SEMESTER/////////
		    { 
			printf("Please pay the fee for the 1st sems i.e, Rs.10000\n");
			scanf(" %d",&amt);
			s.a.amount=10000;
			take=amt-10000;
			printf("please take the cash back:%d\n",take);
			s.a.sems=1;
			fseek(ft,-1*sizeof(s),1);
			fwrite(&s,sizeof(s),1,ft);
			break;
		    }
		    else if(s.a.sems>0)//////IF STUDENT IS PAYING FOR THE SEMESTERS OTHER THAN 1ST SEMESTER///////
		    { 
			printf("Enter the fee:");
			scanf("%d",&amt);
			printf("The required amount for which semester?\n");
			scanf(" %d",&sem);
			if(sem==s.a.sems)
			{ 
			    printf("The amount has been already paid for the chosen semester\n");
			    break;
			}
			if(s.a.sems==6)/////IF THE FEE SUBMISSION FOR ALL THE 6 SEMESTERS IS COMPLETE//////////
			{ 
			    printf("You have already paid the fee for all the semesters...THANK YOU:-)\n");
			    break;
			}
			else
			{ 
			    if(amt==10000)
			    { 
				s.a.amount=s.a.amount+10000;
				s.a.sems+=1;
				printf("Thank you for the payment\n");
				fseek(ft,-1*sizeof(s),1);
				fwrite(&s,sizeof(s),1,ft);
				break;
			    }
			    else if(amt<10000)
			    { 
				printf("The amount you are paying for the semester is not sufficient as per rules\n");
				break;
			    }
			    else if(amt>10000)
			    {
				s.a.amount=s.a.amount+10000;
				s.a.sems+=1;
				take=amt-10000;
				printf("please take back the required s. back:%d\n",take);
				printf("Thank you for the payment\n");
				fseek(ft,-1*sizeof(s),1);
				fwrite(&s,sizeof(s),1,ft);
				break;
			    }
			}
		    }
		}
	    }
	}
	getchar();
	printf("modify any other record\n");
	scanf(" %c",&any);
    }
    fclose(ft);
}
//////////FUNCTION FOR DELETING THE DETAILS OF THE STUDENT////////////////////////
/////////WRITTEN BY:UTSAV RAI-173248///////////////////////////////////////////
void delete_()
{ 
    FILE *ft,*fs,*fe;;
    int i;
    ft=fopen("studentb.txt","rb+");
    fe=fopen("student.txt","w+");
    if(ft==NULL)
    { 
	puts("cannot open the file\n");
	exit(1);
    }

    char any='y';

    while(any=='y')
    { 
	printf("Enter the name of the combined to be deleted\n");
	scanf(" %s",stdname);
	printf("Enter the registration number:");
	scanf("%d",&i);
	fs=fopen("temp.txt","w+");
	rewind(ft);
	while((fread(&s,sizeof(s),1,ft))==1)
	{ 
	    if (strcmp(s.F_name,stdname)!=0)
	    {  if(s.regd_no==i)
		  fwrite(&s,sizeof(s),1,fs);
	    }
	}
	fclose(ft);
	fclose(fs);
	remove("studentb.txt");/////REMOVES THE FILE THAT CONTAINS DETAILS OF A STUDENT ENTERED FOR DELETION///////
	rename("temp.txt","studentb.txt");/////RENAMES THE FILE////////////
	ft=fopen("studentb.txt","r+");
	printf("Delete any other record(y/n)\n");
	scanf(" %c",&any);
    }
    fclose(ft);
}
////////FUNCTION FOR READING STUDENT DETAILS FROM THE TEXT FILE TO THE BINARY FILE///////////////////
////////READS THE DETAILS FROM A TEXT FILE AND FURTHER THE PROCESS WORKS ON THE BINARY FILE///////////
////////WRITTEN BY UTSAV RAI:173248//////////////////////////////////////////////////////////
void read_stud()
{ 
    FILE *fs,*ft;
    char a[400];

    ft=fopen("studentb.txt","w+");
    if(ft==NULL)
    { 
	puts("cannot open the file\n");
	exit(1);
    }

    fs=fopen("student.txt","r+");
    if(fs==NULL)
    {
	puts("no fs\n");
	exit(1);
    }

     fgets(a,400,fs);
    fscanf(fs,"%d",&s.ser);
    while(!feof(fs))
    {
	fscanf(fs,"%s",s.F_name);
	fscanf(fs,"%s",s.L_name);
	fscanf(fs,"%d",&s.regd_no);
	fscanf(fs,"%d %d %d",&s.dt.d,&s.dt.m,&s.dt.y);
	fscanf(fs,"%d",&s.age);
	fscanf(fs,"%s",s.gender);
	fscanf(fs,"%s",s.department);
	fscanf(fs,"%d",&s.yoj);
	fscanf(fs,"%d",&s.a.amount);
	fscanf(fs,"%d",&s.a.sems);
	fwrite(&s,sizeof(s),1,ft);
	fscanf(fs,"%d",&s.ser);
    }
    fclose(ft);
    fclose(fs);
}


/////////////FUNCTION FOR COUNTING THE NUMBER OF STUDENTS//////////////////////////
////////////WRITTEN BY:UTSAV RAI-173248////////////////////////////////
int count()
{  
    FILE *ft;

    ft=fopen("studentb.txt","rb+");
    if(ft==NULL)
    { 
	puts("cannot open the file\n");
	exit(1);
    }

    int count=0; 
    rewind(ft);
    while((fread(&s,sizeof(s),1,ft))==1)
    {
	count++;
    }
    printf("The number of students:%d\n",count);
    return count;
    fclose(ft);
}
///////////FUNCTION RELATING TO THE FESTIVALS AND EVENTS IN THE INSTITUTE////////////////////////////////////////////

////////////THE FUNCTION READS THE FESTIVALS AND EVENTS //////////////////////////////////////////////////////////
/////WRITTEN BY:UTSAV RAI(173248)////////////////////
void read_fest()
{  
    FILE *fe,*fd;
    fe=fopen("event.txt","r+");
    if(fe==NULL)
    { 
	puts("cannot open the file\n");
	exit(1);
    }

    fest E;
    char s[1000];   

    fd=fopen("eventb.txt","w");
    fseek(fe,0,0);
    fgets(s,999,fe);

    fscanf(fe,"%d",&E.day);
    while(!feof(fe))
    { 
	fscanf(fe,"%d",&E.month);
	fscanf(fe,"%d",&E.year);
	fscanf(fe,"%d",&E.days);
	fgets(E.fes,98,fe);
	// fscanf(fe,"%s",E.fes);//
	fwrite(&E,sizeof(fest),1,fd);
	fscanf(fe,"%d",&E.day);
    }
    fclose(fd);
    fclose(fe);
}

///////////THE FUNCTION DISPLAYS THE FESTIVALS WITH THREE CHOICES:1)FOR THE ENTIRE ACADEMIC YEAR,2)FOR A PARTICULAR MONTH && 3)FOR A PARTICUALR DATE/////////////////////////////BASED ON THE NUMBER OF DAYS THE FESTIVAL IS CELEBRATED ,IT CALCULATES THE TILL WHICH DATE AND MONTH IT CONTINUES////////
///////////////////WRITTTEN BY:UTSAV RAI(173248)////////////////////////////////////////////////////////
void display_fest()
{  
    FILE *fd;
    fd=fopen("eventb.txt","r");
    if(fd==NULL)
    {
	puts("cannot open fd\n");
	exit(1);
    }

    fest E;
    int choice,d1,d2,d3,m1,m2,m3; 
    fseek(fd,0,0);
    printf("1)DISPLs. FESTIVc.s.S FOR THE ENTIRE YEAR\n2)DISPLAY FESTIVAL FOR A PARTICULAR MONTH\n3)DISPLAY FESTIVAL FOR A PARTICULAR DAY\n");
    scanf("   %d",&choice);
    switch(choice)
    { case 1:
	fread(&E,sizeof(fest),1,fd);	   
	printf("VArIOUS festivals IN OUR INSTITUTE:\n");
	while(!feof(fd))
	{ printf("					%d-%d-%d(%ddays):%s\n",E.day,E.month,E.year,E.days,E.fes); 
	    fread(&E,sizeof(fest),1,fd);
	}
	break;
	case 2:
	printf("ENTER THE MONTH FOR WHICH YOU Ws.T TO CHECK FESTIVc.s.S\n");
	scanf(" %d",&m3);
	fread(&E,sizeof(fest),1,fd);
	while(!feof(fd))
	{ if(E.month==m3)
	    { if(E.days>1)
		{ d1=E.day+E.days;
		    if(E.month==1 || E.month==3 || E.month==5 || E.month==7 || E.month==8 || E.month==10 || E.month==12)
		    {if(d1>31)
			{ d1=d1-31;
			    m1=E.month+1;
			}
			else
			{d1=d1;
			    m1=E.month;
			}

		    }
		    else if( E.month==4 || E.month==6 || E.month==9 || E.month==11)
		    { if (d1>30)
			{ d1=d1-30;
			    m1=E.month+1;
			}
			else
			{d1=d1;
			    m1=E.month;
			}
		    }
		    else if(E.month==2)
		    { if(E.year%100==0)
			{ if(E.year%400==0)
			    { if(d1>29)
				{ d1=d1-29;
				    m1=E.month+1;
				}
				else
				{d1=d1;
				    m1=E.month;
				}
			    }
			} 
			else if(E.year%100==0 && E.year%400!=0)
			{ if(d1>28)
			    { d1=d1-28;
				m1=E.month+1;
			    }
			    else
			    {d1=d1;
				m1=E.month;
			    }
			}
			else if(E.year%4==0)
			{ if(d1>29)
			    { d1=d1-29;
				m1=E.month+1;
			    }
			    else
			    {d1=d1;
				m1=E.month;
			    }
			}  
		    }
		    printf("					%d-%d-%d TO %d-%d-%d:%s\n",E.day,E.month,E.year,d1,m1,E.year,E.fes);
		}
		else
		    printf("					            %d-%d-%d:%s\n",E.day,E.month,E.year,E.fes);
	    }

	    fread(&E,sizeof(fest),1,fd);

	}
	break;

	case 3:
	printf("ENTER THE Ds.E\n");
	scanf(" %d",&d2);
	fread(&E,sizeof(fest),1,fd);
	while(!feof(fd))
	{ if(E.day==d2)
	    {if(E.days>1)
		{ d3=E.day+E.days;
		    if(E.month==1 || E.month==3 || E.month==5 || E.month==7 || E.month==8 || E.month==10 || E.month==12)
		    {if(d3>31)
			{ d3=d3-31;
			    m2=E.month+1;
			}
			else
			{d3=d3;
			    m2=E.month;
			}
		    }
		    else if( E.month==4 || E.month==6 || E.month==9 || E.month==11)
		    { if (d3>30)
			{ d3=d3-30;
			    m2=E.month+1;
			}
			else
			{d3=d3;
			    m2=E.month;
			}
		    }
		    else if(E.month==2)
		    { if(E.year%100==0)
			{ if(E.year%400==0)
			    { if(d3>29)
				{ d3=d3-29;
				    m2=E.month+1;
				}
				else
				{d3=d3;
				    m2=E.month;
				}
			    }
			}
			else if(E.year%100==0 && E.year%400!=0)
			{ if(d3>28)
			    {d3=d3-28;
				m2=E.month+1;
			    }
			    else
			    {d3=d3;
				m2=E.month;
			    }
			}
			else if(E.year%4==0)
			{ if(d3>29)
			    { d3=d3-29;
				m2=E.month+1;
			    }
			    else
			    {d3=d3;
				m2=E.month;
			    }
			}
		    }

		    printf("					%d-%d-%d TO %d-%d-%d:%s\n",E.day,E.month,E.year,d3,m2,E.year,E.fes);
		}
		else 
		    printf("					            %d-%d-%d:%s\n",E.day,E.month,E.year,E.fes);
	    }

	    fread(&E,sizeof(fest),1,fd);
	} 
	break;

    }
    fclose(fd);
}




//////////////////FUNCTION FOR TEACHER DETAILS ///////////////////////////////////////////////////////////////////////


char another,tchr[40];

////FUNCTION FOR READING TEACHER'S DETAILS//////////////
///////WRITTEN BY:DEBASIS DAS(173238)//////////////////
void mv2bin()
{ 
    teacher t; 
    FILE *fb,*fp;


    fb=fopen("teacher_main.txt","r+");
    if(fb==NULL)
    {
	puts("cannot open the file\n");
	exit(1);
    }

    fp=fopen("bin_teacher.txt","w+");
    if(fp==NULL)
    {
	puts("cannot open the file\n");
	exit(1);
    }


    char line[200];
    for(int i=1;i<=6;i++)
    {
	fgets(line,200,fb);
    }

    fscanf(fb,"%d",&t.serial);
    while(!feof(fb))
    {
	fscanf(fb,"%s",t.tname.in);
	fscanf(fb,"%s",t.tname.sur);
	fscanf(fb,"%d",&t.yoj);
	fscanf(fb,"%s",t.dept);
	fscanf(fb,"%s",t.even.firstyr);
	fscanf(fb,"%s",t.odd.firstyr);
	fscanf(fb,"%s",t.even.secondyr);
	fscanf(fb,"%s",t.odd.secondyr);
	fscanf(fb,"%s",t.even.thirdyr);
	fscanf(fb,"%s",t.odd.thirdyr);
	fwrite(&t,sizeof(t),1,fp);	
	fscanf(fb,"%d",&t.serial);
    }
    fclose(fp);
    fclose(fb);

}
/////////////////FUNCTION DISPLAYS TEACHER DETAILS BY READING FROM THE FILE///////////
/////////////WRITTEN BY:DEBASIS DAS && MODIFIED BY:UTSAV RAI(173248)////////////////////
void dispall()
{
    FILE *fp;

    fp=fopen("bin_teacher.txt","rb+");
    if(fp==NULL)
    {
	puts("cannot open the file\n");
	exit(1);
    }

    teacher t;
    char s[40];
    int choice;
    char another='y';

    printf("<=============================Enter the option===========================>\n");
    printf("+--------------------------------------------------+\n");
    printf("|        1.Display all the teacher's details       |\n");
    printf("|        2.Display specific teacher's detsils      |\n");
    printf("+--------------------------------------------------+\n");
    scanf("     %d",&choice);
    switch(choice)
    {
	case 1:
	    rewind(fp);
	    fread(&t,sizeof(t),1,fp);
	    while(!feof(fp))
	    {
		printf("TEACHER'S NAME=====================>>%s %s\n",t.tname.in,t.tname.sur);
		printf("YEAR OF JOINING====================>>%d\n",t.yoj);
		printf("DEPARTMENT=========================>>%s\n",t.dept);
		printf("SUBJECT OF TEACHING TO THE FIRST YEAR STUDENTS---------EVENSEMS:%s---------ODDSEMS:%s\n",t.even.firstyr,t.odd.firstyr);
		printf("SUBJECT OF TEACHING TO THE SECOND YEAR STUDENTS--------EVENSEMS:%s---------ODDSEMS:%s\n",t.even.secondyr,t.odd.secondyr);
		printf("SUBJECT OF TEACHING TO THE THIRD YEAR STUDENTS---------EVENSEMS:%s---------ODDSEMS:%s\n",t.even.thirdyr,t.odd.thirdyr);
		fread(&t,sizeof(t),1,fp);
	    }
	    break;
	case 2:
	    rewind(fp);
	    another='y';
	    while(another=='y')
	    {
		printf("ENTER THE TEACHER'S NAME:");
		scanf("%s",s);

		//fread(&t,sizeof(t),1,fp);
		while((fread(&t,sizeof(t),1,fp))==1)
		{
		    if((strcmp(t.tname.in,s))==0)
		    {
			printf("TEACHER'S NAME=====================>>%s %s\n",t.tname.in,t.tname.sur);
			printf("YEAR OF JOINING====================>>%d\n",t.yoj);
			printf("DEPARTMENT=========================>>%s\n",t.dept);
			printf("SUBJECT OF TEACHING TO THE FIRST YEAR STUDENTS---------EVENSEMS:%s---------ODDSEMS:%s\n",t.even.firstyr,t.odd.firstyr);
			printf("SUBJECT OF TEACHING TO THE SECOND YEAR STUDENTS--------EVENSEMS:%s---------ODDSEMS:%s\n",t.even.secondyr,t.odd.secondyr);
			printf("SUBJECT OF TEACHING TO THE THIRD YEAR STUDENTS---------EVENSEMS:%s---------ODDSEMS:%s\n",t.even.thirdyr,t.odd.thirdyr);

		    }
		    getchar();
		}
		    printf("Continue your search 'y' or 'n'?\n");
		    scanf(" %c",&another);
             }
		break;

	    fclose(fp);
    }
}  
//function Modifies teacher's details//
////WRITTEN BY DEBASIS DAS(173238)//////////////

void modifyt()
{
    teacher t;
    FILE *fp;

    fp=fopen("bin_teacher.txt","rb+");
    if(fp==NULL)
    {
	puts("cannot open the file\n");
	exit(1);
    }

    char another='y';
    while(another=='y')
    {
	int choice;
	printf("ENTER THE FIRST NAME OF THE TEACHER TO MODIFY\n");
	scanf(" %s",tchr);
	rewind(fp);
	fread(&t,sizeof(t),1,fp);
	while(!feof(fp))
	{
	    if(strcmp(t.tname.in,tchr)==0)
	    {
		printf("Choose what you want to change\n");
		printf("1.Name\n2.Year of joining\n3.Department\n");
		printf("4.Subject teaching in the 1st student\nEven sem\n");
		printf("5.Subject teaching in the 1st student\nOdd sem\n");
		printf("6.Subject teaching in the 2nd student\nEven sem\n");
		printf("7.Subject teaching in the 2nd student\nOdd sem\n");
		printf("8.Subject teaching in the 3rd student\nEven sem\n");
		printf("9.Subject teaching in the 3rd student\nOdd sem\n");
		scanf("%d",&choice);
		switch(choice)
		{

		    case 1:
			printf("Enter the teacher's name(initial and surname also)\n");
			scanf("%s%s",t.tname.in,t.tname.sur);
			break;
		    case 2:
			printf("Year of joining\n");
			scanf("%d",&t.yoj);
			break;
		    case 3:
			printf("Department\n");
			scanf("%s",t.dept);
			break;
		    case 4:
			printf("Subject teaching in the 1st student\nEven sem\n");
			scanf("%s",t.even.firstyr);
			break;
		    case 5:
			printf("Subject teaching in the 1st student\nOdd sem\n");
			scanf("%s",t.odd.firstyr);
			break;
		    case 6:
			printf("Subject teaching in the 2nd student\nEven sem\n");
			scanf("%s",t.even.secondyr);
			break;
		    case 7:
			printf("Subject teaching in the 2nd student\nOdd sem\n");
			scanf("%s",t.odd.secondyr);
			break;
		    case 8:
			printf("Subject teaching in the 3rd student\nEven sem\n");
			scanf("%s",t.even.thirdyr);
			break;
		    case 9:
			printf("Subject teaching in the 3rd student\nOdd sem\n");
			scanf("%s",t.odd.thirdyr);
			break;
		    default :
			printf("invalid option\n");
		}
		fseek(fp,-sizeof(t),1);
		fwrite(&t,sizeof(t),1,fp);
		break;
	    }
	    fread(&t,sizeof(t),1,fp);
	}
	printf("Modify another teacher's details?'y' or 'n'\n");
	scanf(" %c",&another);
    }
    fclose(fp);
}

//Delete function for teacher //////////
//WRITTEN BY UTSAV RAI(173248//////////////
void delt()
{
    teacher t;
    FILE *fp, *ft;

    fp=fopen("bin_teacher.txt","r");
    if(fp==NULL)
    {
	puts("cannot open the file\n");
	exit(1);
    }

    another='y';
    while(another=='y')
    {
	printf("Enter the teacher's name to be deleted\n");
	scanf(" %s",tchr);
	ft=fopen("sample.txt","w");
        rewind(ft);
	if(ft==NULL)
	    printf("Error opening file");
	while((fread(&t,sizeof(t),1,fp))==1)
	{  
	    if(strcmp(t.tname.in,tchr)!=0)
		fwrite(&t,sizeof(t),1,ft);

	}
	fclose(fp);
	fclose(ft);
        remove("bin_teacher.txt");
	rename("sample.txt","bin_teacher.txt");
	fp=fopen("bin_teacher.txt","r+");
	printf("delete another teacher file ?'y' or 'n'\n");
	scanf(" %c", &another);
    }
    fclose(fp);
}

////////FUNCTION FOR ATHLETIC EVENTS AND CHAMPIONSHIP/////////////
/////FUNCTION READS THE DETAILS OF THE ATHLETES RECORDS IN ATHLETIC EVENTS/////////
//WRITTEN BY:UTSAV RAI(173248)/////////////////////////
void r_sports()
{ FILE *ft,*fb;
    char s[999];
    ft=fopen("champ.txt","r+");
    fb=fopen("b.txt","w+");
    fgets(s,999,ft);
    fscanf(ft,"%d",&c.regd);
    while(!feof(ft))
    { fscanf(ft,"%d",&c.track);
	fscanf(ft,"%d",&c.field);
	fscanf(ft,"%d",&c.first);
	fscanf(ft,"%d",&c.second);
	fscanf(ft,"%d",&c.third);
	fwrite(&c,sizeof(c),1,fb);
	fscanf(ft,"%d",&c.regd);
    }
    fclose(ft);
    fclose(fb);
}
//////////////FUNCTION CALCULATES THE POINTS FOR EACH ATHLETE IN THE INSTITUTE BY READING THE DETAILS////////////
//WRITTEN BY:UTSAV RAI(173248)////////////////////////////////////////////
void points()
{ FILE *fb,*fr;
    fb=fopen("b.txt","r+");
    fr=fopen("point.txt","w+");
    rewind(fb);
    fread(&c,sizeof(c),1,fb);
    while(!feof(fb))
    { printf("+======================================================================+\n");
      printf("|REGDNO:%d(TRACK:%d,FIELD:%d,1st PLACES:%d,2nd PLACES:%d,3rd PLACES:%d)|\n",c.regd,c.track,c.field,c.first,c.second,c.third);
      printf("+======================================================================+\n");
	d.regd=c.regd;
	if((c.first+c.second+c.third)>5 || c.first>5 || c.second>5 || c.third>5 || (c.first+c.second+c.third)>(c.track+c.field) )
	{ printf("THE PLACES IS EXCEEDING THE NUMBER OF EVENTS THAT A STUDENT IS ALLOWED TO PARTICIPATE\n");
	    exit(-1);
	}
	d.points=((5*c.first)+(3*c.second)+(1*c.third));
	fwrite(&d,sizeof(d),1,fr);
	fread(&c,sizeof(c),1,fb);
    }
    printf("INITIAL ORDER OF THE POINTS:\n");
    rewind(fr);
    fread(&d,sizeof(d),1,fr);
    while(!feof(fr))
    { printf("+==========================+\n");
      printf("|REGDNO:%d------->POINTS:%d|\n",d.regd,d.points);
      printf("+==========================+\n");
	fread(&d,sizeof(d),1,fr);
    }
    fclose(fb);
    fclose(fr);
}
//////////////////FUNCTION SORTS THE INDIVIDUALS BASED ON THE POINTS AND DECLARES ATHLETIC CHAMPION///////////////////////
//WRITTEN BY:UTSAV RAI(173248)////////////////////////////
void champion()
{   FILE *fr,*fb;
    fr=fopen("point.txt","r+");
    fb=fopen("b.txt","r+");
    rewind(fr);
    int n=0,i=0,j,pos;
    while((fread(&d,sizeof(d),1,fr))>0)
    { n++;
    }
    int a[n],t;
    rewind(fr);
    while((fread(&d,sizeof(d),1,fr))>0)
    {a[i]=d.points;
	i++;
    }
    for(i=0;i<n;i++)
    { for(j=0;j<n-i-1;j++)
	{  if(a[j]>a[j+1])
	    { t=a[j];
		a[j]=a[j+1];
		a[j+1]=t;
	    }
	}
    }

    rewind(fb);
    fread(&c,sizeof(c),1,fb);
    while(!feof(fb))
    {   printf("+======================================================================+\n");
	printf("|REGDNO:%d(TRACK:%d,FIELD:%d,1st PLACES:%d,2nd PLACES:%d,3rd PLACES:%d)|\n\n",c.regd,c.track,c.field,c.first,c.second,c.third);
	printf("+======================================================================+\n");
	fread(&c,sizeof(c),1,fb);
    }
    printf("INITIAL ORDER OF THE POINTS:\n");
    fread(&d,sizeof(d),1,fr);
    while(!feof(fr))
    {   printf("+==========================+\n");
	printf("|REGDNO:%d------->POINTS:%d|\n",d.regd,d.points);
	printf("+==========================+\n");
	fread(&d,sizeof(d),1,fr);
    }

    printf("AFTER SORTING THE POINTS:\n");
    for(i=0;i<=n-1;i++)
	printf("(%d)",a[i]);
    printf("\n");
    rewind(fr);
    while((fread(&d,sizeof(d),1,fr))>0)
    { if(a[n-1]==d.points)
	{   printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
	    printf("|THE STUDENT WITH THE REGISTRAION NUMBER:(%d)IS THE ATHLETIC CHAMPION OF THE ACADEMIC YEAR 2019-2020 WITH THE HIGHEST POINTS:(%d)|\n",d.regd,d.points);
	    printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
	} 
    }
    fclose(fb);
    fclose(fr);
}


/////////////////////STUDENT RESULTS/////////////////////////////////////////////////

/////////////READS THE MARKS FROM THE FILE/////////////////////
//WRITTEN BY:DEBASIS DAS(173248)///////////////////////
void rpt_updt()
{
    FILE *fs,*fr;

 fs=fopen("student_marks.txt","r+");
if(fs==NULL)
{
    puts("no fs\n");
    exit(1);
}

fr=fopen("markb.txt","rb+");
if(fr==NULL)
{
    puts("no fr\n");
    exit(1);
}

float a,b,d;
char line[200];

fgets(line,199,fs);
    fscanf(fs,"%d",&r.regd_no);
while(!feof(fs))
{
    fscanf(fs,"%f",&r.cie1.u601);
    fscanf(fs,"%f",&r.cie2.u601);
    fscanf(fs,"%f",&r.cie3.u601);
    fscanf(fs,"%f",&r.cie1.u602);
    fscanf(fs,"%f",&r.cie2.u602);
    fscanf(fs,"%f",&r.cie3.u602);
    fscanf(fs,"%f",&r.cie1.u603);
    fscanf(fs,"%f",&r.cie2.u603);
    fscanf(fs,"%f",&r.cie3.u603);
    fscanf(fs,"%f",&r.cie1.u604);
    fscanf(fs,"%f",&r.cie2.u604);
    fscanf(fs,"%f",&r.cie3.u604);
    fscanf(fs,"%f",&r.cie1.u605);
    fscanf(fs,"%f",&r.cie2.u605);
    fscanf(fs,"%f",&r.cie3.u605);

    fwrite(&r,sizeof(r),1,fr);
    fscanf(fs,"%d",&r.regd_no);
}
fclose(fs);
fclose(fr);
}

////////////CALCULATES THE PERCENTAGE OF THE STUDENT MARKS FOR REACH CIE//////////////////////
//////WRITTEN BY:DEBASIS DAS(173238)//////////////////////////////////////////////
void percentage()
{
    FILE *fr;
    fr=fopen("markb.txt","rb+");
    if(fr==NULL)
    {
        puts("no fr\n");
        exit(1);
    }

    int pos;
    float a,b,d;
    pos=ftell(fr);
    fread(&r,sizeof(r),1,fr);
    while(!feof(fr))
    {
        a=((r.cie1.u601+r.cie1.u602+r.cie1.u603+r.cie1.u604+r.cie1.u605)/125);
        r.per.cie_a=a*100;

        b=((r.cie2.u601+r.cie2.u602+r.cie2.u603+r.cie2.u604+r.cie2.u605)/125);
        r.per.cie_b=b*100;

        d=((r.cie3.u601+r.cie3.u602+r.cie3.u603+r.cie3.u604+r.cie3.u605)/250);
        r.per.cie_c=d*100;

        // total percentage//
        r.fper=(r.per.cie_a+r.per.cie_b+r.per.cie_c)/3;

       //greade//
        if(r.fper>=90)
            r.grd='A';
        else if(r.fper>=80 && r.fper<90)
            r.grd='B';
        else if(r.fper>=70 && r.fper<80)
            r.grd='C';
        else if(r.fper>=60 && r.fper<70)
            r.grd='D';
        else if(r.fper>=50 && r.fper<60)
            r.grd='E';
        else 
            r.grd='F';

        fseek(fr,pos,0);
        fwrite(&r,sizeof(r),1,fr);
        pos=ftell(fr);
        fread(&r,sizeof(r),1,fr);
    }
    fclose(fr);
}


/////////////////////FUNCTION DISPLAYS RESULTS///////////////////////////
/////BASED ON RANK AND MAKKS/////////////////////////////
//WRITTEN BY:DEBASIS DAS (173238) && UTSAV RAI(173248)////////////////////
void display_results()
{   
    FILE *ft,*fr;

    ft=fopen("studentb.txt","rb+");
    if(ft==NULL)
    {
        puts("cannot open the file ft\n");
        exit(1);
    }

    fr=fopen("markb.txt","rb+");
    if(fr==NULL)
    {
        puts("no fr\n");
        exit(1);
    }

    int choice;
    char another='y',u[4];
    int regno;
    while(another=='y')
    {
        printf("enter the registration number to display the results\n");
        scanf("%d",&regno);
        //fread(&r.zeof(combined),1,ft);
        rewind(ft);
        rewind(fr);
        //while(!feof(ft))
        while((fread(&s,sizeof(s),1,ft))>0)
        {
            if(regno==s.regd_no)
            {
                printf("Name=%s %s\n",s.F_name,s.L_name);
                printf("Regd No.=%d\n",s.regd_no);
                printf("Department=%s\n",s.department);
                break;
            }
        }      

        while((fread(&r,sizeof(r),1,fr))>0)
        {
            if(regno==r.regd_no)
            {
                printf("     SUB CODE          CIE-1           CIE-2           CIE-3       \n");
                printf("     --------          -----           -----           -----       \n");
                printf("     UMAT-601            %f              %f              %f        \n",r.cie1.u601,r.cie2.u601,r.cie3.u601);
                printf("     UMAT-602            %f              %f              %f        \n",r.cie1.u602,r.cie2.u602,r.cie3.u602);
                printf("     UMAT-603            %f              %f              %f        \n",r.cie1.u603,r.cie2.u603,r.cie3.u603);
                printf("     UMAT-604            %f              %f              %f        \n",r.cie1.u604,r.cie2.u604,r.cie3.u604);
                printf("     UMAT-605            %f              %f              %f        \n",r.cie1.u605,r.cie2.u605,r.cie3.u605);
                printf("     PERCENTAGE-         %f              %f              %f        \n",r.per.cie_a,r.per.cie_b,r.per.cie_c);
                printf("TOTAL PERCENTAGE=%f\n",r.fper);
                printf("GRADE=%c\n",r.grd);
		break;
            }
        }

        printf("want to see another student's mark\n");
        scanf(" %c",&another);
    }
    fclose(ft);
    fclose(fr);
}

///////////////FUNCTION CALCULATES THE STUDENT TEACHER RATIO////////////////////////
//WRITTEN BY:DEBASIS DAS(173238) && MODIFIED BY:UTSAV RAI(173248)///
int gcd(int p,int q)
{
    int r;
    while (q>0)
    {
        r=p%q;
        p=q;
        q=r;
    }
    return p;
}

void ratio()
{
    FILE *ft,*fp;

    ft=fopen("studentb.txt","rb+");
    if(ft==NULL)
    {
        puts("cannot open the file ft\n");
        exit(1);
    }

    fp=fopen("bin_teacher.txt","rb+");
    if(fp==NULL)
    {
	    puts("cannot open the file\n");
	    exit(1);
    }

    int x=0,y=0,temp;
    
    while((fread(&s,sizeof(s),1,ft))>0)
        x++;

    while((fread(&t,sizeof(t),1,fp))>0)
    {
        y++;
    }

    while((temp=gcd(x,y))!=1)
    {
        x=x/temp;
        y=y/temp;
    }

    printf("STUDENT TEACHER RATIO =%d : %d\n",x,y);
    fclose(ft);
    fclose(fp);
    
}

//////FUNCTION THAT DECIDES THE RANK OF A STUDENT BASED ON SORTING//////////////////////////////
//////WRITTEN BY:DEBASIS DAS(173238)/////////////////////////////////
void rank()
{
    FILE *fr;
    fr=fopen("markb.txt","rb+");
    if(fr==NULL)
    {
        puts("no fr\n");
        exit(1);
    }

    rewind(fr);

    int n=0,rank=1,i=0,j=0,pos;
    float temp;

    while((fread(&r,sizeof(r),1,fr))>0)
    {
        n++;
    }
    float *a=malloc(n*sizeof(float));

    printf("%d\n",n);
    fseek(fr,0,0);
    i=0;
    while((fread(&r,sizeof(r),1,fr))>0)
    {
        a[i]=r.fper;
        i++;
    }

    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0; )
        {
            if(temp<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            else
                break;
        }
        if(a[j+1]!=temp)
            a[j+1]=temp;
     }
    
        fseek(fr,0,0);
    for(i=n-1;i>=0;i--)
    {
        fseek(fr,0,0);
      fread(&r,sizeof(r),1,fr);
        while(!feof(fr))
        {
            if(a[i]==r.fper)
              { 
                  r.rnk=rank;
                  printf("RANK:%d--->REGISTRAION NO>%d\n",r.rnk,r.regd_no);
                  rank++;
                  fseek(fr,-sizeof(r),1);
                  fwrite(&r,sizeof(r),1,fr);
                  break;
              }
                  fread(&r,sizeof(r),1,fr);
        }
    }
    fclose(fr);
}


   
/////////////////////////ATTENDANCE//////////////////////////////////
//FUNCTION READS THE NUMBER OF PRESENT DAYS FROM  A FILE/////////////////////
//WRITTEN BY:UTSAV RAI(173248)////////////////////////////
void read_attend()
 { FILE *fa,*fb;
   fa=fopen("attend.txt","r+");
   fb=fopen("attendb.txt","w+");
   char t[999];
   fgets(t,999,fa);
   fscanf(fa,"%d",&a.regi);
   while(!feof(fa))
        { fscanf(fa,"%d",&a.pre_days);
	  fwrite(&a,sizeof(a),1,fb);
	  fscanf(fa,"%d",&a.regi);
	}
       fclose(fa);
       fclose(fb);
  }
/////FUNCTION CALCULATES THE PERCENTAGE AND ABSENT DAYS FOR EACH STUDENT AND PRINTS IT///////////////////
//WRITTEN BY:UTSAV RAI(173248)/////
void cal_attend()
 { FILE *fb,*fc;
   int work;
   fb=fopen("attendb.txt","r+");
   fc=fopen("finalat.txt","w+");
   fread(&a,sizeof(a),1,fb);
    while(!feof(fb))
       {printf("+==============================================================+\n");
	printf("|                                                              |\n");
	printf("   REGISTRATION ID:%d            PRESENT DAYS:%d                \n",a.regi,a.pre_days);
	printf("|                                                              |\n");
	printf("+==============================================================+\n");
        ca.regis=a.regi;
	work=250;
	ca.percent=((float)a.pre_days/work)*100;
	if(a.pre_days>work)
	 {printf("SORRY THE INPUT IS INVALID\n");
	  break;
	 }
	ca.abs_days=work-a.pre_days;
	printf("THE STUDENT(%d) WAS ABSENT IN %d DAYS\n\n",ca.regis,ca.abs_days);
	fwrite(&ca,sizeof(ca),1,fc);
	fread(&a,sizeof(a),1,fb);
       }
    fclose(fb);
    fclose(fc);
 }
/////////////FUNCTION PRINTS THE REG_NO,ABSENT DAYS AND ATTENDANCE PERCENTAGE OF A STUDENT////////////
//////WRITTEN BY:UTSAV RAI(1732480//////////////////////////////
void attend()
{ FILE *fr;
  fr=fopen("finalat.txt","r+");
  fread(&ca,sizeof(ca),1,fr);
  while(!feof(fr))
       { 
	  printf("REGISTRATION NUMBER:%d     ABSENT DAYS:%d     PERCENTAGE:%f\n",ca.regis,ca.abs_days,ca.percent);
	
	 fread(&ca,sizeof(ca),1,fr);
       }
   fclose(fr);
 }
  

///////////////////////////PASSWORD FUNCTION/////////////////////////////////
//THE FUNCTIONS ARE BASED ON THE PRIVACY OF IMPLEMENTING PROGRAM WHICH INCLUDES CHANGE OF PASSWORD AND VERIFICATION//////////
//WRITTEN BY:UTSAV RAI(173248)/////////
void encrypt(char *str,char *file)
{ int i=0,len=strlen(str);
  FILE *fp;
  fp=fopen(file,"wb+");
  while(str[i]!='\0')
      { str[i]=str[i]+len;
	i++;
      }
  strcpy(p.pass,str);
  p.len=len;
  fwrite(&p,sizeof(p),1,fp);
  fclose(fp);
}

void decrypt(char str[],char *file)
{ int i=0;
  password p;
  FILE *fr;
  fr=fopen(file,"rb+");
  fread(&p,sizeof(p),1,fr);
  strcpy(str,p.pass);
  while(p.pass[i]!='\0')
      {str[i]=p.pass[i]-p.len;
       i++;
      }
  fclose(fr);
}

int verify_pass(char *file)
 {  FILE *fp;
    char any='y';
    int j=1,choice;
    char str2[15],str1[15],str[15],str3[15],str4[15]="0000";
    fp=fopen(file,"rb+");
    fread(&p,sizeof(p),1,fp);
     decrypt(str3,file);
     if(strcmp(str3,"0000")==0)
      {printf("WE CANNOT LOGIN UNTIL YOU CHANGE YOUR PASSWORD(FOR SAFETY)\n");
change:
       printf("ENTER THE CURRENT PASSWORD\n");
       scanf("%s",str);
       while(any=='y' && strcmp(str,str3)==0)
          {printf("ENTER THE NEW PASSWORD:");
           scanf(" %s",str1);
           printf("CONFIRM NEW PASSWORD:");
           scanf(" %s",str2);
          if(strcmp(str1,str2)==0)
	    { encrypt(str1,file);
	      any='j';
	      printf("PASSWORD CHANGED SUCCESSFULLY\n\n");
	      break;
	    }
          else 
            {printf("TRY AGAIN(WRONG ENTRIES)\n");
             any='y';
	    }
          }
      }
    else
       {printf("+==============================================HELLO ADMIN================================================+\n");
	                             printf("1)LOGIN\n");
				     printf("2)CHANGE PASSWORD AND LOGIN\n");
				     printf("3)QUIT AND DELETE ALL THE MODIFICATIONS\n");
	                             scanf("   %d",&choice);
	switch(choice)
	   { 
	       case 1:
		    goto password;
		    decrypt(str3,file);
		    break;

 	       case 2:
		    goto change;
		    break;
		    
	      case 3:
		     encrypt(str4,file);
		     break;

	      default:
		      printf("SORRY INVALID INPUT\n");
		      

            }
       }
      
      printf("DO YOU WANT TO LOGIN?\n");
      decrypt(str3,file);
      if(strcmp(str3,"0000")!=0)
         { while(j==1)
              { 
		  password:
		     printf("ENTER THE PASSWORD TO LOGIN:");
	        	scanf("%s",str1);
			decrypt(str2,file);
			if(strcmp(str1,str2)==0)
			  {	 return 1;
		    		j=0;

		   	  }
			else
		           { printf("THE PASSWORD IS NOT SECURED CHANGE AND LOGIN(TRY AGAIN)\n");
	                     exit(1);
		             j=1;
		           }  
	       }
          }
     fclose(fp);
  }


void feed()
{       FILE* fr;
        char any='y';
        fr=fopen("studentb.txt","w+");
	 if(fr==NULL)
	   {printf("FILE can't be open\n");
	    exit(1);
	   }
	        fseek(fr,0,2);
	        while(any=='y')
		  { printf("Feed the details:\n");
		    printf("Enter the serial number:");
		    scanf(" %d",&s.ser);
		    printf("First Name:");
		    scanf("%s",s.F_name);
		    printf("last Name:");
		    scanf("%s",s.L_name);
		    printf("Registration number:");
		    scanf("%d",&s.regd_no);
		    printf("Date of birth:");
		    scanf("%d %d %d",&s.dt.d,&s.dt.m,&s.dt.y);
		    printf("Age:");
		    scanf("%d",&s.age);
		    printf("Gender:");
		    scanf("%s",s.gender);
		    printf("Department:");
		    scanf("%s",s.department);
		    printf("Year of joining:");
		    scanf("%d",&s.yoj);
		    s.a.amount=0;
		    s.a.sems=0;
		    fwrite(&s,sizeof(s),1,fr);
		    printf("Any other record(y/n)");
		    scanf(" %c",&any);
	           }
                fclose(fr);
}
































