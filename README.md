# Data Structure Snake Game

A terminal-based Snake game implemented in C++ that demonstrates core data structure concepts such as linked lists, queues, and grid-based state management. The project focuses on clean logic, efficient movement handling, and real-time user input while preserving classic Snake gameplay mechanics.

<img src="meida/snakeGame.gif" width = 100%>

---

## 🧠 Design

The game is designed around a modular architecture where game logic, snake behavior, and board state are handled as distinct responsibilities. The snake itself is represented using dynamic data structures that allow efficient growth, movement, and collision detection.

By relying on data structures rather than hard-coded movement logic, the implementation closely mirrors how real-time systems manage state updates and entity tracking.

---

## 🧭 Approach

1. **Game Board Representation**  
   The game board is modeled as a 2D grid that tracks empty spaces, snake segments, food locations, and boundaries.

2. **Snake Body Management**  
   The snake is implemented using a dynamic data structure (e.g., linked list or deque), allowing constant-time insertion and removal of body segments as the snake moves and grows.

3. **Movement & Input Handling**  
   User keyboard input is captured to update the snake’s direction. Each game tick advances the snake head forward and updates the rest of the body accordingly.

4. **Collision Detection**  
   The system checks for self-collisions and boundary collisions on each update cycle, triggering a game-over state when violations occur.

5. **Scoring & Growth Logic**  
   When the snake consumes food, a new segment is added without removing the tail, increasing both length and score.

---

## 📊 Results

The final implementation successfully recreates classic Snake gameplay within a terminal environment while emphasizing clean data structure usage and logical separation of concerns.

The game responds smoothly to user input, correctly handles growth and collisions, and serves as a strong demonstration of practical data structure applications in real-time systems and game logic.
