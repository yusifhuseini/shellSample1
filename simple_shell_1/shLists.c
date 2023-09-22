#include "shell.h"

/**
 * addNode - func to add node to list start
 * @head: head pointer address node
 * @str: str field node
 * @num: node index history
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: list size
 */
list_t *addNode(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	memSet((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = stringDup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * addNodeEnd - func to add node to list end
 * @head: head pointer address node
 * @str: str field node
 * @num: node index history
 * Return: list size
 */
list_t *addNodeEnd(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	memSet((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = stringDup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * printListStr - func to print str element of list_t linked list
 * @h: first node pointer
 * Return: list size
 */
size_t printListStr(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * deleteNodeAtIndex - func to delete node index
 * @head: first node pointer address
 * @index: delete index node
 * Return: 1 success, 0 failure
 */
int deleteNodeAtIndex(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * freeList - func to free all list nodes
 * @head_ptr: head node address pointer
 * Return: void
 */
void freeList(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}


/**
 * listLen - func to determine linked list lengh
 * @h: first node pointer
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 * Return: list size
 */
size_t listLen(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * listToStrings - func to return str array (list->str)
 * @head: first node pointer
 * Return: strings array
 */
char **listToStrings(list_t *head)
{
	list_t *node = head;
	size_t i = listLen(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(strLen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = stringCpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * printList - func to print all list_t linked list element
 * @h: first node pointer
 * Return: list size
 */
size_t printList(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convertNum(h->num, 10, 0));
		putChar(':');
		putChar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * nodeStartsWith - func to return str node with prefix
 * @node: list head pointer
 * @prefix: match string
 * @c: match character prefix
 * Return: node or null
 */
list_t *nodeStartsWith(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = startsWith(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * getNodeIndex - func to get node index
 * @head: list head pointer
 * @node: node pointer
 * Return: node index or -1
 */
ssize_t getNodeIndex(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
