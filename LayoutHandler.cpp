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

inline bool strToBool(const std::string& str) {
    if (str == "true" || str == "1" || str == "yes" || str == "on") {
        return true;
    }
    if (str == "false" || str == "0" || str == "no" || str == "off") {
        return false;
    }
    throw std::invalid_argument("Invalid boolean string: " + str);
}

#include <ogdf/energybased/DavidsonHarelLayout.h>
void applyDavidsonHarelLayout(GraphAttributes& GA, const std::map<std::string, std::string>& localParams) {
DavidsonHarelLayout layout;

static const char* helpText = "The Davidson-Harel layout algorithm.\n@ingroup gd-energy\nThe implementation used in DavidsonHarelLayout is based on\nthe following publication:\nRon Davidson, David Harel: <i>Drawing Graphs Nicely Using Simulated Annealing</i>.\nACM Transactions on Graphics 15(4), pp. 301-331, 1996.\nfixSettings (SettingsParameter)\nFixes the cost values to special configurations.\nPossible values: \n\n\nsetAttractionWeight (double)\nSets the weight for the energy function \\a Attraction.\n\nsetIterationNumberAsFactor (bool)\nSwitch between using iteration number as fixed number or factor\n(*number of nodes of graph)\n\nsetNodeOverlapWeight (double)\nSets the weight for the energy function \\a NodeOverlap.\n\nsetNumberOfIterations (int)\nSets the number of iterations per temperature step to \\p steps.\n\nsetPlanarityWeight (double)\nSets the weight for the energy function \\a Planarity.\n\nsetPreferredEdgeLength (double)\nSets the preferred edge length to \\p elen\n\nsetPreferredEdgeLengthMultiplier (double)\nSets the preferred edge length multiplier for attraction.\nThis is bad design, cause you dont need to have an attraction function,\nDH is purely modular and independent with its cost functions.\n\nsetRepulsionWeight (double)\nSets the weight for the energy function \\a Repulsion.\n\nsetSpeed (SpeedParameter)\nMore convenient way of setting the speed of the algorithm.\nInfluences number of iterations per temperature step, starting\ntemperature, and cooling factor.\nPossible values: \n\n\nsetStartTemperature (int)\nSets the starting temperature to \\p t.";
if (localParams.find("help") != localParams.end()) {
std::cout << helpText << std::endl;
exit(0);
}
try {
for (const auto& [key, value] : localParams) {
		if (key == "setAttractionWeight" || key == "attractionWeight") {
			layout.setAttractionWeight(std::stod(value));
		}
else 		if (key == "setIterationNumberAsFactor" || key == "iterationNumberAsFactor") {
			layout.setIterationNumberAsFactor(strToBool(value));
		}
else 		if (key == "setNodeOverlapWeight" || key == "nodeOverlapWeight") {
			layout.setNodeOverlapWeight(std::stod(value));
		}
else 		if (key == "setNumberOfIterations" || key == "numberOfIterations") {
			layout.setNumberOfIterations(std::stoi(value));
		}
else 		if (key == "setPlanarityWeight" || key == "planarityWeight") {
			layout.setPlanarityWeight(std::stod(value));
		}
else 		if (key == "setPreferredEdgeLength" || key == "preferredEdgeLength") {
			layout.setPreferredEdgeLength(std::stod(value));
		}
else 		if (key == "setPreferredEdgeLengthMultiplier" || key == "preferredEdgeLengthMultiplier") {
			layout.setPreferredEdgeLengthMultiplier(std::stod(value));
		}
else 		if (key == "setRepulsionWeight" || key == "repulsionWeight") {
			layout.setRepulsionWeight(std::stod(value));
		}
else 		if (key == "setStartTemperature" || key == "startTemperature") {
			layout.setStartTemperature(std::stoi(value));
		}
else if (key == "fixSettings") {
			if (value == "Standard") {
			  layout.fixSettings(DavidsonHarelLayout::SettingsParameter::Standard);
			}
else 			if (value == "Repulse") {
			  layout.fixSettings(DavidsonHarelLayout::SettingsParameter::Repulse);
			}
else 			if (value == "Planar") {
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
else 			if (value == "Medium") {
			  layout.setSpeed(DavidsonHarelLayout::SpeedParameter::Medium);
			}
else 			if (value == "HQ") {
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


#include <ogdf/energybased/FMMMLayout.h>
void applyFMMMLayout(GraphAttributes& GA, const std::map<std::string, std::string>& localParams) {
FMMMLayout layout;

static const char* helpText = "\\brief The fast multipole multilevel layout algorithm.\n@ingroup gd-energy\nThe class FMMMLayout implements a force-directed graph drawing\nmethod suited also for very large graphs. It is based on a\ncombination of an efficient multilevel scheme and a strategy for\napproximating the repulsive forces in the system by rapidly\nevaluating potential fields.\nThe implementation is based on the following publication:\nStefan Hachul, Michael Jünger: <i>Drawing Large Graphs with a\nPotential-Field-Based Multilevel Algorithm</i>. 12th International\nSymposium on %Graph Drawing 1998, New York (GD '04), LNCS 3383,\npp. 285-295, 2004.\n<H3>Optional parameters</H3>\nThe following options are the most important. You can set\nuseHighLevelOptions to true and just need to adjust a few parameters.\nHowever, you can also adjust all parameters that the implementation\nuses (see below), but this requires good knowledge of the algorithm.\n<table>\n<tr>\n<th><i>Option</i><th><i>Type</i><th><i>Default</i><th><i>Description</i>\n</tr><tr>\n<td><i>useHighLevelOptions</i><td>bool<td>false\n<td>Whether high-level options are used or not.\n</tr><tr>\n<td><i>pageFormat</i><td> FMMMOptions::PageFormatType <td> \\c Square\n<td>The desired aspect ratio of the layout.\n</tr><tr>\n<td><i>unitEdgeLength</i><td>double<td>100.0\n<td>The unit edge length.\n</tr><tr>\n<td><i>newInitialPlacement</i><td>bool<td>false\n<td>Specifies if initial placement of nodes is varied.\n</tr><tr>\n<td><i>qualityVersusSpeed</i><td> FMMMOptions::QualityVsSpeed <td> \\c BeautifulAndFast\n<td>Indicates if the algorithm is tuned either for best quality or best speed.\n</tr>\n</table>\nIf you want to do more detailed fine-tuning, you can adjust all parameters\nused by the algorithm. Please refer to the paper cited above for better\nunderstanding of the algorithm.\n<table>\n<tr>\n<th colspan=\"4\" align=\"center\"><b>General</b>\n</tr><tr>\n<td><i>randSeed</i><td>int<td>100\n<td>The seed of the random number generator.\n</tr><tr>\n<td><i>edgeLengthMeasurement</i><td> FMMMOptions::EdgeLengthMeasurement <td> \\c BoundingCircle\n<td>Indicates how the length of an edge is measured.\n</tr><tr>\n<td><i>allowedPositions</i><td> FMMMOptions::AllowedPositions <td> \\c Integer\n<td>Defines which positions for a node are allowed.\n</tr><tr>\n<td><i>maxIntPosExponent</i><td>int<td>40\n<td>Defines the exponent used if allowedPositions == Exponent.\n</tr><tr>\n<th colspan=\"4\" align=\"center\"><b>Divide et impera step</b>\n</tr><tr>\n<td><i>pageRatio</i><td>double<td>1.0\n<td>The desired page ratio.\n</tr><tr>\n<td><i>stepsForRotatingComponents</i><td>int<td>10\n<td>The number of rotations per connected component.\n</tr><tr>\n<td><i>tipOverCCs</i><td> FMMMOptions::TipOver <td> \\c NoGrowingRow\n<td>Specifies when it is allowed to tip over drawings.\n</tr><tr>\n<td><i>minDistCC</i><td>double<td>100\n<td>The minimal distance between connected components.\n</tr><tr>\n<td><i>presortCCs</i><td> FMMMOptions::PreSort <td> \\c DecreasingHeight\n<td>Defines if the connected components are sorted before\nthe packing algorithm is applied.\n</tr><tr>\n<th colspan=\"4\" align=\"center\"><b>Multilevel step</b>\n</tr><tr>\n<td><i>minGraphSize</i><td>int<td>50\n<td>Determines the number of nodes of a graph for which\nno more collapsing of galaxies is performed.\n</tr><tr>\n<td><i>galaxyChoice</i><td> FMMMOptions::GalaxyChoice <td> \\c NonUniformProbLowerMass\n<td>Defines how sun nodes of galaxies are selected.\n</tr><tr>\n<td><i>randomTries</i><td>int<td>20\n<td>Defines the number of tries to get a random node with\nminimal star mass.\n</tr><tr>\n<td><i>maxIterChange</i><td> FMMMOptions::MaxIterChange <td> \\c LinearlyDecreasing\n<td>Defines how MaxIterations is changed in subsequent multilevels.\n</tr><tr>\n<td><i>maxIterFactor</i><td>int<td>10\n<td>Defines the factor used for decreasing MaxIterations.\n</tr><tr>\n<td><i>initialPlacementMult</i><td> FMMMOptions::InitialPlacementMult <td> \\c Advanced\n<td>Defines how the initial placement is generated.\n</tr><tr>\n<th colspan=\"4\" align=\"center\"><b>Force calculation step</b>\n</tr><tr>\n<td><i>forceModel</i><td> FMMMOptions::ForceModel <td> \\c New\n<td>The used force model.\n</tr><tr>\n<td><i>springStrength</i><td>double<td>1.0\n<td>The strength of the springs.\n</tr><tr>\n<td><i>repForcesStrength</i><td>double<td>1.0\n<td>The strength of the repulsive forces.\n</tr><tr>\n<td><i>repulsiveForcesCalculation</i><td> FMMMOptions::RepulsiveForcesMethod <td> \\c NMM\n<td>Defines how to calculate repulsive forces.\n</tr><tr>\n<td><i>stopCriterion</i><td> FMMMOptions::StopCriterion <td> \\c FixedIterationsOrThreshold\n<td>The stop criterion.\n</tr><tr>\n<td><i>threshold</i><td>double<td>0.01\n<td>The threshold for the stop criterion.\n</tr><tr>\n<td><i>fixedIterations</i><td>int<td>30\n<td>The fixed number of iterations for the stop criterion.\n</tr><tr>\n<td><i>forceScalingFactor</i><td>double<td>0.05\n<td>The scaling factor for the forces.\n</tr><tr>\n<td><i>coolTemperature</i><td>bool<td>false\n<td>Use coolValue for scaling forces.\n</tr><tr>\n<td><i>coolValue</i><td>double<td>0.99\n<td>The value by which forces are decreased.\n</tr><tr>\n<td><i>initialPlacementForces</i><td> FMMMOptions::InitialPlacementForces <td> \\c RandomRandIterNr\n<td>Defines how the initial placement is done.\n</tr><tr>\n<th colspan=\"4\" align=\"center\"><b>Force calculation step</b>\n</tr><tr>\n<td><i>resizeDrawing</i><td>bool<td>true\n<td>Specifies if the resulting drawing is resized.\n</tr><tr>\n<td><i>resizingScalar</i><td>double<td>1\n<td>Defines a parameter to scale the drawing if resizeDrawing is true.\n</tr><tr>\n<td><i>fineTuningIterations</i><td>int<td>20\n<td>The number of iterations for fine tuning.\n</tr><tr>\n<td><i>fineTuneScalar</i><td>double<td>0.2\n<td>Defines a parameter for scaling the forces in the fine-tuning iterations.\n</tr><tr>\n<td><i>adjustPostRepStrengthDynamically</i><td>bool<td>true\n<td>If set to true, the strength of the repulsive force field is calculated.\n</tr><tr>\n<td><i>postSpringStrength</i><td>double<td>2.0\n<td>The strength of the springs in the postprocessing step.\n</tr><tr>\n<td><i>postStrengthOfRepForces</i><td>double<td>0.01\n<td>The strength of the repulsive forces in the postprocessing step.\n</tr><tr>\n<th colspan=\"4\" align=\"center\"><b>Repulsive force approximation methods</b>\n</tr><tr>\n<td><i>frGridQuotient</i><td>int<td>2\n<td>The grid quotient.\n</tr><tr>\n<td><i>nmTreeConstruction</i><td> FMMMOptions::ReducedTreeConstruction <td> \\c SubtreeBySubtree\n<td>Defines how the reduced bucket quadtree is constructed.\n</tr><tr>\n<td><i>nmSmallCell</i><td> FMMMOptions::SmallestCellFinding <td> \\c Iteratively\n<td>Defines how the smallest quadratic cell that surrounds\nthe particles of a node in the reduced bucket quadtree is calculated.\n</tr><tr>\n<td><i>nmParticlesInLeaves</i><td>int<td>25\n<td>The maximal number of particles that are contained in\na leaf of the reduced bucket quadtree.\n</tr><tr>\n<td><i>nmPrecision</i><td>int<td>4\n<td>The precision \\a p for the <i>p</i>-term multipole expansions.\n</tr>\n</table>\n<H3>Running time</H3>\nThe running time of the algorithm is\nO(<i>n</i> log <i>n</i> + <i>m</i>) for graphs with \\a n nodes\nand \\a m edges. The required space is linear in the input size.\nadjustPostRepStrengthDynamically (bool)\nSets the option adjustPostRepStrengthDynamically to \\p b.\n\nallowedPositions (FMMMOptions::AllowedPositions)\nSets the option allowedPositions to \\p ap.\nPossible values: \n//! Every position is allowed\nAll,\n\n//! Only integer positions are allowed that are in a range\n//! depending on the number of nodes and the average ideal edge length.\nInteger,\n\n//! Only integer positions in a range of -2^MaxIntPosExponent to\n//! 2^MaxIntPosExponent are alllowed\nExponent\n\ncoolTemperature (bool)\nSets the option coolTemperature to \\p b.\n\ncoolValue (double)\nSets the option coolValue to \\p x.\n\nedgeLengthMeasurement (FMMMOptions::EdgeLengthMeasurement)\nSets the option edgeLengthMeasurement to \\p elm.\nPossible values: \nMidpoint, //!< Measure from center point of edge end points.\nBoundingCircle //!< Measure from border of circle s surrounding edge end points.\n\nfineTuneScalar (double)\nSets the option fineTuneScalar to \\p s\n\nfineTuningIterations (int)\nSets the number of iterations for fine tuning to \\p n.\n\nfixedIterations (int)\nSets the fixed number of iterations for the stop criterion to \\p n.\n\nforceModel (FMMMOptions::ForceModel)\nSets the used force model to \\p fm.\nPossible values: \nFruchtermanReingold, //!< The force-model by Fruchterman, Reingold.\nEades, //!< The force-model by Eades.\nNew //!< The new force-model.\n\nforceScalingFactor (double)\nSets the scaling factor for the forces to \\p f.\n\nfrGridQuotient (int)\nSets the option frGridQuotient to \\p p.\n\ngalaxyChoice (FMMMOptions::GalaxyChoice)\nSets the option galaxyChoice to \\p gc.\nPossible values: \nUniformProb, //!< selecting by uniform random probability\nNonUniformProbLowerMass, //!< selecting by non-uniform probability depending\n//!< on the star masses (prefering nodes with lower star mass)\nNonUniformProbHigherMass //!< as above but prefering nodes with higher star mass\n\ninitialPlacementForces (FMMMOptions::InitialPlacementForces)\nSets the option initialPlacementForces to \\p ipf.\nPossible values: \nUniformGrid, //!< Uniform placement on a grid.\nRandomTime, //!< Random placement (based on current time).\nRandomRandIterNr, //!< Random placement (based on randIterNr()).\nKeepPositions //!< No change in placement.\n\ninitialPlacementMult (FMMMOptions::InitialPlacementMult)\nSets the option initialPlacementMult to \\p ipm.\nPossible values: \nSimple, //!< only using information about placement of nodes on higher levels\nAdvanced //!< using additional information about the placement of all inter solar system nodes\n\nmaxIntPosExponent (int)\nSets the option maxIntPosExponent to \\p e.\n\nmaxIterChange (FMMMOptions::MaxIterChange)\nSets the option maxIterChange to \\p mic.\nPossible values: \nConstant, //!< kept constant at the force calculation step at every level\nLinearlyDecreasing, //!< linearly decreasing from MaxIterFactor*FixedIterations to FixedIterations\nRapidlyDecreasing //!< rapdily decreasing from MaxIterFactor*FixedIterations to FixedIterations\n\nmaxIterFactor (int)\nSets the option maxIterFactor to \\p f.\n\nminDistCC (double)\nSets the  minimal distance between connected components to \\p x.\n\nminGraphSize (int)\nSets the option minGraphSize to \\p n.\n\nnewInitialPlacement (bool)\nSets the option newInitialPlacement to \\p nip.\n\nnmParticlesInLeaves (int)\nSets the option nmParticlesInLeaves to \\p n.\n\nnmPrecision (int)\nSets the precision for the multipole expansions to \\p p.\n\nnmSmallCell (FMMMOptions::SmallestCellFinding)\nSets the option nmSmallCell to \\p scf.\nPossible values: \nIteratively, //!< Iteratively (in constant time).\nAluru //!< According to formula by Aluru et al. (in constant time).\n\nnmTreeConstruction (FMMMOptions::ReducedTreeConstruction)\nSets the option nmTreeConstruction to \\p rtc.\nPossible values: \nPathByPath, //!< Path-by-path construction.\nSubtreeBySubtree //!< Subtree-by-subtree construction.\n\npageFormat (FMMMOptions::PageFormatType)\nSets the option pageRatio to \\p t.\nPossible values: \nPortrait, //!< A4 portrait page.\nLandscape, //!< A4 landscape page.\nSquare //!< Square format.\n\npageRatio (double)\nSets the option pageRatio to \\p r.\n\npostSpringStrength (double)\nSets the strength of the springs in the postprocessing step to \\p x.\n\npostStrengthOfRepForces (double)\nSets the strength of the repulsive forces in the postprocessing step to \\p x.\n\npresortCCs (FMMMOptions::PreSort)\nSets the option presortCCs to \\p ps.\nPossible values: \nNone, //!< Do not presort.\nDecreasingHeight, //!< Presort by decreasing height of components.\nDecreasingWidth //!< Presort by decreasing width of components.\n\nqualityVersusSpeed (FMMMOptions::QualityVsSpeed)\nSets the option qualityVersusSpeed to \\p qvs.\nPossible values: \nGorgeousAndEfficient, //!< Best quality.\nBeautifulAndFast, //!< Medium quality and speed.\nNiceAndIncredibleSpeed //!< Best speed.\n\nrandSeed (int)\nSets the seed of the random number generator.\n\nrandomTries (int)\nSets the option randomTries to \\p n.\n\nrepForcesStrength (double)\nSets the strength of the repulsive forces to \\p x.\n\nrepulsiveForcesCalculation (FMMMOptions::RepulsiveForcesMethod)\nSets the option repulsiveForcesCalculation to \\p rfc.\nPossible values: \nExact, //!< Exact calculation (slow).\nGridApproximation, //!< Grid approximation (inaccurate).\nNMM //!< Calculation as for new multipole method (fast and accurate).\n\nresizeDrawing (bool)\nSets the option resizeDrawing to \\p b.\n\nresizingScalar (double)\nSets the option resizingScalar to \\p s.\n\nsetSingleLevel (bool)\nSets single level option, no multilevel hierarchy is created if b == true\n\nspringStrength (double)\nSets the strength of the springs to \\p x.\n\nstepsForRotatingComponents (int)\nSets the option stepsForRotatingComponents to \\p n.\n\nstopCriterion (FMMMOptions::StopCriterion)\nSets the stop criterion to \\p rsc.\nPossible values: \nFixedIterations, //!< Stop if fixedIterations() is reached.\nThreshold, //!< Stop if threshold() is reached.\nFixedIterationsOrThreshold //!< Stop if fixedIterations() or threshold() is reached.\n\nthreshold (double)\nSets the threshold for the stop criterion to \\p x.\n\ntipOverCCs (FMMMOptions::TipOver)\nSets the option tipOverCCs to \\p to.\nPossible values: \nNone, //!< not allowed at all\nNoGrowingRow, //!< only if the height of the packing row does not grow\nAlways //!< always allowed\n\nunitEdgeLength (double)\nSets the option unitEdgeLength to \\p x.\n\nuseHighLevelOptions (bool)\nSets the option useHighLevelOptions to \\p uho.";
if (localParams.find("help") != localParams.end()) {
std::cout << helpText << std::endl;
exit(0);
}
try {
for (const auto& [key, value] : localParams) {
		if (key == "adjustPostRepStrengthDynamically") {
			layout.adjustPostRepStrengthDynamically(strToBool(value));
		}
else 		if (key == "coolTemperature") {
			layout.coolTemperature(strToBool(value));
		}
else 		if (key == "coolValue") {
			layout.coolValue(std::stod(value));
		}
else 		if (key == "fineTuneScalar") {
			layout.fineTuneScalar(std::stod(value));
		}
else 		if (key == "fineTuningIterations") {
			layout.fineTuningIterations(std::stoi(value));
		}
else 		if (key == "fixedIterations") {
			layout.fixedIterations(std::stoi(value));
		}
else 		if (key == "forceScalingFactor") {
			layout.forceScalingFactor(std::stod(value));
		}
else 		if (key == "frGridQuotient") {
			layout.frGridQuotient(std::stoi(value));
		}
else 		if (key == "maxIntPosExponent") {
			layout.maxIntPosExponent(std::stoi(value));
		}
else 		if (key == "maxIterFactor") {
			layout.maxIterFactor(std::stoi(value));
		}
else 		if (key == "minDistCC") {
			layout.minDistCC(std::stod(value));
		}
else 		if (key == "minGraphSize") {
			layout.minGraphSize(std::stoi(value));
		}
else 		if (key == "newInitialPlacement") {
			layout.newInitialPlacement(strToBool(value));
		}
else 		if (key == "nmParticlesInLeaves") {
			layout.nmParticlesInLeaves(std::stoi(value));
		}
else 		if (key == "nmPrecision") {
			layout.nmPrecision(std::stoi(value));
		}
else 		if (key == "pageRatio") {
			layout.pageRatio(std::stod(value));
		}
else 		if (key == "postSpringStrength") {
			layout.postSpringStrength(std::stod(value));
		}
else 		if (key == "postStrengthOfRepForces") {
			layout.postStrengthOfRepForces(std::stod(value));
		}
else 		if (key == "randSeed") {
			layout.randSeed(std::stoi(value));
		}
else 		if (key == "randomTries") {
			layout.randomTries(std::stoi(value));
		}
else 		if (key == "repForcesStrength") {
			layout.repForcesStrength(std::stod(value));
		}
else 		if (key == "resizeDrawing") {
			layout.resizeDrawing(strToBool(value));
		}
else 		if (key == "resizingScalar") {
			layout.resizingScalar(std::stod(value));
		}
else 		if (key == "setSingleLevel" || key == "singleLevel") {
			layout.setSingleLevel(strToBool(value));
		}
else 		if (key == "springStrength") {
			layout.springStrength(std::stod(value));
		}
else 		if (key == "stepsForRotatingComponents") {
			layout.stepsForRotatingComponents(std::stoi(value));
		}
else 		if (key == "threshold") {
			layout.threshold(std::stod(value));
		}
else 		if (key == "unitEdgeLength") {
			layout.unitEdgeLength(std::stod(value));
		}
else 		if (key == "useHighLevelOptions") {
			layout.useHighLevelOptions(strToBool(value));
		}
else if (key == "allowedPositions") {
			if (value == "All") {
			  layout.allowedPositions(FMMMOptions::AllowedPositions::All);
			}
else 			if (value == "Integer") {
			  layout.allowedPositions(FMMMOptions::AllowedPositions::Integer);
			}
else 			if (value == "Exponent") {
			  layout.allowedPositions(FMMMOptions::AllowedPositions::Exponent);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "edgeLengthMeasurement") {
			if (value == "Midpoint") {
			  layout.edgeLengthMeasurement(FMMMOptions::EdgeLengthMeasurement::Midpoint);
			}
else 			if (value == "BoundingCircle") {
			  layout.edgeLengthMeasurement(FMMMOptions::EdgeLengthMeasurement::BoundingCircle);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "forceModel") {
			if (value == "FruchtermanReingold") {
			  layout.forceModel(FMMMOptions::ForceModel::FruchtermanReingold);
			}
else 			if (value == "Eades") {
			  layout.forceModel(FMMMOptions::ForceModel::Eades);
			}
else 			if (value == "New") {
			  layout.forceModel(FMMMOptions::ForceModel::New);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "galaxyChoice") {
			if (value == "UniformProb") {
			  layout.galaxyChoice(FMMMOptions::GalaxyChoice::UniformProb);
			}
else 			if (value == "NonUniformProbLowerMass") {
			  layout.galaxyChoice(FMMMOptions::GalaxyChoice::NonUniformProbLowerMass);
			}
else 			if (value == "NonUniformProbHigherMass") {
			  layout.galaxyChoice(FMMMOptions::GalaxyChoice::NonUniformProbHigherMass);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "initialPlacementForces") {
			if (value == "UniformGrid") {
			  layout.initialPlacementForces(FMMMOptions::InitialPlacementForces::UniformGrid);
			}
else 			if (value == "RandomTime") {
			  layout.initialPlacementForces(FMMMOptions::InitialPlacementForces::RandomTime);
			}
else 			if (value == "RandomRandIterNr") {
			  layout.initialPlacementForces(FMMMOptions::InitialPlacementForces::RandomRandIterNr);
			}
else 			if (value == "KeepPositions") {
			  layout.initialPlacementForces(FMMMOptions::InitialPlacementForces::KeepPositions);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "initialPlacementMult") {
			if (value == "Simple") {
			  layout.initialPlacementMult(FMMMOptions::InitialPlacementMult::Simple);
			}
else 			if (value == "Advanced") {
			  layout.initialPlacementMult(FMMMOptions::InitialPlacementMult::Advanced);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "maxIterChange") {
			if (value == "Constant") {
			  layout.maxIterChange(FMMMOptions::MaxIterChange::Constant);
			}
else 			if (value == "LinearlyDecreasing") {
			  layout.maxIterChange(FMMMOptions::MaxIterChange::LinearlyDecreasing);
			}
else 			if (value == "RapidlyDecreasing") {
			  layout.maxIterChange(FMMMOptions::MaxIterChange::RapidlyDecreasing);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "nmSmallCell") {
			if (value == "Iteratively") {
			  layout.nmSmallCell(FMMMOptions::SmallestCellFinding::Iteratively);
			}
else 			if (value == "Aluru") {
			  layout.nmSmallCell(FMMMOptions::SmallestCellFinding::Aluru);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "nmTreeConstruction") {
			if (value == "PathByPath") {
			  layout.nmTreeConstruction(FMMMOptions::ReducedTreeConstruction::PathByPath);
			}
else 			if (value == "SubtreeBySubtree") {
			  layout.nmTreeConstruction(FMMMOptions::ReducedTreeConstruction::SubtreeBySubtree);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "pageFormat") {
			if (value == "Portrait") {
			  layout.pageFormat(FMMMOptions::PageFormatType::Portrait);
			}
else 			if (value == "Landscape") {
			  layout.pageFormat(FMMMOptions::PageFormatType::Landscape);
			}
else 			if (value == "Square") {
			  layout.pageFormat(FMMMOptions::PageFormatType::Square);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "presortCCs") {
			if (value == "None") {
			  layout.presortCCs(FMMMOptions::PreSort::None);
			}
else 			if (value == "DecreasingHeight") {
			  layout.presortCCs(FMMMOptions::PreSort::DecreasingHeight);
			}
else 			if (value == "DecreasingWidth") {
			  layout.presortCCs(FMMMOptions::PreSort::DecreasingWidth);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "qualityVersusSpeed") {
			if (value == "GorgeousAndEfficient") {
			  layout.qualityVersusSpeed(FMMMOptions::QualityVsSpeed::GorgeousAndEfficient);
			}
else 			if (value == "BeautifulAndFast") {
			  layout.qualityVersusSpeed(FMMMOptions::QualityVsSpeed::BeautifulAndFast);
			}
else 			if (value == "NiceAndIncredibleSpeed") {
			  layout.qualityVersusSpeed(FMMMOptions::QualityVsSpeed::NiceAndIncredibleSpeed);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "repulsiveForcesCalculation") {
			if (value == "Exact") {
			  layout.repulsiveForcesCalculation(FMMMOptions::RepulsiveForcesMethod::Exact);
			}
else 			if (value == "GridApproximation") {
			  layout.repulsiveForcesCalculation(FMMMOptions::RepulsiveForcesMethod::GridApproximation);
			}
else 			if (value == "NMM") {
			  layout.repulsiveForcesCalculation(FMMMOptions::RepulsiveForcesMethod::NMM);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "stopCriterion") {
			if (value == "FixedIterations") {
			  layout.stopCriterion(FMMMOptions::StopCriterion::FixedIterations);
			}
else 			if (value == "Threshold") {
			  layout.stopCriterion(FMMMOptions::StopCriterion::Threshold);
			}
else 			if (value == "FixedIterationsOrThreshold") {
			  layout.stopCriterion(FMMMOptions::StopCriterion::FixedIterationsOrThreshold);
			}
 else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
else if (key == "tipOverCCs") {
			if (value == "None") {
			  layout.tipOverCCs(FMMMOptions::TipOver::None);
			}
else 			if (value == "NoGrowingRow") {
			  layout.tipOverCCs(FMMMOptions::TipOver::NoGrowingRow);
			}
else 			if (value == "Always") {
			  layout.tipOverCCs(FMMMOptions::TipOver::Always);
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


#include <ogdf/energybased/NodeRespecterLayout.h>
void applyNodeRespecterLayout(GraphAttributes& GA, const std::map<std::string, std::string>& localParams) {
NodeRespecterLayout layout;

static const char* helpText = "The NodeRespecterLayout layout algorithm.\n@ingroup gd-energy\nThis is a force-directed layout algorithm respecting the shapes and sizes of\nnodes. It aims to minimize the number of node overlaps as well as the number\nof edges crossing through non-incident nodes. In order to achieve this, the\nalgorithm adapts its forces to the node sizes and bends edges around close-by\nnodes. The edge bends are created by introducing dummy nodes into the graph,\npositioning all nodes according to forces acting upon them, filtering out\nunnecessary dummy nodes, and then replacing the remaining dummy nodes by edge\nbends.\nThe algorithm is documented in and was developed for the bachelor thesis:\nMax Ilsen: <i>Energy-Based %Layout Algorithms for Graphs with Large Nodes</i>.\nUniversity of Osnabrueck, 2017\nThe following parameters can be set:\n<table>\n<tr>\n<th><i>Parameter</i><th><i>Default Value</i>\n</tr>\n<tr><td> #m_randomInitialPlacement </td><td> true </td></tr>\n<tr><td> #m_postProcessing </td><td> PostProcessingMode::Complete </td></tr>\n<tr><td> #m_bendNormalizationAngle </td><td> Math::pi </td></tr>\n<tr><td> #m_numberOfIterations </td><td> 30000 </td></tr>\n<tr><td> #m_minimalTemperature </td><td> 1.0 </td></tr>\n<tr><td> #m_initialTemperature </td><td> 10.0 </td></tr>\n<tr><td> #m_temperatureDecreaseOffset </td><td> 0.0 </td></tr>\n<tr><td> #m_gravitation </td><td> 1.0/16.0 </td></tr>\n<tr><td> #m_oscillationAngle </td><td> Math::pi_2 </td></tr>\n<tr><td> #m_desiredMinEdgeLength </td><td> LayoutStandards::defaultNodeSeparation() </td></tr>\n<tr><td> #m_initDummiesPerEdge </td><td> 1 </td></tr>\n<tr><td> #m_maxDummiesPerEdge </td><td> 3 </td></tr>\n<tr><td> #m_dummyInsertionThreshold </td><td> 5 </td></tr>\n<tr><td> #m_maxDisturbance </td><td> 0 </td></tr>\n<tr><td> #m_repulsionDistance </td><td> 2*#m_desiredMinEdgeLength </td></tr>\n<tr><td> #m_minDistCC </td><td> LayoutStandards::defaultCCSeparation() </td></tr>\n<tr><td> #m_pageRatio </td><td> 1.0 </td></tr>\n</tr>\n</table>\nsetBendNormalizationAngle (double)\nSets #m_bendNormalizationAngle to \\p bendNormalizationAngle in [0...Pi].\n\nsetDesiredMinEdgeLength (double)\nSets #m_desiredMinEdgeLength to \\p desiredMinEdgeLength > 0.\n\nsetDummyInsertionThreshold (double)\nSets #m_dummyInsertionThreshold to \\p dummyInsertionThreshold >= 1.\n\nsetGravitation (double)\nSets #m_gravitation to \\p gravitation >= 0.\n\nsetInitDummiesPerEdge (int)\nSets #m_initDummiesPerEdge to \\p initDummiesPerEdge >= 0.\n\nsetInitialTemperature (double)\nSets #m_initialTemperature to \\p initialTemperature >\n#m_minimalTemperature.\n\nsetMaxDisturbance (double)\nSets #m_maxDisturbance to \\p maxDisturbance >= 0.\n\nsetMaxDummiesPerEdge (int)\nSets #m_maxDummiesPerEdge to \\p maxDummiesPerEdge >\n#m_initDummiesPerEdge.\n\nsetMinDistCC (double)\nSets #m_minDistCC to \\p minDistCC >= 0.\n\nsetMinimalTemperature (double)\nSets #m_minimalTemperature to \\p minimalTemperature >= 0.\n\nsetNumberOfIterations (int)\nSets #m_numberOfIterations to \\p numberOfIterations >= 0.\n\nsetOscillationAngle (double)\nSets #m_oscillationAngle to \\p oscillationAngle in [0...Pi].\n\nsetPageRatio (double)\nSets #m_pageRatio to \\p pageRatio > 0.\n\nsetPostProcessing (PostProcessingMode)\nSets #m_postProcessing to \\p postProcessing.\nPossible values: \nNone, //!< Keep all bends.\nKeepMultiEdgeBends, //!< Activate post-processing but keep all bends on\n//!< multi-edges and self-loops (such that the\n//!< corresponding edges are visible).\nComplete //!< Activate post-processing: Remove all bends that\n//!< do not prevent edge-node intersections.\n\nsetRandomInitialPlacement (bool)\nSets #m_randomInitialPlacement to \\p randomInitialPlacement.\n\nsetRepulsionDistance (double)\nSets #m_repulsionDistance to \\p repulsionDistance >= 0.\n\nsetTemperatureDecreaseOffset (double)\nSets #m_temperatureDecreaseOffset to \\p temperatureDecreaseOffset in\n[0...1].";
if (localParams.find("help") != localParams.end()) {
std::cout << helpText << std::endl;
exit(0);
}
try {
for (const auto& [key, value] : localParams) {
		if (key == "setBendNormalizationAngle" || key == "bendNormalizationAngle") {
			layout.setBendNormalizationAngle(std::stod(value));
		}
else 		if (key == "setDesiredMinEdgeLength" || key == "desiredMinEdgeLength") {
			layout.setDesiredMinEdgeLength(std::stod(value));
		}
else 		if (key == "setDummyInsertionThreshold" || key == "dummyInsertionThreshold") {
			layout.setDummyInsertionThreshold(std::stod(value));
		}
else 		if (key == "setGravitation" || key == "gravitation") {
			layout.setGravitation(std::stod(value));
		}
else 		if (key == "setInitDummiesPerEdge" || key == "initDummiesPerEdge") {
			layout.setInitDummiesPerEdge(std::stoi(value));
		}
else 		if (key == "setInitialTemperature" || key == "initialTemperature") {
			layout.setInitialTemperature(std::stod(value));
		}
else 		if (key == "setMaxDisturbance" || key == "maxDisturbance") {
			layout.setMaxDisturbance(std::stod(value));
		}
else 		if (key == "setMaxDummiesPerEdge" || key == "maxDummiesPerEdge") {
			layout.setMaxDummiesPerEdge(std::stoi(value));
		}
else 		if (key == "setMinDistCC" || key == "minDistCC") {
			layout.setMinDistCC(std::stod(value));
		}
else 		if (key == "setMinimalTemperature" || key == "minimalTemperature") {
			layout.setMinimalTemperature(std::stod(value));
		}
else 		if (key == "setNumberOfIterations" || key == "numberOfIterations") {
			layout.setNumberOfIterations(std::stoi(value));
		}
else 		if (key == "setOscillationAngle" || key == "oscillationAngle") {
			layout.setOscillationAngle(std::stod(value));
		}
else 		if (key == "setPageRatio" || key == "pageRatio") {
			layout.setPageRatio(std::stod(value));
		}
else 		if (key == "setRandomInitialPlacement" || key == "randomInitialPlacement") {
			layout.setRandomInitialPlacement(strToBool(value));
		}
else 		if (key == "setRepulsionDistance" || key == "repulsionDistance") {
			layout.setRepulsionDistance(std::stod(value));
		}
else 		if (key == "setTemperatureDecreaseOffset" || key == "temperatureDecreaseOffset") {
			layout.setTemperatureDecreaseOffset(std::stod(value));
		}
else if (key == "setPostProcessing") {
			if (value == "None") {
			  layout.setPostProcessing(NodeRespecterLayout::PostProcessingMode::None);
			}
else 			if (value == "KeepMultiEdgeBends") {
			  layout.setPostProcessing(NodeRespecterLayout::PostProcessingMode::KeepMultiEdgeBends);
			}
else 			if (value == "Complete") {
			  layout.setPostProcessing(NodeRespecterLayout::PostProcessingMode::Complete);
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

#include <ogdf/energybased/DavidsonHarel.h>
void applyDavidsonHarel(GraphAttributes& GA, const std::map<std::string, std::string>& localParams) {
DavidsonHarel layout;

static const char* helpText = "setNumberOfIterations (int)\nSets the number of iterations for each temperature step to \\p steps.\n\nsetStartTemperature (int)\nSets the start temperature to \\p startTemp.";
if (localParams.find("help") != localParams.end()) {
std::cout << helpText << std::endl;
exit(0);
}
try {
for (const auto& [key, value] : localParams) {
		if (key == "setNumberOfIterations" || key == "numberOfIterations") {
			layout.setNumberOfIterations(std::stoi(value));
		}
else 		if (key == "setStartTemperature" || key == "startTemperature") {
			layout.setStartTemperature(std::stoi(value));
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

#include <ogdf/energybased/SpringEmbedderKK.h>
void applySpringEmbedderKK(GraphAttributes& GA, const std::map<std::string, std::string>& localParams) {
SpringEmbedderKK layout;

static const char* helpText = "The spring-embedder layout algorithm by Kamada and Kawai.\n@ingroup gd-energy\nThe implementation used in SpringEmbedderKK is based on\nthe following publication:\nTomihisa Kamada, Satoru Kawai: <i>%An Algorithm for Drawing\nGeneral Undirected Graphs</i>. Information Processing Letters 31, pp. 7-15, 1989.\nPrecondition: The input graph has to be connected.\n<H3>Optional parameters</H3>\nThere are some parameters that can be tuned to optimize the\nalgorithm's behavior regarding runtime and layout quality.\nFirst of all note that the algorithm uses all pairs shortest path\nto compute the graph theoretic distance. This can be done either\nwith BFS (ignoring node sizes) in quadratic time or by using\ne.g. Floyd's algorithm in cubic time with given edge lengths\nthat may reflect the node sizes.  Also m_computeMaxIt decides\nif the computation is stopped after a fixed maximum number of\niterations. The desirable edge length can either be set or computed\nfrom the graph and the given layout.\nKamada-Kawai layout provides the following optional parameters.\n<table>\n<tr>\n<th><i>Option</i><th><i>Type</i><th><i>Default</i><th><i>Description</i>\n</tr><tr>\n<td><i>tolerance</i><td>int<td>0.0001\n<td>Tolerance for the energy level (below which the main loop stops).\n</tr>\n</table>\ncomputeMaxIterations (bool)\nIf set to true, number of iterations is computed depending on G\n\nsetDesLength (double)\nSets desirable edge length directly\n\nsetGlobalIterationFactor (int)\n\n\nsetMaxGlobalIterations (int)\nSets the number of global iterations to \\p i.\n\nsetMaxLocalIterations (int)\nSets the number of local iterations to \\p i.\n\nsetStopTolerance (double)\nSets the value for the stop tolerance, below which the\nsystem is regarded stable (balanced) and the optimization stopped\n\nsetUseLayout (bool)\nIf set to true, the given layout is used for the initial positions\n\nsetZeroLength (double)\nIf set != 0, value zerolength is used to determine the\ndesirable edge length by L = zerolength / max distance_ij.\nOtherwise, zerolength is determined using the node number and sizes.";
if (localParams.find("help") != localParams.end()) {
std::cout << helpText << std::endl;
exit(0);
}
try {
for (const auto& [key, value] : localParams) {
		if (key == "computeMaxIterations") {
			layout.computeMaxIterations(strToBool(value));
		}
else 		if (key == "setDesLength" || key == "desLength") {
			layout.setDesLength(std::stod(value));
		}
else 		if (key == "setGlobalIterationFactor" || key == "globalIterationFactor") {
			layout.setGlobalIterationFactor(std::stoi(value));
		}
else 		if (key == "setMaxGlobalIterations" || key == "maxGlobalIterations") {
			layout.setMaxGlobalIterations(std::stoi(value));
		}
else 		if (key == "setMaxLocalIterations" || key == "maxLocalIterations") {
			layout.setMaxLocalIterations(std::stoi(value));
		}
else 		if (key == "setStopTolerance" || key == "stopTolerance") {
			layout.setStopTolerance(std::stod(value));
		}
else 		if (key == "setUseLayout" || key == "useLayout") {
			layout.setUseLayout(strToBool(value));
		}
else 		if (key == "setZeroLength" || key == "zeroLength") {
			layout.setZeroLength(std::stod(value));
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
