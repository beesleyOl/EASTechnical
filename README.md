What I built and why?

I chose to make this route planner as I enjoyed starting to learn C++ in unversity and have been slowly learning more after graduating. So wanted to do this project as something that in theory was quite simple but allowed me to practice some skills and learn some new ones.
The main skills I wanted to improve/highlight was the implementation of Dijkstra's algorithm into a more real world problem as well as reading a data from a text file. Though this was a simple problem I wanted to test my C++ skills with some other concepts and ideas that I have learnt over the years.

How to run

Requirements:
    - C++ 17 compatabile compiler

Built with:
g++ *.cpp -o routeplanner

Run with
./routeplanner
Expects to have a routes.txtfile to be present in project directory

How it works
It uses several different data types made for the system, those being: route, location and graph. These classes interact with the graph data type containing the rotues and locations that are connected from eachother.
The system reads the data from routes.txt with the specified layout of the CSV file being From,to,Distance. If any of this data is invalid it stops the program and lets the user know which part specifically is invalid or empty.
Pathfinding works by implementing Dijkstra's algortihm as the locations acting as the nodes traditionally used in it. As the algorithm is used to determine the shortest route by exploring possible paths and saving the shortest distance. 

What I would add in the future
The main thing I would add in the future is a way for the user to enter in more locations and routes directly into the system. Whether that be still in the command line interface or creating a simple GUI to do so depends on what other features I would like to include. 

General notes.
The system was desinged incrementally, with the first few iterations not having Dijkstra's implemented as well as not reading from a file. This was deliberate as it allowed me to test and verify my decisions were making logical sense throughout. This was made easy by making it as a github repository and allowed me to maintain a good work environment.