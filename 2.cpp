#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
 
 void insert();
 void pack();
 void unpack();
 void help();
 void modify();
 void search();

 class student
   {
 public:
	char name[25],age[5],sem[5],branch[5],usn[5];
   };
 student s;
 char buffer[55],temp[55];
 fstream fp;
 fstream gp;

 void main()
  {  
    int c;
	fp.open("fixed.txt",ios::app);       
	fp.close();
      clrscr();
    while(1)
	{
		cout<<"\t**Enter your choice**\n";
		cout<<"1.Pack 2.Unpack 3.Modify 4.Search 5.Exit"<<endl;
		cin>>c;

		switch(c)
	       {
		case 1:pack();
		break;
		case 2:unpack();
		break;
		case 3:modify();
		break;
	      case 4:search();
		break;
		case 5:exit(0);
		break;
		default:cout<<"Invalid input\n";
		break;
	    }
	}
 }

 void pack()
   {
	fp.open("fixed.txt",ios::app);
	insert();
	fp<<buffer<<endl 
	cout<<"\t**Record insertion successful**"<<endl; 
                                     
	fp.close();
	getch();
	clrscr();
   }
 void insert()
   {
	cout<<"USN";
	cin>>temp;
	strcpy(buffer,temp);
	strcat(buffer,"|");
	cout<<"Name";help();
	cout<<"sem";help();
	cout<<"age";help();
	cout<<"Branch";help();
	int c=strlen(buffer);
	for(int i=0;i<55-c;i++)       
	strcat(buffer,"!");
   }
void help()
    {
	cin>>temp;
	strcat(buffer,temp);
	strcat(buffer,"|");
    }

void unpack()
 {
	fp.open("fixed.txt",ios::in);
	fp.getline(buffer,60,'\n'); 
                      

	cout<<"\t**Unpacked record**"<<endl;
	cout<<"USN\t\tName\tSEM\tage\tBranch"<<endl;
	while(!fp.eof())                             
                      
	 {
	  sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",s.usn,s.name,s.sem,s.age,s.branch);
	  cout<<s.usn<<"\t"<<s.name<<"\t"<<s.sem<<"\t"<<s.age<<"\t"<<s.branch<<"\n";
	  fp.getline(buffer,60,'\n');
	 }
    fp.close(); 
    getch();
    clrscr();
 }

void modify()
  {
	char key[25],usn[25],modify[55];
	int Notfound=1;				              	
	cout<<"Enter the key to Modify (USN)\n";
	cin>>key;
    fp.open("fixed.txt",ios::in);
    gp.open("fixed1.txt",ios::app);

    fp.getline(buffer,60,'\n');
    while(!fp.eof())
     {
	sscanf(buffer,"%[^|]|",usn);
	if(strcmp(usn,key)!=0) 				  
	    {					                     	
		gp<<buffer<<endl;
	    }
	else						             
		{
		Notfound=0;
		cout<<"\t**record found**"<<endl;
		cout<<"Enter New data"<<endl;
		insert();				             
		strcpy(modify,buffer); 
		gp<<modify<<endl;				   
		cout<<"\t**Record Modification successful**"<<endl;
		}
		fp.getline(buffer,60,'\n');

	}
	if(Notfound)						
		{
		  cout<<"\tRecord not found  :("<<endl;
		}
  fp.close();							

  gp.close();
  char new1[]={"fixed1.txt"};		
  char old[]={"fixed.txt"};
  remove("fixed.txt");						
  rename(new1,old);	

  getch();
  clrscr();
}
void search()
   {
	char key[25],usn[25],modify[55];
	cout<<"enter the key to search (USN)\n";
	cin>>key;

	fp.open("fixed.txt",ios::in); 
	fp.getline(buffer,60,'\n');
  
     while(!fp.eof())
	  {
		sscanf(buffer,"%[^|]|",usn);
		if(strcmp(usn,key)!=0);			
		else
		  {
		  cout<<"\t**record found**"<<endl;
		  cout<<"USN\t\tNAME\tSEM\tAge\tBranch"<<endl;
		  sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",s.usn,s.name,s.sem,s.age,s.branch); 
		  cout<<s.usn<<"\t"<<s.name<<"\t"<<s.sem<<"\t"<<s.age<<"\t"<<s.branch<<"\n";	    
		 
		  break;							
		  }
	      fp.getline(buffer,60,'\n');
		  if(fp.eof())			

	   	   {				
		  cout<<"\tRecord not found  :("<<endl;
		   }
	  }
	      fp.close();
	      getch();
	      clrscr();
   }
