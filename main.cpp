#include <iostream>
#include <windows.h>
#include <cstring>
#include <conio.h>
using namespace std;
int playerX,playerY,a[6][6]= {{1,1,1,1,1,1},{1,0,0,5,0,1},{1,1,5,1,0,1},{1,0,0,1,0,1},{1,2,1,3,0,1},{1,1,1,1,1,1}},cheieX,cheieY,usaX,usaY,time,spike1X,spike1Y,spike2X,spike2Y,health;
int b[8][8]=
{
    {1,1,1,1,1,1,1,1},
    {1,2,6,0,0,5,0,1},
    {1,1,1,1,1,1,5,1},
    {1,1,0,0,0,0,0,1},
    {1,0,0,1,0,1,1,1},
    {1,5,1,1,5,1,3,1},
    {1,7,1,1,0,0,0,1},
    {1,1,1,1,1,1,1,1}
};
int usa1X,usa1Y,cheie1X,cheie1Y;
bool gameover,gamestart,ok1,oksaritura,win,ok2;
enum directie {STOP=0,STANGA,DREAPTA,SUS,JOS,SARITURA};
directie dir1,dir2;
void setup1()
{
    gameover=false;
    win=false;
    dir1=STOP;
    dir2=STOP;
    spike1X=3;
    spike1Y=1;
    spike2X=2;
    health=100;
    spike2Y=2;
    cheieX=4;
    cheieY=1;
    usaX=4;
    usaY=3;
    playerX=1;
    playerY=1;
}
void setup2()
{
    win=false;
    gameover=false;
    dir1=STOP;
    dir2=STOP;
    cheieX=1;
    cheieY=1;
    usaX=6;
    usaY=5;
    usa1X=1;
    usa1Y=2;
    cheie1X=6;
    cheie1Y=1;
    health=100;
    playerX=3;
    playerY=4;
    ok2=0;
    ok1=0;
}
void draw1()
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
            if(playerX==i && playerY==j)
                cout<<'P';
            else if(a[i][j]==2)
                cout<<'C';
            else if(a[i][j]==3)
                cout<<'U';
            else  if(a[i][j]==0)
                cout<<' ';
            else if(a[i][j]==1)
                cout<<'#';
            else if(a[i][j]==5)
                cout<<'^';
            else if(a[i][j]==6)
                cout<<']';
            else if(a[i][j])
                cout<<'-';
        cout<<'\n';
    }
    cout<<"health:"<<health;
}
void draw2()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            if(playerX==i && playerY==j)
                cout<<'P';
            else if(b[i][j]==2)
                cout<<'C';
            else if(b[i][j]==3)
                cout<<'U';
            else  if(b[i][j]==0)
                cout<<' ';
            else if(b[i][j]==1)
                cout<<'#';
            else if(b[i][j]==5)
                cout<<'^';
            else if(b[i][j]==6)
                cout<<']';
            else if(b[i][j])
                cout<<'-';
        cout<<'\n';
    }
    cout<<"health:"<<health;

}
void logic1()
{
    if(dir1==STANGA && a[playerX-1][playerY]==1)
    {
        system("cls");
        cout<<"You can't walk through walls u dummy!";
        Sleep(500);
        system("cls");
    }
    else if(dir1==DREAPTA && a[playerX+1][playerY]==1 )
    {
        system("cls");
        cout<<"You can't walk through walls u dummy!";
        Sleep(500);
        system("cls");
    }
    else if(dir1==SUS && a[playerX][playerY-1]==1)
    {
        system("cls");
        cout<<"You can't walk through walls u dummy!";
        Sleep(500);
        system("cls");
    }
    else if(dir1==JOS && a[playerX][playerY+1]==1)
    {
        system("cls");
        cout<<"You can't walk through walls u dummy!";
        Sleep(500);
        system("cls");
    }
    else if((dir1==JOS && a[playerX][playerY+1]==5 && dir2!=SARITURA) || (dir1==JOS && a[playerX][playerY+2]==5 && dir2==SARITURA))
    {
        system("cls");
        if(health-50==0)
        {
            gameover=true;
            win=false;
        }
        else
        {
            cout<<"Auch that must have hurt.";
            health=health-50;
            Sleep(500);
            system("cls");
        }
    }
    else if((dir1==SUS && a[playerX][playerY-1]==5 && dir2!=SARITURA) || (dir1==SUS && a[playerX][playerY-2]==5 && dir2==SARITURA))
    {
        system("cls");

        if(health-50==0)
        {
            gameover=true;
            win=false;
        }
        else
        {
            cout<<"Auch that must have hurt.";
            health=health-50;
            Sleep(500);
            system("cls");
        }
    }
    else if((dir1==DREAPTA && a[playerX+1][playerY]==5 && dir2!=SARITURA) || (dir1==DREAPTA && a[playerX+2][playerY]==5 && dir2==SARITURA))
    {
        system("cls");
        if(health-50==0)
        {
            gameover=true;
            win=false;
        }
        else
        {
            health=health-50;
            cout<<"Auch that must have hurt.";
            Sleep(500);
            system("cls");
        }
    }
    else if((dir1==STANGA && a[playerX-1][playerY]==5 && dir2!=SARITURA) ||(dir1==STANGA && a[playerX-2][playerY]==5 && dir2==SARITURA))
    {
        system("cls");
        if(health-50==0)
        {
            gameover=true;
            win=false;
        }
        else
        {
            health=health-50;
            cout<<"Auch that must have hurt.";
            Sleep(500);
            system("cls");
        }
    }
    else if(((dir1==JOS && a[playerX][playerY+1]==2) || (dir1==SUS && a[playerX][playerY-1]==2) || (dir1==DREAPTA && a[playerX+1][playerY]==2) || (dir1==STANGA && a[playerX-1][playerY]==2)) && dir2!=SARITURA)
    {
        playerX=cheieX;
        playerY=cheieY;
        a[cheieX][cheieY]=0;
        system("cls");
        cout<<"You found the key.Now you can leave"<<'\n';
        Sleep(500);
        system("cls");
        ok1=1;
    }
    else if(((dir1==JOS && a[playerX][playerY+2]==2) || (dir1==SUS && a[playerX][playerY-2]==2) || (dir1==DREAPTA && a[playerX+2][playerY]==2) || (dir1==STANGA && a[playerX-2][playerY]==2)) && dir2==SARITURA)
    {
        playerX=cheieX;
        playerY=cheieY;
        a[cheieX][cheieY]=0;
        system("cls");
        cout<<"You found the key.Now you can leave"<<'\n';
        Sleep(500);
        system("cls");
        ok1=1;
    }
    else if(((dir1==JOS && a[playerX][playerY+2]==7) || (dir1==SUS && a[playerX][playerY-2]==7) || (dir1==DREAPTA && a[playerX+2][playerY]==7) || (dir1==STANGA && a[playerX-2][playerY]==7)) && dir2==SARITURA)
    {
        playerX=cheieX;
        playerY=cheieY;
        a[cheieX][cheieY]=0;
        system("cls");
        cout<<"You found the key.Now you can open the door"<<'\n';
        Sleep(500);
        system("cls");
        ok2=1;
    }
    else if(((dir1==JOS && a[playerX][playerY+1]==7) || (dir1==SUS && a[playerX][playerY-1]==7) || (dir1==DREAPTA && a[playerX+1][playerY]==7) || (dir1==STANGA && a[playerX-1][playerY]==7)) && dir2!=SARITURA)
    {
        playerX=cheieX;
        playerY=cheieY;
        a[cheieX][cheieY]=0;
        system("cls");
        cout<<"You found the key.Now you can open the door"<<'\n';
        Sleep(500);
        system("cls");
        ok2=1;
    }
    else if((((dir1==JOS && a[playerX][playerY+1]==3) || (dir1==SUS && a[playerX][playerY-1]==3) || (dir1==DREAPTA && a[playerX+1][playerY]==3) || (dir1==STANGA && a[playerX-1][playerY]==3)) && ok1==0)&& dir2!=SARITURA)
    {
        system("cls");
        cout<<"You can't leave without a key"<<'\n';
        Sleep(500);
        system("cls");
    }
    else if((((dir1==JOS && a[playerX][playerY+2]==3) || (dir1==SUS && a[playerX][playerY-2]==3) || (dir1==DREAPTA && a[playerX+2][playerY]==3) || (dir1==STANGA && a[playerX-2][playerY]==3)) && ok1==0)&& dir2==SARITURA)
    {
        system("cls");
        cout<<"You can't leave without a key"<<'\n';
        Sleep(500);
        system("cls");
    }
    else if((((dir1==JOS && a[playerX][playerY+2]==6) || (dir1==SUS && a[playerX][playerY-2]==6) || (dir1==DREAPTA && a[playerX+2][playerY]==6) || (dir1==STANGA && a[playerX-2][playerY]==6)) && ok2==0)&& dir2==SARITURA)
    {
        system("cls");
        cout<<"You can't enter without a key"<<'\n';
        Sleep(500);
        system("cls");
    }
    else if((((dir1==JOS && a[playerX][playerY+1]==6) || (dir1==SUS && a[playerX][playerY-1]==6) || (dir1==DREAPTA && a[playerX+1][playerY]==6) || (dir1==STANGA && a[playerX-1][playerY]==6)) && ok2==0)&& dir2!=SARITURA)
    {
        system("cls");
        cout<<"You can't enter without a key"<<'\n';
        Sleep(500);
        system("cls");
    }
    else if((((dir1==JOS && a[playerX][playerY+1]==3) || (dir1==SUS && a[playerX][playerY-1]==3) || (dir1==DREAPTA && a[playerX+1][playerY]==3) || (dir1==STANGA && a[playerX-1][playerY]==3)) && ok1==1) && dir2!=SARITURA)
    {
        gameover= true;
        win=true;
    }
    else if((((dir1==JOS && a[playerX][playerY+2]==3) || (dir1==SUS && a[playerX][playerY-2]==3) || (dir1==DREAPTA && a[playerX+2][playerY]==3) || (dir1==STANGA && a[playerX-2][playerY]==3)) && ok1==1) && dir2==SARITURA)
    {
        gameover= true;
        win=true;
    }
    else if((((dir1==JOS && a[playerX][playerY+1]==6) || (dir1==SUS && a[playerX][playerY-1]==6) || (dir1==DREAPTA && a[playerX+1][playerY]==6) || (dir1==STANGA && a[playerX-1][playerY]==6)) && ok2==1) && dir2!=SARITURA)
    {
        system("cls");
        cout<<"You opened the door"<<'\n';
        Sleep(500);
        system("cls");
        a[usa1X][usa1Y]=0;
        playerX=usa1X;
        playerY=usa1Y;
    }
    else if((((dir1==JOS && a[playerX][playerY+2]==6) || (dir1==SUS && a[playerX][playerY-2]==6) || (dir1==DREAPTA && a[playerX+2][playerY]==6) || (dir1==STANGA && a[playerX-2][playerY]==6)) && ok2==1) && dir2==SARITURA)
    {
        system("cls");
        cout<<"You opened the door"<<'\n';
        Sleep(500);
        system("cls");
        a[usa1X][usa1Y]=0;
        playerX=usa1X;
        playerY=usa1Y;
    }
    else if(dir2!=SARITURA)
    {
        switch(dir1)
        {
        case STANGA:
            playerX=playerX-1;
            break;
        case DREAPTA:
            playerX=playerX+1;
            break;
        case SUS:
            playerY=playerY-1;
            break;
        case JOS:
            playerY=playerY+1;
            break;
        default:
            break;
        }
    }
    else
    {
        if(dir1==STANGA)
        {
            if(a[playerX-2][playerY]==1 || playerX-2<=0)
            {
                system("cls");
                cout<<"You can't walk through walls u dummy!";
                Sleep(500);
                system("cls");
                oksaritura=1;
            }
        }
        else if(dir1==DREAPTA)
        {
            if(a[playerX+2][playerY]==1 || playerX+2>=6)
            {
                system("cls");
                cout<<"You can't walk through walls u dummy!";
                Sleep(500);
                system("cls");
                oksaritura=1;
            }
        }
        else if(dir1==SUS)
        {
            if(a[playerX][playerY-2]==1 || playerY-2<=0)
            {
                system("cls");
                cout<<"You can't walk through walls u dummy!";
                Sleep(500);
                system("cls");
                oksaritura=1;
            }
        }
        else if(dir1==JOS)
        {
            if(a[playerX][playerY+2]==1 || playerY+2>=5)
            {
                system("cls");
                cout<<"You can't walk through walls u dummy!";
                Sleep(500);
                system("cls");
                oksaritura=1;
            }
        }
        if(oksaritura==0)
        {
            switch(dir1)
            {
            case STANGA:
                playerX=playerX-2;
                break;
            case DREAPTA:
                playerX=playerX+2;
                break;
            case SUS:
                playerY=playerY-2;
                break;
            case JOS:
                playerY=playerY+2;
                break;
            default:
                break;
            }
        }
    }
}
void logic2()
{
    if(dir1==STANGA && b[playerX-1][playerY]==1)
    {
        system("cls");
        cout<<"You can't walk through walls u dummy!";
        Sleep(500);
        system("cls");
    }
    else if(dir1==DREAPTA && b[playerX+1][playerY]==1 )
    {
        system("cls");
        cout<<"You can't walk through walls u dummy!";
        Sleep(500);
        system("cls");
    }
    else if(dir1==SUS && b[playerX][playerY-1]==1)
    {
        system("cls");
        cout<<"You can't walk through walls u dummy!";
        Sleep(500);
        system("cls");
    }
    else if(dir1==JOS && b[playerX][playerY+1]==1)
    {
        system("cls");
        cout<<"You can't walk through walls u dummy!";
        Sleep(500);
        system("cls");
    }
    else if((dir1==JOS && b[playerX][playerY+1]==5 && dir2!=SARITURA) || (dir1==JOS && b[playerX][playerY+2]==5 && dir2==SARITURA))
    {
        system("cls");
        if(health-50==0)
        {
            gameover=true;
            win=false;
        }
        else
        {
            cout<<"Auch that must have hurt.";
            health=health-50;
            Sleep(500);
            system("cls");
        }
    }
    else if((dir1==SUS && b[playerX][playerY-1]==5 && dir2!=SARITURA) || (dir1==SUS && b[playerX][playerY-2]==5 && dir2==SARITURA))
    {
        system("cls");

        if(health-50==0)
        {
            gameover=true;
            win=false;
        }
        else
        {
            cout<<"Auch that must have hurt.";
            health=health-50;
            Sleep(500);
            system("cls");
        }
    }
    else if((dir1==DREAPTA && b[playerX+1][playerY]==5 && dir2!=SARITURA) || (dir1==DREAPTA && b[playerX+2][playerY]==5 && dir2==SARITURA))
    {
        system("cls");
        if(health-50==0)
        {
            gameover=true;
            win=false;
        }
        else
        {
            health=health-50;
            cout<<"Auch that must have hurt.";
            Sleep(500);
            system("cls");
        }
    }
    else if((dir1==STANGA && b[playerX-1][playerY]==5 && dir2!=SARITURA) ||(dir1==STANGA && b[playerX-2][playerY]==5 && dir2==SARITURA))
    {
        system("cls");
        if(health-50==0)
        {
            gameover=true;
            win=false;
        }
        else
        {
            health=health-50;
            cout<<"Auch that must have hurt.";
            Sleep(500);
            system("cls");
        }
    }
    else if(((dir1==JOS && b[playerX][playerY+1]==2) || (dir1==SUS && b[playerX][playerY-1]==2) || (dir1==DREAPTA && b[playerX+1][playerY]==2) || (dir1==STANGA && b[playerX-1][playerY]==2)) && dir2!=SARITURA)
    {
        playerX=cheieX;
        playerY=cheieY;
        b[cheieX][cheieY]=0;
        system("cls");
        cout<<"You found the key.Now you can leave"<<'\n';
        Sleep(500);
        system("cls");
        ok1=1;
    }
    else if(((dir1==JOS && b[playerX][playerY+2]==2) || (dir1==SUS && b[playerX][playerY-2]==2) || (dir1==DREAPTA && b[playerX+2][playerY]==2) || (dir1==STANGA && b[playerX-2][playerY]==2)) && dir2==SARITURA)
    {
        playerX=cheieX;
        playerY=cheieY;
        b[cheieX][cheieY]=0;
        system("cls");
        cout<<"You found the key.Now you can leave"<<'\n';
        Sleep(500);
        system("cls");
        ok1=1;
    }
    else if(((dir1==JOS && b[playerX][playerY+2]==7) || (dir1==SUS && b[playerX][playerY-2]==7) || (dir1==DREAPTA && b[playerX+2][playerY]==7) || (dir1==STANGA && b[playerX-2][playerY]==7)) && dir2==SARITURA)
    {
        playerX=cheie1X;
        playerY=cheie1Y;
        b[cheie1X][cheie1Y]=0;
        system("cls");
        cout<<"You found the key.Now you can open the door"<<'\n';
        Sleep(500);
        system("cls");
        ok2=1;
    }
    else if(((dir1==JOS && b[playerX][playerY+1]==7) || (dir1==SUS && b[playerX][playerY-1]==7) || (dir1==DREAPTA && b[playerX+1][playerY]==7) || (dir1==STANGA && b[playerX-1][playerY]==7)) && dir2!=SARITURA)
    {
        playerX=cheie1X;
        playerY=cheie1Y;
        b[cheie1X][cheie1Y]=0;
        system("cls");
        cout<<"You found the key.Now you can open the door"<<'\n';
        Sleep(500);
        system("cls");
        ok2=1;
    }
    else if((((dir1==JOS && b[playerX][playerY+1]==3) || (dir1==SUS && b[playerX][playerY-1]==3) || (dir1==DREAPTA && b[playerX+1][playerY]==3) || (dir1==STANGA && b[playerX-1][playerY]==3)) && ok1==0)&& dir2!=SARITURA)
    {
        system("cls");
        cout<<"You can't leave without a key"<<'\n';
        Sleep(500);
        system("cls");
    }
    else if((((dir1==JOS && b[playerX][playerY+2]==3) || (dir1==SUS && b[playerX][playerY-2]==3) || (dir1==DREAPTA && b[playerX+2][playerY]==3) || (dir1==STANGA && b[playerX-2][playerY]==3)) && ok1==0)&& dir2==SARITURA)
    {
        system("cls");
        cout<<"You can't leave without a key"<<'\n';
        Sleep(500);
        system("cls");
    }
    else if((((dir1==JOS && b[playerX][playerY+2]==6) || (dir1==SUS && b[playerX][playerY-2]==6) || (dir1==DREAPTA && b[playerX+2][playerY]==6) || (dir1==STANGA && b[playerX-2][playerY]==6)) && ok2==0)&& dir2==SARITURA)
    {
        system("cls");
        cout<<"You can't enter without a key"<<'\n';
        Sleep(500);
        system("cls");
    }
    else if((((dir1==JOS && b[playerX][playerY+1]==6) || (dir1==SUS && b[playerX][playerY-1]==6) || (dir1==DREAPTA && b[playerX+1][playerY]==6) || (dir1==STANGA && b[playerX-1][playerY]==6)) && ok2==0)&& dir2!=SARITURA)
    {
        system("cls");
        cout<<"You can't enter without a key"<<'\n';
        Sleep(500);
        system("cls");
    }
    else if((((dir1==JOS && b[playerX][playerY+1]==3) || (dir1==SUS && b[playerX][playerY-1]==3) || (dir1==DREAPTA && b[playerX+1][playerY]==3) || (dir1==STANGA && b[playerX-1][playerY]==3)) && ok1==1) && dir2!=SARITURA)
    {
        gameover= true;
        win=true;
    }
    else if((((dir1==JOS && b[playerX][playerY+2]==3) || (dir1==SUS && b[playerX][playerY-2]==3) || (dir1==DREAPTA && b[playerX+2][playerY]==3) || (dir1==STANGA && b[playerX-2][playerY]==3)) && ok1==1) && dir2==SARITURA)
    {
        gameover= true;
        win=true;
    }
    else if((((dir1==JOS && b[playerX][playerY+1]==6) || (dir1==SUS && b[playerX][playerY-1]==6) || (dir1==DREAPTA && b[playerX+1][playerY]==6) || (dir1==STANGA && b[playerX-1][playerY]==6)) && ok2==1) && dir2!=SARITURA)
    {
        system("cls");
        cout<<"You have opened the door"<<'\n';
        Sleep(500);
        system("cls");
        a[usa1X][usa1Y]=0;
    }
    else if((((dir1==JOS && b[playerX][playerY+2]==6) || (dir1==SUS && b[playerX][playerY-2]==6) || (dir1==DREAPTA && b[playerX+2][playerY]==6) || (dir1==STANGA && b[playerX-2][playerY]==6)) && ok2==1) && dir2==SARITURA)
    {
        system("cls");
        cout<<"You have opened the door"<<'\n';
        Sleep(500);
        system("cls");
        a[usa1X][usa1Y]=0;
    }
    else if(dir2!=SARITURA)
    {
        switch(dir1)
        {
        case STANGA:
            playerX=playerX-1;
            break;
        case DREAPTA:
            playerX=playerX+1;
            break;
        case SUS:
            playerY=playerY-1;
            break;
        case JOS:
            playerY=playerY+1;
            break;
        default:
            break;
        }
    }
    else
    {
        if(dir1==STANGA)
        {
            if(b[playerX-2][playerY]==1 || playerX-2<=0)
            {
                system("cls");
                cout<<"You can't walk through walls u dummy!";
                Sleep(500);
                system("cls");
                oksaritura=1;
            }
        }
        else if(dir1==DREAPTA)
        {
            if(b[playerX+2][playerY]==1 || playerX+2>=8)
            {
                system("cls");
                cout<<"You can't walk through walls u dummy!";
                Sleep(500);
                system("cls");
                oksaritura=1;
            }
        }
        else if(dir1==SUS)
        {
            if(b[playerX][playerY-2]==1 || playerY-2<=0)
            {
                system("cls");
                cout<<"You can't walk through walls u dummy!";
                Sleep(500);
                system("cls");
                oksaritura=1;
            }
        }
        else if(dir1==JOS)
        {
            if(b[playerX][playerY+2]==1 || playerY+2>=8)
            {
                system("cls");
                cout<<"You can't walk through walls u dummy!";
                Sleep(500);
                system("cls");
                oksaritura=1;
            }
        }
        if(oksaritura==0)
        {
            switch(dir1)
            {
            case STANGA:
                playerX=playerX-2;
                break;
            case DREAPTA:
                playerX=playerX+2;
                break;
            case SUS:
                playerY=playerY-2;
                break;
            case JOS:
                playerY=playerY+2;
                break;
            default:
                break;
            }
        }
    }
}
int main()
{
    cout<<"Welcome to The impossible maze."<<'\n';
    cout<<"Press a key to start:"<<'\n';
    while(1)
    {
        if(_kbhit())
            break;
    }
    getch();
    system("cls");
    cout<<"Hello?....";
    Sleep(1000);
    cout<<"Can someone hear me?...";
    while(1)
    {
        if(_kbhit())
            break;
    }
    getch();
    system("cls");
    cout<<"I dont think so....";
    Sleep(1000);
    cout<<"Where am I?...";
    Sleep(1000);
    cout<<"I don't remember anything. Not even who I am.";
    while(1)
    {
        if(_kbhit())
            break;
    }
    getch();
    system("cls");
    cout<<"Hm..What is this?...A door let's see where it goes!";
    while(1)
    {
        if(_kbhit())
            break;
    }
    getch();
    system("cls");
    cout<<"Use w to move forward."<<'\n';
    cout<<"Use a to move to the left."<<'\n';
    cout<<"Use s to move backwards."<<'\n';
    cout<<"Use d to move to the right."<<'\n';
    cout<<"If you want to jump you need to press space then press the key coresponding to the direction you want to move to.";
    while(1)
    {
        if(_kbhit())
            break;
    }
    getch();
    system("cls");
    setup1();
    draw1();
    while(gameover!=1)
    {

        if(_kbhit())
        {
            switch(_getch())
            {
            case 'a':
            {
                system("cls");
                dir2=dir1;
                dir1=SUS;
                logic1();
                draw1();
            }
            break;
            case 'd':
            {
                system("cls");
                dir2=dir1;
                dir1=JOS;
                logic1();
                draw1();
            }

            break;
            case 's':
            {
                system("cls");
                dir2=dir1;
                dir1=DREAPTA;
                logic1();
                draw1();
            }
            break;
            case 'w':
            {
                system("cls");
                dir2=dir1;
                dir1=STANGA;
                logic1();
                draw1();
            }
            break;
            case 'x':
            {
                system("cls");
                cout<<"MADA";
                return 0;
            }
            case ' ':
            {
                system("cls");
                dir2=dir1;
                dir1=SARITURA;
                logic1();
                draw1();
            }
            }
        }
    }
    system("cls");
    if(win==true)
    {
        cout<<"I somehow managed to escape!"<<'\n';
        Sleep(750);
        cout<<"Hm...what is this??";
        system("cls");
        cout<<"-Hello subject #342.You must be confused about everything that is going on."<<'\n'<<"U were brought here because you as many other before you are here to become an experiment."<<'\n';
        cout<<"You have 24 hours to live unless you manage to finish this course and take the antidote of the poison that's in your body."<<'\n';
        cout<<"If you will not succed there will be some unknown effects that might happen to you but in the most part it 99.99% sure you will die"<<'\n';
        while(1)
        {
            if(_kbhit())
                break;
        }
        getch();
        cout<<"-Wh..What do you mean I will die in 24 hours?"<<'\n';
        while(1)
        {
            if(_kbhit())
                break;
        }
        getch();
        cout<<"-That's right.Now go and finish this maze or you will die.";
        while(1)
        {
            if(_kbhit())
                break;
        }
        getch();
        system("cls");
        setup2();
        draw2();
        while(gameover!=1)
        {

            if(_kbhit())
            {
                switch(_getch())
                {
                case 'a':
                {
                    system("cls");
                    dir2=dir1;
                    dir1=SUS;
                    logic2();
                    draw2();
                }
                break;
                case 'd':
                {
                    system("cls");
                    dir2=dir1;
                    dir1=JOS;
                    logic2();
                    draw2();
                }

                break;
                case 's':
                {
                    system("cls");
                    dir2=dir1;
                    dir1=DREAPTA;
                    logic2();
                    draw2();
                }
                break;
                case 'w':
                {
                    system("cls");
                    dir2=dir1;
                    dir1=STANGA;
                    logic2();
                    draw2();
                }
                break;
                case 'x':
                {
                    system("cls");
                    cout<<"MADA";
                    return 0;
                }
                case ' ':
                {
                    system("cls");
                    dir2=dir1;
                    dir1=SARITURA;
                    logic2();
                    draw2();
                }
                }
            }
        }
        if(win==true)
        {
            cout<<"BRAVO";
            return 0;
        }


    }
    else
        cout<<"GAME OVER.";
}
