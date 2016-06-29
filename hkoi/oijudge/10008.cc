// Disjoint-set Data Structure
// Author: Emil Stefanov
// Date Written: 03/28/06
// Implementaton is as described in http://en.wikipedia.org/wiki/Disjoint-set_data_structure

// Copyright (C) 2006 Emil Stefanov
// You may use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of this software subject to the following conditions:
// THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


#ifndef DISJOUNT_SET_H__
#define DISJOUNT_SET_H__

#include <vector>
#include <cassert>

typedef int ElementId; // element identifier type
typedef int SetId; // set identifier type

class DisjointSet
{
public:

    // Create an empty DisjointSet data structure
    DisjointSet()
    {
        m_numElements = 0;
        m_numSets = 0;
    }

    // Create a DisjointSet data structure with a specified number of elements (with element id's from 0 to count-1)
    DisjointSet(int count)
    {
        m_numElements = 0;
        m_numSets = 0;
        AddElements(count);
    }

    // Copy constructor
    DisjointSet(const DisjointSet & s)
    {
        this->m_numElements = s.m_numElements;
        this->m_numSets = s.m_numSets;

        // Copy nodes
        m_nodes.resize(m_numElements);
        for(int i = 0; i < m_numElements; ++i)
            m_nodes[i] = new Node(*s.m_nodes[i]);

        // Update parent pointers to point to newly created nodes rather than the old ones
        for(int i = 0; i < m_numElements; ++i)
            if(m_nodes[i]->parent != NULL)
                m_nodes[i]->parent = m_nodes[s.m_nodes[i]->parent->index];
    }

    // Destructor
    ~DisjointSet()
    {
        for(int i = 0; i < m_numElements; ++i)
            delete m_nodes[i];
        m_nodes.clear();
        m_numElements = 0;
        m_numSets = 0;
    }


    // Find the set identifier that an element currently belongs to.
    // Note: Some data pointed to by this object is modified for optimization even though this method is consant.
    SetId FindSet(ElementId elementId) const
    {
        assert(elementId < m_numElements);

        Node* curNode;

        // Find the root element that represents the set which `elementId` belongs to
        curNode = m_nodes[elementId];
        while(curNode->parent != NULL)
            curNode = curNode->parent;
        Node* root = curNode;

        // Walk to the root, updating the parents of `elementId`. Make those elements the direct
        // children of `root`. This optimizes the tree for future FindSet invokations.
        curNode = m_nodes[elementId];
        while(curNode != root)
        {
            Node* next = curNode->parent;
            curNode->parent = root;
            curNode = next;
        }

        return root->index;
    }

    // Combine two sets into one. All elements in those two sets will share the same set id that can be gotten using FindSet.
    void Union(SetId setId1, SetId setId2)
    {
        assert(setId1 < m_numElements);
        assert(setId2 < m_numElements);

        Node* set1 = m_nodes[setId1];
        Node* set2 = m_nodes[setId2];

        // Determine which node representing a set has a higher rank. The node with the higher rank is
        // likely to have a bigger subtree so in order to better balance the tree representing the
        // union, the node with the higher rank is made the parent of the one with the lower rank and
        // not the other way around.
        if(set1->rank > set2->rank)
            set2->parent = set1;
        else if(set1->rank < set2->rank)
            set1->parent = set2;
        else if(set1->rank == set2->rank)
        {
            set2->parent = set1;
            ++set1->rank; // update rank
        }

        // Since two sets have fused into one, there is now one less set so update the set count.
        --m_numSets;
    }

    // Add a specified number of elements to the DisjointSet data structure. The element id's of the new elements are numbered
    // consequitively starting with the first never-before-used elementId.
    void AddElements(int numToAdd)
    {
        assert(numToAdd >= 0);

        // insert and initialize the specified number of element nodes to the end of the `m_nodes` array
        m_nodes.insert(m_nodes.end(), numToAdd, (Node*)NULL);
        for(int i = m_numElements; i < m_numElements + numToAdd; ++i)
        {
            m_nodes[i] = new Node();
            m_nodes[i]->parent = NULL;
            m_nodes[i]->index = i;
            m_nodes[i]->rank = 0;
        }

        // update element and set counts
        m_numElements += numToAdd;
        m_numSets += numToAdd;
    }

    // Returns the number of elements currently in the DisjointSet data structure.
    int NumElements() const
    {
        return m_numElements;
    }

    // Returns the number of sets currently in the DisjointSet data structure.
    int NumSets() const
    {
        return m_numSets;
    }

private:

    // Internal Node data structure used for representing an element
    struct Node
    {
        int rank; // This roughly represent the max height of the node in its subtree
        ElementId index; // The index of the element the node represents
        Node* parent; // The parent node of the node
    };

    int m_numElements; // the number of elements currently in the DisjointSet data structure.
    int m_numSets; // the number of sets currently in the DisjointSet data structure.
    std::vector<Node*> m_nodes; // the list of nodes representing the elements
};

#endif


int main() {
	DisjointSet same[50000], diff[50000];
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i < n;i ++ ) {
		int a, b;
		scanf("%d %d", &a, &b);
		d[i`
	}
}

