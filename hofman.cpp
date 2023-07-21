#include <iostream>
using namespace std;

class cnode
{
public:
	int num;
	char character;
	cnode* pnext;
	cnode* pleft;
	cnode* pright;
	int nobit = 0;
	int* bits;
};

class clist
{
public:
	cnode* phead;
	cnode* rootail;
	clist()
	{
		phead = NULL;
		rootail = NULL;
	}
	~clist()
	{
		cnode* rootrav;
		rootrav = phead;
		while (rootrav != NULL)
		{
			phead = phead->pnext;
			delete rootrav;
			rootrav = phead;
		}
	}
	void attach(cnode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			rootail = pnn;
		}
		else
		{
			rootail->pnext = pnn;
			rootail = pnn;
		}
	}
	void display()
	{
		cnode* rootrav;
		rootrav = phead;
		while (rootrav != NULL)
		{
			//how to disp
			rootrav = rootrav->pnext;
		}
	}
};
class cstack
{
public:
	cnode* phead;
	cstack()
	{
		phead = NULL;
	}
	~cstack()
	{
		cnode* rootrav;
		rootrav = phead;
		while (rootrav != NULL)
		{
			phead = phead->pnext;
			delete rootrav;
			rootrav = phead;
		}
	}
	void display()
	{
		cnode* rootrav;
		rootrav = phead;
		while (rootrav != NULL)
		{
			cout << "here is nodaia" << endl;
			cout << rootrav->character << ",";
			cout << rootrav->num;
			rootrav = rootrav->pnext;
			cout << endl;
			cout << endl;
		}
	}
	void push(cnode* pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	}
	cnode* pop()
	{
		cnode* rootrav;
		rootrav = phead;
		phead = rootrav->pnext;
		rootrav->pnext = NULL;
		return rootrav;
	}
};

class CSlist
{
public:
	cnode* phead;
	CSlist()
	{
		phead = NULL;
	}
	~CSlist()
	{
		cnode* rootrav = phead;
		while (rootrav != NULL)
		{
			phead = phead->pnext;
			delete rootrav;
			rootrav = phead;
		}
	}
	void insert(cnode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
		}
		else
		{
			cnode* pb = NULL;
			cnode* rootrav = phead;
			while (rootrav != NULL && rootrav->num < pnn->num)
			{
				pb = rootrav;
				rootrav = rootrav->pnext;
			}
			if (pb != NULL)
			{
				pnn->pnext = rootrav;
				pb->pnext = pnn;
			}
			else
			{
				pnn->pnext = rootrav;
				phead = pnn;
			}
		}
	}

	void display()
	{
		cnode* trav = phead;
		while (trav != NULL)
		{
			cout << endl;
			if (trav->character == ' ')
			{
				cout << "Space";
			}
			else
			{
				cout << trav->character;
			}
			cout << "----->";
			cout << trav->num;
			cout << "----->";
			for (int i = 0; i < trav->nobit;i++)
			{
				cout << trav->bits[i];
			}

			trav = trav->pnext;
		}
		cout << endl;
	}
	cnode* pop()
	{
		cnode* rootrav;
		rootrav = phead;
		phead = rootrav->pnext;
		rootrav->pnext = NULL;
		return rootrav;
	}
	cnode* remove(int v)
	{
		cnode* rootrav = phead;
		cnode* pb = NULL;
		while (rootrav != NULL && rootrav->num != v)
		{
			pb = rootrav;
			rootrav = rootrav->pnext;
		}
		if (pb == NULL)
		{
			phead = rootrav->pnext;
		}
		return rootrav;
	}
};

class CBTree
{
public:
	cnode* pRoot;
	CBTree()
	{
		pRoot = NULL;
	}
	~CBTree()
	{
		goodBye(pRoot);
	}
	void display(cnode* rootrav)
	{
		if (rootrav == NULL)
		{
			return;
		}
		display(rootrav->pleft);
		cout << "the letter " << rootrav->character << " the frequency " << rootrav->num << endl;
		cout << endl;
		display(rootrav->pright);
	}
	void goodBye(cnode* rootrav)
	{
		if (rootrav == NULL)
		{
			return;
		}
		goodBye(rootrav->pleft);
		/*if (rootrav->character != '_')
		{
			cout << rootrav->binaryNumber << endl;
			delete rootrav->binaryNumber;
		}*/
		goodBye(rootrav->pright);
		delete rootrav;
	}
};
void copy(cnode* pcurr, cnode* pnn)
{

	pnn->num = pcurr->num;
	pnn->character = pcurr->character;
}
void displayTree(cnode* rootrav, int bitss)
{
	if (rootrav == NULL)
	{
		return;
	}
	if (rootrav->character == ' ')
	{
		cout << "Space";
	}
	else
	{
		cout << rootrav->character;
	}
	cout << " the frequency " << rootrav->num;
	cout << "--->";
	for (int i = 0; i < rootrav->nobit; i++)
	{
		cout << rootrav->bits[i];
	}
	cout << endl;
	displayTree(rootrav->pleft, bitss + 1);
	displayTree(rootrav->pright, bitss + 1);
}

void addbits(cnode* parent, int bitss, int k, cnode* pback)
{
	if (parent == NULL)
		return;
	if (pback != parent)
	{
		parent->bits = new int[bitss];
		parent->nobit = bitss;
		for (int i = 0; i < bitss - 1; i++)
		{
			parent->bits[i] = pback->bits[i];
		}
		parent->bits[bitss - 1] = k;
	}
	if (parent->pright != NULL && parent->pleft != NULL)
	{
		pback = parent;

	}
	addbits(parent->pright, bitss + 1, 1, pback);
	addbits(parent->pleft, bitss + 1, 0, pback);
}
void displaytree2(cnode* parent, int bitss)
{
	if (parent->pleft == NULL && parent->pright == NULL)
	{
		if (parent->character == ' ')
		{
			cout << "Space";
		}
		else
		{
			cout << parent->character;
		}
		cout << "----->";
		for (int i = 0; i < parent->nobit; i++)
		{
			cout << parent->bits[i];
		}
		cout << endl;
		return;
	}
	displaytree2(parent->pright, bitss + 1);
	displaytree2(parent->pleft, bitss + 1);
}

void treetolist(cnode* parent, int bitss, CSlist& finalnode)
{
	if (parent->pleft == NULL && parent->pright == NULL)
	{
		cnode* pnnfinal = new cnode;
		pnnfinal->pnext = parent->pnext;
		pnnfinal->pleft = parent->pleft;
		pnnfinal->pright = parent->pright;
		pnnfinal->character = parent->character;
		pnnfinal->num = parent->num;
		pnnfinal->nobit = parent->nobit;
		pnnfinal->bits = new int[parent->nobit];
		for (int i = 0; i < parent->nobit; i++)
		{
			pnnfinal->bits[i] = parent->bits[i];
		}
		finalnode.insert(pnnfinal);
		return;
	}
	treetolist(parent->pright, bitss + 1, finalnode);
	treetolist(parent->pleft, bitss + 1, finalnode);

}

void compress(CSlist& finalnode, char str[], char compressed[], int& t, int ctstr, int& reader)
{
	int temp = 0;
	int k = 0, i = 0;

	for (i = 0; i < ctstr; i++)//itiraite over each letter 
	{
		k = 0;

		cnode* root = finalnode.phead;
		while (root->character != str[i])
		{
			root = root->pnext;
		}

		while (root->bits[k] == 0 || root->bits[k] == 1)
		{
			if (root->bits[k] == 1)
			{
				temp = temp | (root->bits[k] << reader);
			}
			reader--;
			compressed[t] = temp;
			if (reader == -1)
			{
				reader = 7;
				temp = 0;
				t++;

			}
			k++;
		}
	}

}
void decompress(CSlist& finalnode, char compressed[], int& t, int& reader, char* finbit, int& ok)
{
	cnode* root = finalnode.phead;
	int movebitat = 0;
	int ib = 7, mask = 1;
	int temp = 0; int ex = 0, i = 0;
	char bitat[99999], ct = 0;
	for (i = 0; i < t; i++)
	{
		while (1)
		{
			temp = compressed[i] & (mask << ib);

			if (temp == 0)
			{
				bitat[movebitat] = '0';
			}
			else
			{
				bitat[movebitat] = '1';
			}
			finbit[ok] = bitat[movebitat - 1];
			movebitat++;
			ib--;
			ok++;
			root = finalnode.phead;
			while (root != NULL)
			{
				int s = 0, ct = 0;
				for (s = 0; s < movebitat; s++)
				{
					if (root->bits[s] == bitat[s])
					{
						ct++;
					}
				}
				if (ct == movebitat && root->bits[movebitat] == '\0')
				{
					movebitat = 0;
					break;
				}
				root = root->pnext;
			}

			if (ib == -1)
			{
				ib = 7;
				temp = 0;
				break;
			}
		}
	}

}
void main()
{
	char x[255];
	int x2[255];
	char c = 0;
	char s[10000];
	int i, ctstr = 0;
	cnode* rootravv;
	CBTree cbtree;
	CSlist slist;
	cstack tree;
	cnode* pnn;
	CSlist finalnode;
	gets_s(s);
	for (i = 0;i < 255;i++)
	{
		x[i] = i;
	}
	for (i = 0;i < 255;i++)
	{
		x2[i] = 0;
	}
	for (i = 0;i < 255;i++)
	{
		for (int j = 0;s[j] != NULL;j++)
		{
			if (s[j] == x[i])
			{
				x2[i] = x2[i] + 1;
			}
			if (i == 0)
			{
				ctstr++;
			}
		}
		c++;
	}
	cout << "this is" << ctstr;
	for (i = 0;i < 255;i++)
	{
		if (x2[i] != 0)
		{
			pnn = new cnode;
			pnn->pnext = NULL;
			pnn->nobit = 0;
			pnn->pleft = NULL;
			pnn->pright = NULL;
			pnn->character = x[i];
			pnn->num = x2[i];
			slist.insert(pnn);
		}
	}
	slist.display();
	cout << "slist done" << endl;
	int fleaf1 = 0, fleaf2 = 0;

	cnode* pnn1, * pnn2;
	while (slist.phead->pnext != NULL)
	{
		pnn1 = slist.pop();
		pnn2 = slist.pop();

		pnn = new cnode;
		pnn->pnext = NULL;
		pnn->nobit = 0;
		pnn->pleft = pnn2;
		pnn->pright = pnn1;
		pnn->character = pnn1->character + pnn2->character;

		pnn->num = pnn1->num + pnn2->num;

		pnn->pnext = NULL;
		pnn1->pnext = NULL;
		pnn2->pnext = NULL;

		slist.insert(pnn);

		rootravv = pnn;
	}
	addbits(slist.phead, 0, 0, slist.phead);
	displaytree2(slist.phead, 0);
	displayTree(slist.phead, 0);
	cout << "this is final node";
	treetolist(slist.phead, 0, finalnode);
	finalnode.display();

	cout << "compress";
	char compressed[10000];
	int t = 0;
	int reader = 7;
	compress(finalnode, s, compressed, t, ctstr, reader);
	cout << endl;
	for (int i = 0; i < t; i++)
	{
		cout << compressed[i];
	}
	cout << endl;
	cout << "decompress";
	cout << endl;
	char* k;
	k = new char[100000];
	char* finbit = new char[100000];
	int ok = 0;
	decompress(finalnode, compressed, t, reader, finbit, ok);



	int u = 0;
	int ct = 0;
	cnode* ftrav = finalnode.phead;
	char fin[100000];
	cout << endl;
	for (int i = 0;i < ok;i++)
	{
		cout << finbit[i];
	}
	for (i = 0;i < ok;i++) //iterate on each bit
	{
		int j = 0;
		while (ftrav != NULL)//itreate on each node
		{
			for (j = 0; j < ftrav->nobit;j++) //compares each bit in node with bits in array
			{
				if ((finbit[i + j] == '0' && ftrav->bits[j] == 0) || (finbit[i + j] == '1' && ftrav->bits[j] == 1))
				{
					ct++;
				}
				if (ct == ftrav->nobit)
				{
					break;
				}
			}
			if (ct == ftrav->nobit)
			{
				fin[u] = ftrav->character;
				u++;
				i += ftrav->nobit;
				i--;
				break;
			}
			ftrav = ftrav->pnext;
			ct = 0;
		}
		ftrav = finalnode.phead;
		ct = 0;
	}
	cout << endl;
	for (i = 0;i < ctstr;i++)
	{
		cout << fin[i];
	}

}