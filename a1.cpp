#include<iostream>
#include<math.h>
#include<list>
#include<cmath>
using namespace std;


float h(int ,int ,int ,int );
float g(int ,int );
float g12(int curx,int cury);
float g13(int curx,int cury);
float f(int ,int );




class node
{

public:
float f,g,h;
int x,y,px,py;
node *next;

};

int find1(node *temp);

void remove1(node *temp);

list<node> open1;
list<node> close1;
node *min();
node *findpnode(int px,int py);

int main()
{



int a[10][10];



for(int i=0;i<10;i++)
{
	for(int j=0;j<10;j++)
	{
		a[i][j]=0;

	if(j==5 && i!=8 )
	{
		a[i][j]=1;
	}
	if(j==3 && i!=1 )
	{
		a[i][j]=1;
	}
	if(j==7 && i!=1 )
	{
		a[i][j]=1;
	}
	}
}

//a[5][1]=1;
//a[4][9]=1;


for(int i=0;i<10;i++)
{
	for(int j=0;j<10;j++)
	{
	cout<<a[i][j]<<"\t";
	}
	cout<<endl;
}


node *src,*goal,*curr;
src=new node();
src->f=0;
src->x=5;
src->y=1;
src->g=0;


goal=new node();
//goal->f=0;
goal->x=4;
goal->y=9;

curr=new node();





close1.push_back(*src);
curr=src;
//curr->x!=goal->x && curr->y!=goal->y
int i1=100;
while(!(curr->x==goal->x && curr->y==goal->y))
{
float g1=g12(curr->x,curr->y);
for(int i=-1;i<2;i++)
{
	for(int j=-1;j<2;j++)
	{

	int x=(curr->x)-i;
	int y=(curr->y)-j;
	if(x<10 && y<10 && x>-1 && y>-1 && (x!=5 || y!=1) && a[x][y]!=1)
	{
	node *temp1;
	temp1=new node();
	
	temp1->x=x;
	temp1->y=y;

	temp1->px=x+i;
	temp1->py=y+j;

if(find1(temp1))
{ //not in open list
	temp1->g=g1+sqrt((pow(curr->x-x,2)+pow(curr->y-y,2)));
	temp1->h=(sqrt(pow(temp1->x-4,2)+pow(temp1->y-9,2) ));
	temp1->f=temp1->g + temp1->h;
	if(!(i==0 && j==0))
	{

		cout<<"\n---Push-------"<<endl;
		cout << temp1->f << '\t';
		cout <<temp1->x << '\t';
		cout << temp1->y << '\t';
		cout<<temp1->px;
		cout<<temp1->py;
		open1.push_back(*temp1);
	}
}

else{
//in open list
	if(temp1->g > g1+sqrt((pow(curr->x-x,2)+pow(curr->y-y,2)))){
		temp1->g=g1+sqrt((pow(curr->x-x,2)+pow(curr->y-y,2)));
		temp1->h=(sqrt(pow(temp1->x-4,2)+pow(temp1->y-9,2) ));
		temp1->f=temp1->g + temp1->h;
	}
}
}

}
}
curr=min();
cout<<"\n-----MIN-----"<<endl;
cout << curr->f << '\t';
cout <<curr->x << '\t';
cout << curr->y << '\t';

remove1(curr);
close1.push_back(*curr);
//i1++;

}


cout<<"\n----all visited nodes list------"<<endl;
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<endl;
}

node *temp2;
temp2=new node();

temp2=findpnode(4,9);;
int i2=200;

//!(temp2->x==5 && temp2->y==1)

int g23=0;
while(!(temp2->x==5 && temp2->y==1))
{
cout<<"inside while";

a[temp2->px][temp2->py]=i2;
i2++;
temp2=findpnode(temp2->px,temp2->py);
cout<<"x-----"<<temp2->x<<endl;
cout<<"y ------"<<temp2->y<<endl;
cout<<"px-----"<<temp2->px<<endl;
cout<<"py ------"<<temp2->py<<endl;
g23++;

}



cout<<"----final path------"<<endl;
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<endl;
}

return 0;
} 



float g12(int curx,int cury)
{

list<node>::iterator i=close1.end();

if(!(curx==5 && cury==1)){

float g=(i->f)-(sqrt(pow(i->x-4,2)+pow(i->y-9,2)));
g=g+sqrt((pow(curx-i->x,2)+pow(cury-i->y,2)));
return g;


}
else
{
return (sqrt(pow(5-i->x,2)+pow(1-i->y,2) ));

}
//return (sqrt(pow(5-curx,2)+pow(1-cury,2) ));
}

node *findpnode(int px,int py)
{
	list<node>::iterator i;
	node *temp=new node();

	for(i=close1.begin();i!=close1.end();i++)
	{

	if(px==i->x && py==i->y)
	{
	temp->f=i->f;
	temp->x=i->x;
	temp->y=i->y;
	temp->px=i->px;
	temp->py=i->py;
	return temp;
	break;
	}
	}



}


void remove1(node *temp)
{
	list<node>::iterator i;


	for(i=open1.begin();i!=open1.end();i++)
	{

	if(temp->x==i->x && temp->y==i->y)
	{
	i->f=4444;
	break;
	}
	}

}


int find1(node *temp)
{
	list<node>::iterator i;


	for(i=open1.begin();i!=open1.end();i++)
	{

	if(temp->x==i->x && temp->y==i->y)
	{
	return 0;
	}
	}
	return 1;

}


node *min()
{
	list<node>::iterator i;
	float min1=4444;
	node *temp=new node();
	for(i=open1.begin();i!=open1.end();i++)
	{

	if(i->f<min1 && (i->x!=5 || i->y!=1))
	{
	min1=i->f;
	temp->f=min1;
	temp->x=i->x;
	temp->y=i->y;
	temp->py=i->py;
	temp->px=i->px;

      }
}
return temp;

}



/*float f(int curx,int cury)
{
float h1=h(curx,cury,4,9);
float g1=g(curx, cury);
float g2=g12(curx, cury);
float g3=g13(curx, cury);
cout<<endl;
cout<<"x---"<<curx<<"------y---"<<cury<<endl;
cout<<"g---"<<g1<<endl;
cout<<"g2---"<<g2<<endl;
cout<<"g3---"<<g3<<endl;

return (h1+g3);
}


float h(int currx,int curry,int desx,int desy)
{

return (sqrt(pow(currx-desx,2)+pow(curry-desy,2) ));
}
*/

/*
float g(int curx,int cury)
{

list<node>::iterator i=close1.end();
if(!(curx==5 && cury==1)){

int g=i->f-sqrt(pow(i->x-4,2)+pow(i->y-9,2) );



}
else
{
return (sqrt(pow(5-i->x,2)+pow(1-i->y,2) ));

}
return (sqrt(pow(5-curx,2)+pow(1-cury,2) ));
}
*/





