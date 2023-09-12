#include "test.h"

#define MAX_QUEUE 100000
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

typedef struct s_queue_arr
{
	int	x;
	int	y;
}	t_queue_arr;

typedef struct s_queue
{
	char	**visited;
	t_queue_arr	*arr;
	int	front;
	int	rear;
	int	max_idx;
	int	width;
	int	height;
}	t_queue;

void	free_queue(t_queue *queue)
{
	int	i;

	i = 0;
	free(queue->arr);
	while (i < queue->height)
	{
		free(queue->visited[i]);
		i++;
	}
	free(queue->visited);
	free(queue);
}

char **init_ppi(int height, int width)
{
	char	**ppi;
	int	j;
	int	i;

	i = 0;
	ppi = (char **)malloc(sizeof(char *) * (height + 1));
	ppi[height] = NULL;
	while (ppi[i] != NULL)
	{
		ppi[i] = (char *)malloc(sizeof(char) * (width + 1));
		printf("here\n");
		j = 0;
		while (j < width)
		{
			ppi[i][j] = 0;
			j++;
		}
		ppi[i][j] = '\0';
		i++;
	}
	return (ppi);
}

t_queue *init_queue(t_map *info_map)
{
	t_queue	*queue;
	//int		**ppi;
	//int		i;
	//int		j;

	//i = 0;
	queue = (t_queue *)malloc(sizeof(queue));
	queue->arr = (t_queue_arr *)malloc(sizeof(t_queue_arr) * (MAX_QUEUE));
	// ppi = init_ppi(info_map->height, info_map->width);
	// queue->visited = ppi;
	// while (i < info_map->height)
	// {
	// 	j = 0;
	// 	while (j < info_map->width)
	// 	{
	// 		printf("i: %d j : %d\n", i, j);
	// 		queue->visited[i][j] = 3;
	// 		j++;
	// 	}
	// 	i++;
	// }
	//printf(":%d\n",queue->visited[0][0]);
	// for(int i = 0; i < info_map->height; i++)
	// {
	// 	for(int j = 0; j < info_map->width; j++)
	// 	{
	// 		printf("%d ", queue->visited[i][j]);
	// 	}
	// 	printf("\n");
	// }
	queue->front = 0;
	queue->rear = 0;
	queue->max_idx = MAX_QUEUE - 1;
	queue->width = info_map->width;
	queue->height = info_map->height;
	return (queue);
}

int	q_is_empty(t_queue *queue)
{
	if(queue->front == queue->rear)
		return (1);
	return (0);
}

int	q_is_full(t_queue *queue)
{
	int	gap;

	gap = queue->front - queue->rear;
	if (gap < 0)
		gap *= -1;
	if (gap == 1 || gap == MAX_QUEUE - 1)
		return (1);
	return (0);
}

void	dequeue(t_queue *queue)
{
	if (q_is_empty(queue) == 1)
		ft_error("queue is empty\n");
	queue->front++;
}

void	enqueue(t_queue *queue, int x, int y)
{
	// if (q_is_full(queue) == 0)
	// 	ft_error("queue is full\n");
	printf("enqueue: %d %d\n", x, y);
	queue->arr[queue->rear].x = x;
	queue->arr[queue->rear].y = y;
	queue->rear++;
	if (queue->rear == MAX_QUEUE)
		queue->rear = 0;
	queue->visited[x][y] = 1;
}

int	check_valid_position(t_map *info_map, t_queue *queue, int direction)
{
	int	x;
	int	y;
	
	x = queue->arr[queue->front].x;
	y = queue->arr[queue->front].y;
	if (direction == UP)
		x -= 1;
	if (direction == DOWN)
		x += 1;
	if (direction == RIGHT)
		y += 1;
	if (direction == LEFT)
		y -= 1;
	if (x < 0 || x >= queue->height || y < 0 || y >= queue->width)
		return (0);
	if (queue->visited[x][y] == 1 || info_map->map[x][y] == '1')
		return (0);
	//printf("info_map->map[%d][%d]: %c\n", x, y, info_map->map[x][y]);
	if (info_map->map[x][y] == UNDEFINED_MAP)
		ft_error("Check : map isn't surrounded by wall\n");
	return (1);
}

void	enqueue_valid_position(t_map *info_map, t_queue *queue)
{
	int	front_x;
	int	front_y;

	front_x = queue->arr[queue->front].x;
	front_y = queue->arr[queue->front].y;
	if (check_valid_position(info_map, queue, UP) == 1)
		enqueue(queue, front_x - 1, front_y);
	if (check_valid_position(info_map, queue, DOWN) == 1)
		enqueue(queue, front_x + 1, front_y);
	if (check_valid_position(info_map, queue, RIGHT) == 1)
		enqueue(queue, front_x, front_y - 1);
	if (check_valid_position(info_map, queue, LEFT) == 1)
		enqueue(queue, front_x, front_y + 1);
}

void	check_surrounded_by_wall(t_map *info_map)
{
	t_queue	*queue;

	queue = init_queue(info_map);
	queue->visited = init_ppi(queue->height, queue->width);
	printf("map2:\n");
	printf("height: %d\n", info_map->height);
	for(int i = 0; i < info_map->height; i++)
	{
		for(int j = 0; j < info_map->width; j++)
		{
			printf("%c", info_map->map[i][j]);
		}
		printf("\n");
	}
	//printf("here: %p\n", info_map->map[2]);
	printf("\n");
	// for(int i = 0; i < info_map->height + 1; i++)
	// {
	// 	for(int j = 0; j < info_map->width; j++)
	// 	{
	// 		printf("%c", info_map->map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	//printf("%p\n", &queue->visited[0][0]);
	// for(int i = 0; i < info_map->height; i++)
	// {
	// 	for(int j = 0; j < info_map->width; j++)
	// 	{
	// 		printf("%d ", queue->visited[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("here: %d\n", queue->visited[1][0]);//왜 이게 접근을 못하지..?
	// printf("%p\n%p\n", queue->visited, queue->visited[0]);
	//printf("%d\n", queue->visited[0][0]);
	enqueue(queue, info_map->starting_x, info_map->starting_y);
	printf("front : %d rear: %d\n", queue->front, queue->rear);
	while (q_is_empty(queue) == 0)
	{
		printf("end\n");
		enqueue_valid_position(info_map, queue);
		dequeue(queue);
		printf("front : %d rear: %d\n", queue->front, queue->rear);
	}
	free_queue(queue);
	printf("end\n");
}//완전이상;'