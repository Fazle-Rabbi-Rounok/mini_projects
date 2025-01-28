<!DOCTYPE html>
<html lang="en">

<head>
    <style>
        .to {
            text-align: center;
            /* Centers text inside the box */
            color: rgb(0, 0, 0);
            font-size: 50px;
            font-family: "Georgia", serif;
            max-width: 240px;
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
    <title>AVG Example</title>
    <link rel="stylesheet" href="cs.css" />
</head>

<body>
    <div>
        <p class="to">AVERAGE</p>
    </div>
    <!-- Left-aligned content: Definition -->
    <div class="left-container">
        <p><b>Definition</b></p>
    </div>
    <p class="defination">
        An average query in SQL calculates the average value of a numeric column
        in a table. This is done using the AVG() aggregate function. The AVG()
        function sums up all the values in the specified column and divides the
        total by the number of values.
    </p>
    <!-- Left-aligned content: Code -->
    <div class="left-container">
        <p><b>Code</b></p>
    </div>
    <div>
        <pre class="code-box">
SELECT
        AVG(age) as avg_age
    FROM
        users;</pre>
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

    $sql = "SELECT AVG(age) as avg_age FROM users";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        echo "<table>
                <tr>
                    <th>Avg_age</th>
                </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>{$row['avg_age']}</td>
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