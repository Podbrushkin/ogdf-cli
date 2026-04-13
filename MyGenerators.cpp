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

void complementGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void regularLatticeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int k = std::stoi(localParams.at("k"));
		regularLatticeGraph(G, n, k);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void regularTreeGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int children = std::stoi(localParams.at("children"));
		regularTree(G, n, children);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void completeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		completeGraph(G, n);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void completeBipartiteGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		completeBipartiteGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void wheelGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		wheelGraph(G, n);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void cubeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		cubeGraph(G, n);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void globeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int meridians = std::stoi(localParams.at("meridians"));
		int latitudes = std::stoi(localParams.at("latitudes"));
		globeGraph(G, meridians, latitudes);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void suspensionGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int s = std::stoi(localParams.at("s"));
		suspension(G, s);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void gridGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void petersenGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void emptyGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int nodes = std::stoi(localParams.at("nodes"));
		emptyGraph(G, nodes);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomRegularGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int d = std::stoi(localParams.at("d"));
		randomRegularGraph(G, n, d);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomSimpleGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomSimpleGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomSimpleGraphByProbabilityGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		double pEdge = std::stod(localParams.at("pEdge"));
		randomSimpleGraphByProbability(G, n, pEdge);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomSimpleConnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomSimpleConnectedGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomBiconnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomBiconnectedGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarConnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomPlanarConnectedGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarBiconnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void randomPlanarBiconnectedDigraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void randomUpwardPlanarBiconnectedDigraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomUpwardPlanarBiconnectedDigraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarCNBGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
void randomTriconnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
void randomPlanarTriconnectedGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		int m = std::stoi(localParams.at("m"));
		randomPlanarTriconnectedGraph(G, n, m);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomPlanarTriconnectedGraph2Generator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
void randomTreeGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		randomTree(G, n);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomTree2Generator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
void randomDigraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int n = std::stoi(localParams.at("n"));
		double p = std::stod(localParams.at("p"));
		randomDigraph(G, n, p);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomSeriesParallelDAGGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void randomGeometricCubeGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void randomWaxmanGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void preferentialAttachmentGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int nodes = std::stoi(localParams.at("nodes"));
		int minDegree = std::stoi(localParams.at("minDegree"));
		preferentialAttachmentGraph(G, nodes, minDegree);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}
void randomWattsStrogatzGraphGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
void randomHierarchyGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
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
}
void pruneEdgesGenerator(Graph& G, const std::map<std::string, std::string>& localParams) {
	static const char* helpText = "no help";
	try {
		int max_edges = std::stoi(localParams.at("max_edges"));
		int min_deg = std::stoi(localParams.at("min_deg"));
		pruneEdges(G, max_edges, min_deg);
	} catch (const std::exception& e) {
		std::cout << helpText << std::endl;
		exit(1);
	}
}




using GenFunc = void (*)(Graph&, const std::map<std::string, std::string>&);

static const std::unordered_map<std::string, GenFunc> generatorTable = {
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
	{"randomPlanarTriconnectedGraph", randomPlanarTriconnectedGraphGenerator},
	{"randomPlanarTriconnectedGraph2", randomPlanarTriconnectedGraph2Generator},
	{"randomTree", randomTreeGenerator},
	{"randomTree2", randomTree2Generator},
	{"randomDigraph", randomDigraphGenerator},
	{"randomSeriesParallelDAG", randomSeriesParallelDAGGenerator},
	{"randomGeometricCubeGraph", randomGeometricCubeGraphGenerator},
	{"randomWaxmanGraph", randomWaxmanGraphGenerator},
	{"preferentialAttachmentGraph", preferentialAttachmentGraphGenerator},
	{"randomWattsStrogatzGraph", randomWattsStrogatzGraphGenerator},
	{"randomHierarchy", randomHierarchyGenerator},
	{"pruneEdges", pruneEdgesGenerator}
};

void applyGen(Graph& G, const std::string& name, const std::map<std::string, std::string>& params) {
	static const char* helpText = "complement                           bool directed=false, bool allowSelfLoops=false\nregularLatticeGraph                  int n, int k\nregularTree                          int n, int children\ncompleteGraph                        int n\ncompleteBipartiteGraph               int n, int m\nwheelGraph                           int n\ncubeGraph                            int n\nglobeGraph                           int meridians, int latitudes\nsuspension                           int s\ngridGraph                            int n, int m, bool loopN, bool loopM\npetersenGraph                        int n=5, int m=2\nemptyGraph                           int nodes\nrandomRegularGraph                   int n, int d\nrandomGraph                          int n, int m\nrandomSimpleGraph                    int n, int m\nrandomSimpleGraphByProbability       int n, double pEdge\nrandomSimpleConnectedGraph           int n, int m\nrandomBiconnectedGraph               int n, int m\nrandomPlanarConnectedGraph           int n, int m\nrandomPlanarBiconnectedGraph         int n, int m, bool multiEdges=false\nrandomPlanarBiconnectedDigraph       int n, int m, double p=0, bool multiEdges=false\nrandomUpwardPlanarBiconnectedDigraph int n, int m\nrandomPlanarCNBGraph                 int n, int m, int b\nrandomTriconnectedGraph              int n, double p1, double p2\nrandomPlanarTriconnectedGraph        int n, int m\nrandomPlanarTriconnectedGraph        int n, double p1, double p2\nrandomTree                           int n\nrandomTree                           int n, int maxDeg, int maxWidth\nrandomDigraph                        int n, double p\nrandomSeriesParallelDAG              int edges, double p=0.5, double flt=0.0\nrandomGeometricCubeGraph             int nodes, double threshold, int dimension=2\nrandomWaxmanGraph                    int nodes, double alpha, double beta, double width=1.0, double height=1.0\npreferentialAttachmentGraph          int nodes, int minDegree\nrandomWattsStrogatzGraph             int n, int k, double probability\nrandomHierarchy                      int n, int m, bool planar, bool singleSource, bool longEdges\npruneEdges                           int max_edges, int min_deg";
	auto it = generatorTable.find(name);
	if (it == generatorTable.end()) {
		throw std::invalid_argument("Unknown generator: " + name + ". Try these: \n\n"+helpText);
	}
	it->second(G, params); // Direct call
}
