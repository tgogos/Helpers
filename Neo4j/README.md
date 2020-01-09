# Introduction to Neo4j

 - see more at: https://neo4j.com/graphacademy/
 

## Exercise 1: Retrieving Nodes (Preparations)
In this exercise, you will perform some basic retrievals from the Movie database.

-   **Exercise 1.1**: Retrieve all nodes from the database.

        MATCH (n) RETURN n

-   **Exercise 1.2**: Examine the *schema* of your database.

        CALL db.schema()

-   **Exercise 1.3**: Retrieve all *Person* nodes.

        MATCH (p:Person) RETURN p

-   **Exercise 1.4**: Retrieve all *Movie* nodes.

        MATCH (p:Movie) RETURN p
