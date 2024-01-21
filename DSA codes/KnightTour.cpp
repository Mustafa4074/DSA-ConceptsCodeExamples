#include <iostream>
using namespace std;
const int N=8;
int board[N][N]={0};
int moves[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool ismoveValid(int x,int y){
    return(x>=0&& y>=0&&x<N&&y<N&&board[x][y]==0);
}
bool knightTour(int x,int y,int movecount){
    if(movecount==N*N){
    return true;
}
for(int i=0;i<N;i++){
    int new_x=x+moves[i][0];
    int new_y=y+moves[i][1];

if(ismoveValid(new_x,new_y)){
    board[new_x][new_y]=movecount+1;
    if(knightTour(new_x,new_y,movecount+1)){
        return true;
    }
    board[new_x][new_y]=0;

}
}
return false;
}
int main(){
    int x,y;
    cin>>x >>y;
    if(x<0||x>=N||y<0||y>=N){
        cout<<"Invalid starting position"<<endl;
        return 0;
    }
    board[x][y]=1;
    if(knightTour(x,y,1)){
        cout<<"Solution found"<<endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
            cout<<board[i][j]<< "\t";
        }
        cout<< endl;

        }
    }
    else{
        cout<<"No solution"<<endl;
    }

}