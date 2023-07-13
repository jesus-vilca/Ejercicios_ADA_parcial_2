#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isnum(int n){
    if(n>=48 && n<=57) return true;
    return false;
}

int retirar(int x,vector<int> M){
    if(x==0) return 0;
    int aux = M.size()-1;
    if(M[aux]<=x){
        return 1 + retirar(x-M[aux],M);
    }else{
        M.pop_back();
        return retirar(x,M);
    }
}

int main(){
    int T,n;
    string C;
    vector<int> M;
    cin>>T;
    for(int i=0;i<T;i++){                       
        cin>>n;
        M.resize(n);
        getline(cin>>ws,C);
        while(C.length()!=0){                   
            int a = stoi(C);
            M.push_back(a);
            while(isnum(C[0])){
                for(int a=0;a<C.length()-1;a++)
                    C[a]=C[a+1];
                C.pop_back();
            }
            while(C[0]==' '){
                for(int b=0;b<C.length()-1;b++)
                    C[b]=C[b+1];
                C.pop_back();
            }
        }
        int aux = 2 * M[M.size()-1] - 1;
        cout<<retirar(aux,M)<<endl;
    }
}