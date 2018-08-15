#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct people{
	char name[9];
	int age;
	int money;
};
struct people peop[100010];
bool comp(const struct people &a,const struct people &b)
{
	if(a.money!=b.money)
		return b.money<a.money;
	else if(a.age!=b.age)
		return a.age<b.age;
	else
		return strcmp(a.name,b.name)<0;
}
int main(){
	int n,m;
	int num,min,max;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%s%d%d",peop[i].name,&peop[i].age,&peop[i].money);
	sort(peop,peop+n,comp);
	for(int i=1;i<=m;i++){
		int count=0;
		cin>>num>>min>>max;
		cout<<"Case #"<<i<<':'<<'\n';
		for(int j=0;j<n;j++){
			if(count==num)
				break;
			if(peop[j].age>=min&&peop[j].age<=max){
				printf("%s %d %d\n",peop[j].name,peop[j].age,peop[j].money);
				count++;
			}
		}
		if(count==0)
		   cout<<"None\n";	
	}
	return 0;
}
