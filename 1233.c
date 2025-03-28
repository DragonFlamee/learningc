#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5


enum Dir { UP, DOWN, LEFT, RIGHT };


struct point { int row, col; };


char dir[MAX_ROW][MAX_COL] = {0};


int maze[MAX_ROW][MAX_COL] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0
};


int dfs(struct point current) {

    if (current.row == MAX_ROW-1 && current.col == MAX_COL-1) {
        return 1;
    }

    maze[current.row][current.col] = 2;

    // 尝试四个方向（右->下->左->上）
    struct point next;

    // 向右探索
    if (current.col+1 < MAX_COL && maze[current.row][current.col+1] == 0) {
        next = (struct point){current.row, current.col+1};
        if (dfs(next)) {
            dir[next.row][next.col] = LEFT; // 当前点来自左边
            return 1;
        }
    }

    // 向下探索
    if (current.row+1 < MAX_ROW && maze[current.row+1][current.col] == 0) {
        next = (struct point){current.row+1, current.col};
        if (dfs(next)) {
            dir[next.row][next.col] = UP; // 当前点来自上方
            return 1;
        }
    }

    // 向左探索
    if (current.col-1 >= 0 && maze[current.row][current.col-1] == 0) {
        next = (struct point){current.row, current.col-1};
        if (dfs(next)) {
            dir[next.row][next.col] = RIGHT; // 当前点来自右方
            return 1;
        }
    }

    // 向上探索
    if (current.row-1 >= 0 && maze[current.row-1][current.col] == 0) {
        next = (struct point){current.row-1, current.col};
        if (dfs(next)) {
            dir[next.row][next.col] = DOWN; // 当前点来自下方
            return 1;
        }
    }

    // 回溯：清除访问标记
    maze[current.row][current.col] = 0;
    return 0;
}


void print_path(struct point p) {

    if (p.row == 0 && p.col == 0) {
        printf("(0, 0)");
        return;
    }


    struct point prev;
    switch (dir[p.row][p.col]) {
        case UP:    prev = (struct point){p.row-1, p.col}; break;
        case DOWN:  prev = (struct point){p.row+1, p.col}; break;
        case LEFT:  prev = (struct point){p.row, p.col-1}; break;
        case RIGHT: prev = (struct point){p.row, p.col+1}; break;
    }


    print_path(prev);
    printf(" -> (%d, %d)", p.row, p.col);
}

int main() {
    struct point start = {0, 0};
    
    if (dfs(start)) {
        printf("Find path\n");
        print_path((struct point){MAX_ROW-1, MAX_COL-1}); // 从终点开始回溯
    } else {
        printf("No path\n");
    }

    return 0;
}
