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
            margin: 0 auto 100px auto;
        }
    </style>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Display Form Data</title>

</head>

<body>

    <div>
        <p class="to">Select</p>
    </div>
    <!-- Left-aligned content: Definition -->
    <div class="left-container">
        <p><b>Definition</b></p>
    </div>
    <p class="defination">
        Select is Used to retrieve data from one or more tables.
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
        orders;</pre>
        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "shopping";  // Database name
        $port = 3307;  // Your MySQL port
        
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname, $port);

        // Check the connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        // SQL query to fetch data from the 'form_responses' table
        $sql = "SELECT id, user_id,product, amount FROM orders";
        $result = $conn->query($sql);

        // Display the data in a table format
        if ($result->num_rows > 0) {
            echo "<table>
                <tr>
                    <th>ID</th>
                    <th>user ID</th>
                    <th>product</th>
                    <th>amount</th>
                </tr>";
            while ($row = $result->fetch_assoc()) {
                echo "<tr>
                    <td>{$row['id']}</td>
                    <td>{$row['user_id']}</td>
                    <td>{$row['product']}</td>
                    <td>{$row['amount']}</td>
                </tr>";
            }
            echo "</table>";
        } else {
            echo '<div class="message">No data found</div>';
        }

        $conn->close();
        ?> <a href="http://localhost/exp/05_queries.html" class="go-home">Home</a>
    </div>
</body>

</html>