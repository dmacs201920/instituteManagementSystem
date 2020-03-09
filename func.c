
#include"fheader.h"
char any='y';
char stdname[30];
student s;
student_rpt r;
fest E;
void display()
{   
    FILE *ft;

    ft=fopen("studentb.txt","r+");
    if(ft==NULL)
    { puts("cannot open the file\n");
	exit(1);
    }
    rewind(ft);

//    fread(&s.sizeof(combined),1,ft);
      fread(&s,sizeof(s),1,ft);
    printf("SERIs.NO\tFIRSTNc.s.E\tLASTNAME\tREGDNO\tDATEOFBIRTH\tAGE\tGENDER\tDEPARTMENT\tYEAROFJOINING\tAMOUNT\tSEMESTER\n");
    while(!feof(ft))
    { 
  	printf("%d\t%s\t%s\t%d\t%d-%d-%d\t%d\t%s\t%s\t%d\t%d\t%d\n",s.ser,s.F_name,s.L_name,s.regd_no,s.dt.d,s.dt.m,s.dt.y,s.age,s.gender,s.department,s.yoj,s.a.amount,s.a.sems);
//	fread(&s.sizeof(combined),1,ft);
  	fread(&s,sizeof(s),1,ft);
    }
    fclose(ft);
}

void modify()
{  
    FILE *ft;

    ft=fopen("studentb.txt","rb+");
    if(ft==NULL)
    { puts("cannot open the file\n");
	exit(1);
    }

    char any='y';
    char stdname[30];

    while(any=='y')
    {
       	printf("Enter the name of the student for modification\n");
	scanf(" %s",stdname);
	rewind(ft);
	while((fread(&s,sizeof(s),1,ft))==1)
	{ if ((strcmp(s.F_name,stdname))==0)
	    { printf("Enter the modifications\n");
		getchar();
		scanf("%s %s %d %d %d %d %d %s %s %d",s.F_name,s.L_name,&s.regd_no,&s.dt.d,&s.dt.m,&s.dt.y,&s.age,s.gender,s.department,&s.yoj);
		fseek(ft,-1*sizeof(s),1);
		fwrite(&s,sizeof(s),1,ft);
		break;
	    }
	}
	printf("Modify any other record(y/n)");
	any=getchar();
    }
    fclose(ft);
}


void fee()
{  
    FILE *ft;
      
    ft=fopen("studentb.txt","rb+");
    if(ft==NULL)
    { puts("cannot open the file\n");
	exit(1);
    }

    char any='y';
    int amt, sem,take;

    rewind(ft);

    while(any=='y')
    {
	printf("Enter the name of the combined for updating his fee submission\n");
	scanf(" %s",stdname);
	while((fread(&s,sizeof(s),1,ft))==1)
	{ 
	    if((strcmp(s.F_name,stdname))==0)
	     { 
		if(s.a.amount==0 && s.a.sems==0)
		{ 
		    printf("Please pay the fee for the 1st sems i.e, Rs.10000\n");
		    scanf(" %d",&amt);
		    s.a.amount=s.a.amount+amt;
		    s.a.sems=1;
		    fseek(ft,-1*sizeof(s),1);
		    fwrite(&s,sizeof(s),1,ft);
		    break;
		}
		else if(s.a.sems>0)
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
		    if(s.a.sems==6)
		    { 
			printf("You have already paid the fee for all the semesters...THs.K YOU:-)\n");
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
	getchar();
	printf("modify any other record\n");
	// getchar();
	scanf(" %c",&any);
    }
    fclose(ft);
}

void delete_()
{ 
    FILE *ft,*fs;

    ft=fopen("studentb.txt","rb+");
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
	fs=fopen("temp.txt","w+");
	rewind(ft);
	while((fread(&s,sizeof(s),1,ft))==1)
	{ 
	    if (strcmp(s.F_name,stdname)!=0)
	    { 
		fwrite(&s,sizeof(s),1,fs);
	    }
	}
	fclose(ft);
	fclose(fs);
remove("studentb.txt");
	rename("temp.txt","studentb.txt");
	ft=fopen("studentb.txt","r+");
	printf("Delete any other record(y/n)\n");
	scanf(" %c",&any);
    }
    fclose(ft);
}

void read_stud()
{ 
    FILE *fs,*ft;
    
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


    char a[1000];
    rewind(fs);
    fgets(a,999,fs);
    while(!feof(fs))
    { 
	fscanf(fs,"%d",&s.ser);
	fscanf(fs,"%s",s.F_name);
	fscanf(fs,"%s",s.L_name);
	fscanf(fs,"%d",&s.regd_no);
	fscanf(fs,"%d%d%d",&s.dt.d,&s.dt.m,&s.dt.y);
	fscanf(fs,"%d",&s.age);
	fscanf(fs,"%s",s.gender);
	fscanf(fs,"%s",s.department);
	fscanf(fs,"%d",&s.yoj);
	fscanf(fs,"%d",&s.a.amount);
	fscanf(fs,"%d",&s.a.sems);
	fwrite(&s,sizeof(s),1,ft);
    }
    fclose(ft);
    fclose(fs);
}



void count()
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
    printf("The number of combineds:%d\n",count);
    fclose(ft);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////FUNCTION FOR ALL FESTIVALS /////////////////////////////////////////////

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

    while(!feof(fe))
    { fscanf(fe,"%d",&E.day);
	fscanf(fe,"%d",&E.month);
	fscanf(fe,"%d",&E.year);
	fscanf(fe,"%d",&E.days);
	fgets(E.fes,98,fe);
	// fscanf(fe,"%s",E.fes);//
	fwrite(&E,sizeof(fest),1,fd);
    }
    fclose(fd);
    fclose(fe);
}

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
    int choice,d,m; 
    fseek(fd,0,0);
    printf("1)DISPLs. FESTIVc.s.S FOR THE ENTIRE YEAR\n2)DISPLAY FESTIVAL FOR A PARTICULAR MONTH\n3)DISPLAY FESTIVAL FOR A PARTICULAR DAY\n");
    scanf("   %d",&choice);
    switch(choice)
    { case 1:
	fread(&E,sizeof(fest),1,fd);	   
	printf("Vs.IOUS festivals IN OUR INSTITUTE:\n");
	while(!feof(fd))
	{ printf("					%d-%d-%d(%ddays):%s\n",E.day,E.month,E.year,E.days,E.fes); 
	    fread(&E,sizeof(fest),1,fd);
	}
	break;
	case 2:
	printf("ENTER THE MONTH FOR WHICH YOU Ws.T TO CHECK FESTIVc.s.S\n");
	scanf(" %d",&m);
	fread(&E,sizeof(fest),1,fd);
	while(!feof(fd))
	{ if(E.month==m)
	    { if(E.days>1)
		{ d=E.day+E.days;
		    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
		    {if(d>31)
			{ d=d-31;
			    m=E.month+1;
			}

		    }
		    else if( m==4 || m==6 || m==9 || m==11)
		    { if (d>30)
			{ d=d-30;
			    m=E.month+1;
			}
		    }
		    else if(m==2)
		    { if(E.year%100==0)
			{ if(E.year%400==0)
			    { if(d>29)
				{ d=d-29;
				    m=E.month+1;
				}
			    }
			} 
			else if(E.year%100==0 && E.year%400!=0)
			{ if(d>28)
			    { d=d-28;
				m=E.month+1;
			    }
			}
			else if(E.year%4==0)
			{ if(d>29)
			    { d=d-29;
				m=E.month+1;
			    }
			}  
		    }
		    printf("					%d-%d-%d TO %d-%d-%d:%s\n",E.day,E.month,E.year,d,m,E.year,E.fes);
		}
		else
		    printf("					%d-%d-%d:%s\n",E.day,E.month,E.year,E.fes);
	    }

	    fread(&E,sizeof(fest),1,fd);

	}
	break;

       case 3:
	printf("ENTER THE Ds.E\n");
	scanf(" %d",&d);
	fread(&E,sizeof(fest),1,fd);
	while(!feof(fd))
	{ if(E.day==d)
	    {if(E.days>1)
		{ d=E.day+E.days;
		    if(E.month==1 || E.month==3 || E.month==5 || E.month==7 || E.month==8 || E.month==10 || E.month==12)
		    {if(d>31)
			{ d=d-31;
			    m=E.month+1;
			}
		    }
		    else if( E.month==4 || E.month==6 || E.month==9 || E.month==11)
		    { if (d>30)
			{ d=d-30;
			    m=E.month+1;
			}
		    }
		    else if(E.month==2)
		    { if(E.year%100==0)
			{ if(E.year%400==0)
			    { if(d>29)
				{ d=d-29;
				    m=E.month+1;
				}
			    }
			}
			else if(E.year%100==0 && E.year%400!=0)
			{ if(d>28)
			    {d=d-28;
				m=E.month+1;
			    }
			}
			else if(E.year%4==0)
			{ if(d>29)
			    { d=d-29;
				m=E.month+1;
			    }
			}
		    }

		    printf("					%d-%d-%d TO %d-%d-%d:%s\n",E.day,E.month,E.year,d,m,E.year,E.fes);
		}
		else 
		    printf("					%d-%d-%d:%s\n",E.day,E.month,E.year,E.fes);
	    }

	    fread(&E,sizeof(fest),1,fd);
	} 
	break;

    }
    fclose(fd);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////FUNCTION FOR TEACHER DETAILS  //////////////////////////////////////////


char another,tchr[40];

//Function for getting teacher's details//
void mv2bin()
{ 
    teacher t; 
    FILE *fb,*fp;


    fb=fopen("teacher_main.txt","r");
    if(fb==NULL)
    {
	puts("cannot open the file\n");
	exit(1);
    }

    fp=fopen("bin_teacher.txt","rb+");
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

    while(!feof(fb))
    {
	fscanf(fb,"%d",&t.serial);
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
    }
    fclose(fp);
    fclose(fb);
  
}
//Display teacher's details//
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
    int choice;
    char another='y';

    printf("Enter the option\n");
    printf("1.Display all the teacher's details\n");
    printf("2.Display specific teacher's detsils\n");
    scanf(" %d",&choice);
    switch(choice)
    {
	case 1:
	    rewind(fp);
	    fread(&t,sizeof(t),1,fp);
	    while(!feof(fp))
	    {
		printf("\n\nTeacher's name-%s %s\n",t.tname.in,t.tname.sur);
		printf("Year of joining-%d\n",t.yoj);
		printf("Department-%s\n",t.dept);
		printf("Subject teaching to  the 1st year student\nEven sem-%sOdd sem-%s\n",t.even.firstyr,t.odd.firstyr);
		printf("Subject teaching to the 2nd year student\nEven sem-%sOdd sem-%s\n",t.even.secondyr,t.odd.secondyr);
		printf("Subject teaching to the 3rd year student\nEven sem-%sOdd sem-%s\n",t.even.thirdyr,t.odd.thirdyr);
		fread(&t,sizeof(t),1,fp);
	    }
	    break;
	case 2:
	    another='y';
	    while(another=='y')
	    {
		printf("Enter a teacher's name\n");
		scanf("%s",tchr);

		rewind(fp);
		fread(&t,sizeof(t),1,fp);
		while(!feof(fp))
		{

		    if(strcmp(t.tname.in,tchr)==0)
		    {

			printf("\n\nTeacher's name-%s %s\n",t.tname.in,t.tname.sur);
			printf("Year of joining-%d",t.yoj);
			printf("Department-%s",t.dept);
			printf("Subject teaching to  the 1st year student\nEven sem-%s\n",t.even.firstyr);
			printf("Subject teaching to the 1st year student\nOdd sem-%s\n",t.odd.firstyr);
			printf("Subject teaching to the 2nd year student\nEven sem-%s\n",t.even.secondyr);
			printf("Subject teaching to the 2nd year student\nOdd sem-%s\n",t.odd.secondyr);
			printf("Subject teaching to the 3rd year student\nEven sem-%s\n",t.even.thirdyr);
			printf("Subject teaching to the 3rd year student\nOdd sem-%s\n",t.odd.thirdyr);
		    }
		    else
		    {   
			printf("Searched teacher's details are not found\n");
			break;
		    }
		    fread(&t,sizeof(t),1,fp);
		}
		getchar();
		printf("Continue your search 'y' or 'n'?\n");
		scanf("%c",&another);
	    }
	    break;

	default:
	    printf("invalid option\n");
    }
    fclose(fp);
}
//Modify teacher's details//
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
	printf("enter the teacher's name to modify\n");
	scanf("%s",tchr);
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

//Delete function for teacher //

void delt()
{
    teacher t;
    FILE *fp, *ft;

    fp=fopen("bin_teacher.txt","rb+");
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
	ft=fopen("sample.txt","wb+");
	if(ft==NULL)
	    printf("Error opening file");

	rewind(fp);
	while((fread(&t,sizeof(t),1,fp))==1)
	{  
	    if(strcmp(t.tname.in,tchr)!=0)
	    {
		fwrite(&t,sizeof(t),1,ft);

	    }
	    else
	    {
		printf("found string sucs.fully\n");
	    }
	}

	rename("sample.txt","bin_teacher.txt");
	fp=fopen("bin_teacher.txt","rb+");
	printf("delete another teacher file ?'y' or 'n'\n");
	scanf(" %c", &another);
    }
    fclose(fp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////FUNCTION FOR DTUDENT RESULTS/////////////////////////////////////////////////////////


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
    while(!feof(fs))
    {
	fscanf(fs,"%d",&r.regd_no);
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
    }
    fclose(fs);
    fclose(fr);
}
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

        fseek(fr,pos,0);
	fwrite(&r,sizeof(r),1,fr);
	pos=ftell(fr);
	fread(&r,sizeof(r),1,fr);
    }
    fclose(fr);
}


/*void read_stud()	
{  
    FILE *fp,*ft;

    fp=fopen("student.txt","r+");
    if(fp==NULL)
    {
	    puts("cannot open the file fp\n");
	    exit(1);
    }

    ft=fopen("studentb.txt","rb+");
    if(ft==NULL)
    {
	    puts("cannot open the file ft\n");
	    exit(1);
    }

    char a[200];
    rewind(fp);
    fgets(a,199,fp);

    while(!feof(fp))
    { 
	fscanf(fp,"%d",&s.ser);
	fscanf(fp,"%s",s.F_name);
	fscanf(fp,"%s",s.L_name);
	fscanf(fp,"%d",&s.regd_no);
	fscanf(fp,"%d%d%d",&s.dt.d,&s.dt.m,&s.dt.y);
	fscanf(fp,"%d",&s.age);
	fscanf(fp,"%s",s.gender);
	fscanf(fp,"%s",s.department);
	fscanf(fp,"%d",&s.yoj);
	fscanf(fp,"%d",&s.a.amount);
	fscanf(fp,"%d",&s.a.sems);
	fwrite(&s,sizeof(s),1,ft);
    }
    fclose(fp);
    fclose(ft);
}*/

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
	}      /*	if((strcmp(r.department,"MATHEMATICS"))==0)
		  u[4]="MAT";
		  else
		  u[4]="PHY";*/

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
		break;
	    }
	}

	printf("want to see another student's mark\n");
	scanf(" %c",&another);
    }
    fclose(ft);
    fclose(fr);
}







