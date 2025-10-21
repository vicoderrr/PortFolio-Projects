#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
void rules();
int level1();
int level2();
int level3();
void main()                  //ch is for name input
{                            //o is for answer option
 char name[20],o[10];
 char str[25]="-> Come Let's Play!!!";
 int y,s1,s2,s3,f,a;
 int k;
 long i,j;
 clrscr();
 printf("\t\t\t     ----------------------\n");
 printf("\t\t\t    | ");
 printf("WELCOME To Quiz Game ");
 printf("|\n");
 printf("\t\t\t     ----------------------\n");
 printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t");
 printf(" ->Press any key to continue<-");
 getch();
 clrscr();
 printf("Enter your name:");
 gets(name);
 clrscr();
 printf("\n\t\t\t -> -> !!CONFIRMATION!! <- <-\n\n\n");
 printf("Hey dear %s,\n\n",name);
 printf("\n\n\n");
 printf("Enter 1 if you want to play this game or\n\n");
 printf("Enter any other key... If you want to exit the game\n\n\n\t\t\t\t    ");
 scanf("%d",&y);
 clrscr();
 if(y==1)
 {
  printf("You have selected to play this game...\nEnjoy!!!");
  printf("\n\n\n\nPress any key to continue<-");
  getch();
  for(i=1;i<=100;i++)
  {
   clrscr();
   printf("\n\n\n\n\n\n\n\n\t\n\n\n\t\t\t\t");
   printf("     %ld",i);
   for(j=1;j<=1000000;j++)
   j++;
  }
  clrscr();
 }
 else
  exit(0);
 rules();
 clrscr();
 printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t    ");
 for(k=0;str[k]!='\0';k++)
 {
  printf("%c",str[k]);
  for(i=1;i<=100;i++)
  {
   for(j=1;j<=10000;j++)
   j++;
  }
 }
 sleep(1);
 clrscr();
 printf("\n\n\n\n\n\n\n\t\t\t     -> ->  LEVEL 1  <- <-");
 printf("\n\n\n\n\n\n\t\t      -> ->  Press any key for next  <- <-\n\n\t\t\t\t\t");
 getch();
 clrscr();
 s1=level1();
 getch();
 clrscr();
 if(s1>=3)
 {
  printf("\n\n\n   You have given %d correct answer.\n\n 	 ",s1);
  printf("So according to the rule, You've won 1 crore.\n\n");
  printf("\nCongratulations!!!");
  printf("\n\nNow You can go for the 2nd level");
  printf("\n\n\nPress 1 to go for 2nd level or Press any key if you're satisfied with\n 1 crore and want to quit the game:");
  scanf("%d",&a);
  clrscr();
  if(a==1)
  {
   printf("\n\n\n\n\n\n\n\t\t\t     -> ->  LEVEL 2  <- <-");
   printf("\n\n\n\n\n\n\t\t      -> ->  Press any key for next  <- <-\n\n\t\t\t\t\t");
  }
  else
   exit(0);
 }
 else
 {
  printf("\n\n\n   You have given %d correct answer.\n\n         ",s1);
  printf("So according to the rule, You've lost the game.\n\n");
  printf("\n\n\n\t Better luck next time...Bubbye!!!");
  getch();
  exit(0);
 }
 getch();
 clrscr();
 s2=level2();
 getch();
 clrscr();
 if(s2>=2)
 {
   printf("\n\n\n   You have given %d correct answer.\n\n         ",s2);
   printf("So according to the rule, You've won 3 crores.\n\n");
  printf("\nCongratulations!!!");
  printf("\n\nNow You can go for the 3rd level");
  printf("\n\n\nPress 1 to go for 3rd level or Press any key if you're satisfied with\n 3 crores and want to quit the game:");
  scanf("%d",&a);
  clrscr();
  if(a==1)
  {
   printf("\n\n\n\n\n\n\n\t\t\t     -> ->  LEVEL 3  <- <-");
   printf("\n\n\n\n\n\n\t\t      -> ->  Press any key for next  <- <-\n\n\t\t\t\t\t");
  }
  else
   exit(0);
 }
 else
 {
  printf("\n\n\n   You have given %d correct answer.\n\n         ",s2);
  printf("So You've lost the 2nd level of the game\n");
  printf("\nBut you won 1 crore in 1st level.");
  printf("\n\n\n\tCongrats n Better luck next time ...Bubbyeee!!!");
  getch();
  exit(0);
 }
 getch();
 clrscr();
 s3=level3();
 getch();
 clrscr();
 f=s1+s2+s3;
 if(s3>=1)
 {
  printf("\n\nSo %s,\n    You actually completed all the level of this quiz game..Well done!\n\n",name);
  printf("You gave %d correct answer in this level,\n     that means you won 5 crores.\n\n\n\n",s3);
  printf("You answered %d correct answers out of 10 questions\n\n",f);
  printf("     And that was actually unbelievable, You deserved this 5 crores\n");
  printf("\n\n\n\t\tThank you!!!");
  printf("\n\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c",3,3,3,3,3,3,3,3,3,3);
  printf("\n\t\t\t\t    ");
 }
 else
 {
  printf("\n\nSorry but you didn't give a single correct answer in this level");
  printf("\n\nBut don't be sad\n     You completed 1st and 2nd level of the game");
  printf("\n\nAnd you won 2 crores");
  printf("\n\n\tKeep this money and go and make your future with this money");
  printf("\n\n\n\n\t\tThank you!!!!");
 }
 getch();
}
void rules()
{
  clrscr();
 printf("\t\t\t     ------------------\n");
 printf("\t\t\t    |    GAME\t       |\n");
 printf("\t\t\t    |         RULES    |\n");
 printf("\t\t\t     ------------------\n\n");
 printf("1:> There are 10 questions in this game.\n\n");
 printf("2:> All questions are categorized into 3 levels.\n\n");
 printf("3:> In level 1(Easy):\n\tThere are 05 questions\n\t\tAnd you have to give at least 3 correct answer.\n\n");
 printf("4:> In level 2(Medium):\n\tThere are 03 questions\n\t\tAnd you have to give at least 2 correct answer.\n\n");
 printf("5:> In level 3(Hard):\n\tThere are 02 questions\n\t\tAnd you have to give at least 1 correct answer.\n\n\n");
 printf("\n\t\t       -> Press any key for next <-");
 getch();
 clrscr();
 printf("\t\t\t     ------------------\n");
 printf("\t\t\t    |    GAME\t       |\n");
 printf("\t\t\t    |         RULES    |\n");
 printf("\t\t\t     ------------------\n\n");
 printf("6:> Each question has 4 options,\n        You just have to choose the right one to answer that fucking question.\n\n");
 printf("7:> You can actually quit the game after completing any level\n        Or you can go for the next level.\n\n");
 printf("8:> If you loose any mode(like easy),\n        You'll not allow to go in next level\n\n");
 printf("9:> If you complete 1st level,\n          You'll win 1 crore \n\n");
 printf("10:> If you complete both 1st and 2nd level,\n        You'll win (1+2)= 3 crores\n\n");
 printf("11:> If you complete all the levels of the game\n         Bravo! You'll win (1+2+2)= 5 crores.\n\n");
 printf("\t\t   -> Press any key to continue <-");
 getch();
}
int level1()
{
 char o[5];
 int c=0;
  printf("1. Who is the father of computer?\n\n\n");
 printf("   (a)Dennis Ritchie\n\n   (b)Napier\n\n   (c)Charles Babbage\n\n   (d)Alan Turing");
 printf("\n\n\nChoose The Correct Option:");
 flushall();
 scanf("%c",&o[0]);
 if(o[0]=='c' || o[0]=='C')
 {
  printf("\n\n\n Correct!");
  c+=1;
 }
 else
  printf("\n\n\n Wrong!!!");
 printf("\n\n\n\n\t\t    -> Press any key for next question <-");
 getch();
 clrscr();
 printf("2. Computer cannot perform\n\n\n");
 printf("   (a)Input\n\n   (b)Thinking\n\n   (c)Output\n\n   (d)Processing");
 printf("\n\n\nChoose The Correct Option:");
 flushall();
 scanf("%c",&o[1]);
 if(o[1]=='b' || o[1]=='B')
 {
  printf("\n\n\n Correct!");
  c+=1;
 }
 else
  printf("\n\n\n Wrong!!!");
 printf("\n\n\n\n\t\t     -> Press any key for next question  <-");
 getch();
 clrscr();
 printf("3. What is the brain of the computer\n\n\n");
 printf("   (a)Keyboard\n\n   (b)Mouse\n\n   (c)CPU\n\n   (d)Printer");
 printf("\n\n\nChoose The Correct Option:");
 flushall();
 scanf("%c",&o[2]);
 if(o[2]=='c' || o[2]=='B')
 {
  printf("\n\n\n Correct!");
  c+=1;
 }
 else
  printf("\n\n\n Wrong!!!");
 printf("\n\n\n\n\t\t     -> Press any key for next question  <-");
 getch();
 clrscr();
 printf("4. The number system based on '0' and '1' only, is known as\n\n\n");
 printf("   (a)Binary number\n\n   (b)Barter number\n\n   (c)Number system\n\n   (d)Hexadecimal number");
 printf("\n\n\nChoose The Correct Option:");
 flushall();
 scanf("%c",&o[3]);
 if(o[3]=='a' || o[3]=='A')
 {
  printf("\n\n\n Correct!");
  c+=1;
 }
 else
  printf("\n\n\n Wrong!!!");
 printf("\n\n\n\n\t\t    -> Press any key for next question  <-");
 getch();
 clrscr();
 printf("5. An operating system is a/an\n\n\n");
 printf("   (a)Accounting software\n\n   (b)Application software\n\n   (c)System software\n\n   (d)Utility software");
 printf("\n\n\nChoose The Correct Option:");
 flushall();
 scanf("%c",&o[4]);
 if(o[4]=='c' || o[4]=='C')
 {
  printf("\n\n\n Correct!");
  c+=1;
 }
 else
  printf("\n\n\n Wrong!!!");
 printf("\n\n\n\n\t\t    ->  Press any key to see result  <-");
 return c;
}
int level2()
{
 char p[3];
 int d=0;
  printf("1. Who was the developer of C language?\n\n\n");
 printf("   (a)Grace Hopper\n\n   (b)Niklaus Wirth\n\n   (c)John McCarthy\n\n   (d)Dennis Ritchie");
 printf("\n\n\nChoose the correct option:");
 flushall();
 scanf("%c",&p[0]);
 if(p[0]=='d' || p[0]=='D')
 {
  printf("\n\n Correct!");
  d+=1;
 }
 else
  printf("\n\n Wrong!");
 printf("\n\n\n\n\t\t    -> Press any key for next question  <-");
 getch();
 clrscr();
 printf("2. The ...... program is used to convert mnemonic code to machine code.\n\n\n");
 printf("   (a)Debug\n\n   (b)Assembler\n\n   (c)FORTRAN\n\n   (d)C++");
 printf("\n\n\nChoose the correct option:");
 flushall();
 scanf("%c",&p[1]);
 if(p[1]=='b' || p[1]=='B')
 {
  printf("\n\n Correct!");
  d+=1;
 }
 else
  printf("\n\n Wrong!!!");
 printf("\n\n\n\n\t\t    -> Press any key for next question  <-");
 getch();
 clrscr();
 printf("3. In programming, repeating some statements is usually called\n\n\n");
 printf("   (a)Looping\n\n   (b)Control statement\n\n   (c)Compiling\n\n   (d)Structure");
 printf("\n\n\nChoose the correct option:");
 flushall();
 scanf("%c",&p[2]);
 if(p[2]=='a' || p[2]=='A')
 {
  printf("\n\n Correct!");
  d+=1;
 }
 else
  printf("\n\n Wrong!!!");
 printf("\n\n\n\n\t\t    -> Press any key to see the result <-");
 return d;
}
int level3()
{
 char q[5];
 int e=0;
  printf("1. 23 will be written in binary as\n\n\n");
 printf("   (a)10111\n\n   (b)11111\n\n   (c)10011\n\n   (d)11011");
 printf("\n\n\nChoose the correct option:");
 flushall();
 scanf("%c",&q[0]);
 if(q[0]=='a' || q[0]=='A')
 {
  printf("\n\n Correct!");
  e+=1;
 }
 else
  printf("\n\n Wrong!!!");
 printf("\n\n\n\n\t\t    -> Press any key for next question  <-");
 getch();
 clrscr();
 printf("2. For what purpose\"gets\" funtion is used\n\n\n");
 printf("   (a)To input character\n\n   (b)To input string\n\n   (c)To input integer\n\n   (d)To print integer");
 printf("\n\n\nChoose the correct answer:");
 flushall();
 scanf("%c",&q[1]);
 if(q[1]=='b' || q[1]=='B')
 {
  printf("\n\n Correct!");
  e+=1;
 }
 else
  printf("\n\n Wrong!!!");
 printf("\n\n\n\n\t\t    -> Press any key to see the result <-");
 return e;
}
