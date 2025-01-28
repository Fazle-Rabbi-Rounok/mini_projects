<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Group By Example</title>
    <style>
        .to {
            text-align: center;
            /* Centers text inside the box */
            color: rgb(0, 0, 0);
            font-size: 50px;
            font-family: "Georgia", serif;
            max-width: 280px;
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
</head>

<body>

    <div>
        <p class="to">GROUP BY</p>
    </div>
    <!-- Left-aligned content: Definition -->
    <div class="left-container">
        <p><b>Definition</b></p>
    </div>
    <p class="defination">
        The GROUP BY statement in SQL is used to arrange identical data into
        groups. It is commonly used with aggregate functions (e.g., COUNT(),
        SUM(), AVG(), MAX(), MIN()) to perform calculations on each group of data.
    </p>
    <!-- Left-aligned content: Code -->
    <div class="left-container">
        <p><b>Code</b></p>
    </div>
    <div>
        <pre class="code-box">
SELECT
        age,
        COUNT(*) as total_users
    FROM
        users
    GROUP BY
        age;</pre>
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

    $sql = "SELECT age, COUNT(*) as total_users FROM users GROUP BY age";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        echo "<table>
                <tr>
                    <th>Age</th>
                    <th>Total_Users</th>
                </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>{$row['age']}</td>
                    <td>{$row['total_users']}</td>
                </tr>";
        }
        echo "</table>";
    } else {
        echo "No data found.";
    }

    $conn->close();
    ?><a href="http://localhost/exp/05_queries.html" class="go-home">Home</a>
</body>

</html>