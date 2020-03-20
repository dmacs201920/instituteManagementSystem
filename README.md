#instituteManagementSystem
A novice implementation of educational institute management
=======================================================================================================================================================================
                      ==================        	      
		              "
		              "
		              "	      
		      ================NSTITUTE*MANAGEMENT*SYSTEM


WRITTEN BY: UTSAV RAI(173248) AND DEBASIS DAS(173238)
DESCRIPTION:
1)The INSTITUTE MANAGEMENT SYSTEM is divided into different areas like student and teacher details,fee submission,festivals and events,results of the students,attendance,extra curricular activities.
2)The modifications of the details of students and teachers can be proceeded only with the help of password. Basically,the administration of  the institute is only allowed to modify,delete the contents(official*).
3)The project has an option of entering 1 to continue with the same submenu and entering 0 or any number except 1 to go back to the previous  menu.
4)The details are read from the text file(in the beginning of the main program) and the work is performed in the binary text file.
5)For calculating the attendance of the student,working days is required which will be same for all the students.
6)To run the project the file name ("passnew.txt") should be written on the command line(say:./fout passnew.txt).
7)There are three options to enter the administrative options:
  a)login:ENTER THE Initial password "0000" and the user is asked to change the password for safety.
  b)change the password:The option helps us to change the password(The user should not keep the password like 0000,1111,etc for safety.
  c)Quit (*deletes all the modifications and initializes password to the default password*)
=====================================================================================================================================================.C file:
1)func.c:The file contains the functions required for the project which includes,
    (a)functions for reading the student details ,teacher details,student reports,festivals,attendance.
    (b)functions for displaying the reports of the student,attendance percentage,teacher's subjects of teaching,festivals for various months,extra curricular activities.
(The output of the functions has been commented on the func.c file)
2)fmain.c:The file contains the main program for the project which includes switch cases and function calls based on the choice of user.
.txt file:
1)student.txt:The text file contains the details of the students which is read on the program and written to binary file(studentb.txt).
2)event.txt:The text file contains the festivals and events in the institute to be read and written in the binary file(eventb.txt).
3)teacher_main.txt:The text file contains the teacher details to be read and written to the binary file(bin_teacher.txt).
4)champ.txt:The text file contains the details of the events and places secured by the student in the institute athletic's meet.
5)point.txt:The binary file contains the points of the students in the athletic events.
6)attend.txt:The text file  contains the attendance of the student present days and registration number from which the details are read to calculate the attendance percentage.
7)finalat.txt:The binary file contains the attendance percentage of the student.
8)pass.txt:For password(encryption && decryption).
.h file:
fheader.h:(a)The file contains the header files and the structures for student details and fees,teachers details,events,attendance,results,extra curricular activities.
(b)It also contains the name of the functions declared.
