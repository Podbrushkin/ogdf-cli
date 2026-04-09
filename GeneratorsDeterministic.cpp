#include <map>
#include <string>
#include <iostream>
#include <ogdf/basic/Graph.h>
#include <ogdf/basic/graph_generators/deterministic.h>

using namespace ogdf;


void regularLatticeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : regularLatticeGraph\ndescription : Creates a regular lattice graph.\n              Generates a cycle on \\p n sequential nodes, where any two nodes whose\n              distance is at most \\p k / 2 are connected by an additional edge.\n              @see ::circulantGraph(Graph&, int, Array<int>)\n              \n              @pre \\p n must be at least 4, \\p k must be an even number between 0 and \\p n-2.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes in the graph.\n\ntype        : int\nname        : k\ndescription : is the degree of each node.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int k = std::stoi(localParams.at("k"));
		regularLatticeGraph(G, n, k);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void regularTreeGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : regularTree\ndescription : Creates a regular tree.\n              indizes 1...children, the children of node 1 have indizes children+1...2*children, etc.\n              if number of nodes does not allow a regular node, the \"last\" node will have fewer children.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the tree.\n\ntype        : int\nname        : children\ndescription : is the number of children per node. root has index 0, the next level has";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int children = std::stoi(localParams.at("children"));
		regularTree(G, n, children);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void completeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : completeGraph\ndescription : Creates the complete graph \\a K_n.\n              The returned graph is directed acyclic.\n              \n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		completeGraph(G, n);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void completeBipartiteGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : completeBipartiteGraph\ndescription : Creates the complete bipartite graph \\a K_{n,m}.\n              The returned graph is directed acyclic.\n              \n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the first partition set.\n\ntype        : int\nname        : m\ndescription : is the number of nodes of the second partition set.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		completeBipartiteGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void wheelGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : wheelGraph\ndescription : Creates the graph \\a W_n: A wheel graph.\n              @pre \\p n must be at least 2.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes on the rim of the wheel (W_n).";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		wheelGraph(G, n);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void cubeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : cubeGraph\ndescription : Creates the graph \\a Q^n: A <tt>n</tt>-cube graph.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of the cube's dimensions (n>=0).";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		cubeGraph(G, n);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void globeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : globeGraph\ndescription : Creates a globe graph with a given number of meridians and latitudes.\n              The graph will contain a node at each crossing of a meridian and a latitude,\n              and a node at each pole, hence \\p meridians * \\p latitudes + 2 nodes overall.\n              \n              \n\n\ntype        : int\nname        : meridians\ndescription : is the number of meridians.\n\ntype        : int\nname        : latitudes\ndescription : is the number of latitudes.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int meridians = std::stoi(localParams.at("meridians"));
		int latitudes = std::stoi(localParams.at("latitudes"));
		globeGraph(G, meridians, latitudes);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void suspensionGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : suspension\ndescription : Modifies \\p G by adding its <tt>s</tt>-th suspension.\n              A suspension node is a node that is connected to all other nodes in the graph.\n              This function adds \\p s such suspension nodes that will not be directly connected\n              to each other.\n              \n              \n\n\ntype        : int\nname        : s\ndescription : is the amount of suspension nodes to add.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int s = std::stoi(localParams.at("s"));
		suspension(G, s);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void gridGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : gridGraph\ndescription : Creates a (toroidal) grid graph on \\p n x \\p m nodes.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes on first axis.\n\ntype        : int\nname        : m\ndescription : is the number of nodes on second axis.\n\ntype        : bool\nname        : loopN\ndescription : if the grid is cyclic on first axis\n\ntype        : bool\nname        : loopM\ndescription : if the grid is cyclic on second axis";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		bool loopN = localParams.at("loopN") == "" || localParams.at("loopN") == "true" || localParams.at("loopN") == "1";
		bool loopM = localParams.at("loopM") == "" || localParams.at("loopM") == "true" || localParams.at("loopM") == "1";
		gridGraph(G, n, m, loopN, loopM);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void petersenGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : petersenGraph\ndescription : Creates a generalized Petersen graph.\n              Creates an outer cycle of nodes \\a 1, ..., \\p n, each of which has a direct\n              neighbor (a corresponding inner node). For two outer nodes \\a i, \\a j, there\n              is an edge between their corresponding inner nodes if the absolute difference\n              of \\a i and \\a j equals the jump length \\p m.\n              \n              If no values for \\p n or \\p m are given, assume the standard Petersen graph\n              of \\c 5 nodes and a jump length of \\c 2.\n              \n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes on the outer cycle.\n\ntype        : int\nname        : m\ndescription : is the length of jumps for the inner part.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		petersenGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void emptyGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : emptyGraph\ndescription : Creates a graph with \\p nodes nodes and no edges.\n              \n\n\ntype        : int\nname        : nodes\ndescription : is the number of nodes of the generated graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int nodes = std::stoi(localParams.at("nodes"));
		emptyGraph(G, nodes);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}