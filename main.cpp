#include <iostream>
using namespace std;

int v[1001];
int main()
{
    int i, m, n, contor, contor2, modal=0, ok=0;
    cin >> m >> n;
    contor=n;
    for(i=1; i<=m; i++)
        if(contor!=0){
            v[i]=1;
            contor--;
        }
    int poz=1, poz2=2;
    if(m%2==0)
        if(n>m/2){
            cout << 0;
            return 0;
        }
    if(m%2==1)
        if(n>(m/2+1)){
            cout << 0;
            return 0;
        }
    if(n==1){
        cout << m;
        return 0;
    }
    if(n==2){
            while(v[m]!=1 || v[m-1]!=1){
                contor=0;
                contor2=0;
                if(v[m]!=1){
                    for(i=1; i<m; i++){
                        if(v[i]==1)
                            contor2++;
                        if(contor2==n){
                            v[i+1]=1;
                            v[i]=0;
                            break;
                        }
                    }
                }
                else{
                    v[m]=0;
                    for(i=1; i<m; i++){
                        if(v[i]==1)
                            contor2++;
                        if(contor2==(n-1)){
                            v[i+1]=1;
                            v[i+2]=1;
                            v[i]=0;
                            break;
                        }
                    }
                }
                for(i=1; i<m; i++)
                    if(v[i]==1)
                        if(v[i]==v[i+1])
                            contor=1;
                if(contor==0)
                    modal++;
            }
            cout << modal;
            return 0;
    }
    if(n==3){
        while(v[m-2]!=1 || v[m-1]!=1 || v[m]!=1){
            contor=0;
            contor2=0;
            if(v[m]!=1){
                for(i=1; i<m; i++){
                    if(v[i]==1)
                        contor2++;
                    if(contor2==n){
                        v[i+1]=1;
                        v[i]=0;
                        break;
                    }
                }
            }
            else{
                v[m]=0;
                if(ok==0){
                    for(i=1; i<m; i++){
                        if(v[i]==1)
                            contor2++;
                        if(contor2==(n-1)){
                            v[i+1]=1;
                            v[i+2]=1;
                            v[i]=0;
                            if(v[m]==v[m-1])
                                if(v[m]==1)
                                    ok=1;
                            break;
                        }
                    }
                }
                else{
                    v[m-1]=0;
                    ok=0;
                    v[poz]=0;
                    v[poz+1]=1;
                    v[poz+2]=1;
                    v[poz+3]=1;
                    poz++;
                }
            }
            for(i=1; i<m; i++)
                if(v[i]==1)
                    if(v[i]==v[i+1])
                        contor=1;
            if(contor==0)
                modal++;
        }
        cout << modal;
        return 0;
    }
}
