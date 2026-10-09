#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#define delim "_"

using namespace std;

class sofa{
    public:
        int fsr,fsc,ssr,ssc,moves;
        char dir;

        sofa(int fsr,int fsc,int ssr,int ssc,char d,int m){
            this->fsr=fsr;
            this->fsc=fsc;
            this->ssr=ssc;
            this->ssc=ssc;
            this->dir=d;
            this->moves=m;

        }
};

bool canAdd(int r1 , int c1 , int r2 , int c2 , set<string>& vis)
{
    string key = to_string(r1) + delim + to_string(c1) + delim + to_string(r2) + delim + to_string(c2);

    if(vis.count(key)){
        return false;
    }
    else{
        vis.insert(key);
        return true;
    }
}

void solve(){
    int N,M;cin>>N>>M;
    cin.ignore();
    queue<sofa> Q;
    set<string> vis;
    int fsr,fsc,ssr,ssc,sofacount=0;
    fsr=fsc=ssr=ssc=-1;
    vector<string> grid(N);
    for(int i=0;i<N;i++){
        getline(cin,grid[i]);
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(grid[i][j] == 's'){
                sofacount++;
                if(sofacount){
                    fsr=i;fsc=j;
                }else{
                    ssr=i;ssc=j;
                    canAdd(fsr,fsc,ssr,ssc,vis);
                    sofa s(fsr,fsc,ssr,ssc,(fsr==ssr)?'H':'V',0);
                    Q.push(s);
                }
            }
        }
    }


    while(!Q.empty())
        {
                sofa s = Q.front();
                Q.pop();
                if(grid[s.fsr][s.fsc] == 'S' && grid[s.ssr][s.ssc] == 'S'){
                    cout << s.moves << endl;return;
                }
                if(s.dir == 'H'){
                if(s.ssc<M-1 && grid[s.ssr][s.ssc+1] != 'H'){
                    if(canAdd(s.ssr , s.ssc , s.ssr , s.ssc+1 , vis))
                    {
                        Q.push(sofa(s.ssr , s.ssc , s.ssr , s.ssc+1 , 'H' , s.moves+1));
                    }
                }

                if(s.fsc > 0 && grid[s.fsr][s.fsc-1] != 'H'){
                    if(canAdd(s.fsr , s.fsc-1 , s.fsr , s.fsc , vis))
                    {
                        Q.push(sofa(s.fsr , s.fsc-1 , s.fsr , s.fsc , 'H' , s.moves+1));
                    }
                }
                if(s.fsr > 0  && grid[s.fsr-1][s.fsc] != 'H' && grid[s.ssr-1][s.ssc] != 'H'){
                    if(canAdd(s.fsr-1 , s.fsc , s.ssr-1 , s.ssc , vis))
                    {
                        Q.push(sofa(s.fsr-1 , s.fsc , s.ssr-1 , s.ssc , 'H' , s.moves+1));
                   }
                }
                if(s.fsr < N-1  && grid[s.fsr+1][s.fsc] != 'H' && grid[s.ssr+1][s.ssc] != 'H'){
                    if(canAdd(s.fsr+1 , s.fsc , s.ssr+1 , s.ssc , vis))
                    {
                        Q.push(sofa(s.fsr+1 , s.fsc , s.ssr+1 , s.ssc , 'H' , s.moves+1));
                    }

                }

                }
                else if(s.dir == 'V')
                {
                if(s.fsr > 0 && grid[s.fsr-1][s.fsc] != 'H'){
                    if(canAdd(s.fsr-1 , s.fsc , s.fsr , s.fsc , vis))
                    {
                        Q.push(sofa(s.fsr-1 , s.fsc , s.fsr , s.fsc  , 'V' , s.moves+1));
                    }
                }
                if(s.ssr < N-1 && grid[s.ssr+1][s.ssc] != 'H'){
                    if(canAdd(s.ssr , s.ssc , s.ssr+1 , s.ssc , vis))
                    {
                        Q.push(sofa(s.ssr , s.ssc , s.ssr+1 , s.ssc , 'V' , s.moves+1));
                    }
                }
                if(s.ssc < M-1  && grid[s.fsr][s.fsc+1] != 'H' && grid[s.ssr][s.ssc+1] != 'H'){
                    if(canAdd(s.fsr , s.fsc+1 , s.ssr , s.ssc+1 , vis))
                    {
                        Q.push(sofa(s.fsr , s.fsc+1 , s.ssr , s.ssc+1 , 'V' , s.moves+1));
                   }
                }
                if(s.fsc > 0  && grid[s.fsr][s.fsc-1] != 'H' && grid[s.ssr][s.ssc-1] != 'H'){
                    if(canAdd(s.fsr , s.fsc-1 , s.ssr , s.ssc-1 , vis))
                    {
                        Q.push(sofa(s.fsr , s.fsc-1 , s.ssr , s.ssc-1 , 'V' , s.moves+1));
                    }
                }


                

                if(s.dir == 'H' && s.fsr < N-1 && grid[s.fsr+1][s.fsc] != 'H' && grid[s.ssr+1][s.ssc] != 'H'){
                    if(canAdd(s.ssr , s.ssc , s.ssr+1 , s.ssc , vis))
                    {
                        Q.push(sofa(s.ssr , s.ssc , s.ssr+1 , s.ssc , 'V' , s.moves+1));
                    }

                    if(canAdd(s.fsr , s.fsc , s.fsr+1 , s.fsc , vis))
                    {
                        Q.push(sofa(s.fsr , s.fsc , s.fsr+1 , s.fsc , 'V' , s.moves+1));
                    }
                }
                if(s.dir == 'H' && s.fsr > 0  && grid[s.fsr-1][s.fsc] != 'H' && grid[s.ssr-1][s.ssc] != 'H'){
                    if(canAdd(s.ssr-1 , s.ssc , s.ssr , s.ssc , vis))
                    {
                        Q.push(sofa(s.ssr-1 , s.ssc , s.ssr , s.ssc , 'V' , s.moves+1));
                    }

                    if(canAdd(s.fsr-1 , s.fsc , s.fsr , s.fsc , vis))
                    {
                        Q.push(sofa(s.fsr-1 , s.fsc , s.fsr , s.fsc , 'V' , s.moves+1));
                    }
                }



                if(s.dir == 'V' && s.fsc < M-1 && grid[s.fsr][s.fsc+1] != 'H' && grid[s.ssr][s.ssc+1] != 'H'){
                    if(canAdd(s.fsr , s.fsc , s.fsr , s.fsc+1 , vis))
                    {
                        Q.push(sofa(s.fsr , s.fsc , s.fsr , s.fsc+1, 'H' , s.moves+1));
                    }

                    if(canAdd(s.ssr , s.ssc , s.ssr , s.ssc+1 , vis))
                    {
                        Q.push(sofa(s.ssr , s.ssc , s.ssr , s.ssc+1 , 'H' , s.moves+1));
                    }
                }
                if(s.dir == 'V' && s.fsc > 0  && grid[s.fsr][s.fsc-1] != 'H' && grid[s.ssr][s.ssc-1] != 'H'){
                    if(canAdd(s.fsr , s.fsc-1 , s.fsr , s.fsc , vis))
                    {
                        Q.push(sofa(s.fsr , s.fsc-1 , s.fsr , s.fsc , 'H' , s.moves+1));
                    }

                    if(canAdd(s.ssr , s.ssc-1 , s.ssr , s.ssc , vis))
                    {
                        Q.push(sofa(s.ssr , s.ssc-1 , s.ssr , s.ssc , 'H' , s.moves+1));
                    }
                }
            }
        }

        
    cout << "Impossible" << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc =1;
    while(tc--) solve();
}