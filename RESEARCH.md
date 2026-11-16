Dijkstra's algorithm
What I Needed to Learn and Why

The biggest topic I needed to learn for this project was Dijkstra's shortest path algorithm. I was aware of the algorithm before starting the project, but I had never implemented it myself or fully understood how it worked internally. As the route planner's main purpose is finding the shortest route between two locations, it made sense to use Dijkstra's algorithm and take the opportunity to learn more about it.

The main resources I looked at was:
https://github.com/bayram-dev/Dijkstra-Algorithm
I found this useful because it provided a complete implementation that I could read through and understand. Rather than copying the solution directly, I used it to understand the overall structure of the algorithm and how concepts such as tracking visited nodes and reconstructing paths worked. I also compared what I was seeing in the implementation against other explanations of Dijkstra's algorithm to ensure I understood the reasoning behind each part rather than just copying code.

Problems or Approaches That Didn't Work

The main issue I encountered was that many examples of Dijkstra's algorithm are written for grid-based pathfinding and use x and y coordinates. My project instead uses named locations stored within a graph structure. Because of this, I could not directly use many of the examples I found and instead had to adapt the underlying ideas to work with my own design.

What I Learned

I learned how Dijkstra's algorithm keeps track of the shortest known distance to each location, how a priority queue helps determine which location should be explored next and how a previous-location map can be used to reconstruct the final route once the destination is reached.


File Handling and Reading Data

What I Needed to Learn and Why
I wanted to store the locations and rotues in their own text file, as it's a concept that I have used many times within other languages and was something that I haven't done duirng the learning of C++. 

To learn this I read straight from the documentation here:
https://cplusplus.com/doc/tutorial/files/
I used this to understand how file streams work in C++ and how to read text line by line. After reading the documentation, I implemented it by using a text file filled with all of the routes and locations that I had in my hardcoded version as I already knew the correct output to verify it was working as intended.

Problems or Approaches That Didn't Work
While testing the file loading functionality I encountered an issue where blank lines within the file caused the application to crash. This happened because an empty string was being passed into std::stoi() when attempting to convert route distances. I also found that if the text file was not in the desired format it would crash the system, leading me to implement some basic validation techniques.

What I Learned
I learned how to use file streams, string streams and string conversion functions. More importantly, I learned the importance of validating external input and handling invalid data safely rather than assuming every line will be formatted correctly.