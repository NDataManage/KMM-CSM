#ifndef CSM_ALG_H
#define CSM_ALG_H
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;
class Graph{
public:
    int vNum,eNum;
    vector<int> node_id;
    vector<int> node_label;
    vector<int> node_adj;
    vector<int> adj_find;
    vector<int> node_degree;
    unordered_map<int,multiset<int>> neighbor;        //node_id: nei_node01_label...
    unordered_map<int,unordered_set<int>> label_set;  //label: node_id ...
    vector<unordered_set<int>> adj;
    map<pair<int,int>,set<pair<int,int>>> edge_count; // <label_a,label_b> -> {(0,1),(2,3) ...}  label_a < label_b
    int max_degree_id=0;
    unordered_set<int> kernel_set;  // only for query

public:
    void readGraph(string &path);
    void printGraph();
    void print_Neighbor();
    void print_label_set();
    void set_adj();
    void print_adj();
    void print_edge_count();
    void print_kernel();
    void set_kernel();
};



/**
 * 有优化空间 因为寻找核心的时候每次都进行了查询与比较
 * 只覆盖点集 基于度 当点集归零 边集自然也归零
 * 要求：度最大优先 且保持连通状态
 * @param graph 查询图
 */
unordered_set<int> findKernel(const Graph &graph);

/**
 * 寻找当前邻接组内最大度数节点
 * 配合findKernel()使用
 * @param adj
 * @param degree
 * @return
 */
int findMax(const unordered_set<int> &adj,const vector<int> &degree);

void preProsessing(const Graph &graph,vector<int> &kernelSet,unordered_map<int,multiset<int>> &queryNeighbor,unordered_map<int,vector<pair<int,int>>> &index);


void updateIndex(int a, int b ,Graph &query, Graph &data,vector<unordered_set<int>> &com_index,vector<multimap<int,int>> &miss_index);

void preProsessing(Graph &query, Graph &data,vector<unordered_set<int>> &com_index,vector<multimap<int,int>> &miss_index);

bool com_Match(multiset<int> &queryNode,multiset<int> &dataNode);
int miss_Match(multiset<int> &queryNode,multiset<int> &dataNode);


#endif //CSM_ALG_H
