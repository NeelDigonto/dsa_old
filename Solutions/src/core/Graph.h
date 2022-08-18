#pragma once
#include <core/Common.h>

namespace cds {

	template<typename node_t = std::size_t, typename Wt = int>//bool Acyclic, bool Directed, bool Weighted
	class Graph {
	public:
		struct NodeWtPair { node_t node; Wt wt; };
		struct Edge { node_t u; node_t v; Wt fwdWt; Wt bckWt; };
		using edge_list_t = vector<NodeWtPair>;
		using adl_t = vector<edge_list_t>;
	private:
		adl_t graph_;
	public:
		Graph() = delete;
		Graph(std::size_t N) {
			graph_ = adl_t(N, edge_list_t{});
		}

		inline void AddEdges(vector<Edge> _edges) {
			for (const auto& edge : _edges)
				AddEdge(edge.u, edge.v, edge.fwdWt, edge.bckWt);
		}

		inline void AddEdge(Edge _edge) {
			AddEdge(_edge.u, _edge.v, _edge.fwdWt, _edge.bckWt);
		}

		inline void AddEdge(node_t u, node_t v, Wt fwdWt = 0, Wt bckWt = fwdWt) {
			graph_[u].push_back({ v, fwdWt });
			graph_[v].push_back({ u, bckWt });
		}

		vector<Wt> GetEdges() const noexcept {

		}

		template<typename Callback>
		void _BFSComponent(Callback _callback, vector<bool>& visited, queue<node_t>& toVisit, node_t _startNode) {
			if (graph_[_startNode].empty()) {
				visited[_startNode] = true;
				_callback(_startNode, true, true); // new component , isolated component
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

					for (auto it = graph_[currentNode].begin(); it != graph_[currentNode].end(); ++it)
						if (!visited[it->node])
							toVisit.push(it->node);
				}

				toVisit.pop();
			}
		}

		template<typename Callback>
		auto BFSComponent(Callback _callback, node_t _startNode = 0u)
			-> std::enable_if_t<std::is_invocable_r_v<void, Callback, node_t, bool, bool>, void>
		{
			const auto graphSize = graph_.size();
			if (graphSize == 0) return;

			std::vector<bool> visited(graphSize, false);
			std::queue<node_t> toVisit;

			_BFSComponent(_callback, visited, toVisit, _startNode);
		}

		template<typename Callback>
		auto BFS(Callback _callback, node_t _startNode = 0u)
			-> std::enable_if_t<std::is_invocable_r_v<void, Callback, node_t, bool, bool>, void>
		{
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

		template<typename Callback>
		void _DFSComponent(Callback _callback, vector<bool>& visited, stack<node_t>& toVisit, node_t _startNode) {
			if (graph_[_startNode].empty()) {
				visited[_startNode] = true;
				_callback(_startNode, true, true); // new component , isolated component
				return;
			}

			bool newComponent = true;
			toVisit.push(_startNode);

			while (!toVisit.empty()) {
				const auto currentNode = toVisit.top();
				toVisit.pop();

				if (!visited[currentNode]) {
					visited[currentNode] = true;
					if (!newComponent) [[likely]]
						_callback(currentNode, false, false);
					else {
						_callback(currentNode, true, false);
						newComponent = false;
					}

					for (auto it = graph_[currentNode].rbegin(); it != graph_[currentNode].rend(); ++it)
						if (!visited[it->node])
							toVisit.push(it->node);
				}

			}
		}

		template<typename Callback>
		auto DFSComponent(Callback _callback, node_t _startNode = 0u)
			-> std::enable_if_t<std::is_invocable_r_v<void, Callback, node_t, bool, bool>, void>
		{
			const auto graphSize = graph_.size();
			if (graphSize == 0) return;

			std::vector<bool> visited(graphSize, false);
			std::stack<node_t> toVisit;

			_DFSComponent(_callback, visited, toVisit, _startNode);
		}

		template<typename Callback>
		auto DFS(Callback _callback, node_t _startNode = 0u)
			-> std::enable_if_t<std::is_invocable_r_v<void, Callback, node_t, bool, bool>, void>
		{
			const auto graphSize = graph_.size();
			if (graphSize == 0) return;

			vector<bool> visited(graphSize, false);
			stack<node_t> toVisit;
			auto visitedAllUntil = visited.begin();

			while (visitedAllUntil != visited.end()) {
				_startNode = std::distance(visited.begin(), visitedAllUntil);
				_DFSComponent(_callback, visited, toVisit, _startNode);
				visitedAllUntil = std::find(visitedAllUntil, visited.end(), false);
			}
			// nullopt
		}

	};


}