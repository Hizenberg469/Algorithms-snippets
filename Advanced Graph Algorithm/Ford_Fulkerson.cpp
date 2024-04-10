#include <bits/stdc++.h>

//used for ignoring/removing the assert statement at compile-time.
//#define NDEBUG

using namespace std;

class Edge{
public:
    int from, to;
    Edge* residual;
    long flow;
    long capacity;

    Edge(int from, int to, long capacity){
        this->from = from;
        this->to = to;
        this->capacity = capacity;
        flow = 0;
    }

    bool isResidual(){
        return capacity == 0;
    }

    long remainingCapacity(){
        return capacity - flow;
    }

    void augment(long bottleNeck){
        flow += bottleNeck;
        residual->flow -= bottleNeck;
    }

    string toString(int s ,int t){
        string u = (from == s) ? "s" : ((from == t) ? "t" : to_string(from));
        string v = (to == s ) ? "s" : ((to == t) ? "t" : to_string(to));
        string res = "Edge " + u + " -> " + v + " | " + " flow = " +
        to_string(flow) + " | " + " capacity: " + to_string(capacity)
        + " | " + " is residual: " + to_string((int)isResidual()) ;
        return res;
    }
};

class NetworkFlowSolverBase{
protected :
    long INF = INT_MAX/2;
    //Input: n = Number of nodes, s = source, t = sink
    int n , s, t;

    //'visited' and 'visitedToken' are keep track of the
    //visited nodes.
protected:
    int visitedToken = 1;
    int* visited;


    bool solved;
    long maxFlow;

    //Representing the graph.
    vector<vector<Edge*>> graph;

public:

    NetworkFlowSolverBase(int n, int s,int t){
        this->n = n;
        this->s = s;
        this->t = t;
        graph.resize(n);
        visited = new int[n];
    }

    void addEdge(int from ,int to ,long capacity){
        assert(capacity > 0);

        Edge* e1 = new Edge(from, to , capacity);
        Edge* e2 = new Edge(to, from, 0);
        e1->residual = e2;
        e2->residual = e1;
        graph[from].push_back(e1);
        graph[to].push_back(e2);
    }

    vector<vector<Edge*>> getGraph(){
        execute();
        return graph;
    }

    long getMaxFlow(){
        execute();
        return maxFlow;
    }

private :
    void execute(){
        if( solved )return;
        solved = true;
        solve();
    }

public:
    virtual void solve(){}
};


class FordFulkersonDfsSolver : public NetworkFlowSolverBase{
public :
    FordFulkersonDfsSolver(int n, int s, int t) : NetworkFlowSolverBase(n,s,t){
    }

    void solve(){
        for( long f = dfs(s, INF) ; f != 0 ; f = dfs(s,INF)){
            visitedToken++;
            maxFlow += f;
        }
    }

private :
    long dfs(int node, long flow){
        if( node == t )return flow;

        visited[node] = visitedToken;

        vector<Edge*> edges = graph[node];
        for(Edge* edge : edges){
            if( edge->remainingCapacity() > 0 && visited[edge->to] != visitedToken){
                long bottleNeck = dfs(edge->to , min(flow,edge->remainingCapacity()));

                if( bottleNeck > 0){
                    edge->augment(bottleNeck);
                    return bottleNeck;
                }
            }
        }
        return 0;
    }
};


int main(){

    int n = 12;

    int s = n - 2;
    int t = n - 1;

    NetworkFlowSolverBase* solver = new FordFulkersonDfsSolver(n,s,t);

    //Edges from Source
    solver->addEdge(s, 0, 10);
    solver->addEdge(s, 1, 5);
    solver->addEdge(s, 2, 10);

    //Middle edges
    solver->addEdge(0, 3, 10);
    solver->addEdge(1, 2, 10);
    solver->addEdge(2, 5, 15);
    solver->addEdge(3, 1, 2);
    solver->addEdge(3, 6, 15);
    solver->addEdge(4, 1, 15);
    solver->addEdge(4, 3, 3);
    solver->addEdge(5, 4, 4);
    solver->addEdge(5, 8, 10);
    solver->addEdge(6, 7, 10);
    solver->addEdge(7, 4, 10);
    solver->addEdge(7, 5, 7);

    //Edges to sink
    solver->addEdge(6, t, 15);
    solver->addEdge(8, t, 10);

    cout << "Maximum Flow is: " << solver->getMaxFlow() << '\n';

    vector<vector<Edge*>> resultGraph = solver->getGraph();

    for(vector<Edge*> edges : resultGraph ){
        for( Edge* e : edges){
            cout << e->toString(s,t) << '\n';
        }
    }
    return 0;
}
