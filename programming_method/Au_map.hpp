#include <iostream>
#include <set>

enum color
{
    red,
    green,
    blue,
    black
};
class edge;
class Node;
class Graph;

class Node
{
private:
    color Node_color;
    std::string name;
    std::set<const edge *> outEdges; // outgoing edges of this node
public:
    Node(std::string n)
    {
        name = n;
    }
    color get_color() { return Node_color; }
    std::string get_name(){ return name;}
    void set_color(color c) { Node_color = c; }
    std::set<const edge *> getOutEdges() const
    {
        return outEdges;
    }

    // Add an edge into outEdges
    void addOutEdge(const edge *e, ...)
    {
        outEdges.insert(e);
    }
};

class edge
{
private:
    Node *per;
    Node *next;

public:
    edge(Node *p, Node *src) : per(p), next(src) {}
    ~edge() = default;
    Node *get_per() const { return per; }
    Node *get_next() const { return next; }
};

class Graph
{
private:
    std::set<const Node *> nodes; // a set of nodes on the graph
public:
    Graph(){};
    // Get all the nodes of the graph
    std::set<const Node *> &getNodes()
    {
        return nodes;
    }
    // Add a node into the graph
    void addNode(const Node *node)
    {
        nodes.insert(node);
    }
};
