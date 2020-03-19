////////////////////MAIN PROGRAM FOR INSITUTE MANAGEMENT PROGRAM//////////////////////////////////
/////////////////WRITTEN BY:UTSAV RAI(173248)//////////////////////////////////////////////////
#include"fheader.h"
void main(int n,char* file[] )
{   char any='y',str[15];
    int choice,j=1,i,k;
    system("clear");
    if(n!=2)
    { printf("inappropriate argument\n");
	exit(-1);
    }
    decrypt(str,file[1]);
    if(strcmp(str,"0000")==0)
      {read_stud();
      }
    read_fest();
    r_sports();
    mv2bin();
    rpt_updt();
    read_attend();
 while(j==1)
  {
	printf("===============================================WELCOME TO OUR INSTITUTE MANAGEMENT SYSTEM==============================================================\n");
	printf("=====================================THE INSTITUTE MANAGEMENT SYSTEM IS DISTRIBUTED INTO 6 AREAS=======================================================\n");
	printf("\n\n\n\n\n");
	printf("=============1)ADMINISTRATIVE(*official*):IT INCLUDES DISPLAY,MODIFICATION,DELETION,FEEDING,FEE HISTORY,STUDENT ATTENDANCE AND MODIFICATION(OFA)\n");
	printf("=============2)EVENTS AND FESTIVALS:IT INCLUDES READING AND DISPLAYING VARIOUS FESTIVALS IN OUR  INSTITUTE,CALCULATES THE DATES IN WHICH THE FESTIVAL OCCURS\n");
	printf("=============3)STUDENTS(GENERAL):THE OPTION IS ONLY FOR GENERAL REFERENCE(i.e,DISPLAYS SSTUDENT HISTORY)\n");
	printf("=============4)TEACHER DETAILS:THE OPTION IS FOR READING,DISPLAYING,MODIFYING,DELETING TEACHER DETAILS  (MODIFYING AND DELETING ONLY FOR ADMINISTRATION)\n");
	printf("==============5)RESULTS OF THE ACADEMIC YEAR:  (A)THE OPTION INCLUDES DISPLAYING THE MARKS OF CONTINUOUS INTERNAL EVALUATIONS FOR DIFFERENT SUBJECTS,CALCULATING PERCENTAGES FOR EACH CIE AND GIVING THE FINAL PERCENTAGE CONSIDERING EACH PERCENTAGE,(B)RANK AND GRADES OF THE STUDENTS\n");
	printf("==============6)CURRICULAR ACTIVITIES:KEEPS TRACK OF THE EVENTS PARTICIAPTED BY A STUDENT AND POINTS,ANNOUNCES THE ATHLETIC CHAMPION BASED ON THE POINTS\n");   
	printf("+-----------------------------------------+\n");
	printf("|1.FOR ADMINSTRATIVE PURPOSE(admin*)------|\n");
	printf("|2.VAROIUS EVENTS-------------------------|\n");
	printf("|3.GENERAL DETAILS------------------------|\n");
	printf("|4.TEACHER DETAILS(admin*)----------------|\n");
	printf("|5.RESULTS OF THE ACADEMIC YEAR-----------|\n");
	printf("|6.EXTRA CURRICULAR ACTIVITIES------------|\n");
	printf("|9.EXIT-----------------------------------|\n");
	printf("+-----------------------------------------|\n");
	scanf("%d",&choice);

   switch(choice)
    {
	    case 1:
		system("clear");
		i=verify_pass(file[1]);
		while(j==1)
		{
		    if(i!=1)
		    printf("WRONG PASSWORD SORRY\n");
		    else
		    { 
			printf("+------------------------------------------------------------------------------------+\n");
			printf("|1.DISPLAY STUDENT DETAILS-----------------------------------------------------------|\n");
			printf("|2.MODIFY STUDENT DETAILS------------------------------------------------------------|\n");
			printf("|3.DELETE STUDENT DETAILS------------------------------------------------------------|\n");
			printf("|4.FEE MODIFICATION------------------------------------------------------------------|\n");
			printf("|5.CHECK THE NUMBER OF STUDENTS------------------------------------------------------|\n");
			printf("|6.STUDENTS ATTENDANCE FOR A PARTICULAR SEMESTER-------------------------------------|\n");
			printf("|7.FEED NEW STUDENT DETAILS----------------------------------------------------------|\n");
			printf("|0.exit------------------------------------------------------------------------------|\n");
			printf("+------------------------------------------------------------------------------------+\n");
			scanf("         %d",&choice);
			switch(choice)
			{
			    case 1:
				display();
				break;

			    case 2:
				modify();
				break;

			    case 3:
				delete_();
				break;

			    case 4:
				fee();
				break;

			    case 5:
				count();
				break;

			    case 6:
				system("clear");
				while(j==1)
				{
				    printf("+---------------------------+\n");
				    printf("|1)CALCULATE THE ATTENDANCE |\n");
				    printf("|2)PERCENTAGE               |\n");
				    printf("+---------------------------+\n");
				    scanf("     %d",&choice);
				    switch(choice)
				    { 
					case 1:
					    cal_attend();
					    break;

					case 2:
					    attend();
					    break;

				    }
				    printf("TO CONTINUE WITH THE ATTENDANCE MENU(ENTER 1) OR ELSE(ENTER ANY NUMBER) TO GO TO THE PREVIOUS MENU:");
				    scanf("%d",&j);
				}				       }
			        break;

			     case 7:
				    feed();
				    break;


			   case 0:
			     break;

			default:
			printf("INVALID OPTION\n");

		    }
		}
		printf("TO CONTINUE AS AN ADMINISTRATIVE PERSON(ENTER 1) OR ELSE GO BACK TO THE MAIN MENU:");
		scanf(" %d",&j);
		system("clear");
	      break;
	    

       case 2:
	while(j==1)
	{ printf("+--------------------+\n");
	    printf("|1.DISPLAY FESTIVALS-|\n");
	    printf("|0.EXIT--------------|\n");
	    printf("+--------------------+\n");
	    printf("ENTER YOUR CHOICE\n");
	    scanf("    %d",&choice);

	    switch(choice)
	    {
		case 1:
		    display_fest();
		    break;

		case 0:
		    break;

		default :
		    puts("INVALID OPTION\n");
	    }
	    printf("TO CONTINUE WITH THE FESTIVAL'S MENU(ENTER 1) OR ELSE (ENTER ANY NUMBER) TO GO BACK TO THE MAIN MENU:");
	    scanf(" %d",&j);
	}
	break;

       case 3:
	while(j==1)
	{printf("+--------------------------+\n");
	    printf("|1.DISPLAY STUDENT DETAILS |\n");
	    printf("|2.COUNT NUMBER OF STUDENTS|\n");
	    printf("|3.DISPLAY TEACHER DETAILS |\n");
	    printf("|4.STUDENT TEACHER RATIO   |\n");
	    printf("|0.EXIT                    |\n");
	    printf("+--------------------------+\n");
	    printf("ENTER YOUR CHOICE\n");
	    scanf("       %d",&choice);
	    switch(choice)
	    {
		case 1:
		    display(); 
		    break;

		case 2:
		    count();
		    break;

		case 3:
		    dispall();
		    break;

		case 4:
		    ratio();
		    break;

		case 0:
		    break;

		default :
		    puts("INVALID OPTION\n");
	    }
	    printf("TO CONTINUE WITH STUDENT DETAILS(enter 1) OR ELSE(ENTER ANY NUMBER) TO GO BACK TO THE MAIN MENU:");
	    scanf(" %d",&j);

	}
	break;

      case 4:
	k=verify_pass(file[1]);
	while(j==1)
	{ if(k==1)
	    {printf("+------------------------------------------+\n");
		printf("|1.DISPLAY TEACHER DETAILS-----------------|\n");
		printf("|2.MODIFY----------------------------------|\n");
		printf("|3.DELETE----------------------------------|\n");
		printf("|0.EXIT------------------------------------|\n");
		printf("+------------------------------------------+\n");
		printf("ENTER YOUR CHOICE\n");
		scanf("        %d",&choice);

		switch(choice)
		{
		    case 1:
			dispall(); 
			break;

		    case 2:
			modifyt(); 
			break;

		    case 3:
			delt();
			break;

		    case 0:
			break;

		    default :
			puts("INVALID OPTION\n");

		}   
	    }
	    printf("TO CONTINUE WITH TEACHER'S MENU(enter 1) OR ELSE (ENTER ANY NUMBER)TO GO BACK TO THE MAIN MENU:");
	    scanf("%d",&j);
	}
	break;

       case 5:
	while(j==1)
	{ printf("+--------------------------------------------+\n");
	    printf("|1)CALCULATE THE PERCENTAGES                 |\n");
	    printf("|2)DISPLAYING THE RESULTS                    |\n");
	    printf("|3)RANK DISPLAYING (CUMULATIVE)              |\n");
	    printf("|0)EXIT                                      |\n");
	    printf("+--------------------------------------------+\n");
	    scanf("      %d",&choice);
	    switch(choice)
	    { 
		case 1:
		    percentage();
		    break;

		case 2:
		    display_results();
		    break;

		case 3:
		    rank();
		    break;

		case 0:
		    break;

	    }
	    printf("TO CONTINUE WITH RESULTS MENU(ENTER 1)OR ELSE(ENTER ANY NUMBER) TO GO BACK TO MAIN MENU:");
	    scanf("%d",&j);
	}
	break;



	case 6:
	while(j==1)
	{ 
	    printf("+-----------------------------------------------------------------------------------------+\n");
	    printf("|1)CALCULATING THE TOTAL POINTS GAINED BY STUDENTS                                        |\n");
	    printf("|2)ARRANGING THE STUDENTS BASED ON POINTS AND DECLARING THE CHAMPION FOR THE ACADEMIC YEAR|\n");
	    printf("|0)EXIT FROM THIS SUBMENU                                                                 |\n");
	    printf("+-----------------------------------------------------------------------------------------+\n");
	    scanf("      %d",&choice);
	    switch(choice)
	    { 
		case 1:
		    points();
		    break;

		case 2:
		    champion();
		    break;

		case 0:
		    break;

		default:
		    puts("invalid option\n");

	    }
	    printf("TO CONTINUE WITH THE EXTRA CURICULAR OPTIONS(ENTER 1) OR ELSE (ENTER ANY NUMBER) TO GO BACK TO THE MAIN MENU:");
	    scanf(" %d",&j);
	}
	break;
	case 9:
	     exit(1);
	     break;
    }
    j=1;
    system("clear");
} 
}
