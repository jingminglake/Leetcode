class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        _width = width;
        _height = height;
        foodIndex = 0;
        _food = food;
        body = vector<vector<bool> >(height, vector<bool>(width, false));
        body[0][0] = true;
        dir["R"] = {0, 1};
        dir["L"] = {0, -1};
        dir["U"] = {-1, 0};
        dir["D"] = {1, 0};
        snake.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int i = snake.back().first;
        int j = snake.back().second;
        int next_i = i + dir[direction].first;
        int next_j = j + dir[direction].second;
        if (next_j < 0 || next_j >= _width || next_i < 0 || next_i >= _height)
            return -1;
        if (foodIndex < _food.size() && next_i == _food[foodIndex][0] && next_j == _food[foodIndex][1]) {
            body[next_i][next_j] = true;
            snake.push_back({next_i, next_j});
            return ++foodIndex;
        } else {
            pair<int, int> tail = snake.front();
            snake.pop_front();
            body[tail.first][tail.second] = false;
            if (body[next_i][next_j])
                return -1;
            body[next_i][next_j] = true;
            snake.push_back({next_i, next_j});
            return foodIndex;
        }
        //cout << next_i << ", " << next_j << " " << body[next_i][next_j] << endl;
       /* for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++) {
                cout << body[i][j] << " ";
            }
            cout << endl;
        }
        cout << "------" << endl;*/
    }
    int _width;
    int _height;
    int foodIndex;
    vector<vector<int> > _food;
    vector<vector<bool> > body;
    deque<pair<int, int> > snake;
    unordered_map<string, pair<int, int> > dir;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
