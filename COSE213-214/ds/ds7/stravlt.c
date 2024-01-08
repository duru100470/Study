#define SHOW_STEP 0 // 제출시 0
#define BALANCING 1 // 제출시 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h> //strcmp, strdup

#define max(x, y) (((x) > (y)) ? (x) : (y))

////////////////////////////////////////////////////////////////////////////////
// AVL_TREE type definition
typedef struct node
{
	char *data;
	struct node *left;
	struct node *right;
	int height;
} NODE;

typedef struct
{
	NODE *root;
	int count; // number of nodes
} AVL_TREE;

////////////////////////////////////////////////////////////////////////////////
// Prototype declarations

/* Allocates dynamic memory for a AVL_TREE head node and returns its address to caller
	return	head node pointer
			NULL if overflow
*/
AVL_TREE *AVL_Create(void);

/* Deletes all data in tree and recycles memory
 */
void AVL_Destroy(AVL_TREE *pTree);
static void _destroy(NODE *root);

/* Inserts new data into the tree
	return	1 success
			0 overflow
*/
int AVL_Insert(AVL_TREE *pTree, char *data);

/* internal function
	This function uses recursion to insert the new data into a leaf node
	return	pointer to new root
*/
static NODE *_insert(NODE *root, NODE *newPtr);

static NODE *_makeNode(char *data);

/* Retrieve tree for the node containing the requested key
	return	address of data of the node containing the key
			NULL not found
*/
char *AVL_Retrieve(AVL_TREE *pTree, char *key);

/* internal function
	Retrieve node containing the requested key
	return	address of the node containing the key
			NULL not found
*/
static NODE *_retrieve(NODE *root, char *key);

/* Prints tree using inorder traversal
 */
void AVL_Traverse(AVL_TREE *pTree);
static void _traverse(NODE *root);

/* Prints tree using inorder right-to-left traversal
 */
void printTree(AVL_TREE *pTree);
/* internal traversal function
 */
static void _infix_print(NODE *root, int level);

/* internal function
	return	height of the (sub)tree from the node (root)
*/
static int getHeight(NODE *root);

/* internal function
	Exchanges pointers to rotate the tree to the right
	updates heights of the nodes
	return	new root
*/
static NODE *rotateRight(NODE *root);

/* internal function
	Exchanges pointers to rotate the tree to the left
	updates heights of the nodes
	return	new root
*/
static NODE *rotateLeft(NODE *root);

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
	AVL_TREE *tree;
	char str[1024];
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s FILE\n", argv[0]);
		return 0;
	}
	// creates a null tree
	tree = AVL_Create();

	if (!tree)
	{
		fprintf( stderr, "Cannot create tree!\n");
		return 100;
	}

	FILE *fp = fopen(argv[1], "rt");
	if (fp == NULL)
	{
		fprintf(stderr, "Cannot open file! [%s]\n", argv[1]);
		return 200;
	}

	while (fscanf(fp, "%s", str) != EOF)
	{

#if SHOW_STEP
		fprintf(stdout, "Insert %s>\n", str);
#endif
		// insert function call
		AVL_Insert(tree, str);

#if SHOW_STEP
		fprintf(stdout, "Tree representation:\n");
		printTree(tree);
#endif
	}

	fclose(fp);

#if SHOW_STEP
	fprintf(stdout, "\n");

	// inorder traversal
	fprintf(stdout, "Inorder traversal: ");
	AVL_Traverse(tree);
	fprintf(stdout, "\n");

	// print tree with right-to-left infix traversal
	fprintf(stdout, "Tree representation:\n");
	printTree(tree);
#endif
	fprintf(stdout, "Height of tree: %d\n", tree->root->height);
	fprintf(stdout, "# of nodes: %d\n", tree->count);

	// retrieval
	char *key;
	fprintf(stdout, "Query: ");
	while (fscanf(stdin, "%s", str) != EOF)
	{
		key = AVL_Retrieve(tree, str);

		if (key)
			fprintf(stdout, "%s found!\n", key);
		else
			fprintf(stdout, "%s NOT found!\n", str);

		fprintf(stdout, "Query: ");
	}

	// destroy tree
	AVL_Destroy(tree);

	return 0;
}

/* Allocates dynamic memory for a AVL_TREE head node and returns its address to caller
	return	head node pointer
			NULL if overflow
*/
AVL_TREE *AVL_Create(void)
{
	AVL_TREE *newTree = (AVL_TREE *)malloc(sizeof(AVL_TREE));
	newTree->count = 0;
	newTree->root = NULL;

	return newTree;
}

/* Deletes all data in tree and recycles memory
 */
void AVL_Destroy(AVL_TREE *pTree)
{
	_destroy(pTree->root);
	free(pTree);
}
static void _destroy(NODE *root)
{
	if (!root)
		return;

	if (root->left)
		_destroy(root->left);
	if (root->right)
		_destroy(root->right);

	free(root->data);
	free(root);
}

/* Inserts new data into the tree
	return	1 success
			0 overflow
*/
int AVL_Insert(AVL_TREE *pTree, char *data)
{
	NODE *newNode = _makeNode(data);

	if (!newNode)
		return 0;

	if (pTree->count == 0)
	{
		pTree->root = newNode;
		(pTree->count)++;
		return 1;
	}

	pTree->root = _insert(pTree->root, newNode);
	(pTree->count)++;
	return 1;
}

/* internal function
	This function uses recursion to insert the new data into a leaf node
	return	pointer to new root
*/
static NODE *_insert(NODE *root, NODE *newPtr)
{
	int ret = strcmp(root->data, newPtr->data);

	if (ret > 0)
	{
		if (root->left)
		{
			root->left = _insert(root->left, newPtr);
		}
		else
		{
			root->left = newPtr;
		}
	}
	else
	{
		if (root->right)
		{
			root->right = _insert(root->right, newPtr);
		}
		else
		{
			root->right = newPtr;
		}
	}
	root->height = getHeight(root);

#if BALANCING
	int bf = (root->left ? root->left->height : 0) - (root->right ? root->right->height : 0);

	if (bf > 1)
	{
		int lSubBF = (root->left->left ? root->left->left->height : 0) - (root->left->right ? root->left->right->height : 0);

		if (lSubBF > 0)
		{
			root = rotateRight(root);
		}
		else
		{
			root->left = rotateLeft(root->left);
			root = rotateRight(root);
		}
	}
	else if (bf < -1)
	{
		int rSubBF = (root->right->left ? root->right->left->height : 0) - (root->right->right ? root->right->right->height : 0);

		if (rSubBF < 0)
		{
			root = rotateLeft(root);
		}
		else
		{
			root->right = rotateRight(root->right);
			root = rotateLeft(root);
		}
	}
#endif

	return root;
}

static NODE *_makeNode(char *data)
{
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = strdup(data);
	newNode->height = 1;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

/* Retrieve tree for the node containing the requested key
	return	address of data of the node containing the key
			NULL not found
*/
char *AVL_Retrieve(AVL_TREE *pTree, char *key)
{
	NODE *ret = _retrieve(pTree->root, key);

	if (ret)
		return ret->data;
	else
		return NULL;
}

/* internal function
	Retrieve node containing the requested key
	return	address of the node containing the key
			NULL not found
*/
static NODE *_retrieve(NODE *root, char *key)
{
	int cmp = strcmp(root->data, key);

	if (cmp == 0)
	{
		return root;
	}
	else if (cmp > 0)
	{
		if (root->left)
			return _retrieve(root->left, key);
		else
			return NULL;
	}
	else
	{
		if (root->right)
			return _retrieve(root->right, key);
		else
			return NULL;
	}
}

/* Prints tree using inorder traversal
 */
void AVL_Traverse(AVL_TREE *pTree)
{
	_traverse(pTree->root);
}
static void _traverse(NODE *root)
{
	if (root->left)
		_traverse(root->left);

	printf("%s ", root->data);

	if (root->right)
		_traverse(root->right);
}

/* Prints tree using inorder right-to-left traversal
 */
void printTree(AVL_TREE *pTree)
{
	_infix_print(pTree->root, 0);
}
/* internal traversal function
 */
static void _infix_print(NODE *root, int level)
{
	if (!root)
		return;

	if (root->right)
		_infix_print(root->right, level + 1);

	for (int i = 0; i < level; i++)
	{
		printf("\t");
	}
	printf("%s\n", root->data);

	if (root->left)
		_infix_print(root->left, level + 1);
}

/* internal function
	return	height of the (sub)tree from the node (root)
*/
static int getHeight(NODE *root)
{
	int l = 0, r = 0;
	if (root->left)
		l = root->left->height;
	if (root->right)
		r = root->right->height;

	return max(l, r) + 1;
}

/* internal function
	Exchanges pointers to rotate the tree to the right
	updates heights of the nodes
	return	new root
*/
static NODE *rotateRight(NODE *root)
{
	NODE *l = root->left;

	root->left = l->right;
	l->right = root;
	root->height = getHeight(root);
	l->height = getHeight(l);

	return l;
}

/* internal function
	Exchanges pointers to rotate the tree to the left
	updates heights of the nodes
	return	new root
*/
static NODE *rotateLeft(NODE *root)
{
	NODE *r = root->right;

	root->right = r->left;
	r->left = root;
	root->height = getHeight(root);
	r->height = getHeight(r);

	return r;
}