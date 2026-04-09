#include <map>
#include <string>
#include <iostream>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/basic/Graph.h>
#include <ogdf/basic/graph_generators/randomized.h>

using namespace ogdf;

//void randomRegularGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
//	try {
//		randomRegularGraph(G, std::stoi(localParams.get("n")), std::stod(localParams.get("d")));
//	} catch (const std::exception& e) {
//		
//	}
//}

void randomRegularGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomRegularGraph\ndescription : Creates a random <tt>d</tt>-regular graph.\n              @pre \\p n * \\p d must be even\n              @warning This method is not guaranteed to terminate!\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : d\ndescription : is the degree of each vertex";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int d = std::stoi(localParams.at("d"));
		randomRegularGraph(G, n, d);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomGraph\ndescription : Creates a random graph.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges of the generated graph.";
	if (localParams.count("help")) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		std::cout << "Error: " << e.what() << std::endl;
		for (const auto& pair : localParams) {
			std::cout << "  " << pair.first << " = " << pair.second << std::endl;
		}
		exit(1);
	}
}
void randomSimpleGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomSimpleGraph\ndescription : Creates a random simple graph.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges of the generated graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomSimpleGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomSimpleGraphByProbabilityGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomSimpleGraphByProbability\ndescription : Creates a random simple graph.\n              Algorithm based on PreZER/LogZER from:\n              Sadegh Nobari, Xuesong Lu, Panagiotis Karras, and Stéphane Bressan. 2011. Fast random graph generation.\n              In Proceedings of the 14th International Conference on Extending Database Technology (EDBT/ICDT '11),\n              ACM, New York, NY, USA, 331-342. DOI=http://dx.doi.org/10.1145/1951365.1951406\n              \n              @pre /p pEdge is in [0, 1]\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : double\nname        : pEdge\ndescription : is the probability for each edge to be added into the graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		double pEdge = std::stod(localParams.at("pEdge"));
		randomSimpleGraphByProbability(G, n, pEdge);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomSimpleConnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomSimpleConnectedGraph\ndescription : Creates a random simple and connected graph.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges of the generated graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomSimpleConnectedGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomBiconnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomBiconnectedGraph\ndescription : Creates a random biconnected graph.\n              @note \\p n has a lower bound of 3, and \\p m a lower bound of \\p n.\n              If the parameters are smaller than that, they get increased prior\n              to the algorithm.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges of the generated graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomBiconnectedGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarConnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomPlanarConnectedGraph\ndescription : Creates a random connected (simple) planar (embedded) graph.\n              @note \\p n has a lower bound of 1, and \\p m has a lower bound of\n              \\p n and an upper bound of \\f$3n-6\\f$. The supplied values are\n              adjusted if they are out of these bounds.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges of the generated graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomPlanarConnectedGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarBiconnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomPlanarBiconnectedGraph\ndescription : Creates a random planar biconnected (embedded) graph.\n              multi-edges.\n              @note \\p n has a lower bound of 3, and \\p m has a lower bound of\n              \\p n and an upper bound of \\f$3n-6\\f$. The supplied values are\n              adjusted if they are out of these bounds.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges of the generated graph.\n\ntype        : bool\nname        : multiEdges\ndescription : determines if the generated graph may contain";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		bool multiEdges = localParams.at("multiEdges") == "" || localParams.at("multiEdges") == "true" || localParams.at("multiEdges") == "1";
		randomPlanarBiconnectedGraph(G, n, m, multiEdges);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarBiconnectedDigraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomPlanarBiconnectedDigraph\ndescription : Creates a random planar biconnected acyclic (embedded) digraph.\n              multi-edges; default = false.\n              @pre \\p d is between 0.0 and 1.0\n              @note \\p n has a lower bound of 3, and \\p m has a lower bound of\n              \\p n and an upper bound of \\f$3n-6\\f$. The supplied values are\n              adjusted if they are out of these bounds.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges of the generated graph.\n\ntype        : double\nname        : p\ndescription : up to \\p m * \\p p edges will be reversed preversing acyclicity; default = 0.0.\n\ntype        : bool\nname        : multiEdges\ndescription : determines if the generated graph may contain";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		double p = std::stod(localParams.at("p"));
		bool multiEdges = localParams.at("multiEdges") == "" || localParams.at("multiEdges") == "true" || localParams.at("multiEdges") == "1";
		randomPlanarBiconnectedDigraph(G, n, m, p, multiEdges);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomUpwardPlanarBiconnectedDigraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomUpwardPlanarBiconnectedDigraph\ndescription : Creates a random upward planar biconnected (embedded) digraph.\n              @note \\p n has a lower bound of 3, and \\p m has a lower bound of\n              \\p n and an upper bound of \\f$3n-6\\f$. The supplied values are\n              adjusted if they are out of these bounds.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges of the generated graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomUpwardPlanarBiconnectedDigraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarCNBGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomPlanarCNBGraph\ndescription : Creates a random planar graph, that is connected, but not biconnected.\n              \n              @pre It holds that n > 1, m >= n (unless n = 2, m = 1) and b > 1.\n              \n\n\ntype        : int\nname        : n\ndescription : is the max. number of nodes in each biconnected component\n\ntype        : int\nname        : m\ndescription : is the max. number of edges in each biconnected component\n\ntype        : int\nname        : b\ndescription : is the number of biconnected components";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		int b = std::stoi(localParams.at("b"));
		randomPlanarCNBGraph(G, n, m, b);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomTriconnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomTriconnectedGraph\ndescription : Creates a random triconnected (and simple) graph.\n              The graph generator proceeds as follows. It starts with a \\a K_4 and performs\n              then \\p n -4 split node operations on randomly selected nodes of the graph\n              constructed so far. Each such operation splits a node \\a v into two nodes\n              \\a x and \\a y and distributes \\a v's neighbors to the two nodes such that each\n              node gets at least two neighbors. Additionally, the edge (\\a x,\\a y) is inserted.\n              \n              The neighbors are distributed such that a neighbor of \\a v becomes\n              - only a neighbor of \\a x with probability \\p p1;\n              - only a neighbor of \\a y with probability \\p p1;\n              - a neighbor of both \\a x and \\a y with probability 1.0 - \\p p1 - \\p p2.\n              \n              node after splitting a node.\n              node after splitting a node.\n              \n              The probability for a neighbor to be moved to both split nodes is\n              1.0 - \\p p1 - \\p p2. The higher this probability, the higher the density\n              of the resulting graph.\n              \n              \\pre The probabilities \\a p1 and \\a p2 must lie between 0.0 and 1.0, and\n              \\p p1 + \\p p2 <= 1.0.\n              @note \\p n has a lower bound of 4 and will get increased to this if smaller.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes in the generated graph.\n\ntype        : double\nname        : p1\ndescription : is the probability that an edge is moved only to the left\n\ntype        : double\nname        : p2\ndescription : is the probability that an edge is moved only to the right";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		double p1 = std::stod(localParams.at("p1"));
		double p2 = std::stod(localParams.at("p2"));
		randomTriconnectedGraph(G, n, p1, p2);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarTriconnectedGraph1Gen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomPlanarTriconnectedGraph\ndescription : Creates a random planar triconnected (and simple) graph.\n              This graph generator works in two steps.\n              -# A planar triconnected 3-regular graph is constructed using successive\n              splitting of pairs of nodes. The constructed graph has \\p n nodes and\n              1.5\\p n edges.\n              -# The remaining edges are inserted by successive splitting of faces\n              with degree four or greater.\n              The resulting graph also represents a combinatorial embedding.\n              \n              \n              @note\n              - \\p n >= 4 and \\p n must be even; otherwise, \\p n is adjusted\n              to the next feasible integer.\n              - 1.5\\p n <= \\p m <= 3\\p n -6; otherwise, \\p m is adjusted\n              to a feasible value.\n              \nindex       : 1\n\n\ntype        : int\nname        : n\ndescription : is the number of nodes in the generated graph.\n\ntype        : int\nname        : m\ndescription : is the number of edges in the generated graph.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomPlanarTriconnectedGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarTriconnectedGraph2Gen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomPlanarTriconnectedGraph\ndescription : Creates a random planar triconnected (and simple) graph.\n              This graph generator creates a planar triconnected graph by successive\n              node splitting. It starts with the \\a K_4 and performs \\p n -4 node\n              splits. Each such split operation distributes a node's neighbors to the\n              two nodes resulting from the split. Aftewards, two further edges can be\n              added; the probability for adding these edges is given by \\p p1 and \\p p2.\n              The higher these probabilities, the denser the resulting graph. Note that\n              a simple planar triconnected graph has between 1.5\\p n and 3\\p n -6 edges.\n              \n              \\pre 0.0 <= \\p p1, \\p p2 <= 1.0.\n              \n              @note \\p n has a lower bound of 4 and will get increased to this if smaller.\n              \nindex       : 2\n\n\ntype        : int\nname        : n\ndescription : is the number of nodes in the generated graph.\n\ntype        : double\nname        : p1\ndescription : is the probability for the first additional edge to be added.\n\ntype        : double\nname        : p2\ndescription : is the probability for the second additional edge to be added.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		double p1 = std::stod(localParams.at("p1"));
		double p2 = std::stod(localParams.at("p2"));
		randomPlanarTriconnectedGraph(G, n, p1, p2);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomTree1Gen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomTree\ndescription : Creates a random tree (simpler version.\n              \nindex       : 1\n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the tree.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		randomTree(G, n);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomTree2Gen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomTree\ndescription : Creates a random tree.\n              @note if \\p maxDeg or \\p maxWidth are 0 (or negative), they are set to \\p n\n              \nindex       : 2\n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the tree.\n\ntype        : int\nname        : maxDeg\ndescription : is the maximal allowed node degree; 0 means no restriction.\n\ntype        : int\nname        : maxWidth\ndescription : is the maximal allowed width of a level; 0 means no restriction.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int maxDeg = std::stoi(localParams.at("maxDeg"));
		int maxWidth = std::stoi(localParams.at("maxWidth"));
		randomTree(G, n, maxDeg, maxWidth);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomDigraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomDigraph\ndescription : Creates a random (simple) directed graph.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes in the generated graph.\n\ntype        : double\nname        : p\ndescription : is the probability that an edge is created (for each node pair)";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		double p = std::stod(localParams.at("p"));
		randomDigraph(G, n, p);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomSeriesParallelDAGGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomSeriesParallelDAG\ndescription : Creates a random (simple, biconnected) series parallel DAG.\n              This function creates a random series parallel biconnected DAG.\n              Note, that the resulting graph is trivially upward planar!\n              To use this generator for experiments, e.g. concerning upward planarity,\n              you can fit the graph by reversing some edges with the parameter 0 < flt < 1.\n              \n              @pre \\p p is in \\f$[0.0, 1.0]\\f$, and \\p flt is in \\f$[0.0, 1.0)\\f$.\n              \n\n\ntype        : int\nname        : edges\ndescription : is the number of edges in the generated graph.\n\ntype        : double\nname        : p\ndescription :   = probability of a series composition; default = 0.5\n\ntype        : double\nname        : flt\ndescription : = up to edges*flt edges will be reversed preversing acyclicity; default = 0.0";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int edges = std::stoi(localParams.at("edges"));
		double p = std::stod(localParams.at("p"));
		double flt = std::stod(localParams.at("flt"));
		randomSeriesParallelDAG(G, edges, p, flt);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomGeometricCubeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomGeometricCubeGraph\ndescription : Creates a random geometric graph by laying out nodes in a unit n-cube.\n              Nodes with a distance < threshold are connected,\n              0 <= threshold <= sqrt(dimension). The graph is simple.\n              \n\n\ntype        : int\nname        : nodes\ndescription : is the number of nodes of the generated graph.\n\ntype        : double\nname        : threshold\ndescription : is threshold radius of nodes which will be connected.\n\ntype        : int\nname        : dimension\ndescription : is the dimension of the cube.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int nodes = std::stoi(localParams.at("nodes"));
		double threshold = std::stod(localParams.at("threshold"));
		int dimension = std::stoi(localParams.at("dimension"));
		randomGeometricCubeGraph(G, nodes, threshold, dimension);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomWaxmanGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomWaxmanGraph\ndescription : Generates a Waxman graph where nodes are uniformly randomly placed in a grid, then edges\n              are inserted based on nodes' euclidean distances.\n              Routing of Multipoint Connections\n              Bernard M. Waxman (1988)\n              \n              After generating the nodes, edges are inserted between each pair of nodes \\a v, \\a w with\n              probability based on their euclidean distance \\f$\\beta \\exp{\\frac{-||v-w||}{m \\, \\alpha}}\\f$\n              where \\f$m:=\\max\\limits_{u,v}||u-v||\\f$.\n              \n              Small values increase the density of short edges relative to longer ones.\n              Large values result in a graph with higher edge density.\n              \n\n\ntype        : int\nname        : nodes\ndescription : is the number of nodes of the generated graph.\n\ntype        : double\nname        : alpha\ndescription : is a parameter for the probability in the range (0,1].\n\ntype        : double\nname        : beta\ndescription : is a parameter for the probability in the range (0,1].\n\ntype        : double\nname        : width\ndescription : is the width of the area the nodes are distributed in.\n\ntype        : double\nname        : height\ndescription : is the height of the area the nodes are distributed in.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int nodes = std::stoi(localParams.at("nodes"));
		double alpha = std::stod(localParams.at("alpha"));
		double beta = std::stod(localParams.at("beta"));
		double width = std::stod(localParams.at("width"));
		double height = std::stod(localParams.at("height"));
		randomWaxmanGraph(G, nodes, alpha, beta, width, height);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void preferentialAttachmentGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : preferentialAttachmentGraph\ndescription : Creates a graph where new nodes are more likely to connect to nodes with high degree.\n              Implements the Preferential Attachment algorithm as described in:\n              Emergence of Scaling in Random Networks\n              Albert-Laszlo Barabasi and Reka Albert\n              https://arxiv.org/abs/cond-mat/9910332v1\n              This algorithm creates edges based on the degree of nodes,\n              so it is most useful to apply this to a pre-built graph.\n              If no graph is supplied, a complete graph of \\p minDegree nodes\n              is generated and the algorithm adds \\p nodes - \\p minDegree nodes.\n              If a graph is supplied, it must contain at least \\p minDegree\n              nodes of degree 1.\n              \n              \n\n\ntype        : int\nname        : nodes\ndescription : is the number of nodes to be added to graph.\n\ntype        : int\nname        : minDegree\ndescription : is the minimum degree of new nodes.";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int nodes = std::stoi(localParams.at("nodes"));
		int minDegree = std::stoi(localParams.at("minDegree"));
		preferentialAttachmentGraph(G, nodes, minDegree);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomWattsStrogatzGraphGen(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "name        : randomWattsStrogatzGraph\ndescription : Creates a \"small world\" graph as described by Watts & Strogatz\n              Takes a regular lattice graph and, with given probability, rewires each\n              edge to a random other non-neighbor.\n              \n              Collective dynamics of ‘small-world’ networks\n              https://www.nature.com/articles/30918.pdf\n              \n              @warning\n              This implementation does not perform very well if \\p k is close to half of \\p n for large graphs.\n              \n              modify the graph, while one of 1 will cause full randomness.\n              \n\n\ntype        : int\nname        : n\ndescription : is the number of nodes of the generated graph.\n\ntype        : int\nname        : k\ndescription : is the initial degree of each node and must be even and smaller than half of \\p n.\n\ntype        : double\nname        : probability\ndescription : determines how likely each edge is rewired. A probability of 0 will not";
	if (localParams.find("help") != localParams.end()) {
		std::cout << helpText << std::endl;
		exit(0);
	}
	try {
		int n = std::stoi(localParams.at("n"));
		int k = std::stoi(localParams.at("k"));
		double probability = std::stod(localParams.at("probability"));
		randomWattsStrogatzGraph(G, n, k, probability);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}