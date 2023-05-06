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

    int max_degree_id=0;

public:
    void readGraph(string &path);
    void printGraph();
    void print_Neighbor();
    void print_label_set();
};



/**
 * 有优化空间 因为寻找核心的时候每次都进行了查询与比较
 * 只覆盖点集 基于度 当点集归零 边集自然也归零
 * 要求：度最大优先 且保持连通状态
 * @param graph 查询图
 */
vector<int> findKernel(const Graph &graph);

/**
 * 寻找当前邻接组内最大度数节点
 * 配合findKernel()使用
 * @param adj
 * @param degree
 * @return
 */
int findMax(const unordered_set<int> &adj,const vector<int> &degree);







void preProsessing(const Graph &graph,vector<int> &kernelSet,unordered_map<int,multiset<int>> &queryNeighbor,unordered_map<int,vector<pair<int,int>>> &index);
/**
 * 在索引内寻找匹配 目前仅实现增加操作 默认为增加操作
 * @param index
 * @param node_1
 * @param node_2
 * @param flag true 增加 false 减少
 */

void updateIndex(int a, int b ,Graph &query, Graph &data,vector<unordered_set<int>> &com_index,vector<multimap<int,int>> &miss_index);


void preProsessing(Graph &query, Graph &data,vector<unordered_set<int>> &com_index,vector<multimap<int,int>> &miss_index);

bool com_Match(multiset<int> &queryNode,multiset<int> &dataNode);
int miss_Match(multiset<int> &queryNode,multiset<int> &dataNode);
#endif //CSM_ALG_H
