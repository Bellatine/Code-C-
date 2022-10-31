#define MAX 100
#define oo 1000
int n,m,w,u,v;
int G[MAX][MAX];

int dist[MAX];
int truoc[MAX];

void dijkstra(int s)
{
    queue<int> Q;

    for (int u = 1; u <= n; u++)
        dist[u] = oo;

    truoc[s] = -1;
    dist[s] = 0;
    Q.push(s);

    while (Q.empty() != true)
    {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v <= n; v++)
            if (G[u][v] != 0)
            {
                if (dist[v] >(dist[u] +G[u][v]))
                {
                    Q.push(v);
                    truoc[v] = u;
                    dist[v] = dist[u] + G[u][v];
                }
            }
    }
}



int main(int argc, char const *argv[])
{
    for (int i=0; i < MAX; i++)
        for(int j=0; j< MAX; j++)
            G[i][j] = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int e=0; e < m; e++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u][v]=G[v][u]=w;
        }

    dijkstra(1);
    for (int u = 2; u <= n; u++){
        v=u;
        do{
            cout<<v<<"<-";
            v=truoc[v];
        }
        while(v!=1);
        cout<<"1\n";
    }
    return 0;
}
