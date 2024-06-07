using System;

public enum NodeColor
{
    Red,
    Black
}

public class Node
{
    public string Data;
    public NodeColor Color;
    public Node Left, Right, Parent;

    public Node(string data)
    {
        Data = data;
        Color = NodeColor.Red;
        Left = Right = Parent = null;
    }
}

public class RedBlackTree
{
    private Node root;
    private Node TNULL;

    public RedBlackTree()
    {
        TNULL = new Node(null);
        TNULL.Color = NodeColor.Black;
        root = TNULL;
    }

    private void LeftRotate(Node x)
    {
        Node y = x.Right;
        x.Right = y.Left;
        if (y.Left != TNULL)
        {
            y.Left.Parent = x;
        }
        y.Parent = x.Parent;
        if (x.Parent == null)
        {
            root = y;
        }
        else if (x == x.Parent.Left)
        {
            x.Parent.Left = y;
        }
        else
        {
            x.Parent.Right = y;
        }
        y.Left = x;
        x.Parent = y;
    }

    private void RightRotate(Node x)
    {
        Node y = x.Left;
        x.Left = y.Right;
        if (y.Right != TNULL)
        {
            y.Right.Parent = x;
        }
        y.Parent = x.Parent;
        if (x.Parent == null)
        {
            root = y;
        }
        else if (x == x.Parent.Right)
        {
            x.Parent.Right = y;
        }
        else
        {
            x.Parent.Left = y;
        }
        y.Right = x;
        x.Parent = y;
    }

    private void InsertFix(Node k)
    {
        while (k.Parent.Color == NodeColor.Red)
        {
            if (k.Parent == k.Parent.Parent.Right)
            {
                Node u = k.Parent.Parent.Left;
                if (u.Color == NodeColor.Red)
                {
                    u.Color = NodeColor.Black;
                    k.Parent.Color = NodeColor.Black;
                    k.Parent.Parent.Color = NodeColor.Red;
                    k = k.Parent.Parent;
                }
                else
                {
                    if (k == k.Parent.Left)
                    {
                        k = k.Parent;
                        RightRotate(k);
                    }
                    k.Parent.Color = NodeColor.Black;
                    k.Parent.Parent.Color = NodeColor.Red;
                    LeftRotate(k.Parent.Parent);
                }
            }
            else
            {
                Node u = k.Parent.Parent.Right;

                if (u.Color == NodeColor.Red)
                {
                    u.Color = NodeColor.Black;
                    k.Parent.Color = NodeColor.Black;
                    k.Parent.Parent.Color = NodeColor.Red;
                    k = k.Parent.Parent;
                }
                else
                {
                    if (k == k.Parent.Right)
                    {
                        k = k.Parent;
                        LeftRotate(k);
                    }
                    k.Parent.Color = NodeColor.Black;
                    k.Parent.Parent.Color = NodeColor.Red;
                    RightRotate(k.Parent.Parent);
                }
            }
            if (k == root)
            {
                break;
            }
        }
        root.Color = NodeColor.Black;
    }

    public void Insert(string key)
    {
        Node node = new Node(key);
        node.Parent = null;
        node.Data = key;
        node.Left = TNULL;
        node.Right = TNULL;
        node.Color = NodeColor.Red;

        Node y = null;
        Node x = root;

        while (x != TNULL)
        {
            y = x;
            if (node.Data.CompareTo(x.Data) < 0)
            {
                x = x.Left;
            }
            else
            {
                x = x.Right;
            }
        }

        node.Parent = y;
        if (y == null)
        {
            root = node;
        }
        else if (node.Data.CompareTo(y.Data) < 0)
        {
            y.Left = node;
        }
        else
        {
            y.Right = node;
        }

        if (node.Parent == null)
        {
            node.Color = NodeColor.Black;
            return;
        }

        if (node.Parent.Parent == null)
        {
            return;
        }

        InsertFix(node);
    }

    private void DeleteFix(Node x)
    {
        while (x != root && x.Color == NodeColor.Black)
        {
            if (x == x.Parent.Left)
            {
                Node s = x.Parent.Right;
                if (s.Color == NodeColor.Red)
                {
                    s.Color = NodeColor.Black;
                    x.Parent.Color = NodeColor.Red;
                    LeftRotate(x.Parent);
                    s = x.Parent.Right;
                }

                if (s.Left.Color == NodeColor.Black && s.Right.Color == NodeColor.Black)
                {
                    s.Color = NodeColor.Red;
                    x = x.Parent;
                }
                else
                {
                    if (s.Right.Color == NodeColor.Black)
                    {
                        s.Left.Color = NodeColor.Black;
                        s.Color = NodeColor.Red;
                        RightRotate(s);
                        s = x.Parent.Right;
                    }

                    s.Color = x.Parent.Color;
                    x.Parent.Color = NodeColor.Black;
                    s.Right.Color = NodeColor.Black;
                    LeftRotate(x.Parent);
                    x = root;
                }
            }
            else
            {
                Node s = x.Parent.Left;
                if (s.Color == NodeColor.Red)
                {
                    s.Color = NodeColor.Black;
                    x.Parent.Color = NodeColor.Red;
                    RightRotate(x.Parent);
                    s = x.Parent.Left;
                }

                if (s.Left.Color == NodeColor.Black && s.Right.Color == NodeColor.Black)
                {
                    s.Color = NodeColor.Red;
                    x = x.Parent;
                }
                else
                {
                    if (s.Left.Color == NodeColor.Black)
                    {
                        s.Right.Color = NodeColor.Black;
                        s.Color = NodeColor.Red;
                        LeftRotate(s);
                        s = x.Parent.Left;
                    }

                    s.Color = x.Parent.Color;
                    x.Parent.Color = NodeColor.Black;
                    s.Left.Color = NodeColor.Black;
                    RightRotate(x.Parent);
                    x = root;
                }
            }
        }
        x.Color = NodeColor.Black;
    }

    private void Transplant(Node u, Node v)
    {
        if (u.Parent == null)
        {
            root = v;
        }
        else if (u == u.Parent.Left)
        {
            u.Parent.Left = v;
        }
        else
        {
            u.Parent.Right = v;
        }
        v.Parent = u.Parent;
    }

    public void DeleteNode(string data)
    {
        DeleteNodeHelper(root, data);
    }

    private void DeleteNodeHelper(Node node, string key)
    {
        Node z = TNULL;
        Node x, y;
        while (node != TNULL)
        {
            if (node.Data == key)
            {
                z = node;
            }

            if (node.Data.CompareTo(key) <= 0)
            {
                node = node.Right;
            }
            else
            {
                node = node.Left;
            }
        }

        if (z == TNULL)
        {
            Console.WriteLine("Couldn't find key in the tree");
            return;
        }

        y = z;
        NodeColor yOriginalColor = y.Color;
        if (z.Left == TNULL)
        {
            x = z.Right;
            Transplant(z, z.Right);
        }
        else if (z.Right == TNULL)
        {
            x = z.Left;
            Transplant(z, z.Left);
        }
        else
        {
            y = Minimum(z.Right);
            yOriginalColor = y.Color;
            x = y.Right;
            if (y.Parent == z)
            {
                x.Parent = y;
            }
            else
            {
                Transplant(y, y.Right);
                y.Right = z.Right;
                y.Right.Parent = y;
            }

            Transplant(z, y);
            y.Left = z.Left;
            y.Left.Parent = y;
            y.Color = z.Color;
        }
        if (yOriginalColor == NodeColor.Black)
        {
            DeleteFix(x);
        }
    }

    private Node Minimum(Node node)
    {
        while (node.Left != TNULL)
        {
            node = node.Left;
        }
        return node;
    }

    public bool Search(string key)
    {
        return SearchTreeHelper(this.root, key);
    }

    private bool SearchTreeHelper(Node node, string key)
    {
        if (node == TNULL || key == node.Data)
        {
            return node != TNULL;
        }

        if (key.CompareTo(node.Data) < 0)
        {
            return SearchTreeHelper(node.Left, key);
        }
        return SearchTreeHelper(node.Right, key);
    }

    public void PrintTree()
    {
        if (root != TNULL)
        {
            PrintTreeHelper(this.root, "", true);
        }
    }

    private void PrintTreeHelper(Node node, string indent, bool last)
    {
        if (node != TNULL)
        {
            Console.Write(indent);
            if (last)
            {
                Console.Write("R----");
                indent += "   ";
            }
            else
            {
                Console.Write("L----");
                indent += "|  ";
            }

            string sColor = node.Color == NodeColor.Red ? "RED" : "BLACK";
            Console.WriteLine(node.Data + "(" + sColor + ")");
            PrintTreeHelper(node.Left, indent, false);
            PrintTreeHelper(node.Right, indent, true);
        }
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        RedBlackTree bst = new RedBlackTree();

        string[] fruits = {
                    "caqui", "banana", "abacate",
                    "abacaxi", "figo", "goiaba", "laranja",
                    "marmelo","pera", "meancia"};

        foreach (var fruit in fruits)
        {
            bst.Insert(fruit);
        }

        bst.PrintTree();

        Console.WriteLine("\nProcurando por 'goiaba': " + bst.Search("goiaba"));
        Console.WriteLine("\nProcurando por 'limão': " + bst.Search("limão"));

        Console.WriteLine("\nDeleting 'maça'");
        bst.DeleteNode("maça");
        bst.PrintTree();

        Console.WriteLine("\nDeleting 'banana'");
        bst.DeleteNode("banana");
        bst.PrintTree();
    }
}
