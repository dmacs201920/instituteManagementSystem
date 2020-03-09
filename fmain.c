//C_PROJECT
#include"fheader.h"
void main()
{   char any='y';
    int choice,j=1,i;
    system("clear");
    printf("===============================================WELCOME TO OUR INSTITUTE MANAGEMENT SYSTEM====================================================\n");
    printf("======THE INSTITUTE MANAGEMENT SYSTEM IS DISTRIBUTED INTO 4 AREAS:\n");
    printf("=================================================================1)ADMINISTRATIVE(*official*):IT INCLUDES DISPLAY,MODIFICATION,DELETION,FEEDING,FEE HISTORY AND MODIFICATION(OFA)\n");
    printf("=================================================================2)EVENTS AND FESTIVALS:IT INCLUDES READING AND DISPLAYING VARIOUS FESTIVALS IN OUR  INSTITUTE,CALCULATES THE DATES IN WHICH THE FESTIVAL OCCURS\n");
    printf("=================================================================3)STUDENTS(GENERAL):THE OPTION IS ONLY FOR GENERAL REFERENCE(i.e,DISPLAYSSSTUDENT HISTORY)\n");
    printf("=================================================================4)TEACHER DETAILS:THE OPTION IS FOR READING,DISPLAYING,MODIFYING,DELETING TEACHER DETAILS  (MODIFYING AND DELETING ONLY FOR ADMINISTRATION)\n");
   printf("==================================================================5)RESULTS OF THE ACADEMIC YEAR:  (A)THE OPTION INCLUDES DISPLAYING THE MARKS OF CONTINUOUS INTERNAL EVALUATIONS FOR DIFFERENT SUBJECTS,CALCULATING PERCENTAGES FOR EACH CIE AND GIVING THE FINAL PERCENTAGE CONSIDERING EACH PERCENTAGE,(B)RANK AND GRADES OF THE STUDENTS\n");       
    while(j==1)
    {   
	printf("+-----------------------------------------+\n");
	printf("|1.FOR ADMINSTRATIVE PURPOSE--------------|\n");
	printf("|2.VAROIUS EVENTS-------------------------|\n");
	printf("|3.STUDENT DETAILS------------------------|\n");
	printf("|4.TEACHER DETAILS------------------------|\n");
	printf("|5.RESULTS OF THE ACADEMIC YEAR-----------|\n");
	printf("|0.EXIT-----------------------------------|\n");
	printf("+-----------------------------------------|\n");
	scanf("%d",&choice);

	switch(choice)
	{
	    case 1:
		printf("------------------------HELLO ADMIN:(PLEASE ENTER THE PASSWORD)--------------------------\n");
		printf("----------------------->:");
		scanf(" %d",&i);
		while(j==1)
		 {if(i==12345)
		  { printf("+------------------------------------------------------------------------------------+\n");
		    printf("|1.READ STUDENT DETAILS FROM THE FILE------------------------------------------------|\n");
		    printf("|2.DISPLAY STUDENT DETAILS-----------------------------------------------------------|\n");
		    printf("|3.MODIFY STUDENT DETAILS------------------------------------------------------------|\n");
		    printf("|4.DELETE STUDENT DETAILS------------------------------------------------------------|\n");
		    printf("|5.FEE MODIFICATION------------------------------------------------------------------|\n");
		    printf("|6.CHECK THE NUMBER OF STUDENTS------------------------------------------------------|\n");
		    printf("|0.exit------------------------------------------------------------------------------|\n");
		    printf("+------------------------------------------------------------------------------------+\n");
		    scanf("         %d",&choice);
		   switch(choice)
			 {
			     case 1:
				    read_stud();
				    break;

			     case 2:
				    display();
				    break;

			     case 3:
				    modify();
				    break;

		             case 4:
				    delete_();
				    break;

		             case 5:
				    fee();
				    break;

			     case 6:
				    count();
				    break;

			     case 0:
				    break;
		         }
	        }
	     else 
		 printf("WRONG PASSWORD SORRY\n");
              printf("TO CONTINUE FURTHER (ENTER 1):");
	      scanf(" %d",&j);
	      system("clear");
	    }

	  case 2:
		while(j==1)
	         { printf("+--------------------+\n");
		   printf("|1.READ FESTIVAL-----|\n");
		   printf("|2.DISPLAY FESTIVALS-|\n");
	 	   printf("|3.EXIT--------------|\n");
		   printf("+--------------------+\n");
		   printf("ENTER YOUR CHOICE\n");
		   scanf("    %d",&choice);

		 switch(choice)
		  {
		    case 1:
			read_fest();
			break;

		    case 2:
			display_fest();
			break;

		    case 3:
			exit(1);

		    default :
			puts("invalid option\n");
		  }
		 printf("TO CONTINUE ENTER 1:");
		 scanf(" %d",&j);
		}

	    case 3:
		printf("+-----------------------+");
		printf("|1.DISPLAY--------------||\n");
		printf("|2.READ STUDENT DETAILS-|\n");
		printf("|3.COUNT----------------|\n");
		printf("|0.EXIT-----------------|\n");
		printf("+-----------------------+\n");
		printf("ENTER YOUR CHOICE\n");
                scanf("%d",&choice);
		switch(choice)
		{
		    case 1:
			display(); 
			break;

		    case 2:
			   read_stud();
			   break;

		    case 3:
			  count();
			  break;

		    case 0:
			  exit(1);

                    default :
			  puts("invalid option\n");
		}
		break;

	    case 4:
		printf("+------------------------------------------+\n");
		printf("|1.READ DETAILS FROM THE BINARY------------|\n");
		printf("|2.DISPLAY TEACHER DETAILS-----------------|\n");
		printf("|3.MODIFY----------------------------------|\n");
		printf("|4.DELETE----------------------------------|\n");
		printf("|5.EXIT------------------------------------|\n");
		printf("+------------------------------------------+\n");
		printf("ENTER YOUR CHOICE\n");
		scanf(" %d",&choice);

		switch(choice)
		{
		    case 1:
			 mv2bin();    
			 break;

		    case 2:
			 dispall(); 
			 break;

		    case 3:
			  modifyt(); 
			  break;

		    case 4:
			   delt();
			   break;

		    case 5:
			   exit(1);
			   break;

		    default :
			   puts("invalid option\n");

		}
		break;

                case 5:
		printf("+------------------------+\n");
		printf("|1.REPORT UPDATE---------|\n");
		printf("|2.DISPLAY RESULTS-------|\n");
		printf("|3.READ STUDENT DETAILS--|\n");
		printf("|4.DISPLAY---------------|\n");
		printf("|5.PERCENTAGE------------|\n");
		printf("|6.EXIT------------------|\n");
		printf("+------------------------+\n");
		printf("ENTER YOUR CHOICE\n");

		scanf(" %d",&choice);

		switch(choice)
		{
		    case 1:
			 rpt_updt(); 
			 break;

		    case 2:
			  display_results();
			  break;

		    case 3:
			  read_stud(); 
			  break;

		    case 4:
			   display();
			   break;

		    case 5:
			    percentage();
			    break;

		    case 6:
			    exit(1);
			    break;

		    default :
			    puts("invalid option\n");
		}
		break;

		case 0:
		exit(1);

		default :
		puts("invalid option\n");
	}

    }
}
