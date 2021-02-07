#include<iostream>
#include<fstream>
#define n 6
using namespace std;
class Djkstra{
    int Graph[n][n],Distance[n],cost[n][n];//Distance Will Be Output Array
    bool Selected[n];
    public:
        void getData(){
            ifstream fin("dijkstra1.txt");
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    fin>>Graph[i][j];
                }
            }
            fin.close();
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(Graph[i][j]==0){
                        cost[i][j]=INT_MAX;
                    }
                    else{
                        cost[i][j]=Graph[i][j];
                    }
                }
            }
        }
        void inputDataShow(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<Graph[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void dijkstra(int src){
            for(int i=0;i<n;i++){
                Distance[i]=cost[src][i];
                Selected[i]=false;
            }
            Selected[src]=true;
            Distance[src]=0;
            for(int i=1;i<n-1;i++){
                //This Function Return Minimum Vertex Index Which Are Not Selected
                int u=minDistanceVertex(Distance,Selected);
                //This We Select u Vertex
                Selected[u]=true;
                //Here,We Update Our Adjacent Vertex Length(In Distance Array) Of Selected Vertex
                for(int i=0;i<n;i++){
                    if(!Selected[i]&& Graph[u][i]&&Distance[u] != INT_MAX&&((Distance[u]+Graph[u][i])<Distance[i])){
                        Distance[i]=Distance[u]+Graph[u][i];
                    }
                }
            }
        }
        int minDistanceVertex(int Distance[],bool Selected[]){
            //Here minVertexLength Assume Infinite So That Easy To Compare
            int minVertexLength=INT_MAX,min_index;
            for(int i=0;i<n;i++){
                if(Selected[i]==false&&Distance[i]<=minVertexLength){
                    minVertexLength=Distance[i],min_index=i;
                }
            }
            return min_index;
        }
        void output(){
            for(int i=0;i<n;i++){
                cout<<i<<"    "<<Distance[i]<<endl;
            }
        }
};
int main(){
    Djkstra d1;
    d1.getData();
    d1.inputDataShow();
    cout<<"Enter Your Source Vertex"<<endl;
    int src;
    cin>>src;
    d1.dijkstra(src);
    d1.output();
}

