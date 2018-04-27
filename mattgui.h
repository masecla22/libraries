#include <mattcore.h>

using namespace std;
namespace matt{ namespace gui {
int getSlash(char a[255])
{
    int ss=0;
    for(int i=0;i<strlen(a);i++)
        if(a[i]=='/'&&a[i+1]!='/')
            ss++;
    return ss;
}
void showArg(char a[255],int which)
{
    int j=0;
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i]=='/')
            j++;
        if(j==which)
            if(a[i]!='/')
                cout<<a[i];
    }
}
void show(char opts[255],int vals[100], int _style)
{
    if(_style==1)
    {
        for(int i=0; i<getSlash(opts); i++)
        {
            if(vals[i]==1)
                cout<<"> ";
            showArg(opts,i);
            cout<<"   "<<endl;
        }
    }
    if(_style==2)
    {
        for(int i=0; i<getSlash(opts); i++)
        {
            cout<<"                           ";
            if(vals[i]==1)
                cout<<">";
            showArg(opts,i);
            if(vals[i]==1)
                cout<<"<   "<<endl;
            else
                cout<<"      "<<endl;
        }
    }
}
int gui(char opts[255], int _style=1)
{
    matt::clear();
    if(_style==1)
    {
        cout<<"> ";
        int vals[100];
        for(int i=0; i<getSlash(opts); i++)
        {
            vals[i]=0;
        }
        show(opts,vals,_style);
        int pos=0;
        while(2)
        {
            int a=_getch();
            matt::ShowConsoleCursor(false);
            matt::clear();
            if(a==80)
                if(pos==(getSlash(opts)-1))
                    pos=0;
                else
                    pos++;
            if(a==72)
                if(pos==0)
                    pos=(getSlash(opts)-1);
                else
                    pos--;
            if(a==13)
            {
                matt::clear();
                break;
            }
            for(int i=0; i<getSlash(opts); i++)
            {
                vals[i]=(pos==i);
            }
            show(opts,vals,_style);

        }
        return pos;
    }
    if(_style==2)
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   >";
        int vals[100];
        for(int i=0; i<getSlash(opts); i++)
        {
            vals[i]=0;
        }
        show(opts,vals,_style);
        int pos=0;
        while(2)
        {
            int a=_getch();
            matt::clear();
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            if(a==80 && pos<(getSlash(opts)-1))
                pos++;
            if(a==72 && pos>0)
                pos--;
            if(a==13)
            {
                matt::clear();
                break;
            }
            for(int i=0; i<getSlash(opts); i++)
            {
                vals[i]=(pos==i);
            }
            show(opts,vals,_style);
        }system("cls");
        return pos;}}}}
