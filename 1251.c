#include <stdio.h>
#include <stdbool.h>
#define MAX_ROW 5
#define MAX_COL 5
#define QUE_SIZE 5    //minimum

struct point { int row, col; } queue[QUE_SIZE];
int head = 0, tail = 0;

int is_empty(void)
{
	return head == tail;
}

bool is_full(void)
{
    return (tail+1)%QUE_SIZE == head;
}

void enqueue(struct point p)
{
    if(is_full()) printf("It's full !");
    tail = (tail + 1) % QUE_SIZE;
	queue[tail] = p;
}

struct point dequeue(void)
{
    head = (head+1) % QUE_SIZE;
    struct point q = queue[head];
	return q;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};


void visit(int row, int col)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	enqueue(visit_point);
}

int main(void)
{
	struct point p = { 0, 0};

	maze[p.row][p.col] = 2;
	enqueue(p);
	
	while (!is_empty()) {
		p = dequeue();
		if (p.row == MAX_ROW - 1  /* goal */
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     /* right */
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1);
		if (p.row+1 < MAX_ROW     /* down */
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col);
		if (p.col-1 >= 0          /* left */
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1);
		if (p.row-1 >= 0          /* up */
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col);
	}
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		printf("Find it !\n");
	} else
		printf("No path!\n");
	return 0;
}


// #include <stdio.h>
// #include <stdbool.h>

// #define MAX_ROW 5
// #define MAX_COL 5
// #define QUEUE_SIZE 5  // 可调整这个值测试最小所需空间

// typedef struct {
//     int row;
//     int col;
// } Point;

// typedef struct {
//     Point data[QUEUE_SIZE];
//     int head;
//     int tail;
// } CircularQueue;

// CircularQueue queue = {{0}, 0, 0};
// int maze[MAX_ROW][MAX_COL] = {
//     0, 1, 0, 0, 0,
//     0, 1, 0, 1, 0,
//     0, 0, 0, 0, 0,
//     0, 1, 1, 1, 0,
//     0, 0, 0, 1, 0,
// };

// bool is_empty() {
//     return queue.head == queue.tail;
// }

// bool is_full() {
//     return (queue.tail + 1) % QUEUE_SIZE == queue.head;
// }

// void enqueue(Point p) {
//     if (is_full()) {
//         printf("Queue overflow!\n");
//         return;
//     }
//     queue.data[queue.tail] = p;
//     queue.tail = (queue.tail + 1) % QUEUE_SIZE;
// }

// Point dequeue() {
//     Point p = queue.data[queue.head];
//     queue.head = (queue.head + 1) % QUEUE_SIZE;
//     return p;
// }

// bool bfs() {
//     // 初始化标记数组
//     int visited[MAX_ROW][MAX_COL] = {0};
//     Point start = {0, 0};
    
//     enqueue(start);
//     visited[0][0] = 1;

//     // 四个移动方向（右，下，左，上）
//     int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

//     while (!is_empty()) {
//         Point current = dequeue();

//         // 到达终点
//         if (current.row == MAX_ROW-1 && current.col == MAX_COL-1) {
//             return true;
//         }

//         // 探索四个方向
//         for (int i = 0; i < 4; i++) {
//             int new_row = current.row + directions[i][0];
//             int new_col = current.col + directions[i][1];

//             if (new_row >= 0 && new_row < MAX_ROW &&
//                 new_col >= 0 && new_col < MAX_COL &&
//                 !visited[new_row][new_col] &&
//                 maze[new_row][new_col] == 0) {
                
//                 Point next = {new_row, new_col};
//                 enqueue(next);
//                 visited[new_row][new_col] = 1;
//             }
//         }
//     }
//     return false;
// }

// int main() {
//     if (bfs()) {
//         printf("Path exists!\n");
//     } else {
//         printf("No path!\n");
//     }
//     return 0;
// }