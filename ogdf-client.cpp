#include <ogdf/basic/Graph.h>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/fileformats/GraphIO.h>
#include <ogdf/energybased/FMMMLayout.h>
#include <ogdf/fileformats/GraphIO.h>
#include <ogdf/basic/graph_generators/deterministic.h>
#include <ogdf/basic/graph_generators/randomized.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace ogdf;

void applyFMMMLayout(ogdf::GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams);
//void applyGEMLayout(ogdf::GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams);
//void applySugiyamaLayout(ogdf::GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams);
//void applySpringEmbedderGridVariant(ogdf::GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams);
//void applySpringEmbedderKK(ogdf::GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams);
//void applyTutteLayout(ogdf::GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams);
void applyDavidsonHarelLayout(GraphAttributes& GA, const std::map<std::string, std::string>& localParams);
void applyNodeRespecterLayout(GraphAttributes& GA, const std::map<std::string, std::string>& localParams);

// Randomized generators
void randomRegularGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomSimpleGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomSimpleGraphByProbabilityGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomSimpleConnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomBiconnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomPlanarConnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomPlanarBiconnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomPlanarBiconnectedDigraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomUpwardPlanarBiconnectedDigraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomPlanarCNBGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomTriconnectedGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomPlanarTriconnectedGraph1Gen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomPlanarTriconnectedGraph2Gen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomTree1Gen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomTree2Gen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomDigraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomSeriesParallelDAGGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomGeometricCubeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomWaxmanGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void preferentialAttachmentGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void randomWattsStrogatzGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);

// Determenistic gens
void regularLatticeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void regularTreeGen(Graph& G, const std::map<std::string, std::string>& localParams);
void completeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void completeBipartiteGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void wheelGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void cubeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void globeGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void suspensionGen(Graph& G, const std::map<std::string, std::string>& localParams);
void gridGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void petersenGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);
void emptyGraphGen(Graph& G, const std::map<std::string, std::string>& localParams);

// Helper function to check if a string ends with a suffix
bool endsWith(const std::string& str, const std::string& suffix) {
	if (suffix.length() > str.length()) {
        return false;
    }
    // Compare the end of 'str' with 'suffix'
    return str.substr(str.length() - suffix.length()) == suffix;
}

std::map<std::string, std::string> parseArgs(const std::vector<std::string>& args) {
    std::map<std::string, std::string> result;
    
    for (size_t i = 0; i < args.size(); i++) {
        bool isNamed = args[i].substr(0, 2) == "--";
        
        // Collect values that follow (until next named argument or end)
        std::vector<std::string> values;
        size_t j = i + 1;
        while (j < args.size() && args[j].substr(0, 2) != "--") {
            values.push_back(args[j]);
            j++;
        }
        
        // Common case: --key value1 value2 ...
        if (isNamed && !values.empty()) {
            std::string key = args[i].substr(2); // Remove "--"
            
            // Join values with ";"
            std::ostringstream joinedValues;
            for (size_t k = 0; k < values.size(); k++) {
                if (k > 0) joinedValues << ";";
                joinedValues << values[k];
            }
            
            result[key] = joinedValues.str();
            i += values.size();
            continue;
        }
        // Switch case: --key (no values)
        else if (isNamed && values.empty()) {
            std::string key = args[i].substr(2); // Remove "--"
            result[key] = "true";
        }
    }
	if (result.count("echo")) {
		for (const auto& pair : result) {
			std::cout << "  " << pair.first << " = " << pair.second << std::endl;
		}
		exit(1);
	}
	
	//std::cerr << "Parsed args" << std::endl;
	return result;
}

bool readGraphFromTSV(const std::string& filename, 
                     const std::string& sourceCol, 
                     const std::string& targetCol,
                     Graph& G,
                     std::unordered_map<std::string, node>& nodeMap) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return false;
    }
    
    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "Empty file" << std::endl;
        return false;
    }
    
    // Parse header
    std::istringstream headerStream(line);
    std::string column;
    int sourceIndex = -1, targetIndex = -1;
    int colIndex = 0;
    
    while (std::getline(headerStream, column, '\t')) {
        if (column == sourceCol) sourceIndex = colIndex;
        if (column == targetCol) targetIndex = colIndex;
        colIndex++;
    }
    
    if (sourceIndex == -1 || targetIndex == -1) {
        std::cerr << "Source or target column not found in header" << std::endl;
        return false;
    }
    
    // Read data
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::string source, target;
        int currentIndex = 0;
        
        while (std::getline(iss, token, '\t')) {
            if (currentIndex == sourceIndex) source = token;
            if (currentIndex == targetIndex) target = token;
            currentIndex++;
        }
        
        if (!source.empty() && !target.empty()) {
            // Handle source node
            if (nodeMap.find(source) == nodeMap.end()) {
                node n = G.newNode();
                nodeMap[source] = n;
            }
            
            // Handle target node
            if (nodeMap.find(target) == nodeMap.end()) {
                node n = G.newNode();
                nodeMap[target] = n;
            }
            
            // Create edge
            G.newEdge(nodeMap[source], nodeMap[target]);
        }
    }
    
    return true;
}

void exportCoordinatesToTSV(const GraphAttributes& GA, 
                           const std::unordered_map<std::string, node>& nodeMap,
                           const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Cannot create output file: " + filename);
    }
    
    // Write header
    outFile << "id\tx\ty\n";
    
    // Create reverse mapping: node -> string ID
    std::unordered_map<node, std::string> nodeIdMap;
    for (const auto& pair : nodeMap) {
        nodeIdMap[pair.second] = pair.first;
    }
    
    // Write node coordinates
    for (node v : GA.constGraph().nodes) {
        double x = GA.x(v);
        double y = GA.y(v);
        auto it = nodeIdMap.find(v);
        if (it != nodeIdMap.end()) {
            outFile << it->second << "\t" << x << "\t" << y << "\n";
        } else {
            // Fallback - use node index if no mapping found
            outFile << "Node_" << v->index() << "\t" << x << "\t" << y << "\n";
        }
    }
    
    outFile.close();
}

void exportEdgesToTSV(const Graph& G,
                      const std::unordered_map<std::string, node>& nodeMap,
                      const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Cannot create output file: " + filename);
    }
    
    // Write header
    outFile << "source\ttarget\n";
    
    // Create reverse mapping: node -> string ID
    std::unordered_map<node, std::string> nodeIdMap;
    for (const auto& pair : nodeMap) {
        nodeIdMap[pair.second] = pair.first;
    }
    
    // Write edges
    for (edge e : G.edges) {
        node src = e->source();
        node tgt = e->target();
        
        auto srcIt = nodeIdMap.find(src);
        auto tgtIt = nodeIdMap.find(tgt);
        
        if (srcIt != nodeIdMap.end() && tgtIt != nodeIdMap.end()) {
            outFile << srcIt->second << "\t" << tgtIt->second << "\n";
        } else {
            // Fallback to node indices if no mapping found
            outFile << "Node_" << src->index() << "\t" << "Node_" << tgt->index() << "\n";
        }
    }
    
    outFile.close();
}
int findEndIndex(int startIndex, int argc, char* argv[], const std::vector<std::string>& stopStrings) {
    // Start searching from startIndex
    for (int i = startIndex; i < argc; i++) {
        std::string arg = argv[i];
        
        // Check if current argument matches any stop string
        for (const std::string& stopStr : stopStrings) {
            if (arg == stopStr) {
                return i; // Return index where stop string is found
            }
        }
    }
    
    // If no stop string found, return argc (end of arguments)
    return argc;
}

int main(int argc, char* argv[]) {
    
    std::string inFile, sourceCol, targetCol;
    Graph G;
	GraphAttributes GA; // Declare but don't initialize yet
	//std::unordered_map<node, std::string> nodeLabels;
	std::unordered_map<std::string, node> nodeMap;
	
    try {
        auto argsMap = parseArgs(std::vector<std::string>(argv + 1, argv + argc));
		
		
		if (argsMap.count("in-file") == 1 && argsMap.count("source") == 1 && argsMap.count("target") == 1) {
			// Simple extraction (will throw std::out_of_range if key doesn't exist)
			inFile = argsMap.at("in-file");
			sourceCol = argsMap.at("source");
			targetCol = argsMap.at("target");
			
			std::cout << "Reading graph from: " << inFile << std::endl;
			std::cout << "Source column: " << sourceCol << std::endl;
			std::cout << "Target column: " << targetCol << std::endl;
			
			// Read graph from TSV
			
			
			
			
			if (!readGraphFromTSV(inFile, sourceCol, targetCol, G, nodeMap)) {
				std::cout << "Failed to read graph " << std::endl;
				return 1;
			}
			
			std::cout << "Graph loaded: " << G.numberOfNodes() << " nodes, " 
					  << G.numberOfEdges() << " edges" << std::endl;
			
		}
		//std::cout << "hey 0 " << std::endl;
        // Apply layouts
		//GraphAttributes GA(G, GraphAttributes::nodeGraphics | GraphAttributes::edgeGraphics);
		
		int nodeId = 0; // Will be needed if generator used
		std::vector<std::string> stopStrings = {"--layout", "--out-file", "--out-edges"};
		for (int i = 1; i < argc - 1; i++) {
			std::string arg = argv[i];
			//std::cout << "arg " << arg << std::endl;
			if (arg == "--generate") {
				std::string generatorName = argv[i + 1];
				
				int endIndex = findEndIndex(i + 2, argc, argv, stopStrings);
				std::vector<std::string> subArgs = std::vector<std::string>(argv + i + 2, argv + endIndex);
				std::map<std::string, std::string> localParams = parseArgs(subArgs);
				
				if (generatorName == "randomRegularGraph") {
				randomRegularGraphGen(G, localParams);
				}
				 else if (generatorName == "randomGraph") {
				randomGraphGen(G, localParams);
				}
				 else if (generatorName == "randomSimpleGraph") {
				randomSimpleGraphGen(G, localParams);
				}
				 else if (generatorName == "randomSimpleGraphByProbability") {
				randomSimpleGraphByProbabilityGen(G, localParams);
				}
				 else if (generatorName == "randomSimpleConnectedGraph") {
				randomSimpleConnectedGraphGen(G, localParams);
				}
				 else if (generatorName == "randomBiconnectedGraph") {
				randomBiconnectedGraphGen(G, localParams);
				}
				 else if (generatorName == "randomPlanarConnectedGraph") {
				randomPlanarConnectedGraphGen(G, localParams);
				}
				 else if (generatorName == "randomPlanarBiconnectedGraph") {
				randomPlanarBiconnectedGraphGen(G, localParams);
				}
				 else if (generatorName == "randomPlanarBiconnectedDigraph") {
				randomPlanarBiconnectedDigraphGen(G, localParams);
				}
				 else if (generatorName == "randomUpwardPlanarBiconnectedDigraph") {
				randomUpwardPlanarBiconnectedDigraphGen(G, localParams);
				}
				 else if (generatorName == "randomPlanarCNBGraph") {
				randomPlanarCNBGraphGen(G, localParams);
				}
				 else if (generatorName == "randomTriconnectedGraph") {
				randomTriconnectedGraphGen(G, localParams);
				}
				 else if (generatorName == "randomPlanarTriconnectedGraph1") {
				randomPlanarTriconnectedGraph1Gen(G, localParams);
				}
				 else if (generatorName == "randomPlanarTriconnectedGraph2") {
				randomPlanarTriconnectedGraph2Gen(G, localParams);
				}
				 else if (generatorName == "randomTree1") {
				randomTree1Gen(G, localParams);
				}
				 else if (generatorName == "randomTree2") {
				randomTree2Gen(G, localParams);
				}
				 else if (generatorName == "randomDigraph") {
				randomDigraphGen(G, localParams);
				}
				 else if (generatorName == "randomSeriesParallelDAG") {
				randomSeriesParallelDAGGen(G, localParams);
				}
				 else if (generatorName == "randomGeometricCubeGraph") {
				randomGeometricCubeGraphGen(G, localParams);
				}
				 else if (generatorName == "randomWaxmanGraph") {
				randomWaxmanGraphGen(G, localParams);
				}
				 else if (generatorName == "preferentialAttachmentGraph") {
				preferentialAttachmentGraphGen(G, localParams);
				}
				 else if (generatorName == "randomWattsStrogatzGraph") {
				randomWattsStrogatzGraphGen(G, localParams);
				}
				
				// DETERMINISTIC GENERATORS
				else if (generatorName == "regularLatticeGraph") {
				regularLatticeGraphGen(G, localParams);
				}
				 else if (generatorName == "regularTree") {
				regularTreeGen(G, localParams);
				}
				 else if (generatorName == "completeGraph") {
				completeGraphGen(G, localParams);
				}
				 else if (generatorName == "completeBipartiteGraph") {
				completeBipartiteGraphGen(G, localParams);
				}
				 else if (generatorName == "wheelGraph") {
				wheelGraphGen(G, localParams);
				}
				 else if (generatorName == "cubeGraph") {
				cubeGraphGen(G, localParams);
				}
				 else if (generatorName == "globeGraph") {
				globeGraphGen(G, localParams);
				}
				 else if (generatorName == "suspension") {
				suspensionGen(G, localParams);
				}
				 else if (generatorName == "gridGraph") {
				gridGraphGen(G, localParams);
				}
				 else if (generatorName == "petersenGraph") {
				petersenGraphGen(G, localParams);
				}
				 else if (generatorName == "emptyGraph") {
				emptyGraphGen(G, localParams);
				}

					else {
						static const char* availRandomizedGenNames = "randomRegularGraph \n randomGraph \n randomSimpleGraph \n randomSimpleGraphByProbability \n randomSimpleConnectedGraph \n randomBiconnectedGraph \n randomPlanarConnectedGraph \n randomPlanarBiconnectedGraph \n randomPlanarBiconnectedDigraph \n randomUpwardPlanarBiconnectedDigraph \n randomPlanarCNBGraph \n randomTriconnectedGraph \n randomPlanarTriconnectedGraph1 \n randomPlanarTriconnectedGraph2 \n randomTree1 \n randomTree2 \n randomDigraph \n randomSeriesParallelDAG \n randomGeometricCubeGraph \n randomWaxmanGraph \n preferentialAttachmentGraph \n randomWattsStrogatzGraph";
						static const char* availDeterministicGenNames = "regularLatticeGraph \n regularTree \n completeGraph \n completeBipartiteGraph \n wheelGraph \n cubeGraph \n globeGraph \n suspension \n gridGraph \n petersenGraph \n emptyGraph";
						std::cout << "No such generator: " << generatorName << std::endl;
						std::cout << "Try these randomized: " << std::endl << availRandomizedGenNames << std::endl << std::endl;
						std::cout << "Try these deterministic: " << availDeterministicGenNames << std::endl;
						exit(1);
					}
					// After generator was used, need to record node ids and init GA
					for (node v : G.nodes) {
						nodeMap[std::to_string(nodeId++)] = v;
					}
					GA.init(G, GraphAttributes::nodeGraphics | GraphAttributes::edgeGraphics);
					i = endIndex - 1;
				
			}
			else if (arg == "--layout") {
				std::string layoutName = argv[i + 1];
				//auto layoutParams = parseArgs(std::vector<std::string>(i, argv + argc), layoutName);
				int endIndex = findEndIndex(i + 2, argc, argv, stopStrings);
				std::vector<std::string> subArgs = std::vector<std::string>(argv + i + 2, argv + endIndex);
				std::map<std::string, std::string> layoutParams = parseArgs(subArgs);
				
				//std::cout << "count0 " << std::endl;
				
				GA.init(G, GraphAttributes::nodeGraphics | GraphAttributes::edgeGraphics);
				
				if (layoutName == "FMMM") {
					//std::cout << "Applying layout: " << layoutName << std::endl;
					applyFMMMLayout(GA, layoutParams);
				} 
				//else if (layoutName == "GEM") {
				//	//std::cout << "Applying layout: " << layoutName << std::endl;
				//	applyGEMLayout(GA, layoutParams);
				//	//applyFFFMLayout(GA, layoutParams);
				//}
				//else if (layoutName == "Sugiyama") {
				//	applySugiyamaLayout(GA, layoutParams);
				//}
				//else if (layoutName == "SpringEmbedderGridVariant") {
				//	applySpringEmbedderGridVariant(GA, layoutParams);
				//}
				//else if (layoutName == "SpringEmbedderKK") {
				//	applySpringEmbedderKK(GA, layoutParams);
				//}
				//else if (layoutName == "Tutte") {
				//	applyTutteLayout(GA, layoutParams);
				//}
				else if (layoutName == "DavidsonHarel") {
					applyDavidsonHarelLayout(GA, layoutParams);
				}
				else if (layoutName == "NodeRespecter") {
					applyNodeRespecterLayout(GA, layoutParams);
				}
				else {
					std::cout << "No such layout: " << layoutName << std::endl;
					exit(1);
				}
				
				std::cout << "Layout " << layoutName << " applied successfully" << std::endl;
				i = endIndex - 1;
			}
		}
		//std::cout << "count> " << std::endl;
		//std::cout << "count " << argsMap.count("out-file") << std::endl;
		
        
		if (argsMap.count("out-file")) {
			std::string file = argsMap.at("out-file");
			if (endsWith(file, ".csv") || endsWith(file, ".tsv")) {
				exportCoordinatesToTSV(GA, nodeMap, file);
				std::cout << "Nodes exported to TSV: " << file << std::endl;
			} else {
				// Default OGDF exporter, find formats here:
				// https://ogdf.netlify.app/classogdf_1_1_graph_i_o
				ogdf::GraphIO::write(GA, file, nullptr);
			}
		}
		if (argsMap.count("out-edges")) {
			auto file = argsMap.at("out-edges");
			exportEdgesToTSV(G, nodeMap, file);
			std::cout << "Edges exported to TSV: " << file << std::endl;
		}
		
        
    } catch (const std::exception& e) {
		std::cout << "usage: --in-file tree.tsv --source source --target target --out-file coords.tsv" << std::endl;
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
