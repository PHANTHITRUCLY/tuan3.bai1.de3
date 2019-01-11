#include<stdio.h>
#include<fstream>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#include<map>
using namespace std; 

void Sapxep(int a[], int n)
{
	int i,j;
	for(i=0;i<n - 1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}
	}
}
void Xuat(int a[], int n){

	for(int i=0;i<n;i++)
	{
		if(a[i]<10) cout<<"0"<<a[i]<<" ";
		else cout<<a[i]<<" ";
	}
}



int Soxo(int a[]){
	srand((int)time(0));//--random thay doi theo tg
	map<int, bool> vis;//----tao map
	for(int i = 0; i< 7; ++i){
		do{
			a[i] = rand() % 55 + 1;
		} while(vis.find(a[i]) != vis.end());//-------kiem tra dieu kien ket thuc
		vis[a[i]] = true;//-----danh dau a da co
	}
	Sapxep(a,6);
	cout<<endl<<"So xo: ";
	Xuat(a,7);
}
void Nguoi(int c[]){
	map<int, bool> vis;
	for(int i = 0; i < 6; i++){
		do{
		cout<<endl<<"Nhap so thu "<<i+1<<": ";
		cin>>c[i];
		}while(vis.find(c[i]) != vis.end() || c[i] <= 0 || c[i] > 55);//-------kiem tra dieu kien ket thuc
		vis[c[i]] = true;//-----danh dau a da co
	}
	Sapxep(c,6);
	cout<<endl<<"Nguoi choi: ";	
	Xuat(c,6);
	}
void Kiemtra(int a[],  int c[]){
	int dem = 0, dem1 =0, d[6]={0,0,0,0,0,0};
	for(int i = 0 ; i <6 ; i++){
		for(int j =0; j<6; j++){
			if(a[i] == c[j])
				{
				dem++;
				d[j]=1;
				}
		}
	}
	
	
	if(dem == 3)
		cout<<endl<<"Chuc mung ban da trung giai ba";
	else if(dem == 4)
		cout<<endl<<"Chuc mung ban da trung giai nhi";
	else if(dem == 5){
		for(int i = 0; i < 6; i++)
			if(d[i] == 0&&c[i] == a[6]) 
			 cout<<endl<<"Chuc mung ban da trung jackpot 2";
	}
	else if(dem == 6)
		cout<<endl<<"Chuc mung ban da trung jackpot 1";
	
	else cout<<endl<<"Khong trung. Chuc ban may man lan sau!";
	
}

int main(){
	int a[7], c[6];
	bool choi;
	do{
		cout<<endl<<"Bat dau choi ? (nhap 1 de choi, 0 de dung): ";
		cin>>choi;
		if(choi != 0){
			Soxo(a);
			cout<<"\nVui long nhap 6 so ban muon!\n (Yeu cau: So tu 01 -> 55, khong nhap trung nhau )\n";
			Nguoi(c);		
			Kiemtra(a,c);	
		}	
	}while(choi!=0);
	return 0;
}
