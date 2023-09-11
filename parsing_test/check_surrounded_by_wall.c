#include "test.h"

#define MAX_QUEUE 1000

typedef struct s_queue_arr
{
	int	x;
	int	y;
}	t_queue_arr;

typedef struct s_queue
{
	t_queue_arr	*arr;
	int	**visited;
	int	front;
	int	rear;
	int	max_idx;
	int	width;
	int	height;
}	t_queue;

t_queue *init_queue(t_map *info_map)
{
	t_queue	*queue;
	int		i;

	i = 0;
	queue = (t_queue *)malloc(sizeof(queue));
	queue->arr = (t_queue_arr *)malloc(sizeof(t_queue_arr) * (MAX_QUEUE));
	queue->visited = init_ppc(info_map->height, info_map->width);
	while (queue->visited[i] != NULL)
	{
		ft_memset(queue->visited[i], 0, info_map->width - 1);
		i++;
	}
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
		return (1);
	queue->front++;
}

void	enqueue(t_queue *queue, int x, int y)
{
	if (q_is_full(queue) == 0)
		ft_error("queue is full\n");
	queue->arr[queue->rear].x = x;
	queue->arr[queue->rear].y = y;
	queue->rear++;
	queue->visited[x][y] == 1;
}

void	enqueue_valid_position(t_queue *queue)
{
	int	front_x;
	int	front_y;

	front_x = queue->arr[queue->front].x;
	front_y = queue->arr[queue->rear].y;
	if (front_x - 1 >= 0 && queue->visited[front_x - 1][front_y] == 0)
		enqueue(queue, front_x - 1, front_y);//위
	if (front_x + 1 <= queue->height && queue->visited[front_x + 1][front_y] == 0)
		enqueue(queue, front_x + 1, front_y);//아래
	if (front_y + 1 <= queue->width && queue->visited[front_x][front_y + 1] == 0)
		enqueue(queue, front_x, front_y + 1);//오
	if (front_y - 1 >= 0 && queue->visited[front_x][front_y - 1] == 0)
		enqueue(queue, front_x, front_y - 1);//왼
}

void	check_surrounded_by_wall(char **map, t_map *info_map)
{
	t_queue	*queue;

	queue = init_queue(info_map);
	queue->arr[queue->front].x = info_map->starting_x;
	queue->arr[queue->front].y = info_map->starting_y;
	queue->visited[info_map->starting_x][info_map->starting_y] = 1;
	while (q_is_empty(queue) == 0)
	{
		enqueue_valid_position(queue);
		dequeue(queue);
	}


}