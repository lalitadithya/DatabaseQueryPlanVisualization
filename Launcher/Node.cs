using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Launcher
{
    class Node
    {
        public int Id { get; set; }
        public string Name { get; set; }

        private List<Node> Children;

        public Node()
        {
            Children = new List<Node>();
        }

        public void AddChild(Node node)
        {
            Children.Add(node);
        }

        public List<Node> GetChildren()
        {
            return Children;
        }
    }
}
