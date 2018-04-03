#include<iostream>
using namespace std;

int countparenth(char symbol[],char op[],int n){
    int f[n][n],t[n][n];
    for(int i=0;i<n;i++){
        f[i][i]=(symbol[i]=='F')?1:0;
        t[i][i]=(symbol[i]=='T')?1:0;
    }
    int j;
    for(int gap=1;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            t[i][j]=f[i][j]=0;
            for(int g=0;g<gap;g++){
                int k=i+g;
                int tik=t[i][k]+f[i][k];
                int tkj=t[k+1][j]+f[k+1][j];
                if(op[k]=='&'){
                    t[i][j]+=t[i][k]*t[k+1][j];
                    f[i][j]+=(tik*tkj-t[i][k]*t[k+1][j]);
                                    }
                if(op[k]=='|'){
                    f[i][j]+=f[i][k]*f[k+1][j];
                    t[i][j]+=(tik*tkj-f[i][k]*f[k+1][j]);

                }
                if(op[k]=='^'){
                    t[i][j]+=f[i][k]*t[k+1][j]+t[i][k]*f[k+1][j];
                    f[i][j]+=t[i][k]*t[k+1][j]+f[i][k]*f[k+1][j];
                }
            }
        }
    }
    return t[0][n-1];
}

int main()
{
    char symbols[] = "TTFT";
    char operators[] = "|&^";
    int n =4;

cout<<countparenth(symbols,operators,n)<<endl;
}