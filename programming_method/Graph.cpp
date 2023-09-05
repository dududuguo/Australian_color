#include "Au_map.hpp"
#include <vector>

bool isSafe(Node *node, color c)
{
    for (const edge *e : node->getOutEdges())
    {
        if (e->get_next()->get_color() == c)
        {
            return false;
        }
    }
    return true;
}

bool colorAustralia(Graph &graph, std::vector<Node *> &nodes, int index)
{
    if (index == nodes.size())
    {
        return true;
    }

    Node *currentNode = nodes[index];
    for (int c = red; c <= black; c++)
    {
        if (isSafe(currentNode, static_cast<color>(c)))
        {
            currentNode->set_color(static_cast<color>(c));
            if (colorAustralia(graph, nodes, index + 1))
            {
                return true;
            }
            currentNode->set_color(static_cast<color>(black + 1)); // reset color
        }
    }
    return false;
}

void solveAustraliaColoringProblem(Graph &graph)
{
    std::vector<Node *> nodes;
    for (const Node *n : graph.getNodes())
    {
        nodes.push_back(const_cast<Node *>(n));
    }

    if (colorAustralia(graph, nodes, 0))
    {
        for (Node *node : nodes)
        {
            std::cout << node->get_name() << " : " << node->get_color() << std::endl;
        }
    }
    else
    {
        std::cout << "No solution found" << std::endl;
    }
}

int main()
{
    // 创建图实例
    Graph australiaGraph;

    // 创建澳大利亚各个地区的节点
    Node *westernAustralia = new Node("Western Australia");
    Node *northernTerritory = new Node("Northern Territory");
    Node *southAustralia = new Node("South Australia");
    Node *queensland = new Node("Queensland");
    Node *newSouthWales = new Node("New South Wales");
    Node *victoria = new Node("Victoria");
    Node *tasmania = new Node("Tasmania");

    // 将节点添加到图中
    australiaGraph.addNode(westernAustralia);
    australiaGraph.addNode(northernTerritory);
    australiaGraph.addNode(southAustralia);
    australiaGraph.addNode(queensland);
    australiaGraph.addNode(newSouthWales);
    australiaGraph.addNode(victoria);
    australiaGraph.addNode(tasmania);

    // 创建边并定义它们的关系
    westernAustralia->addOutEdge(new edge(westernAustralia, northernTerritory));
    westernAustralia->addOutEdge(new edge(westernAustralia, southAustralia));

    northernTerritory->addOutEdge(new edge(northernTerritory, westernAustralia));
    northernTerritory->addOutEdge(new edge(northernTerritory, southAustralia));
    northernTerritory->addOutEdge(new edge(northernTerritory, queensland));

    southAustralia->addOutEdge(new edge(southAustralia, westernAustralia));
    southAustralia->addOutEdge(new edge(southAustralia, northernTerritory));
    southAustralia->addOutEdge(new edge(southAustralia, queensland));
    southAustralia->addOutEdge(new edge(southAustralia, newSouthWales));
    southAustralia->addOutEdge(new edge(southAustralia, victoria));

    queensland->addOutEdge(new edge(queensland, northernTerritory));
    queensland->addOutEdge(new edge(queensland, southAustralia));
    queensland->addOutEdge(new edge(queensland, newSouthWales));

    newSouthWales->addOutEdge(new edge(newSouthWales, queensland));
    newSouthWales->addOutEdge(new edge(newSouthWales, southAustralia));
    newSouthWales->addOutEdge(new edge(newSouthWales, victoria));

    victoria->addOutEdge(new edge(victoria, southAustralia));
    victoria->addOutEdge(new edge(victoria, newSouthWales));


    // 调用解决方案函数
    solveAustraliaColoringProblem(australiaGraph);

    // 删除为节点和边分配的内存
    delete westernAustralia;
    delete northernTerritory;
    delete southAustralia;
    delete queensland;
    delete newSouthWales;
    delete victoria;
    delete tasmania;

    return 0;
}
