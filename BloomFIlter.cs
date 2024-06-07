using System;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Text;

public class BloomFilter
{
    private readonly bool[] bits;
    private readonly int size;
    private readonly int hashCount;

    public BloomFilter(int size, int hashCount)
    {
        this.size = size;
        this.hashCount = hashCount;
        bits = new bool[size];
    }

    private IEnumerable<int> GetHashes(string item)
    {
        byte[] bytes = Encoding.UTF8.GetBytes(item);
        using (var md5 = MD5.Create())
        {
            byte[] hash1 = md5.ComputeHash(bytes);
            int hash1Int = BitConverter.ToInt32(hash1, 0);
            yield return Math.Abs(hash1Int % size);

            using (var sha256 = SHA256.Create())
            {
                byte[] hash2 = sha256.ComputeHash(bytes);
                int hash2Int = BitConverter.ToInt32(hash2, 0);
                yield return Math.Abs(hash2Int % size);
            }
        }
    }

    public void Insert(string item)
    {
        foreach (var hash in GetHashes(item))
        {
            bits[hash] = true;
        }
    }

    public bool Search(string item)
    {
        foreach (var hash in GetHashes(item))
        {
            if (!bits[hash])
            {
                return false;
            }
        }
        return true;
    }

    public void Visualize()
    {
        for (int i = 0; i < size; i++)
        {
            Console.Write(bits[i] ? '1' : '0');
            if ((i + 1) % 10 == 0)
            {
                Console.WriteLine();
            }
        }
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        var bloomFilter = new BloomFilter(25, 2);

        string[] fruits = {
                    "caqui", "banana", "abacate",
                    "abacaxi", "figo", "goiaba", "laranja",
                    "marmelo", "pera", "melancia" };

        foreach (var item in items){
            bloomFilter.Insert(item);
        }

        bloomFilter.Visualize();

        Console.WriteLine(bloomFilter.Search("goiaba")); 
        Console.WriteLine(bloomFilter.Search("limão")); 
		
		
		//Deleting 'banana'
		var bloomFilter = new BloomFilter(25, 2);

        string[] fruitDelecao = {
                    "caqui", "abacate",
                    "abacaxi", "figo", "goiaba", "laranja",
                    "marmelo", "pera", "melancia" };

        foreach (var item in items){
            bloomFilter.Insert(item);
        }
		
		
    }
}
