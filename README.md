# Tabu Search

### What is Tabu Search?
Tabu Search is a commonly used meta-heuristic used for optimizing model parameters. A meta-heuristic is a general strategy that is used to guide and control actual heuristics. Tabu Search is often regarded as integrating memory structures into local search strategies. As local search has a lot of limitations, Tabu Search is designed to combat a lot of those issues.

### Tabu Search (TS)
The basic idea of Tabu Search is to penalize moves that take the solution into previously visited search spaces (also known as tabu). Tabu Search, however, does deterministically accept non-improving solutions in order to prevent getting stuck in local minimums.

### Short-term vs. Long-term Memory
Short Term memory is based off of recency of occurrence and is used to prevent the search algorithm from revisiting previously visited solutions and also can be used to return to good components in order to localize and intensify a search. This is accomplished by the Tabu List and is also known as intensification.

Long Term memory is based off of frequency of occurrence and is used to diversity the search and explore unvisited areas of the search space by avoiding explored areas. This is accomplished by frequency memory and is also known as diversification.

### Tabu List
The Tabu List is the cornerstone of utilizing short-term memory. This list stores a fixed amount of recently made moves. In some implementations, complete solutions are used instead of the moves used but this is not ideal if complete solutions are very large due to space limitations. Some examples of these moves are:

swap nodes in a graph/tour
toggling a bit between 0 and 1
insert or delete edges in a graph
Tabu Tenure
The Tabu Tenure is the number of iterations that a move stays in the Tabu List. The moves that are in the Tabu List are moves that cannot be made again as it was already recently visited. There are two ways to implement the Tabu Tenure (T):

Static: choose T to be a constant (often sqrt(T))
Dynamic: choose T randomly between some T_min and T_max
Aspiration Criteria
This is an optional part of Tabu Search. Moves or solutions that are part of the Aspiration Criteria cancel out the Tabu and the move can be made even if it’s in the Tabu List. This can also be used to prevent stagnation in cases where all possible moves are prohibited by the Tabu List. Some examples of Aspiration Criteria are:

if the new solution is better than the current best solution, then the new solution is used even if it’s on the Tabu List
setting the Tabu Tenure to be a smaller value
Frequency Memory
This memory holds the total number of iterations that each solution was picked since the beginning of the search. Solutions that were visited more are less likely to to be picked again and would promote more diverse solutions. There are two main approaches for diversifying:

Restart Diversification: allows components that rarely appear to be in the current solution by restarting the search from these points
Continuous Diversification: biases the evaluation of possible moves with the frequency of these moves. Moves that do not appear as often will then have a higher probability to be made.
Algorithm
1. Step 1: We first start with an initial solution s = S₀. This can be any solution that fits the criteria for an acceptable solution.

2. Step 2: Generate a set of neighbouring solutions to the current solution s labeled N(s). From this set of solutions, the solutions that are in the Tabu List are removed with the exception of the solutions that fit the Aspiration Criteria. This new set of results is the new N(s).


3. Step 3: Choose the best solution out of N(s) and label this new solution s’. If the solution s’ is better than the current best solution, update the current best solution. After, regardless if s’ is better than s, we update s to be s’.

4. Step 4: Update the Tabu List T(s) by removing all moves that are expired past the Tabu Tenure and add the new move s’ to the Tabu List. Additionally, update the set of solutions that fit the Aspiration Criteria A(s). If frequency memory is used, then also increment the frequency memory counter with the new solution.

5. Step 5: If the Termination Criteria are met, then the search stops or else it will move onto the next iteration. Termination Criteria is dependent upon the problem at hand but some possible examples are:
