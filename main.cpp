#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
using namespace std;
ifstream f ("LFA.in");
string p;
int graf[101][101];
int stari,alfabet,initiala,finale;
char a[101];
int s[101],fin[101];
bool parcurgere( int drum[], int init,int final[],int finall,string cuv)
{
    int i,cont=0;
//cout<<endl;
    if(cuv.length()==0)
    {
        for( i=0; i<finall; i++)
            if(final[i]==init)
                return true;
        return false;
    }
//cout<<init<<endl;
    for( i=0; i<cuv.length(); ++i)
    {
        cont++;
        if(graf[init][drum[i]]!=-1)
        {

            init=graf[init][drum[i]];
            //cout<<init<<endl;
        }
        else
            return false;
    }
//    cout<<cont<<endl<<graf[init][drum[i]]<<endl;
    for( i=0; i<finall; i++)
        if(final[i]==init)
            return true;
    return false;
}
int main()
{
    string l;
    int i,j;
    f>>stari>>alfabet>>initiala>>finale;

    for(i=0; i<stari; ++i)
    {
        f>>l;
        j = 0;
        string res = "";
        while(j<l.length())
        {
            if(isdigit(l[j]))
                res += l[j];
            j++;
        }
        s[i]=stoi(res);


    }
    for(i=0; i<alfabet; ++i)


        f>>a[i];

    for(i=0; i<stari; ++i)
    {
        for( j=0; j<alfabet; ++j)
            graf[i][j]=-1;
    }
    for(i=0; i<finale; ++i)
    {
        f>>l;
        j = 0;
        string res = "";
        while(j<l.length())
        {
            if(isdigit(l[j]))
                res += l[j];
            j++;
        }
        fin[i]=stoi(res);
    }
    string s1,s2;
    char c;

    f>>p;///citirea cuvantului
    // getline(f, p);
     cout<<p<<endl;
    while(f>>s1>>c>>s2)
    {
        j = 0;
        string   res = "";
        while(j<s1.length())
        {
            if(isdigit(s1[j]))
                res += s1[j];
            j++;
        }
        int s3=stoi(res);

        j = 0;
        res = "";
        while(j<s2.length())
        {
            if(isdigit(s2[j]))
                res += s2[j];
            j++;
        }
        int s4=stoi(res);
        for(j=0;j<alfabet;++j)
            if(a[j]==c)
            break;
            graf[s3][j]=s4;



    }



    int drum[101];
    for(int i=0; i<p.length(); ++i)
    {
         for(j=0;j<alfabet;++j)
            if(a[j]==p[i])
            break;
        drum[i]=j;
         //cout<<drum[i]<<" ";
    }
    if(parcurgere(drum,initiala,fin,finale,p))
        cout<<"Drumul este acceptat";
    else
        cout<<"Drumul nu este acceptat";
    return 0;
}
