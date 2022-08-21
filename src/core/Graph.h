#pragma once
#include "./Common.h"

//  -> std::enable_if_t<std::is_invocable_r_v<void, Callback, node_t, bool,
//  bool>, void >

namespace cds {
template <typename node_t,
          typename Wt>  // bool Acyclic, bool Directed, bool Weighted
class GraphBase {
 public:
  struct NodeWtPair {
    node_t node;
    Wt wt;
  };
  struct Edge {
    node_t u;
    node_t v;
    Wt fwdWt;
    Wt bckWt;
  };
  using edge_list_t = std::vector<NodeWtPair>;
  using adl_t = std::vector<edge_list_t>;

 private:
  adl_t graph_;

 public:
  GraphBase() = delete;
  GraphBase(std::size_t N) { graph_ = adl_t(N, edge_list_t{}); }

  inline void AddEdges(std::vector<Edge> _edges) {
    for (const auto& edge : _edges) AddEdge(edge);
  }

  inline void AddEdge(Edge _edge) {
    graph_[_edge.u].push_back({_edge.v, _edge.fwdWt});
    graph_[_edge.v].push_back({_edge.u, _edge.bckWt});
  }

  std::vector<Wt> GetEdges() const noexcept {
    /*vector<Wt> edges;
    for (const auto& edge_list : graph_) {
      for (const auto& edge : edge_list) {
        edges.push_back(edge.wt);
      }
    }
    return edges;*/
  }

  template <typename Callback>
  void _BFSComponent(Callback _callback, std::vector<bool>& visited,
                     std::queue<node_t>& toVisit, node_t _startNode) {
    if (graph_[_startNode].empty()) {
      visited[_startNode] = true;
      _callback(_startNode, true,
                true);  // new component , isolated node(no edges)
      return;
    }

    bool newComponent = true;
    toVisit.push(_startNode);

    while (!toVisit.empty()) {
      const auto& currentNode = toVisit.front();
      if (!visited[currentNode]) {
        visited[currentNode] = true;
        if (!newComponent) [[likely]]
          _callback(currentNode, false, false);
        else {
          _callback(currentNode, true, false);
          newComponent = false;
        }

        for (auto it = graph_[currentNode].begin();
             it != graph_[currentNode].end(); ++it)
          if (!visited[it->node]) toVisit.push(it->node);
      }

      toVisit.pop();
    }
  }

  template <typename Callback>
  void BFSComponent(Callback _callback, node_t _startNode = 0u) {
    const auto graphSize = graph_.size();
    if (graphSize == 0) return;

    std::vector<bool> visited(graphSize, false);
    std::queue<node_t> toVisit;

    _BFSComponent(_callback, visited, toVisit, _startNode);
  }

  template <typename Callback>
  void BFS(Callback _callback, node_t _startNode = 0u) {
    const auto graphSize = graph_.size();
    if (graphSize == 0) return;

    std::vector<bool> visited(graphSize, false);
    std::queue<node_t> toVisit;
    auto visitedAllUntil = visited.begin();

    while (visitedAllUntil != visited.end()) {
      _startNode = std::distance(visited.begin(), visitedAllUntil);
      _BFSComponent(_callback, visited, toVisit, _startNode);
      visitedAllUntil = std::find(visitedAllUntil, visited.end(), false);
    }
    // nullopt
  }

  template <typename Callback>
  void _DFSComponent(Callback _callback, std::vector<bool>& visited,
                     std::stack<node_t>& toVisit, node_t _startNode) {
    if (graph_[_startNode].empty()) {
      visited[_startNode] = true;
      _callback(_startNode, true,
                true);  // new component , isolated component
      return;
    }

    bool newComponent = true;
    toVisit.push(_startNode);

    while (!toVisit.empty()) {
      const auto currentNode = toVisit.top();
      toVisit.pop();

      if (!visited[currentNode]) {
        visited[currentNode] = true;

        if (!newComponent) [[likely]] {
          _callback(currentNode, false, false);
        } else {
          _callback(currentNode, true, false);
          newComponent = false;
        }

        for (auto it = graph_[currentNode].rbegin();
             it != graph_[currentNode].rend(); ++it)
          if (!visited[it->node]) toVisit.push(it->node);
      }
    }
  }

  template <typename Callback>
  void DFSComponent(Callback _callback, node_t _startNode = 0u) {
    const auto graphSize = graph_.size();
    if (graphSize == 0) return;

    std::vector<bool> visited(graphSize, false);
    std::stack<node_t> toVisit;

    _DFSComponent(_callback, visited, toVisit, _startNode);
  }

  template <typename Callback>
  void DFS(Callback _callback, node_t _startNode = 0u) {
    const auto graphSize = graph_.size();
    if (graphSize == 0) return;

    std::vector<bool> visited(graphSize, false);
    std::stack<node_t> toVisit;
    auto visitedAllUntil = visited.begin();

    while (visitedAllUntil != visited.end()) {
      _startNode = std::distance(visited.begin(), visitedAllUntil);
      _DFSComponent(_callback, visited, toVisit, _startNode);
      visitedAllUntil = std::find(visitedAllUntil, visited.end(), false);
    }
    // nullopt
  }
};

using Graph = GraphBase<std::size_t, int>;

}  // namespace cds