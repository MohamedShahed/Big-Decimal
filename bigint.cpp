#include "bigint.h"


bigint::bigint(string input){
    int siz=input.size();
    for(int i=0; i<siz; i++)v.push_back(input[i]);

}

void bigint::operator=(const bigint&B){
    v=B.v;
}

bigint::bigint(int x){
    int number;

    while(x>=0){
        number=0;
        number=x%10;
        v.push_back(number+'0');
        x/=10;
        if(x==0)break;
    }
    reverse(v.begin(), v.end());

}

int bigint:: siz(){
    return v.size();
}

void bigint:: print(){
    int siz=v.size();
    for(int i=0; i<siz; i++)cout<<v[i];
}


bigint bigint:: add(const bigint&P){
    bigint re;
    int indx1=v.size()-1;
    int indx2=P.v.size()-1;
    int number=0;
    char ch;
    while(indx1>=0 && indx2>=0){
        number+=(v[indx1--]-'0')+(P.v[indx2--]-'0');
        ch=(number%10)+'0';
        re.v.push_back(ch);
        number/=10;
    }

    while(indx1>=0){
        number+=(v[indx1--]-'0');
        ch=((number)%10)+'0';
        re.v.push_back(ch);
        number/=10;
    }
    while(indx2>=0){
        number+=(P.v[indx2--]-'0');
        ch=(number%10)+'0';
        re.v.push_back(ch);
        number/=10;
    }
    if(number>0)
        re.v.push_back(number+'0');
    reverse(re.v.begin(), re.v.end());

    return re;




}

bigint bigint:: sub(const bigint &P){
    bigint re;
    int indx=0;
    vector<char>big;
    vector<char>small;
    if(v.size()!=P.v.size()){
        big=(v.size()>P.v.size()?v:P.v);
        small=(v.size()<P.v.size()?v:P.v);
    }
    else{
        for(int i=0; i<v.size(); i++){
            if(v[i]==P.v[i])continue;
            else{
                indx=i;break;}
        }

        if(indx==0){re.v.push_back('0');return re;}
        big=(v[indx]>P.v[indx]?v:P.v);
        small=(v[indx]<P.v[indx]?v:P.v);

    }
    int indxbig=big.size()-1;
    int indxsmall=small.size()-1;
    int number=0;
    while(indxbig>=0 && indxsmall>=0){
        if((big[indxbig]-'0')<(small[indxsmall]-'0') && indxbig!=0){
            big[indxbig]=((big[indxbig]-'0')+10)+'0';
            big[indxbig-1]=((big[indxbig-1]-'0')-1)+'0';
        }

        else if((big[indxbig]-'0')<(small[indxsmall]-'0') && indxbig==0){
            big[indxbig]=((big[indxbig]-'0')+10)+'0';
        }
        number=((big[indxbig--]-'0')-(small[indxsmall--]-'0'));
        re.v.push_back(number+'0');

    }
    while(indxbig>=0){
        re.v.push_back(big[indxbig--]);
    }

    reverse(re.v.begin(), re.v.end());
    int i=0;
    while(re.v[i]=='0'){
        re.v.erase(re.v.begin(), re.v.begin()+1);
    }
    return re;
}


bigint bigint:: operator+(const bigint&P){
    bigint re=P;
    char indx1=v[0];
    char indx2=re.v[0];
    if(indx1=='-' && indx2=='-'){
        v.erase(v.begin(), v.begin()+1);
        re.v.erase(re.v.begin(), re.v.begin()+1);
        re=add(re);
        re.v.insert(re.v.begin(),'-');
        return re;
    }
    else if(indx1=='-' && indx2!='-'){
        v.erase(v.begin(), v.begin()+1);
        re=sub(re);
        if(v.size()>P.v.size()) re.v.insert(re.v.begin(),'-');
        else if(v.size()==P.v.size()){
            int indx=-1;
            int siz=v.size();
            for(int i=0; i<siz; i++){
                if(v[i]==P.v[i])continue;
                else{
                    indx=i;break;}
            }
            if(indx!=-1){
                if((v[indx]-'0')>(P.v[indx]-'0')) re.v.insert(re.v.begin(),'-');
            }
        }
        return re;
    }

    else if(indx2=='-' && indx1!='-'){
        re.v.erase(re.v.begin(), re.v.begin()+1);
        bigint ans;
        ans=sub(re);
        if(v.size()<re.v.size()) ans.v.insert(ans.v.begin(),'-');
        else if(v.size()==re.v.size()){
            int indx=-1;
            int siz=v.size();
            for(int i=0; i<siz; i++){
                if(v[i]==re.v[i])continue;
                else{
                    indx=i;break;}
            }
            if(indx!=-1){
                if((v[indx]-'0')<(re.v[indx]-'0')) ans.v.insert(ans.v.begin(),'-');
            }
        }
        return ans;
    }
    else{
        re=add(re);
        return re;
    }


}

ostream&operator<<(ostream&out, const bigint&P){
    int siz=P.v.size();
    for(int i=0; i<siz; i++)out<<P.v[i];
    return out;
}