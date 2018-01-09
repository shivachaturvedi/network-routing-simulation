# network-routing-simulation

-- This is a C implementation to simulation Distance Vector and Link State Routing algorithms for routing IP packets over a network.

-- The code simulates a network based on user input
-- Network is simulated in form of a graph with edge weight representing the time it takes to route a packet along that edge
-- The simulation routes a packet between a given source and destination 
-- Relevant details such as the hop count and path are displayed 
-- The user can chose to add/delete an edge while the simulation is running
-- The user can chose to modify edge weight while the simulation is running
-- Implementation of Dijstra's Shortest Path and Warshall algorithms is used to route the packets based on the chosen routing algorithm
