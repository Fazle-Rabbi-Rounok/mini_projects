<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <style>
        .to {
            text-align: center;
            /* Centers text inside the box */
            color: rgb(0, 0, 0);
            font-size: 50px;
            font-family: "Georgia", serif;
            max-width: 200px;
            /* Limits the width of the box */
            padding: 14px;
            /* Adds space inside the box */
            background: bisque;
            /* White background */
            border-radius: 10px;
            /* Rounds the corners */
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
            /* Adds shadow for depth */
            border: 2px solid rgb(7, 1, 0);
            /* Red border */
            margin: 0 auto 50px auto;
        }
    </style>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>WHERE Clause</title>
</head>

<body>
    <div>
        <p class="to">Where</p>
    </div>
    <!-- Left-aligned content: Definition -->
    <div class="left-container">
        <p><b>Definition</b></p>
    </div>
    <p class="defination">
        The WHERE clause in SQL is used to filter rows in a query based on a
        specific condition. It is commonly used with the SELECT, UPDATE, and
        DELETE statements.
    </p>
    <!-- Left-aligned content: Code -->
    <div class="left-container">
        <p><b>Code</b></p>
    </div>
    <div>
        <pre class="code-box">
SELECT
        *
    FROM
        users
    WHERE
        age > 23;</pre>
    </div>

    <?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "shopping";
    $port = 3307;

    $conn = new mysqli($servername, $username, $password, $dbname, $port);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $sql = "SELECT id, name, email, age FROM users WHERE age > 23";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        echo "<table>
                <tr>
                    <th>User ID</th>
                    <th>Name</th> 
                    <th>Email</th>
                    <th>Age</th>
                </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>{$row['id']}</td>
                    <td>{$row['name']}</td>
                    <td>{$row['email']}</td>
                    <td>{$row['age']}</td>
                </tr>";
        }
        echo "</table>";
    } else {
        echo "No data found.";
    }

    $conn->close();
    ?> <a href="http://localhost/exp/05_queries.html" class="go-home">Home</a>
</body>

</html>