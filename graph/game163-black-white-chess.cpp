#include <iostream>
#include <vector>
using namespace std;
#define N 8

char ch[2]= {'*','o'};

int dirs[8][2]= {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};


void solve(vector<vector<char> >& grid, int x, int y, char c)
{
    grid[x][y]=c;
    for(int i=0; i<8; i++)
    {
        vector<vector <int> > paths;
        int nx=x+dirs[i][0];
        int ny=y+dirs[i][1];
        while(nx>=0 && nx<N && ny>=0 && ny<N )
        {
            if(grid[nx][ny]!='.' && grid[nx][ny]!=c)
            {
                paths.push_back({nx,ny});
                nx=nx+dirs[i][0];
                ny=ny+dirs[i][1];
            }
            else if(grid[nx][ny]==c)
            {
                for(int i=0; i<paths.size(); i++)
                {
                    grid[paths[i][0]][paths[i][1]]=c;
                }
                break;
            }
            else if(grid[nx][ny]=='.')
                break;
        }
    }
}

int main()
{
    int s;
    vector<vector<char> > grid(N,vector<char>(N));
    cin>>s;
    int n,x,y,t;
    while(s--)
    {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin>>grid[i][j];
        cin>>n;
        //cout<<n<<endl;
        while(n--)
        {
            cin>>x>>y>>t;
            solve(grid,x,y,ch[t]);
        }
        int w=0,b=0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(grid[i][j]=='*')
                    b++;
                else if(grid[i][j]=='o')
                    w++;
            }
        }
        cout<<b<<" "<<w<<endl;
    }
    return 0;
}
