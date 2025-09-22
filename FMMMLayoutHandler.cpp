#include <map>
#include <string>
#include <iostream>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/energybased/FMMMLayout.h>
#include <ogdf/energybased/GEMLayout.h>
#include <ogdf/energybased/SpringEmbedderGridVariant.h>
#include <ogdf/energybased/SpringEmbedderKK.h>
#include <ogdf/energybased/TutteLayout.h>
#include <ogdf/layered/SugiyamaLayout.h>

using namespace ogdf;

bool strToBool(const std::string& str) {
    if (str == "true" || str == "1" || str == "yes" || str == "on") {
        return true;
    }
    if (str == "false" || str == "0" || str == "no" || str == "off") {
        return false;
    }
    throw std::invalid_argument("Invalid boolean string: " + str);
}

//class FMMMLayoutHandler {
//public:
void applyFMMMLayout(GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams) {
	FMMMLayout layout;
	
	// Reset to default options first
	layout.resetOptions();
	
	
	for (const auto& [key, value] : layoutParams) {
		// Auto-generated-start
		if (key == "useHighLevelOptions") {
			layout.useHighLevelOptions(value == "true" || value == "1");
		}
		else if (key == "unitEdgeLength") {
			layout.unitEdgeLength(std::stod(value));
		}
		else if (key == "newInitialPlacement") {
			layout.newInitialPlacement(value == "true" || value == "1");
		}
		else if (key == "randSeed") {
			layout.randSeed(std::stoi(value));
		}
		else if (key == "maxIntPosExponent") {
			layout.maxIntPosExponent(std::stoi(value));
		}
		else if (key == "pageRatio") {
			layout.pageRatio(std::stod(value));
		}
		else if (key == "stepsForRotatingComponents") {
			layout.stepsForRotatingComponents(std::stoi(value));
		}
		else if (key == "minDistCC") {
			layout.minDistCC(std::stod(value));
		}
		else if (key == "minGraphSize") {
			layout.minGraphSize(std::stoi(value));
		}
		else if (key == "randomTries") {
			layout.randomTries(std::stoi(value));
		}
		else if (key == "maxIterFactor") {
			layout.maxIterFactor(std::stoi(value));
		}
		else if (key == "springStrength") {
			layout.springStrength(std::stod(value));
		}
		else if (key == "repForcesStrength") {
			layout.repForcesStrength(std::stod(value));
		}
		else if (key == "threshold") {
			layout.threshold(std::stod(value));
		}
		else if (key == "fixedIterations") {
			layout.fixedIterations(std::stoi(value));
		}
		else if (key == "forceScalingFactor") {
			layout.forceScalingFactor(std::stod(value));
		}
		else if (key == "coolTemperature") {
			layout.coolTemperature(value == "true" || value == "1");
		}
		else if (key == "coolValue") {
			layout.coolValue(std::stod(value));
		}
		else if (key == "resizeDrawing") {
			layout.resizeDrawing(value == "true" || value == "1");
		}
		else if (key == "resizingScalar") {
			layout.resizingScalar(std::stod(value));
		}
		else if (key == "fineTuningIterations") {
			layout.fineTuningIterations(std::stoi(value));
		}
		else if (key == "fineTuneScalar") {
			layout.fineTuneScalar(std::stod(value));
		}
		else if (key == "adjustPostRepStrengthDynamically") {
			layout.adjustPostRepStrengthDynamically(value == "true" || value == "1");
		}
		else if (key == "postSpringStrength") {
			layout.postSpringStrength(std::stod(value));
		}
		else if (key == "postStrengthOfRepForces") {
			layout.postStrengthOfRepForces(std::stod(value));
		}
		else if (key == "frGridQuotient") {
			layout.frGridQuotient(std::stoi(value));
		}
		else if (key == "nmParticlesInLeaves") {
			layout.nmParticlesInLeaves(std::stoi(value));
		}
		else if (key == "nmPrecision") {
			layout.nmPrecision(std::stoi(value));
		}
		// Auto-generated-end
		else {
			std::cout << "Ignored key: " << key << std::endl;
		}
	}
	//std::cout << "Applying layout... "<< std::endl;
	layout.call(GA);
	//std::cout << "Finished "<< std::endl;
}

void applyGEMLayout(GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams) {
GEMLayout layout;


for (const auto& [key, value] : layoutParams) {
if (key == "numberOfRounds") {
    layout.numberOfRounds(std::stoi(value));
}
 else if (key == "minimalTemperature") {
    layout.minimalTemperature(std::stod(value));
}
 else if (key == "initialTemperature") {
	//std::cout << "1: "<< value << std::endl;
	//std::cout << "2: "<< std::stod(value) << std::endl;
    layout.initialTemperature(std::stod(value));
}
 else if (key == "gravitationalConstant") {
    layout.gravitationalConstant(std::stod(value));
}
 else if (key == "desiredLength") {
    layout.desiredLength(std::stod(value));
}
 else if (key == "maximalDisturbance") {
    layout.maximalDisturbance(std::stod(value));
}
 else if (key == "rotationAngle") {
    layout.rotationAngle(std::stod(value));
}
 else if (key == "oscillationAngle") {
    layout.oscillationAngle(std::stod(value));
}
 else if (key == "rotationSensitivity") {
    layout.rotationSensitivity(std::stod(value));
}
 else if (key == "oscillationSensitivity") {
    layout.oscillationSensitivity(std::stod(value));
}
 else if (key == "attractionFormula") {
    layout.attractionFormula(std::stoi(value));
}
 else if (key == "minDistCC") {
    layout.minDistCC(std::stod(value));
}
 else if (key == "pageRatio") {
    layout.pageRatio(std::stod(value));
}
else {
std::cout << "Ignored key: " << key << std::endl;
}
}

//std::cout << "Applying layout... "<< std::endl;
	layout.call(GA);
	//std::cout << "Finished "<< std::endl;
}

void applySugiyamaLayout(GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams) {
	SugiyamaLayout layout;
	
	//layout.resetOptions();
	
	for (const auto& [key, value] : layoutParams) {
		if (key == "runs") {
    layout.runs(std::stoi(value));
}
		 else if (key == "transpose") {
    layout.transpose(value == "true" || value == "1");
}
		 else if (key == "fails") {
    layout.fails(std::stoi(value));
}
		 else if (key == "arrangeCCs") {
    layout.arrangeCCs(value == "true" || value == "1");
}
		 else if (key == "minDistCC") {
    layout.minDistCC(std::stod(value));
}
		 else if (key == "alignBaseClasses") {
    layout.alignBaseClasses(value == "true" || value == "1");
}
		 else if (key == "alignSiblings") {
    layout.alignSiblings(value == "true" || value == "1");
}
		else {
			std::cout << "Ignored key: " << key << std::endl;
		}
	}
	
	layout.call(GA);
}

void applySpringEmbedderGridVariant(GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams) {
	SpringEmbedderGridVariant layout;
	
	//layout.resetOptions();
	
	for (const auto& [key, value] : layoutParams) {
		if (key == "iterations") {
    layout.iterations(std::stoi(value));
}
		 else if (key == "noise") {
    layout.noise(value == "true" || value == "1");
}
		 else if (key == "minDistCC") {
    layout.minDistCC(std::stod(value));
}
		 else if (key == "pageRatio") {
    layout.pageRatio(std::stod(value));
}
		 else if (key == "scaleFunctionFactor") {
    layout.scaleFunctionFactor(std::stod(value));
}
		else {
			std::cout << "Ignored key: " << key << std::endl;
		}
	}
	
	layout.call(GA);
}

void applySpringEmbedderKK(GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams) {
	SpringEmbedderKK layout;
	
	//layout.resetOptions();
	
	for (const auto& [key, value] : layoutParams) {
		if (key == "tolerance") {
			layout.setStopTolerance(std::stoi(value));
		}
		else {
			std::cout << "Ignored key: " << key << std::endl;
		}
	}
	
	layout.call(GA);
}
void applyTutteLayout(GraphAttributes& GA, const std::map<std::string, std::string>& layoutParams) {
	TutteLayout layout;
	
	//layout.resetOptions();
	
	for (const auto& [key, value] : layoutParams) {
		std::cout << "Ignored key: " << key << std::endl;
	}
	
	layout.call(GA);
}

// ----------------- GENERATED ---------------------------------
#include <ogdf/energybased/DavidsonHarelLayout.h>
void applyDavidsonHarelLayout(GraphAttributes& GA, const std::map<std::string, std::string>& localParams) {
DavidsonHarelLayout layout;

static const char* helpText = "The Davidson-Harel layout algorithm.\n@ingroup gd-energy\nThe implementation used in DavidsonHarelLayout is based on\nthe following publication:\nRon Davidson, David Harel: <i>Drawing Graphs Nicely Using Simulated Annealing</i>.\nACM Transactions on Graphics 15(4), pp. 301-331, 1996.\nfixSettings (SettingsParameter)\nFixes the cost values to special configurations.\nPossible values: Standard, Repulse, Planar\n\nsetAttractionWeight (double)\nSets the weight for the energy function \\a Attraction.\n\nsetIterationNumberAsFactor (bool)\nSwitch between using iteration number as fixed number or factor\n(*number of nodes of graph)\n\nsetNodeOverlapWeight (double)\nSets the weight for the energy function \\a NodeOverlap.\n\nsetNumberOfIterations (int)\nSets the number of iterations per temperature step to \\p steps.\n\nsetPlanarityWeight (double)\nSets the weight for the energy function \\a Planarity.\n\nsetPreferredEdgeLength (double)\nSets the preferred edge length to \\p elen\n\nsetPreferredEdgeLengthMultiplier (double)\nSets the preferred edge length multiplier for attraction.\nThis is bad design, cause you dont need to have an attraction function,\nDH is purely modular and independent with its cost functions.\n\nsetRepulsionWeight (double)\nSets the weight for the energy function \\a Repulsion.\n\nsetSpeed (SpeedParameter)\nMore convenient way of setting the speed of the algorithm.\nInfluences number of iterations per temperature step, starting\ntemperature, and cooling factor.\nPossible values: Fast, Medium, HQ\n\nsetStartTemperature (int)\nSets the starting temperature to \\p t.";
if (localParams.find("help") != localParams.end()) {
std::cout << helpText << std::endl;
exit(0);
}
try {
for (const auto& [key, value] : localParams) {
if (key == "setAttractionWeight" || key == "attractionWeight") {
 layout.setAttractionWeight(std::stod(value));
}
else if (key == "setIterationNumberAsFactor" || key == "iterationNumberAsFactor") {
 layout.setIterationNumberAsFactor(strToBool(value));
}
else if (key == "setNodeOverlapWeight" || key == "nodeOverlapWeight") {
 layout.setNodeOverlapWeight(std::stod(value));
}
else if (key == "setNumberOfIterations" || key == "numberOfIterations") {
 layout.setNumberOfIterations(std::stoi(value));
}
else if (key == "setPlanarityWeight" || key == "planarityWeight") {
 layout.setPlanarityWeight(std::stod(value));
}
else if (key == "setPreferredEdgeLength" || key == "preferredEdgeLength") {
 layout.setPreferredEdgeLength(std::stod(value));
}
else if (key == "setPreferredEdgeLengthMultiplier" || key == "preferredEdgeLengthMultiplier") {
 layout.setPreferredEdgeLengthMultiplier(std::stod(value));
}
else if (key == "setRepulsionWeight" || key == "repulsionWeight") {
 layout.setRepulsionWeight(std::stod(value));
}
else if (key == "setStartTemperature" || key == "startTemperature") {
 layout.setStartTemperature(std::stoi(value));
}
else if (key == "fixSettings") {
		if (value == "Standard") {
		  layout.fixSettings(DavidsonHarelLayout::SettingsParameter::Standard);
		}
else 		if (value == "Repulse") {
		  layout.fixSettings(DavidsonHarelLayout::SettingsParameter::Repulse);
		}
else 		if (value == "Planar") {
		  layout.fixSettings(DavidsonHarelLayout::SettingsParameter::Planar);
		}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "setSpeed") {
		if (value == "Fast") {
		  layout.setSpeed(DavidsonHarelLayout::SpeedParameter::Fast);
		}
else 		if (value == "Medium") {
		  layout.setSpeed(DavidsonHarelLayout::SpeedParameter::Medium);
		}
else 		if (value == "HQ") {
		  layout.setSpeed(DavidsonHarelLayout::SpeedParameter::HQ);
		}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else {
std::cout << "Bad key: " << key << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
layout.call(GA);
} catch (const std::exception& e) {
std::cout << e.what() << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}