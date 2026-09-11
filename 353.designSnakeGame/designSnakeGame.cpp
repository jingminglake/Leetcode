class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        w = width;
        h = height;
        foods = food;
        score = 0;
        foodIndex = 0;
        s.insert(0);
        q.push_back(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (score == -1) {
            return -1;
        }
        int rowHead = q.front() / w;
        int colHead = q.front() % w;
        if (direction == "U") {
            rowHead--;
        } else if (direction == "D") {
            rowHead++;
        } else if (direction == "L") {
            colHead--;
        } else if (direction == "R") {
            colHead++;
        }
        int head = rowHead * w + colHead;
        s.erase(q.back());
        if (rowHead < 0 || rowHead >= h || colHead < 0 || colHead >= w || s.count(head))
            return score = -1;
        s.insert(head);
        q.push_front(head);
        if (foodIndex < foods.size() && rowHead == foods[foodIndex].first && colHead == foods[foodIndex].second) { //eat
            foodIndex++;
            score++;
            s.insert(q.back());
        } else {
            q.pop_back();
        }
        return score;
    }
    unordered_set<int> s;
    deque<int> q;
    int score;
    int w;
    int h;
    int foodIndex;
    vector<pair<int, int>> foods;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
