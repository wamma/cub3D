#include <stdio.h>
#include <stdlib.h>

typedef struct s_queue
{
	int	**visited;
	int	front;
	int	rear;
	int	max_idx;
	int	width;
	int	height;
}	t_queue;

int	**init_ppi(int height, int width)
{
	int	**ppi;
	int	j;
	int	i;

	i = 0;
	j = 0;
	ppi = (int **)malloc(sizeof(int *) * (height + 1));
	ppi[height] = NULL;
	while (i < height)
	{
		ppi[i] = (int *)malloc(sizeof(int) * (width));
		while (j < width)
		{
			ppi[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ppi);
}

t_queue *init_queue()
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(queue));
	queue->visited = init_ppi(3, 4);
	return (queue);
}

int main()
{
	t_queue *queue;
	int	i;
	int	j;

	i = 0;
	queue = init_queue();
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d ", queue->visited[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
