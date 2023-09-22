#include "shell.h"

/**
 * myExit - shell exits func
 * @info: arg struct func prototype
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 *  Return: exits or exit status
*/
int myExit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = errAtoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			printError(info, "Illegal number: ");
			ePuts(info->argv[1]);
			ePutChar('\n');
			return (1);
		}
		info->err_num = errAtoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * myCd - change current directory process
 * @info: arg struct func prototype
 *  Return: always 0
 */
int myCd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = getEnv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = getEnv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (stringCmp(info->argv[1], "-") == 0)
	{
		if (!getEnv(info, "OLDPWD="))
		{
			_puts(s);
			putChar('\n');
			return (1);
		}
		_puts(getEnv(info, "OLDPWD=")), putChar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = getEnv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		printError(info, "can't cd to ");
		ePuts(info->argv[1]), ePutChar('\n');
	}
	else
	{
		SetEnv(info, "OLDPWD", getEnv(info, "PWD="));
		SetEnv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * myHelp - change current directory process
 * @info: arg struct func prototype
 *  Return: always 0
 */
int myHelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

/**
 * myHistory - display history list by cmd line
 * @info: arg struct func prototype
 * Code by - Huseini Yusif & Bennet Aboagye-Asare
 *  Return: always 0
 */
int myHistory(info_t *info)
{
	printList(info->history);
	return (0);
}

/**
 * unsetAlias - sets alias to str
 * @info: parameter struct
 * @str: string alias
 * Return: 0 (success), 1 (error)
 */
int unsetAlias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strChr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = deleteNodeAtIndex(&(info->alias),
		getNodeIndex(info->alias, nodeStartsWith(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * setAlias - sets alias to str
 * @info: parameter struct
 * @str: string alias
 * Return: 0 (success), 1 (error)
 */
int setAlias(info_t *info, char *str)
{
	char *p;

	p = _strChr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unsetAlias(info, str));

	unsetAlias(info, str);
	return (addNodeEnd(&(info->alias), str, 0) == NULL);
}

/**
 * printAlias - prints an alias string
 * @node: the alias node
 * Return: 0 (success), 1 (error)
 */
int printAlias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strChr(node->str, '=');
		for (a = node->str; a <= p; a++)
			putChar(*a);
		putChar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * myAlias - mimic alias built-in
 * @info: arg struct func prototype
 *  Return: always 0
 */
int myAlias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printAlias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strChr(info->argv[i], '=');
		if (p)
			setAlias(info, info->argv[i]);
		else
			printAlias(nodeStartsWith(info->alias, info->argv[i], '='));
	}

	return (0);
}
