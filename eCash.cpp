//
//  main.cpp
//  Final
//
//  Created by yvonne90520 on 2021/8/27.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class eCash{
public:
    void login(string id){
        int i,m=0,c=0;
        fstream file;
        
        file.open("IDbook", ios::in);
        file>>m;
        for(i=0;i<m;i++){
            file>>ID[i]>>Money[i];
        }
        file.close();
        
        for(i=0;i<m;i++){
            if(id==ID[i]){
                cout<<"eCash: 帳號開啟完成!"<<endl;
                c=1;
            }
        }
        if(c==0){
            cout<<"eCash: 帳號不存在, 第一次使用!"<<endl;
        }
        
    }
    void logout(string id){
        int i,j,m=0,c=0;
        fstream file;
        
        for(i=0;i<m;i++){
            if(id==ID[i]){
                file.open("IDbook", ios::out);
                for(j=0;j<m;j++){
                    file<<m<<endl;
                    file<<ID[j]<<"  "<<Money[j]<<endl;
                }
                file.close();
                c=1;
            }
        }
        if(c==0){
            ID[m]=id;
            file.open("IDbook", ios::out);
            file<<m+1<<endl;
            for(i=0;i<m+1;i++){
                file<<ID[i]<<"  "<<Money[i]<<endl;
            }
            file.close();
                
        }
        
    }
    void store(string id,int h){
        int i,m=0,c=0;
        
        
        for(i=0;i<m;i++){
            if(id==ID[i]){
                if(h<0){
                    cout<<"eCash:  請輸入大於0的金額"<<endl;
                    Money[i]+=0;
                    return;
                }
                cout<<"eCash: 您存了"<<h<<"元"<<endl;
                Money[i]+=h;
                
                c=1;
            }
        }
        if(c==0){
            if(h<0){
                cout<<"eCash:  請輸入大於0的金額"<<endl;
                Money[m]+=0;
                return;
            }
            cout<<"eCash: 您存了"<<h<<"元"<<endl;
            Money[m]+=h;
            
        }
    }
    void pay(string id,int h){
        int i,m=0,c=0;
        
        
        for(i=0;i<m;i++){
            if(id==ID[i]){
                if(Money[i]<h){
                    cout<<"eCash: 您的錢不夠"<<endl;
                    return;
                }
                if(h<0){
                    cout<<"eCash:  請輸入大於0的金額"<<endl;
                    return;
                }
                cout<<"eCash: 您花了"<<h<<"元"<<endl;
                Money[i]-=h;
                
                c=1;
            }
        }
        if(c==0){
            if(Money[m]<h){
                cout<<"eCash: 您的錢不夠"<<endl;
                return;
            }
            if(h<0){
                cout<<"eCash:  請輸入大於0的金額"<<endl;
                return;
            }
            cout<<"eCash: 您花了"<<h<<"元"<<endl;
            Money[m]-=h;
            
        }
    }
    void display(string id){
        int i,m=0,c=0;
        
        for(i=0;i<m;i++){
            if(id==ID[i]){
                cout<<"eCash: 您尚有"<<Money[i]<<"元"<<endl;
                c=1;
            }
        }
        if(c==0){
            cout<<"eCash: 您尚有"<<Money[m]<<"元"<<endl;
        }
    };
private:
    int Money[100];
    string ID[100];
};
int main(int argc, const char * argv[]) {
    eCash e;
    char op;
    int num;
    string id1;
    
    
    cout<<"=== 歡迎使用eClash ==="<<endl;
    cout<<"eClash: 請輸入您的帳號: ";
    cin>>id1;
    
    e.login(id1);
    
    cout<<endl;
    while(1){
        cout<<id1<<"您好，請選擇項目:"<<endl;
        cout<<"s: 儲值"<<endl;
        cout<<"p: 消費"<<endl;
        cout<<"d: 查詢餘額"<<endl;
        cout<<"q: 離開"<<endl;
        cin>>op;
        switch(op){
            case 's':
                cout<<"請輸入儲存金額:"<<endl;
                cin>>num;
                e.store(id1,num);
                break;
            case 'p':
                cout<<"請輸入消費金額:"<<endl;
                cin>>num;
                e.pay(id1,num);
                break;
            case 'd':
                e.display(id1);
                break;
            case 'q':
                e.logout(id1);
                cout<<"eCash: 帳號登出, 已存檔!"<<endl;
                cout<<"謝謝，ByeBye!"<<endl;
                return 0;
                break;
        }
        getchar();
        system("clear");
    }
    
    return 0;
}
