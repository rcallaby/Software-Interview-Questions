# **Graphs: Mastering a Core Topic for Technical Interviews**

Graphs are one of the most versatile and powerful data structures in computer science. This section of the repository provides clean, well-explained solutions to the most common graph problems encountered in software engineering technical interviews, along with the key concepts, patterns, and techniques you need to solve them efficiently.

### What Are Graphs?

A **graph** is a non-linear data structure consisting of:

- **Vertices** (also called nodes) — entities or points.
- **Edges** — connections or relationships between those vertices.

Graphs can be:
- **Directed** (edges have direction, e.g., one-way roads) or **Undirected** (bidirectional).
- **Weighted** (edges have costs/weights) or **Unweighted**.
- **Cyclic** or **Acyclic** (DAGs — Directed Acyclic Graphs are especially important).
- Represented using adjacency lists (most common in interviews), adjacency matrices, or edge lists.

Unlike trees (which are a special type of acyclic, connected graph with a single root), general graphs can have cycles, multiple paths between nodes, and disconnected components.

### Why Are Graphs So Useful?

Graphs excel at modeling **relationships** and **networks**, which appear everywhere in real-world systems:

- **Social networks** — Friend connections (Facebook, LinkedIn).
- **Transportation** — Road maps, flight routes, navigation (Google Maps uses graph algorithms).
- **Web** — Pages linked by hyperlinks (Google’s PageRank is graph-based).
- **Dependencies** — Package managers, task scheduling, build systems.
- **Recommendations** — “People you may know,” movie/product suggestions.
- **Biology & Chemistry** — Protein interactions, molecular structures.
- **Computer networks** — Routing packets, distributed systems.
- **Games & AI** — State spaces, pathfinding (e.g., A* algorithm).

Common algorithms you’ll use include **BFS** (shortest path in unweighted graphs, level-order traversal), **DFS** (cycle detection, connectivity), **Dijkstra’s**, **Bellman-Ford**, **Floyd-Warshall**, **Topological Sort**, **Union-Find** (Disjoint Set Union), and **Minimum Spanning Tree** algorithms (Kruskal’s, Prim’s).

Because so many practical problems can be reduced to graph traversal, connectivity, shortest paths, or optimization on graphs, mastering this topic dramatically improves your ability to design scalable systems and solve complex problems.

### Why Are Graphs Heavily Tested in Technical Interviews?

Graph problems are a favorite in coding interviews (FAANG/MANGA, startups, and most top tech companies) for several reasons:

1. **They test deep problem-solving skills** — You must choose the right representation, traversal algorithm, and handle edge cases (cycles, disconnected components, large inputs).
2. **They combine multiple concepts** — Recursion, queues/stacks, hashing, greedy techniques, dynamic programming on graphs, etc.
3. **They reflect real engineering work** — Many backend, infrastructure, ML, and platform problems involve networks, dependencies, or relationships.
4. **They scale in difficulty** — Easy problems test basic BFS/DFS; medium/hard ones require optimization, clever state tracking, or advanced techniques.
5. **They reveal how you think** — Interviewers can easily ask follow-ups: “What if the graph is weighted?”, “How would you handle updates?”, or “What’s the time/space complexity?”

Performing well on graph questions often separates candidates who can implement basic algorithms from those who can truly model and optimize real systems.

### What You'll Find in This Section

This repository section covers:
- Core graph representations and traversal templates (BFS, DFS, both iterative and recursive).
- Classic problems: Number of Islands, Course Schedule (topological sort), Clone Graph, Word Ladder, Network Delay Time, etc.
- Advanced patterns: Union-Find with path compression & union by rank, Dijkstra with priority queues, detecting/handling cycles, bipartite graphs, bridges/articulation points (where relevant).
- Complexity analysis and optimization tips.
- Common variations and follow-up questions.

Each solution includes:
- Clear problem statement
- Thought process / approach
- Clean, idiomatic code (with language variants where helpful)
- Time & space complexity
- Key takeaways and common pitfalls

Whether you're preparing for your first coding interview or refining your skills for senior/staff-level roles, strong graph intuition is a high-leverage skill that pays dividends across your career.

**Start with the fundamentals (BFS/DFS templates), then move to the categorized problems.** Practice until you can recognize when a problem is best solved by modeling it as a graph — even if it's not obvious at first.

### Table of Contents
