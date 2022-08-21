#include "../core/Common.h"
#include "../core/Graph.h"
using namespace std;

void BFSTest() {
  cds::Graph graph(8);
  graph.AddEdges({{1, 2, 0, 0}, {2, 3}, {2, 7}, {7, 5}, {3, 5}, {4, 6}});
  graph.BFSComponent(
      [](const auto& node, bool _, bool __) { cout << node << ", "; }, 1);
  cout << endl;
  graph.BFS(
      [](const auto& node, bool _, bool __) {
        if (_) cout << endl;
        cout << node << ", ";
      },
      0);
}

void DFSTest() {
  cds::Graph graph(8);
  graph.AddEdges({{1, 2}, {2, 3}, {2, 7}, {7, 5}, {3, 5}, {4, 6}});

  graph.DFSComponent(
      [](const auto& node, bool _, bool __) { cout << node << ", "; }, 1);
  cout << endl;
  graph.DFS(
      [](const auto& node, bool _, bool __) {
        if (_) cout << endl;
        cout << node << ", ";
      },
      0);
}

int main() {
  BFSTest();
  cout << "\n\n" << endl;
  DFSTest();

  cout << "\n\n" << endl;

  return 0;
}