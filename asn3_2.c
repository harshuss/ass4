#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
int main (int argc, char **argv)
{
system ("python upgrade.py");
time_t current_time;
char* c_time_string;
current_time = time(NULL);
FILE * fp,*filepointer;
char *fvalue= NULL,*lvalue= NULL,lFlag=0;
int c,got;

if (current_time == ((time_t)-1)) 
{
 (void) fprintf(stderr, "Failure to compute the current time.");
 return EXIT_FAILURE;
}
c_time_string = ctime(&current_time);
if (c_time_string == NULL) {
       	(void) fprintf(stderr, "Failure to convert the current time.");
       	return EXIT_FAILURE;
    	}
    	while((c=getopt(argc,argv,"l:f:")) !=-1) {
                switch(c) {
                        case 'f':fvalue=optarg;
                                 if(strcmp(fvalue,"record.txt") != 0) {
                                         printf("Can't open the required file\n");
                                         printf("The file to be opened was record.txt. TRY AGAIN!!!\n");
                                         exit(EXIT_FAILURE);
                                 }
                                 break;
                        case 'l':lFlag=1;
				 lvalue=optarg;
                                 if(strcmp(lvalue,"log.txt") != 0) {
                                         printf("Can't open the required file\n");
                                         printf("The file to be opened was log.txt. TRY AGAIN!!!\n");
                                         exit(EXIT_FAILURE);
				 }
                                 break;
                        default:
                                 printf("Invaild input \n");
                                 exit(EXIT_FAILURE);
                }
	}
	filepointer=fopen("log.txt","a+");
	fprintf(filepointer,"%s\t\tInput Received:%s\n",c_time_string,fvalue);
	//fflush(filepointer);
	

char de[100];
fp=fopen("record.txt","r+");
char line[100];
char *pass[100];
int i=0;
char username[20];
int flag=0 , flag1=0 ,flag2=0;
int p=1;
char pw[100];
char name[100];

fun:{while(p==1)
{
	printf("Please Enter User Name:\n ");
  	scanf("%s", username);
	while(fgets(line, sizeof line, fp)!=NULL)
 	{
  		char * pch;
   		pch = strtok (line," ,.-");
		if(strcmp(username,pch)==0) // comparing the strings
		{
          	flag=1;
		}
		else
		{
		flag2=1;
		}
	  if(flag==1)
                {
		  printf("username already exists\n");
                  printf("enter other username\n");
		  flag=0;
                  printf("\nDo you want to continue??\nIf yes press 1 else press 0");
		  scanf("%d",&p);
	if(p==0)
	{	
	printf("***********end***********");
	exit(0);
	}
	if(p==1){
	goto fun;}
		}

}
	if(flag2 == 1)
  	{
	printf("\nusername accepted\n");
        printf("\nEnter password:\n");
	scanf("%s",pw);
	printf("\nEnter name:\n");
	scanf("%s",name);
	printf("\nusername is : %s\n password is : %s\n name is : %s\n",username,pw,name);
        fp = fopen ("record.txt", "a+");
	fprintf(fp,"%s %s %s %s %s",username,",",pw,",",name);
	fprintf(fp,"\n");
	flag2=0;
	(void) printf("Current time is %s\n", c_time_string);
	fp=fopen("record.txt","a+");
	printf("***********end***********");
	 printf("\nDo you want to continue??\nIf yes press 1 else press 0");
		  scanf("%d",&p);
	if(p==0)
	{	
	printf("***********end***********");
	exit(0);
	}
	if(p==1){
	goto fun;}
	
	

  	}


	
}
}
}


	 
	
