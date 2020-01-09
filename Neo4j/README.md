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




## Exercise 2: Filtering queries using property values (Overview)

Thus far, you have filtered what nodes are returned from a query based upon the `Label` for the node where you returned *Person* or *Movie* nodes.

In this exercise, you will retrieve nodes from the database by specifying a filter criteria that is a property value. Then, you will examine the property keys in the training *Movie* graph. Finally, you will query the graph to return property values for nodes retrieved.

-   **Exercise 2.1**: Retrieve all movies that were released in a specific year.

        MATCH (m:Movie {released:2003}) RETURN m

-   **Exercise 2.2**: View the retrieved results as a table.

        # In the result pane, click the table icon. You should see this table in the result pane

-   **Exercise 2.3**: Query the database for all property keys.

        CALL db.propertyKeys

-   **Exercise 2.4**: Retrieve all Movies released in a specific year, returning their titles.

        MATCH (m:Movie {released: 2006}) RETURN m.title

-   **Exercise 2.5**: Display *title*, *released*, and *tagline* values for every *Movie* node in the graph.

        MATCH (m:Movie) RETURN m.title, m.released, m.tagline

-   **Exercise 2.6**: Display more user-friendly headers in the table.

        MATCH (m:Movie) RETURN m.title AS `movie title`, m.released AS released, m.tagline AS tagLine





## Exercise 3: Filtering queries using relationships (Overview)

In the previous exercise, you have filtered what nodes and properties are returned from a query based upon a value of a property for a node.

In this exercise, you will write queries that filter the nodes and property values that are returned based upon the relationships between nodes. You will first use an anonymous node to specify a filter based upon a node's specific relationship to other nodes. Then you will write a query that selects data based upon any relationship between nodes. Next, you will write a Cypher query to return information about the relationships between nodes. Finally, you will write a query to return property values for the relationships between nodes.

-   **Exercise 3.1:** Display the schema of the database.

        CALL db.schema()

-   **Exercise 3.2**: Retrieve all people who wrote the movie *Speed Racer*.

        MATCH (p:Person)-[:WROTE]->(:Movie {title: 'Speed Racer'}) RETURN p.name

-   **Exercise 3.3**: Retrieve all movies that are connected to the person, *Tom Hanks*.

        MATCH (m:Movie)<--(:Person {name: 'Tom Hanks'}) RETURN m.title

-   **Exercise 3.4:** Retrieve information about the relationships *Tom Hanks* had with the set of movies retrieved earlier.

        MATCH (m:Movie)-[rel]-(:Person {name: 'Tom Hanks'}) RETURN m.title, type(rel)

-   **Exercise 3.5:** Retrieve information about the roles that *Tom Hanks* acted in.

        MATCH (m:Movie)-[rel:ACTED_IN]-(:Person {name: 'Tom Hanks'}) RETURN m.title, rel.roles
