#include <map>
#include <string>
#include <iostream>
//#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/basic/Graph.h>
#include <ogdf/basic/graph_generators/operations.h>
#include <ogdf/basic/graph_generators/randomized.h>
#include <ogdf/basic/graph_generators/deterministic.h>
#include <ogdf/basic/graph_generators/clustering.h>

#include <unordered_map>

using namespace ogdf;

inline bool strToBool(const std::string& str) {
	if (str == "true" || str == "1" || str == "yes" || str == "on") {
		return true;
	}
	if (str == "false" || str == "0" || str == "no" || str == "off") {
		return false;
	}
	throw std::invalid_argument("Invalid boolean string: " + str);
}

// %GENERATORS_DEFINITIONS%
void complementGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== complement ===\n\nargsString          : (Graph &G, bool directed=false, bool allowSelfLoops=false)\ndefinition          : OGDF_EXPORT void ogdf::complement\ndetailedDescription : Computes the complement of G.\n\n\ntype    declName       description\n----    --------       -----------\nGraph & G              is the input graph and will be assigned the complement.\nbool    directed       Whether edge direction should be considered when computing the complement graph.\nbool    allowSelfLoops Whether to allow self loops. If false and G contains self loops, these will not be removed.\n\n";
  try {
    bool directed = false;
    if (localParams.find("directed") != localParams.end()) {
      directed = strToBool(localParams.at("directed"));
    }
    bool allowSelfLoops = false;
    if (localParams.find("allowSelfLoops") != localParams.end()) {
      allowSelfLoops = strToBool(localParams.at("allowSelfLoops"));
    }
    complement(G, directed, allowSelfLoops);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void regularLatticeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== regularLatticeGraph ===\n\nargsString       : (Graph &G, int n, int k)\ndefinition       : OGDF_EXPORT void ogdf::regularLatticeGraph\nbriefDescription : Creates a regular lattice graph. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes in the graph.\nint     k        is the degree of each node.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int k = std::stoi(localParams.at("k"));
    regularLatticeGraph(G, n, k);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void regularTreeGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== regularTree ===\n\nargsString       : (Graph &G, int n, int children)\ndefinition       : OGDF_EXPORT void ogdf::regularTree\nbriefDescription : Creates a regular tree. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the tree.\nint     n        is the number of nodes of the tree.\nint     children is the number of children per node. root has index 0, the next level has indizes 1...children, the children of node 1 have indize…\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int children = std::stoi(localParams.at("children"));
    regularTree(G, n, children);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void completeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== completeGraph ===\n\nargsString       : (Graph &G, int n)\ndefinition       : OGDF_EXPORT void ogdf::completeGraph\nbriefDescription : para\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    completeGraph(G, n);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void completeBipartiteGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== completeBipartiteGraph ===\n\nargsString       : (Graph &G, int n, int m)\ndefinition       : OGDF_EXPORT void ogdf::completeBipartiteGraph\nbriefDescription : para\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the first partition set.\nint     m        is the number of nodes of the second partition set.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    completeBipartiteGraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void wheelGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== wheelGraph ===\n\nargsString       : (Graph &G, int n)\ndefinition       : OGDF_EXPORT void ogdf::wheelGraph\nbriefDescription : para\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes on the rim of the wheel (W_n).\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    wheelGraph(G, n);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void cubeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== cubeGraph ===\n\nargsString       : (Graph &G, int n)\ndefinition       : OGDF_EXPORT void ogdf::cubeGraph\nbriefDescription : para\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of the cube's dimensions (n>=0).\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    cubeGraph(G, n);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void globeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== globeGraph ===\n\nargsString          : (Graph &G, int meridians, int latitudes)\ndefinition          : OGDF_EXPORT void ogdf::globeGraph\nbriefDescription    : Creates a globe graph with a given number of meridians and latitudes. \ndetailedDescription : The graph will contain a node at each crossing of a meridian and a latitude, and a node at each pole, hence meridians * latitudes + 2 nodes overall.\n\n\ntype    declName  description\n----    --------  -----------\nGraph & G         is assigned the generated graph.\nint     meridians is the number of meridians.\nint     latitudes is the number of latitudes.\n\n";
  try {
    int meridians = std::stoi(localParams.at("meridians"));
    int latitudes = std::stoi(localParams.at("latitudes"));
    globeGraph(G, meridians, latitudes);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void suspensionGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== suspension ===\n\nargsString          : (Graph &G, int s)\ndefinition          : OGDF_EXPORT void ogdf::suspension\nbriefDescription    : para\ndetailedDescription : A suspension node is a node that is connected to all other nodes in the graph. This function adds s such suspension nodes that will not be directly connected to each other.\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is the graph to extend.\nint     s        is the amount of suspension nodes to add.\n\n";
  try {
    int s = std::stoi(localParams.at("s"));
    suspension(G, s);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void gridGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== gridGraph ===\n\nargsString       : (Graph &G, int n, int m, bool loopN, bool loopM)\ndefinition       : OGDF_EXPORT void ogdf::gridGraph\nbriefDescription : para\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes on first axis.\nint     m        is the number of nodes on second axis.\nbool    loopN    if the grid is cyclic on first axis\nbool    loopM    if the grid is cyclic on second axis\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    bool loopN = strToBool(localParams.at("loopN"));
    bool loopM = strToBool(localParams.at("loopM"));
    gridGraph(G, n, m, loopN, loopM);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void petersenGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== petersenGraph ===\n\nargsString          : (Graph &G, int n=5, int m=2)\ndefinition          : OGDF_EXPORT void ogdf::petersenGraph\nbriefDescription    : Creates a generalized Petersen graph. \ndetailedDescription : {Creates an outer cycle of nodes 1, ..., n, each of which has a direct neighbor (a corresponding inner node). For two outer nodes i, j, there is an edge between their corresponding inner nodes if the absolute difference of i and j equals the jump length m., If no values for n or m are given, assume the standard Petersen graph of 5 nodes and a jump length of 2.}\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes on the outer cycle.\nint     m        is the length of jumps for the inner part.\n\n";
  try {
    int n = 5;
    if (localParams.find("n") != localParams.end()) {
      n = std::stoi(localParams.at("n"));
    }
    int m = 2;
    if (localParams.find("m") != localParams.end()) {
      m = std::stoi(localParams.at("m"));
    }
    petersenGraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void emptyGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== emptyGraph ===\n\nargsString       : (Graph &G, int nodes)\ndefinition       : OGDF_EXPORT void ogdf::emptyGraph\nbriefDescription : para\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     nodes    is the number of nodes of the generated graph.\n\n";
  try {
    int nodes = std::stoi(localParams.at("nodes"));
    emptyGraph(G, nodes);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomRegularGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomRegularGraph ===\n\nargsString       : (Graph &G, int n, int d)\ndefinition       : OGDF_EXPORT void ogdf::randomRegularGraph\nbriefDescription : para\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\nint     d        is the degree of each vertex\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int d = std::stoi(localParams.at("d"));
    randomRegularGraph(G, n, d);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomGraph ===\n\nargsString       : (Graph &G, int n, int m)\ndefinition       : OGDF_EXPORT void ogdf::randomGraph\nbriefDescription : Creates a random graph. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\nint     m        is the number of edges of the generated graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    randomGraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomSimpleGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomSimpleGraph ===\n\nargsString       : (Graph &G, int n, int m)\ndefinition       : OGDF_EXPORT bool ogdf::randomSimpleGraph\nbriefDescription : Creates a random simple graph. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\nint     m        is the number of edges of the generated graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    randomSimpleGraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomSimpleGraphByProbabilityGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomSimpleGraphByProbability ===\n\nargsString          : (Graph &G, int n, double pEdge)\ndefinition          : OGDF_EXPORT bool ogdf::randomSimpleGraphByProbability\nbriefDescription    : Creates a random simple graph. \ndetailedDescription : Algorithm based on PreZER/LogZER from: Sadegh Nobari, Xuesong Lu, Panagiotis Karras, and Stéphane Bressan. 2011. Fast random graph generation. In Proceedings of the 14th International Conference on Extending Database Technology (EDBT/ICDT '11), ACM, New York, NY, USA, 331-342. DOI=http://dx.doi.org/10.1145/1951365.1951406\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\ndouble  pEdge    is the probability for each edge to be added into the graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    double pEdge = std::stod(localParams.at("pEdge"));
    randomSimpleGraphByProbability(G, n, pEdge);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomSimpleConnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomSimpleConnectedGraph ===\n\nargsString       : (Graph &G, int n, int m)\ndefinition       : OGDF_EXPORT bool ogdf::randomSimpleConnectedGraph\nbriefDescription : Creates a random simple and connected graph. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\nint     m        is the number of edges of the generated graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    randomSimpleConnectedGraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomBiconnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomBiconnectedGraph ===\n\nargsString       : (Graph &G, int n, int m)\ndefinition       : OGDF_EXPORT void ogdf::randomBiconnectedGraph\nbriefDescription : Creates a random biconnected graph. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\nint     m        is the number of edges of the generated graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    randomBiconnectedGraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomPlanarConnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomPlanarConnectedGraph ===\n\nargsString       : (Graph &G, int n, int m)\ndefinition       : OGDF_EXPORT void ogdf::randomPlanarConnectedGraph\nbriefDescription : Creates a random connected (simple) planar (embedded) graph. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\nint     m        is the number of edges of the generated graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    randomPlanarConnectedGraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomPlanarBiconnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomPlanarBiconnectedGraph ===\n\nargsString       : (Graph &G, int n, int m, bool multiEdges=false)\ndefinition       : OGDF_EXPORT void ogdf::randomPlanarBiconnectedGraph\nbriefDescription : Creates a random planar biconnected (embedded) graph. \n\n\ntype    declName   description\n----    --------   -----------\nGraph & G          is assigned the generated graph.\nint     n          is the number of nodes of the generated graph.\nint     m          is the number of edges of the generated graph.\nbool    multiEdges determines if the generated graph may contain multi-edges.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    bool multiEdges = false;
    if (localParams.find("multiEdges") != localParams.end()) {
      multiEdges = strToBool(localParams.at("multiEdges"));
    }
    randomPlanarBiconnectedGraph(G, n, m, multiEdges);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomPlanarBiconnectedDigraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomPlanarBiconnectedDigraph ===\n\nargsString       : (Graph &G, int n, int m, double p=0, bool multiEdges=false)\ndefinition       : OGDF_EXPORT void ogdf::randomPlanarBiconnectedDigraph\nbriefDescription : Creates a random planar biconnected acyclic (embedded) digraph. \n\n\ntype    declName   description\n----    --------   -----------\nGraph & G          is assigned the generated graph.\nint     n          is the number of nodes of the generated graph.\nint     m          is the number of edges of the generated graph.\ndouble  p          up to m * p edges will be reversed preversing acyclicity; default = 0.0.\nbool    multiEdges determines if the generated graph may contain multi-edges; default = false.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    double p = 0;
    if (localParams.find("p") != localParams.end()) {
      p = std::stod(localParams.at("p"));
    }
    bool multiEdges = false;
    if (localParams.find("multiEdges") != localParams.end()) {
      multiEdges = strToBool(localParams.at("multiEdges"));
    }
    randomPlanarBiconnectedDigraph(G, n, m, p, multiEdges);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomUpwardPlanarBiconnectedDigraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomUpwardPlanarBiconnectedDigraph ===\n\nargsString       : (Graph &G, int n, int m)\ndefinition       : OGDF_EXPORT void ogdf::randomUpwardPlanarBiconnectedDigraph\nbriefDescription : Creates a random upward planar biconnected (embedded) digraph. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes of the generated graph.\nint     m        is the number of edges of the generated graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    randomUpwardPlanarBiconnectedDigraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomPlanarCNBGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomPlanarCNBGraph ===\n\nargsString       : (Graph &G, int n, int m, int b)\ndefinition       : OGDF_EXPORT void ogdf::randomPlanarCNBGraph\nbriefDescription : Creates a random planar graph, that is connected, but not biconnected. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the max. number of nodes in each biconnected component\nint     m        is the max. number of edges in each biconnected component\nint     b        is the number of biconnected components\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    int b = std::stoi(localParams.at("b"));
    randomPlanarCNBGraph(G, n, m, b);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomTriconnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomTriconnectedGraph ===\n\nargsString          : (Graph &G, int n, double p1, double p2)\ndefinition          : OGDF_EXPORT void ogdf::randomTriconnectedGraph\nbriefDescription    : Creates a random triconnected (and simple) graph. \ndetailedDescription : {The graph generator proceeds as follows. It starts with a K_4 and performs then n -4 split node operations on randomly selected nodes of the graph constructed so far. Each such operation splits a node v into two nodes x and y and distributes v's neighbors to the two nodes such that each node gets at least two neighbors. Additionally, the edge (x,y) is inserted., The neighbors are distributed such that a neighbor of v becomesonly a neighbor of x with probability p1;only a neighbor of y with probability p1;a neighbor of both x and y with probability 1.0 - p1 - p2., The probabilities p1 and p2 must lie between 0.0 and 1.0, and p1 + p2 <= 1.0. n has a lower bound of 4 and will get increased to this if smaller. }\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes in the generated graph.\ndouble  p1       is the probability that an edge is moved only to the left node after splitting a node.\ndouble  p2       is the probability that an edge is moved only to the right node after splitting a node.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    double p1 = std::stod(localParams.at("p1"));
    double p2 = std::stod(localParams.at("p2"));
    randomTriconnectedGraph(G, n, p1, p2);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomPlanarTriconnectedGraph1Generator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomPlanarTriconnectedGraph1 ===\n\nargsString          : (Graph &G, int n, int m)\ndefinition          : OGDF_EXPORT void ogdf::randomPlanarTriconnectedGraph\nbriefDescription    : Creates a random planar triconnected (and simple) graph. \ndetailedDescription : This graph generator works in two steps.A planar triconnected 3-regular graph is constructed using successive splitting of pairs of nodes. The constructed graph has n nodes and 1.5n edges.The remaining edges are inserted by successive splitting of faces with degree four or greater. The resulting graph also represents a combinatorial embedding.\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes in the generated graph.\nint     m        is the number of edges in the generated graph.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    randomPlanarTriconnectedGraph(G, n, m);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomPlanarTriconnectedGraph2Generator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomPlanarTriconnectedGraph2 ===\n\nargsString          : (Graph &G, int n, double p1, double p2)\ndefinition          : OGDF_EXPORT void ogdf::randomPlanarTriconnectedGraph\nbriefDescription    : Creates a random planar triconnected (and simple) graph. \ndetailedDescription : This graph generator creates a planar triconnected graph by successive node splitting. It starts with the K_4 and performs n -4 node splits. Each such split operation distributes a node's neighbors to the two nodes resulting from the split. Aftewards, two further edges can be added; the probability for adding these edges is given by p1 and p2. The higher these probabilities, the denser the resulting graph. Note that a simple planar triconnected graph has between 1.5n and 3n -6 edges.\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes in the generated graph.\ndouble  p1       is the probability for the first additional edge to be added.\ndouble  p2       is the probability for the second additional edge to be added.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    double p1 = std::stod(localParams.at("p1"));
    double p2 = std::stod(localParams.at("p2"));
    randomPlanarTriconnectedGraph(G, n, p1, p2);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomTree1Generator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomTree1 ===\n\nargsString       : (Graph &G, int n)\ndefinition       : OGDF_EXPORT void ogdf::randomTree\nbriefDescription : Creates a random tree (simpler version. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the tree.\nint     n        is the number of nodes of the tree.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    randomTree(G, n);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomTree2Generator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomTree2 ===\n\nargsString       : (Graph &G, int n, int maxDeg, int maxWidth)\ndefinition       : OGDF_EXPORT void ogdf::randomTree\nbriefDescription : Creates a random tree. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the tree.\nint     n        is the number of nodes of the tree.\nint     maxDeg   is the maximal allowed node degree; 0 means no restriction.\nint     maxWidth is the maximal allowed width of a level; 0 means no restriction.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int maxDeg = std::stoi(localParams.at("maxDeg"));
    int maxWidth = std::stoi(localParams.at("maxWidth"));
    randomTree(G, n, maxDeg, maxWidth);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomDigraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomDigraph ===\n\nargsString       : (Graph &G, int n, double p)\ndefinition       : OGDF_EXPORT void ogdf::randomDigraph\nbriefDescription : Creates a random (simple) directed graph. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     n        is the number of nodes in the generated graph.\ndouble  p        is the probability that an edge is created (for each node pair)\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    double p = std::stod(localParams.at("p"));
    randomDigraph(G, n, p);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomSeriesParallelDAGGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomSeriesParallelDAG ===\n\nargsString       : (Graph &G, int edges, double p=0.5, double flt=0.0)\ndefinition       : OGDF_EXPORT void ogdf::randomSeriesParallelDAG\nbriefDescription : Creates a random (simple, biconnected) series parallel DAG. \n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     edges    is the number of edges in the generated graph.\ndouble  p        = probability of a series composition; default = 0.5\ndouble  flt      = up to edges*flt edges will be reversed preversing acyclicity; default = 0.0\n\n";
  try {
    int edges = std::stoi(localParams.at("edges"));
    double p = 0.5;
    if (localParams.find("p") != localParams.end()) {
      p = std::stod(localParams.at("p"));
    }
    double flt = 0.0;
    if (localParams.find("flt") != localParams.end()) {
      flt = std::stod(localParams.at("flt"));
    }
    randomSeriesParallelDAG(G, edges, p, flt);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomGeometricCubeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomGeometricCubeGraph ===\n\nargsString : (Graph &G, int nodes, double threshold, int dimension=2)\ndefinition : OGDF_EXPORT void ogdf::randomGeometricCubeGraph\n\n\ntype    declName  description\n----    --------  -----------\nGraph & G         is assigned the generated graph.\nint     nodes     is the number of nodes of the generated graph.\ndouble  threshold is threshold radius of nodes which will be connected.\nint     dimension is the dimension of the cube.\n\n";
  try {
    int nodes = std::stoi(localParams.at("nodes"));
    double threshold = std::stod(localParams.at("threshold"));
    int dimension = 2;
    if (localParams.find("dimension") != localParams.end()) {
      dimension = std::stoi(localParams.at("dimension"));
    }
    randomGeometricCubeGraph(G, nodes, threshold, dimension);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomWaxmanGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomWaxmanGraph ===\n\nargsString          : (Graph &G, int nodes, double alpha, double beta, double width=1.0, double height=1.0)\ndefinition          : OGDF_EXPORT void ogdf::randomWaxmanGraph\ndetailedDescription : Generates a Waxman graph where nodes are uniformly randomly placed in a grid, then edges are inserted based on nodes' euclidean distances. Routing of Multipoint Connections\n                      Bernard M. Waxman (1988)\n                       After generating the nodes, edges are inserted between each pair of nodes v, w with probability based on their euclidean distance $\\beta \\exp{\\frac{-||v-w||}{m \\, \\alpha}}$ where $m:=\\max\\limits_{u,v}||u-v||$.\n\n\ntype    declName description\n----    -------- -----------\nGraph & G        is assigned the generated graph.\nint     nodes    is the number of nodes of the generated graph.\ndouble  alpha    is a parameter for the probability in the range (0,1]. Small values increase the density of short edges relative to longer ones.\ndouble  beta     is a parameter for the probability in the range (0,1]. Large values result in a graph with higher edge density.\ndouble  width    is the width of the area the nodes are distributed in.\ndouble  height   is the height of the area the nodes are distributed in.\n\n";
  try {
    int nodes = std::stoi(localParams.at("nodes"));
    double alpha = std::stod(localParams.at("alpha"));
    double beta = std::stod(localParams.at("beta"));
    double width = 1.0;
    if (localParams.find("width") != localParams.end()) {
      width = std::stod(localParams.at("width"));
    }
    double height = 1.0;
    if (localParams.find("height") != localParams.end()) {
      height = std::stod(localParams.at("height"));
    }
    randomWaxmanGraph(G, nodes, alpha, beta, width, height);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void preferentialAttachmentGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== preferentialAttachmentGraph ===\n\nargsString          : (Graph &G, int nodes, int minDegree)\ndefinition          : OGDF_EXPORT void ogdf::preferentialAttachmentGraph\nbriefDescription    : Creates a graph where new nodes are more likely to connect to nodes with high degree. \ndetailedDescription : Implements the Preferential Attachment algorithm as described in: Emergence of Scaling in Random Networks Albert-Laszlo Barabasi and Reka Albert https://arxiv.org/abs/cond-mat/9910332v1 This algorithm creates edges based on the degree of nodes, so it is most useful to apply this to a pre-built graph. If no graph is supplied, a complete graph of minDegree nodes is generated and the algorithm adds nodes - minDegree nodes. If a graph is supplied, it must contain at least minDegree nodes of degree 1.\n\n\ntype    declName  description\n----    --------  -----------\nGraph & G         is the input graph (see above) and is assigned the expanded graph.\nint     nodes     is the number of nodes to be added to graph.\nint     minDegree is the minimum degree of new nodes.\n\n";
  try {
    int nodes = std::stoi(localParams.at("nodes"));
    int minDegree = std::stoi(localParams.at("minDegree"));
    preferentialAttachmentGraph(G, nodes, minDegree);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomWattsStrogatzGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomWattsStrogatzGraph ===\n\nargsString          : (Graph &G, int n, int k, double probability)\ndefinition          : OGDF_EXPORT void ogdf::randomWattsStrogatzGraph\nbriefDescription    : Creates a \"small world\" graph as described by Watts & Strogatz. \ndetailedDescription : {$null, Collective dynamics of ‘small-world’ networks https://www.nature.com/articles/30918.pdf}\n\n\ntype    declName    description\n----    --------    -----------\nGraph & G           is assigned the generated graph.\nint     n           is the number of nodes of the generated graph.\nint     k           is the initial degree of each node and must be even and smaller than half of n.\ndouble  probability determines how likely each edge is rewired. A probability of 0 will not modify the graph, while one of 1 will cause full rando…\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int k = std::stoi(localParams.at("k"));
    double probability = std::stod(localParams.at("probability"));
    randomWattsStrogatzGraph(G, n, k, probability);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void randomHierarchyGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== randomHierarchy ===\n\nargsString       : (Graph &G, int n, int m, bool planar, bool singleSource, bool longEdges)\ndefinition       : OGDF_EXPORT void ogdf::randomHierarchy\nbriefDescription : Creates a random hierarchical graph. \n\n\ntype    declName     description\n----    --------     -----------\nGraph & G            is assigned the generated graph.\nint     n            is the number of nodes.\nint     m            is the number of edges.\nbool    planar       determines if the resulting graph is (level-)planar.\nbool    singleSource determines if the graph is a single-source graph.\nbool    longEdges    determines if the graph has long edges (spanning 2 layers or more); otherwise the graph is proper.\n\n";
  try {
    int n = std::stoi(localParams.at("n"));
    int m = std::stoi(localParams.at("m"));
    bool planar = strToBool(localParams.at("planar"));
    bool singleSource = strToBool(localParams.at("singleSource"));
    bool longEdges = strToBool(localParams.at("longEdges"));
    randomHierarchy(G, n, m, planar, singleSource, longEdges);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
} void pruneEdgesGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "=== pruneEdges ===\n\nargsString       : (Graph &G, int max_edges, int min_deg)\ndefinition       : OGDF_EXPORT void ogdf::pruneEdges\nbriefDescription : Remove random edges from /p G until it has less than /p max_edges edges, not removing edges from nodes with degree less than /p min_deg. \n\n\ntype    declName\n----    --------\nGraph & G\nint     max_edges\nint     min_deg\n\n";
  try {
    int max_edges = std::stoi(localParams.at("max_edges"));
    int min_deg = std::stoi(localParams.at("min_deg"));
    pruneEdges(G, max_edges, min_deg);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
}
	// %GENERATORS_DEFINITIONS%


using GenFunc = void (*)(Graph&, const std::map<std::string, std::string>&);

static const std::unordered_map<std::string, GenFunc> generatorTable = {
	// it goes like that:
	// {"complement", complementGenerator},
	// {"regularLatticeGraph", regularLatticeGraphGenerator},

	// %GENERATORS_TABLE%
  {"complement", complementGenerator},
  {"regularLatticeGraph", regularLatticeGraphGenerator},
  {"regularTree", regularTreeGenerator},
  {"completeGraph", completeGraphGenerator},
  {"completeBipartiteGraph", completeBipartiteGraphGenerator},
  {"wheelGraph", wheelGraphGenerator},
  {"cubeGraph", cubeGraphGenerator},
  {"globeGraph", globeGraphGenerator},
  {"suspension", suspensionGenerator},
  {"gridGraph", gridGraphGenerator},
  {"petersenGraph", petersenGraphGenerator},
  {"emptyGraph", emptyGraphGenerator},
  {"randomRegularGraph", randomRegularGraphGenerator},
  {"randomGraph", randomGraphGenerator},
  {"randomSimpleGraph", randomSimpleGraphGenerator},
  {"randomSimpleGraphByProbability", randomSimpleGraphByProbabilityGenerator},
  {"randomSimpleConnectedGraph", randomSimpleConnectedGraphGenerator},
  {"randomBiconnectedGraph", randomBiconnectedGraphGenerator},
  {"randomPlanarConnectedGraph", randomPlanarConnectedGraphGenerator},
  {"randomPlanarBiconnectedGraph", randomPlanarBiconnectedGraphGenerator},
  {"randomPlanarBiconnectedDigraph", randomPlanarBiconnectedDigraphGenerator},
  {"randomUpwardPlanarBiconnectedDigraph", randomUpwardPlanarBiconnectedDigraphGenerator},
  {"randomPlanarCNBGraph", randomPlanarCNBGraphGenerator},
  {"randomTriconnectedGraph", randomTriconnectedGraphGenerator},
  {"randomPlanarTriconnectedGraph1", randomPlanarTriconnectedGraph1Generator},
  {"randomPlanarTriconnectedGraph2", randomPlanarTriconnectedGraph2Generator},
  {"randomTree1", randomTree1Generator},
  {"randomTree2", randomTree2Generator},
  {"randomDigraph", randomDigraphGenerator},
  {"randomSeriesParallelDAG", randomSeriesParallelDAGGenerator},
  {"randomGeometricCubeGraph", randomGeometricCubeGraphGenerator},
  {"randomWaxmanGraph", randomWaxmanGraphGenerator},
  {"preferentialAttachmentGraph", preferentialAttachmentGraphGenerator},
  {"randomWattsStrogatzGraph", randomWattsStrogatzGraphGenerator},
  {"randomHierarchy", randomHierarchyGenerator},
  {"pruneEdges", pruneEdgesGenerator}
	// %GENERATORS_TABLE%
};

void applyGen(Graph& G, const std::string& name, const std::map<std::string, std::string>& params) {
	// e.g. static const char* helpText = "no help";
	// %GENERATORS_HELPLINE%
static const char* helpText = "\ncomplement                           bool directed=false, bool allowSelfLoops=false\nregularLatticeGraph                  int n, int k\nregularTree                          int n, int children\ncompleteGraph                        int n\ncompleteBipartiteGraph               int n, int m\nwheelGraph                           int n\ncubeGraph                            int n\nglobeGraph                           int meridians, int latitudes\nsuspension                           int s\ngridGraph                            int n, int m, bool loopN, bool loopM\npetersenGraph                        int n=5, int m=2\nemptyGraph                           int nodes\nrandomRegularGraph                   int n, int d\nrandomGraph                          int n, int m\nrandomSimpleGraph                    int n, int m\nrandomSimpleGraphByProbability       int n, double pEdge\nrandomSimpleConnectedGraph           int n, int m\nrandomBiconnectedGraph               int n, int m\nrandomPlanarConnectedGraph           int n, int m\nrandomPlanarBiconnectedGraph         int n, int m, bool multiEdges=false\nrandomPlanarBiconnectedDigraph       int n, int m, double p=0, bool multiEdges=false\nrandomUpwardPlanarBiconnectedDigraph int n, int m\nrandomPlanarCNBGraph                 int n, int m, int b\nrandomTriconnectedGraph              int n, double p1, double p2\nrandomPlanarTriconnectedGraph1       int n, int m\nrandomPlanarTriconnectedGraph2       int n, double p1, double p2\nrandomTree1                          int n\nrandomTree2                          int n, int maxDeg, int maxWidth\nrandomDigraph                        int n, double p\nrandomSeriesParallelDAG              int edges, double p=0.5, double flt=0.0\nrandomGeometricCubeGraph             int nodes, double threshold, int dimension=2\nrandomWaxmanGraph                    int nodes, double alpha, double beta, double width=1.0, double height=1.0\npreferentialAttachmentGraph          int nodes, int minDegree\nrandomWattsStrogatzGraph             int n, int k, double probability\nrandomHierarchy                      int n, int m, bool planar, bool singleSource, bool longEdges\npruneEdges                           int max_edges, int min_deg\n\n";
	// %GENERATORS_HELPLINE%
	auto it = generatorTable.find(name);
	if (it == generatorTable.end()) {
		throw std::invalid_argument("Unknown generator: " + name + ". Try these: \n\n"+helpText);
	}
	it->second(G, params); // Direct call
}
