/*LEAKY BUCKET ALGORITHM. PACKET SIZE=3,BUCKET LENGTH=9*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<GL/glut.h>
Glint PI[1][2]={10,10};//Initial (x,y) of the graph
Glint PF[1][2]={10,10};//Final (x,y) of the graph
Glint A[9]={0};//Original array for the packet input
Glint B[9]={0};//Final output to store the non-conforming/conforming packets
GLfloat a[2];//Droplets
GLfloat b[2];
GLfloat c[2];
GLfloat d[2];
GLfloat w[2];//Water inside the bucket
GLfloat x[2];
GLfloat y[2];
GLfloat z[2];
Glint cnt=0;//Count of non-coforming packets
Int font;//font of text
Int op;
Void number(Glint X,Glint Y,int n)
{
Int I;
Char f[]=”Zero”;
Char g[]=”1”;
Char h[]=”2”;
Char j[]=”3”;
Char k[]=”4”;
Char l[]=”5”;
Char m[]=”6”;
Char N[]=”7”;
Char o[]=”8”;
Char p[]=”9”;
Switch(n)
{
Case’0’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;f[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,f[i]);
break;
case’1’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;g[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,g[i]);
break;
case’2’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;h[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,h[i]);
break;
case’3’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;j[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,j[i]);
break;
case’4’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;k[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,k[i]);
break;
case’5’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;l[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,l[i]);
break;
case’6’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;m[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,m[i]);
break;
case’7’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;N[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,N[i]);
break;
case’8’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;o[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,o[i]);
break;
case’9’:glColor3f(1.0,0.0,0.0);
glRasterPos2f(X,Y);
for(i=0;p[i]!=’\0’;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,p[i]);
break;
}
}
Void draw_line(Glint *a,Glint *b) //DRAW LINES
{
glColor3f(1.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2iv(a);
glVertex2iv(b);
glEnd();
}
Void draw_line_1() //DRAW LINES
{
glColor3f(1.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2iv(PI[0]);
glVertex2iv(PF[0]);
glEnd();
}
Void non_polygon(Glint *B ) //NON CONFORMING packets
{
Int I,x,x1;
Cnt=0;
For(i=0;i<9;i++)
{
If(B[i]==1)
{
Cnt++;
X=(i*100)+10;
X1=((i+1)*100)+10;
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//To show the non-conforming packets on top
glVertex2i(x,930);
glVertex2i(x1,930);
glVertex2i(x1,980);
glVertex2i(x,980);
glEnd();
glColor3f(0.0,0.0,0.0);//Outline over each packet
glBegin(GL_LINE_LOOP);
glVertex2i(x,930);
glVertex2i(x1,930);
glVertex2i(x1,980);
glVertex2i(x,980);
glEnd();
}
}
}
Void polygon(Glint *a) //CONFORMING PACKETS
{
Int I,x,x1,v=10;
For(i=0;i<9;i++)
{
If(a[i]==1)
{
X=(i*100)+10;
X1=((i+1)*100)+10;
glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);//To show the conforming packets on top
glVertex2i(x,930);
glVertex2i(x1,930);
glVertex2i(x1,980);
glVertex2i(x,980);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);//Outline over each packet
glVertex2i(x,930);
glVertex2i(x1,930);
glVertex2i(x1,980);
glVertex2i(x,980);
glEnd();
}
}
For(i=0;i<9;i++)
{
V=i*100+10;
glColor3f(1.0,1.0,1.0);//Marking on the packet line
glBegin(GL_LINES);
glVertex2i(v,930);
glVertex2i(v,940);
glEnd();
}
glColor3f(1.0,1.0,1.0);//Base of packet line on top
glBegin(GL_LINES);
glVertex2i(10,930);
glVertex2i(910,930);
glEnd();
}
Void leaky_bucket() // ALGORITHM :CALCULATION
{
Glint X,Y;
Int i=0,j,k,count=0,C=0,val,e;
For(i=0;i<9;i++)//Finding the initial packet postion
{
If(A[i]==0)
Count++;
Else
Break;
}
PI[0][0]+=(count*100);
J=I;//First packet
PF[0][0]+=count*100;
While(j<9)
{
 Count=0;
If(A[j]==1)
{
PF[0][1]+=300;
C+=3;
If(PF[0][1]>910)
{
PF[0][1]-=300;
B[j]=1;
}
Draw_line(PI[0],PF[0]);//Vertical Line,I=3
X=PF[0][1]+2;
Y=PF[0][1]+2;
glColor3f(1.0,0.0,0.0);
// glColor3f(1.0,0.0,0.0);
//char f[]=”HI”;
//glRasterPos2f(PF[0][0],PF[0][1]);
//for(e=0;f[e]!=’\0’;e++)
// glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,f[i]);
If(C==0)
{
glColor3f(1.0,0.0,0.0);
char f[]=”0packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;f[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,f[e]);}
else if(C==1){glColor3f(1.0,0.0,0.0);char g[]=”1 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;g[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,g[e]);
}
Else if(C==2){glColor3f(1.0,0.0,0.0);
Char h[]=”2 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);;
for(e=0;h[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,h[e]);
}
Else if(C==3){glColor3f(1.0,0.0,0.0);
Char J[]=”3 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;J[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,J[e]);
}
Else if(C==4){glColor3f(1.0,0.0,0.0);
Char k[]=”4 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;k[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,k[e]);
}
Else if(C==5){glColor3f(1.0,0.0,0.0);
Char l[]=”5 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;l[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,l[e]);
}
Else if(C==6){glColor3f(1.0,0.0,0.0);
Char m[]=”6 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;m[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,m[e]);
}
Else if(C==7){glColor3f(1.0,0.0,0.0);
Char N[]=”7 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;N[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,N[e]);
}
Else if(C==8){glColor3f(1.0,0.0,0.0);
Char o[]=”8 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;o[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,o[e]);
}
Else if(C==9){glColor3f(1.0,0.0,0.0);
Char p[]=”9 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;p[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,p[e]);
}
PI[0][0]=PF[0][0];
PI[0][1]=PF[0][1];
PF[0][0]+=100;//Drop after every addition of packet
PF[0][1]-=100;
C-=1;
If(C==0)
{
glColor3f(1.0,0.0,0.0);
char f[]=”0packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;f[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,f[e]);}
else if(C==1){glColor3f(1.0,0.0,0.0);char g[]=”1 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;g[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,g[e]);
}
Else if(C==2){glColor3f(1.0,0.0,0.0);
Char h[]=”2 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);;
for(e=0;h[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,h[e]);
}
Else if(C==3){glColor3f(1.0,0.0,0.0);
Char J[]=”3 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;J[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,J[e]);
}
Else if(C==4){glColor3f(1.0,0.0,0.0);
Char k[]=”4 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;k[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,k[e]);
}
Else if(C==5){glColor3f(1.0,0.0,0.0);
Char l[]=”5 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;l[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,l[e]);
}
Else if(C==6){glColor3f(1.0,0.0,0.0);
Char m[]=”6 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;m[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,m[e]);
}
Else if(C==7){glColor3f(1.0,0.0,0.0);
Char N[]=”7 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;N[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,N[e]);
}
Else if(C==8){glColor3f(1.0,0.0,0.0);
Char o[]=”8 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;o[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,o[e]);
}
Else if(C==9){glColor3f(1.0,0.0,0.0);
Char p[]=”9 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;p[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,p[e]);
}
Draw_line(PI[0],PF[0]);//Draw the drop
PI[0][0]=PF[0][0];
PI[0][1]=PF[0][1];
J++;
}
Else
{
For(k=j;k<9;k++)//Finding the next packet
{
If(A[k]==0)
{
Count++;
C-=1;
}
Else
Break;
}
PF[0][1]=PF[0][1]-(100*count);
PF[0][0]=PF[0][0]+(100*count);
If(PF[0][1]<10)
{
Val=10-PF[0][1];
PF[0][0]-=val;
PF[0][1]=10;
Draw_line(PI[0],PF[0]);
If(C==0)
{
glColor3f(1.0,0.0,0.0);
char f[]=”0packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;f[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,f[e]);}
else if(C==1){glColor3f(1.0,0.0,0.0);char g[]=”1 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);
for(e=0;g[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,g[e]);
}
Else if(C==2){glColor3f(1.0,0.0,0.0);
Char h[]=”2 packets”;
glRasterPos2f(PF[0][0],PF[0][1]);;
for(e=0;h[e]!=’\0’;e++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,h[e]);
}
