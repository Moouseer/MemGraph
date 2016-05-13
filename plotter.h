//
// Created by Michael Holubec on 02.03.16.
//

#ifndef BACHELOR_PLOTTER_H
#define BACHELOR_PLOTTER_H


#include "graph.h"

const std::string new_line = "\n";
const std::string tab = "\t";

class Plotter {
private:
	std::string getIdent();
	std::string dotGraphHeader();
	std::string dotAttribute(std::string name, Attribute *attr);
	std::string dotNodes(nodes_map *nodes);
	std::string dotEdges(edges_vect *edges);
	std::string dotSubgraphs(subgraphs_map *subgraphs);
	std::string dotSubgraph(Subgraph *subgraph);
	std::string dotEdgeType();
	std::string dotGraphAttrs(Attributes *attrs);
	std::string dotGraphNodeAttrs(Attributes *attrs);
	std::string dotGraphEdgeAttrs(Attributes *attrs);
	std::string dotAttributes(Attributes *attrs);

public:
	Graph *graph = NULL;
	int ident_step = 0;

	Plotter(Graph *graph) : graph(graph) { }
	Plotter() { graph = new Graph; }


	virtual ~Plotter() {
		if(graph != NULL) {
			delete graph;
		}
	}

	std::string getDot();
	virtual void plot() = 0;
	virtual void setOutputPath(const char *path) = 0;
	virtual void setOutputName(const char *name) = 0;

};


#endif //BACHELOR_PLOTTER_H
