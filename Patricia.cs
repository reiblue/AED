using System;
using System.Collections.Generic;

public class PatriciaNode
{
    public Dictionary<string, PatriciaNode> Children { get; set; }
    public bool IsEndOfWord { get; set; }

    public PatriciaNode()
    {
        Children = new Dictionary<string, PatriciaNode>();
        IsEndOfWord = false;
    }
}

public class PatriciaTrie
{
    private PatriciaNode root;

    public PatriciaTrie()
    {
        root = new PatriciaNode();
    }

    // Insere uma palavra na árvore Patrícia
    public void Insert(string word)
    {
        Insert(root, word);
    }

    private void Insert(PatriciaNode node, string word)
    {
        foreach (var key in node.Children.Keys)
        {
            int commonPrefixLength = CommonPrefixLength(key, word);

            if (commonPrefixLength > 0)
            {
                if (commonPrefixLength < key.Length)
                {
                    // Divida a aresta existente
                    string commonPrefix = key.Substring(0, commonPrefixLength);
                    string keyRemainder = key.Substring(commonPrefixLength);
                    string wordRemainder = word.Substring(commonPrefixLength);

                    PatriciaNode newChild = new PatriciaNode();
                    newChild.Children[keyRemainder] = node.Children[key];
                    node.Children.Remove(key);
                    node.Children[commonPrefix] = newChild;

                    if (string.IsNullOrEmpty(wordRemainder))
                    {
                        newChild.IsEndOfWord = true;
                    }
                    else
                    {
                        Insert(newChild, wordRemainder);
                    }

                    return;
                }

                Insert(node.Children[key], word.Substring(commonPrefixLength));
                return;
            }
        }

        // Adiciona uma nova aresta
        node.Children[word] = new PatriciaNode { IsEndOfWord = true };
    }

    // Busca uma palavra na árvore Patrícia
    public bool Search(string word)
    {
        return Search(root, word);
    }

    private bool Search(PatriciaNode node, string word)
    {
        foreach (var key in node.Children.Keys)
        {
            if (word.StartsWith(key))
            {
                if (word.Length == key.Length)
                {
                    return node.Children[key].IsEndOfWord;
                }

                return Search(node.Children[key], word.Substring(key.Length));
            }
        }

        return false;
    }

    // Verifica se existe alguma palavra na árvore que começa com o prefixo dado
    public bool StartsWith(string prefix)
    {
        return StartsWith(root, prefix);
    }

    private bool StartsWith(PatriciaNode node, string prefix)
    {
        foreach (var key in node.Children.Keys)
        {
            if (prefix.StartsWith(key))
            {
                if (prefix.Length == key.Length)
                {
                    return true;
                }

                return StartsWith(node.Children[key], prefix.Substring(key.Length));
            }

            if (key.StartsWith(prefix))
            {
                return true;
            }
        }

        return false;
    }
    // Deleta uma palavra da árvore Patrícia
    public bool Delete(string word)
    {
        return Delete(root, word);
    }

    private bool Delete(PatriciaNode node, string word)
    {
        foreach (var key in node.Children.Keys)
        {
            if (word.StartsWith(key))
            {
                if (word.Length == key.Length)
                {
                    if (node.Children[key].IsEndOfWord)
                    {
                        if (node.Children[key].Children.Count == 0)
                        {
                            node.Children.Remove(key);
                        }
                        else
                        {
                            node.Children[key].IsEndOfWord = false;
                        }
                        return true;
                    }
                    return false;
                }

                bool deleted = Delete(node.Children[key], word.Substring(key.Length));
                if (deleted && node.Children[key].Children.Count == 0 && !node.Children[key].IsEndOfWord)
                {
                    node.Children.Remove(key);
                }
                return deleted;
            }
        }

        return false;
    }
    // Método para visualizar a árvore no console
    public void Print()
    {
        PrintNode(root, "", "");
    }

    private void PrintNode(PatriciaNode node, string prefix, string childrenPrefix)
    {
        if (node == null)
        {
            return;
        }

        foreach (var child in node.Children)
        {
            Console.WriteLine(childrenPrefix + "└── " + child.Key + (child.Value.IsEndOfWord ? " (Fim)" : ""));
            PrintNode(child.Value, prefix + "    ", childrenPrefix + "    ");
        }
    }

    private int CommonPrefixLength(string str1, string str2)
    {
        int minLength = Math.Min(str1.Length, str2.Length);
        for (int i = 0; i < minLength; i++)
        {
            if (str1[i] != str2[i])
            {
                return i;
            }
        }
        return minLength;
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        PatriciaTrie trie = new PatriciaTrie();

        string[] fruits = {
                    "caqui", "banana", "abacate",
                    "abacaxi", "figo", "goiaba", "laranja",
                    "marmelo","pera", "meancia"};

        foreach (var fruit in fruits)
        {
            trie.Insert(fruit);
        }
		
        Console.WriteLine(trie.Search("goiaba"));
        Console.WriteLine(trie.Search("limão")); 
        

        Console.WriteLine("\nÁrvore Patrícia:");
        trie.Print();


        Console.WriteLine("\nDeletando 'maça':");
        trie.Delete("maça");
        trie.Print();
		
		Console.WriteLine("\nDeletando 'banana':");
        trie.Delete("banana");
		trie.Print();



    }
}
