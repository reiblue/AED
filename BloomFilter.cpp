#include <bits/stdc++.h> 
#define ll long long 
using namespace std; 

// hash 1 
int h1(string s, int arrSize) 
{ 
	ll int hash = 0; 
	for (int i = 0; i < s.size(); i++) 
	{ 
		hash = (hash + ((int)s[i])); 
		hash = hash % arrSize; 
	} 
	return hash; 
} 

// hash 2 
int h2(string s, int arrSize) 
{ 
	ll int hash = 1; 
	for (int i = 0; i < s.size(); i++) 
	{ 
		hash = hash + pow(19, i) * s[i]; 
		hash = hash % arrSize; 
	} 
	return hash % arrSize; 
} 

// hash 3 
int h3(string s, int arrSize) 
{ 
	ll int hash = 7; 
	for (int i = 0; i < s.size(); i++) 
	{ 
		hash = (hash * 31 + s[i]) % arrSize; 
	} 
	return hash % arrSize; 
} 

// hash 4 
int h4(string s, int arrSize) 
{ 
	ll int hash = 3; 
	int p = 7; 
	for (int i = 0; i < s.size(); i++) { 
		hash += hash * 7 + s[0] * pow(p, i); 
		hash = hash % arrSize; 
	} 
	return hash; 
} 


// lookup operation 
bool lookup(bool* bitarray, int arrSize, string s) 
{ 
	int a = h1(s, arrSize); 
	int b = h2(s, arrSize); 
	int c = h3(s, arrSize); 
	int d = h4(s, arrSize); 

	if (bitarray[a] && bitarray[b] && bitarray[c] 
		&& bitarray[d]) 
		return true; 
	else
		return false; 
} 

// insert operation 
void insert(bool* bitarray, int arrSize, string s) 
{ 
	// verifica se o elemento 's' já está contido 
	if (lookup(bitarray, arrSize, s)) 
		cout << s << " provavelmente esta presente " << endl; 
	else
	{ 
		int a = h1(s, arrSize); 
		int b = h2(s, arrSize); 
		int c = h3(s, arrSize); 
		int d = h4(s, arrSize); 

		bitarray[a] = true; 
		bitarray[b] = true; 
		bitarray[c] = true; 
		bitarray[d] = true; 

		cout << s << " inserido" << endl; 
	} 
} 

// Driver Code 
int main() 
{ 
	bool bitarray[100] = { false }; 
	int arrSize = 100; 
	string sarray[33] 
		= { "facebook",    "instagram",   "twitter",
            "linkedin",    "snapchat",    "tiktok",
            "pinterest",   "reddit",      "whatsapp",
            "telegram",    "wechat",      "tumblr",
            "quora",       "viber",       "youtube",
            "vimeo",       "flickr",      "dribbble",
            "behance",     "clubhouse",   "discord",
            "slack",       "medium",      "twitch",
            "soundcloud",  "mix",         "mastodon",
            "nextdoor",    "meetup",      "xing",
            "goodreads",   "deviantart",  "kakaotalk"  }; 
	for (int i = 0; i < 33; i++) { 
		insert(bitarray, arrSize, sarray[i]); 
	} 

    string palavraBusca;
    
    do{
		cout << "Bloom filter digite -1 para sair ou " << endl;
        cout << "Digite uma palavra de busca: ";
        cin >> palavraBusca;

        if(lookup(bitarray, arrSize, palavraBusca))
            cout << "Encontrado" << endl << endl;
        else
            cout << "Não encontrado" << endl << endl;        

    }while(palavraBusca != "-1");

    

	return 0; 
}
