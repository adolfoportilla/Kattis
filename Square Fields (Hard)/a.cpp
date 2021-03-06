// Meysam Aghighi

#include <algorithm>
#include <iostream>
using namespace std;

int T,k,n,best;
int x[20],y[20];
int minx[20],miny[20],maxx[20],maxy[20];

void solve(int next, int marked, int cur){
	cout << next << " " << marked << " " << cur << endl;
    if (marked<=k && cur<=best){
        if (next == n) best = min(best,cur);
        else for (int i=0;i<marked+1;i++){
                int temp1 = minx[i], temp2 = miny[i], temp3 = maxx[i], temp4 = maxy[i];
                minx[i] = min(minx[i],x[next]), miny[i] = min(miny[i],y[next]);
                maxx[i] = max(maxx[i],x[next]), maxy[i] = max(maxy[i],y[next]);
                solve( next+1 , max(marked,i+1) , max(cur,max(maxx[i]-minx[i],maxy[i]-miny[i])) );
                minx[i] = temp1, miny[i] = temp2, maxx[i] = temp3, maxy[i] = temp4;
		}
    }
}

int main(){
    cin >> T;
    for (int ii=0;ii<T;ii++){
        cin >> n >> k;
        for (int i=0;i<n;i++) cin >> x[i] >> y[i];
        for (int i=0;i<20;i++) minx[i] = miny[i] = 100000, maxx[i] = maxy[i] = -1;
        best = 100000;
        solve(0,0,0);
        cout << "Case #" << ii+1 << ": " << best << endl;
    }
    return 0;
}
